// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW
// EXCEPT PATHFINDER::RUN() METHOD THAT YOU NEED TO IMPLEMENT.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "PathFinder.h"

#include "InvalidArgumentError.h"
#include "PathNotFoundError.h"

PathFinder::PathFinder(const Matrix &matrix, const std::vector<Sequence> &sequences, int maxPathLength)
    : m_matrix(matrix)
    , m_sequences(sequences)
    , m_maxPathLength(maxPathLength)
{
}

Path PathFinder::run()
{
    // TODO: Implement me.
    return Path();
}
