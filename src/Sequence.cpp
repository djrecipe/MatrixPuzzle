// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "Sequence.h"

Sequence::Sequence(const std::vector<unsigned char> &codes, int score)
    : m_codes(codes)
    , m_score(score)
{
}

const std::vector<unsigned char> &Sequence::codes() const
{
    return m_codes;
}

int Sequence::score() const
{
    return m_score;
}
