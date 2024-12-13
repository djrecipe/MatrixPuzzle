// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include "Common.h"
#include "Position.h"

class Sequence
{
public:
    Sequence(const std::vector<unsigned char> &codes, int score);

    const std::vector<unsigned char> &codes() const;

    int score() const;

    // You can add your own class members here.
    std::size_t GetHashCode();
    int GetStartIndexOf(Sequence sequence);
    int GetSolutionStartIndexOf(Sequence sequence);
    void SetSolution(std::vector<Position> positions);
    std::vector<Position> m_solution;
private:
    std::vector<unsigned char> m_codes;
    int m_score;
};
