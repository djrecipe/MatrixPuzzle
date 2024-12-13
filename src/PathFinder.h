// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW
// EXCEPT PATHFINDER::RUN() METHOD THAT YOU NEED TO IMPLEMENT.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include "Common.h"
#include "Matrix.h"
#include "Path.h"
#include "Sequence.h"

class PathFinder
{
public:
    PathFinder(const Matrix &matrix, const std::vector<Sequence> &sequences, int maxPathLength);

    Path run();

    // You can add your own class members here.

private:
    Matrix m_matrix;
    std::vector<Sequence> m_sequences;
    int m_maxPathLength;
};
