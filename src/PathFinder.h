// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW
// EXCEPT PATHFINDER::RUN() METHOD THAT YOU NEED TO IMPLEMENT.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include <optional>
#include <unordered_map>

#include "Common.h"
#include "Enums.h"
#include "Matrix.h"
#include "Path.h"
#include "Sequence.h"
#include "SequenceCollection.h"
#include "Solution.h"

class PathFinder
{
public:
    PathFinder(const Matrix &matrix, const std::vector<Sequence> &sequences, int maxPathLength);

    Path run();

    // You can add your own class members here.
    int m_rowCount;
    int m_colCount;
    Position* FindNext(Position* curr_pos, std::vector<unsigned char> values, SearchAreas area,
        Solution* solution, int max_path_len, SequenceCollection sequenceCollection);
    SequenceCollectionResult GetResult(SequenceCollection collection) const;
    Path MatchSequence(Position* start_pos, Sequence sequence, SearchAreas& search_area,
        int max_path_len, SequenceCollection sequenceCollection, Solution solution);
    bool WasteTillNext(Position* start_pos, SearchAreas last_search_area,
        std::vector<unsigned char> values, Solution* solution,
        int match_index, int max_path_len, SequenceCollection sequenceCollection);

private:
    Matrix m_matrix;
    std::vector<Sequence> m_sequences;
    int m_maxPathLength;
};
