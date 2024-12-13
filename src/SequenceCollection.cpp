#include "SequenceCollection.h"

SequenceCollection::SequenceCollection(std::vector<Sequence> sequences_in)
    :sequences(sequences_in), lastCompletedSequence(std::nullopt)
{
}

void SequenceCollection::ClearAttempted()
{
    this->attempted.clear();
}

void SequenceCollection::ResetSuboptimalCompletions()
{
    for(auto seq : this->sequences)
    {
        if (this->completed.find(seq.GetHashCode()) == std::end(this->completed))
            continue;
        if (this->completion_lengths[seq.GetHashCode()] > seq.codes().size())
            this->completed.erase(seq.GetHashCode());
    }
    return;
}


void SequenceCollection::SetAttempted(Sequence sequence)
{
    this->attempted.insert(sequence.GetHashCode());
    this->completion_lengths[sequence.GetHashCode()] = sequence.m_solution.size();
}

void SequenceCollection::SetCompleted(Sequence sequence)
{
    sequence_start_index[sequence.GetHashCode()] = this->GetSolutionLength();
    this->completion_lengths[sequence.GetHashCode()] = sequence.m_solution.size();
    this->completed.insert(sequence.GetHashCode());
    this->ClearAttempted();
    this->lastCompletedSequence = sequence;
}

void SequenceCollection::SetFinalPath(Path path)
{
    this->finalPath = path;
}

bool SequenceCollection::GetAnyAttemptsRemain()
{
    return this->attempted.size() + this->completed.size() < this->sequences.size();
}

bool SequenceCollection::GetAlreadyAttemptedOrCompleted(Sequence sequence)
{
    return completed.find(sequence.GetHashCode()) != std::end(completed)
        || attempted.find(sequence.GetHashCode()) != std::end(attempted);
}

std::optional<Sequence> SequenceCollection::GetLastCompletedSequence()
{
    return this->lastCompletedSequence;
}

int SequenceCollection::GetLastStartIndex()
{
    if(this->lastCompletedSequence == std::nullopt)
        return 0;
    return sequence_start_index[this->lastCompletedSequence->GetHashCode()];
}

std::optional<Sequence> SequenceCollection::GetNextUnattempted()
{
    for(int i=0; i<this->sequences.size(); i++)
    {
        if(this->GetAlreadyAttemptedOrCompleted(this->sequences[i]))
            continue;
        return this->sequences[i];
    }
    return std::nullopt;
}

SequenceCollectionResult SequenceCollection::GetResult()
{
    SequenceCollectionResult result;
    result.Path = this->finalPath;
    result.TotalLength = this->finalPath.size();
    result.TotalPoints = 0;
    int optimal_points = 0;
    int optimal_length = 0;
    for(auto seq : this->sequences)
    {
        optimal_points += seq.score();
        optimal_length += seq.codes().size();
        if (this->completed.find(seq.GetHashCode()) != std::end(this->completed))
            result.TotalPoints += seq.score();
    }
    result.IsOptimal = result.TotalPoints >= optimal_points && result.TotalLength <= optimal_length;
    return result;
}

std::size_t SequenceCollection::GetSolutionLength()
{
    std::size_t length = 0;
    for(auto seq : this->sequences)
        length += seq.m_solution.size();
    return length;
}

bool SequenceCollection::GetAllUncompleted()
{
    return this->completed.size() < 1;
}
