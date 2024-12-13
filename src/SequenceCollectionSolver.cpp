#include "SequenceCollectionSolver.h"
#include "Matrix.h"
#include "Solution.h"
#include "SequenceCollection.h"
#include "PathNotFoundError.h"

SequenceCollectionSolver::SequenceCollectionSolver(SequenceCollection collection_in, Matrix matrix, int max_length)
    :m_matrix(matrix), collection(collection_in), last_search_area(SearchRow), last_start_pos(nullptr), m_maxPathLength(max_length)
{

}
SequenceCollectionResult SequenceCollectionSolver::Solve()
{
    this->last_start_pos = nullptr;
    this->last_search_area = SearchRow;
    this->m_matrix.ClearAll();
    Path path;
    auto start_pos = m_matrix.positionAt(0, 0);
    while (collection.GetAnyAttemptsRemain())
    {
        auto seq = collection.GetNextUnattempted();
        if (seq == std::nullopt)
            break;

        // update start position
        auto last_completed_seq = collection.GetLastCompletedSequence();
        Solution starter_solution;
        if (!path.empty())
        {
            int start_index = -1;
            // check if last completed sequence contains a subset of this sequence
            if (last_completed_seq.has_value() && (start_index = last_completed_seq.value().GetSolutionStartIndexOf(seq.value())) > -1)
            {
                // lock positions that belong to both previous and next sequence
                auto sol_start_index = start_index + collection.GetLastStartIndex();
                for (int i = sol_start_index; i < last_completed_seq.value().m_solution.size()
                    && starter_solution.GetValidMatchCount() < seq.value().codes().size(); i++)
                {
                    auto abs_pos = last_completed_seq.value().m_solution[i];
                    auto pos = m_matrix.positionAt(abs_pos.row(), abs_pos.column());
                    pos->SetIsLocked(true);
                    starter_solution.Append(pos, false);
                }
                start_pos = starter_solution.GetLastPosition();
            }
            else
            {
                // subset not found, start at end of last sequence
                start_pos = m_matrix.positionAt(
                    path.last().row(),
                    path.last().column());
                if (start_pos->value() == seq.value().codes()[0])
                    starter_solution.Append(start_pos, false);
            }
        }
        else
        {
            // no matches yet, always start at beginning
            start_pos = m_matrix.positionAt(0, 0);
            if (start_pos->value() == seq.value().codes()[0])
                starter_solution.Append(start_pos, false);

        }

        // iterate through sequence lengths from shortest to longest
        Path new_path;
        SearchAreas area = ((path.size()) % 2) == 0 ? SearchRow : SearchColumn;
        if (path.size() == 0)
            area = ((starter_solution.GetValidMatchCount()) % 2) == 0 ? SearchRow : SearchColumn;
        for (int i = seq.value().codes().size(); i <= this->m_maxPathLength; i++)
        {
            // try to find a match
            new_path = MatchSequence(start_pos, seq.value(), area, i, collection, starter_solution);
            if (!new_path.positions().empty())
                break;
        }

        // check if match found
        if (new_path.positions().empty())
        {
            collection.SetAttempted(seq.value());
        }
        else
        {
            if (starter_solution.GetValidMatchCount() > 0 && path.size() > 0)
                new_path = new_path.skip(starter_solution.GetValidMatchCount());
            if (new_path.positions().size() + path.positions().size() > m_maxPathLength)
            {
                new_path = Path();
                collection.SetAttempted(seq.value());
            }
            else
            {
                seq.value().SetSolution(new_path.positions());
                collection.SetCompleted(seq.value());
            }
        }
        path += new_path;
    }
    if (collection.GetAllUncompleted())
        throw PathNotFoundError("Failed to find any matches");
    collection.SetFinalPath(path);
    return collection.GetResult();
}

