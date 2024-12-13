// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include "Common.h"

class Sequence
{
public:
    Sequence(const std::vector<unsigned char> &codes, int score);

    const std::vector<unsigned char> &codes() const;

    int score() const;

    // You can add your own class members here.

private:
    std::vector<unsigned char> m_codes;
    int m_score;
};
