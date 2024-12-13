// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW
// EXCEPT PATHFINDER::RUN() METHOD THAT YOU NEED TO IMPLEMENT.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "PathFinder.h"

#include <utility>

#include "SequenceCollection.h"
#include "SequenceCollectionFactory.h"

#include "InvalidArgumentError.h"
#include "SequenceCollectionSolver.h"

PathFinder::PathFinder(const Matrix &matrix, const std::vector<Sequence> &sequences, int maxPathLength)
    : m_matrix(matrix)
    , m_sequences(sequences)
    , m_maxPathLength(maxPathLength)
{
    m_rowCount = matrix.rowCount();
    m_colCount = matrix.columnCount();
}

SequenceCollectionResult PathFinder::GetResult(SequenceCollection collection) const
{
    SequenceCollectionSolver solver(std::move(collection), this->m_matrix, this->m_maxPathLength);
    return solver.Solve();
}

Path PathFinder::run()
{
    SequenceCollectionFactory factory;
    auto collections = factory.GenerateUniqueSequenceCollections(this->m_sequences);
    SequenceCollectionResult best_result;
    best_result.TotalPoints = 0;
    best_result.TotalLength = 9999;
    best_result.IsOptimal = false;
    best_result.Path = Path();
    for(auto collection : collections)
    {
        auto result = this->GetResult(collection);
        if (result.TotalPoints > best_result.TotalPoints)
            best_result = result;
        else if (result.TotalPoints == best_result.TotalPoints && result.TotalLength < best_result.TotalLength)
            best_result = result;
        if (best_result.IsOptimal)
            break;
    }
    return best_result.Path;
}
