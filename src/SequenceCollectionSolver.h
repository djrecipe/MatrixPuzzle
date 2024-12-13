#pragma once
#include "Enums.h"
#include "SequenceCollection.h"
#include "Matrix.h"
class Solution;

class SequenceCollectionSolver
{
public:
    SequenceCollectionSolver(SequenceCollection collection_in, Matrix matrix, int max_length);
    SequenceCollectionResult Solve();
    Position* FindNext(Position* curr_pos, std::vector<unsigned char> values, SearchAreas area,
        Solution* solution, int max_path_len, SequenceCollection sequenceCollection);
    bool WasteTillNext(Position* start_pos, SearchAreas last_search_area,
        std::vector<unsigned char> values, Solution* solution, int match_index, int max_path_len, SequenceCollection sequenceCollection);
    Path MatchSequence(Position* start_pos, Sequence sequence, SearchAreas& search_area,
        int max_path_len, SequenceCollection sequenceCollection, Solution solution);

private:
    SequenceCollection collection;
    Position* last_start_pos;
    SearchAreas last_search_area;
    Matrix m_matrix;
    int m_maxPathLength;
};