Position* SequenceCollectionSolver::FindNext(Position* curr_pos, std::vector<unsigned char> values, SearchAreas area,
    Solution* solution, int max_path_len, SequenceCollection sequenceCollection)
{
    // init values
    int match_index = solution->GetValidMatchCount();
    if (match_index >= values.size())
        return nullptr;
    auto desired_value = values[match_index];
    Position* match = nullptr;

    // find match
    match = curr_pos->FindNeighbor(area, desired_value, match_index);

    // check if match found
    if (match)
    {
        // match found: find next match in sequence
        solution->Append(match);
        // check if done
        if (solution->GetValidMatchCount() >= values.size())
            return match;
        // (alternate between row search & column search)
        return FindNext(match, values,
            (SearchAreas)(~area), solution, max_path_len, sequenceCollection);
    }

    // 
    else if (curr_pos->GetIsDisqualifiedForMatchIndex(-1))
    {
        curr_pos = curr_pos->FindNeighbor(area, std::nullopt, match_index);
        if (!curr_pos)
            return nullptr;
        solution->Append(curr_pos, true);
        return FindNext(curr_pos, values, (SearchAreas)~area, solution, max_path_len, sequenceCollection);
    }

    // dead-end: go back and check next potential column/row
    else
    {
        // check if still trying to find very first match in entire sequence collection
        auto search_area = solution->GetValidMatchCount() < 1 && sequenceCollection.GetLastCompletedSequence() == std::nullopt ? (SearchAreas)(~area) : area;
        // waste moves
        if (!curr_pos->GetIsDisqualifiedForMatchIndex(match_index)
            && WasteTillNext(curr_pos, search_area, values, solution, match_index, max_path_len, sequenceCollection))
        {
            // check if done
            if (solution->GetValidMatchCount() >= values.size())
                return match;
            if (solution->GetWastedCount() >= max_path_len)
                return nullptr;

            // find next;
            return FindNext(solution->GetTotalCount() > 0 ? solution->GetLastPosition() : last_start_pos,
                values, area, solution, max_path_len, sequenceCollection);
        }
        else
        {
            //
            if (!solution->EraseLastPosition())
                return nullptr;
            curr_pos->DisqualifyForMatchIndex(match_index - 1);
            auto next_pos = solution->GetTotalCount() > 0 ? solution->GetLastPosition() : m_matrix.positionAt(0, 0);
            auto search_area = solution->GetTotalCount() > 0 ? (SearchAreas)~area : SearchRow;
            auto find_next = FindNext(next_pos, values, search_area, solution, max_path_len, sequenceCollection);
            if (!find_next)
            {
                return nullptr;
            }
        }
        return curr_pos;
    }
}

Path SequenceCollectionSolver::MatchSequence(Position* start_pos, Sequence sequence, SearchAreas& search_area,
    int max_path_len, SequenceCollection sequenceCollection, Solution solution)
{
    // init starting values
    auto desired_values = sequence.codes();
    if (solution.GetValidMatchCount() >= desired_values.size())
        return Path(std::move(solution.GetPositions()));
    m_matrix.ClearDisqualifications();

    // find next match in sequence
    last_start_pos = start_pos;
    last_search_area = search_area;

    auto result = FindNext(start_pos, desired_values, search_area, &solution, max_path_len, sequenceCollection);
    if (!result)
        return Path();
    return Path(std::move(solution.GetPositions()));
}

bool SequenceCollectionSolver::WasteTillNext(Position* start_pos, SearchAreas last_search_area,
    std::vector<unsigned char> values, Solution* solution, int match_index, int max_path_len, SequenceCollection sequenceCollection)
{
    auto desired_value = values[match_index];
    auto match = start_pos->FindNeighbor(last_search_area, desired_value, match_index + 1);
    start_pos->DisqualifyForMatchIndex(match_index);
    if (match)
    {
        if (solution->GetValidMatchCount() < 1 && sequenceCollection.GetLastCompletedSequence() == std::nullopt)
            solution->Append(start_pos, true);
        solution->Append(match, solution->GetValidMatchCount() > 0);
        return true;
    }

    // check if max length reached
    if (solution->GetTotalCount() + (values.size() - match_index) >= max_path_len)
    {
        // clear entire solution and start over
        solution->Clear();
        return true;
    }

    // get any adjacent neighbor
    if (solution->GetValidMatchCount() < 1 && (start_pos = start_pos->FindNeighbor(last_search_area, std::nullopt, match_index)))
    {
        solution->Append(start_pos, true);
        return WasteTillNext(start_pos, (SearchAreas)~last_search_area, values, solution, match_index, max_path_len, sequenceCollection);
    }

    // can no longer progress
    return false;
}