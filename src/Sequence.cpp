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

std::size_t Sequence::GetHashCode()
{
    std::size_t seed = this->m_codes.size() + this->m_score;
    for(auto i=0; i<this->m_codes.size(); i++)
    {
        seed ^= i * 0x9e3779b9 + (this->m_codes[i] << 6) + (this->m_codes[i] >> 2);
    }
    return seed;
}

int Sequence::GetStartIndexOf(Sequence sequence)
{
    auto it = std::find(this->m_codes.begin(), this->m_codes.end(), sequence.m_codes[0]);
    if (it == std::end(this->m_codes))
        return -1;
    auto start_index = it - std::begin(this->m_codes);
    if (sequence.m_codes.size() < 2)
        return start_index;
    auto j = 0;
    for(int i=start_index; i<this->m_codes.size() && j < sequence.m_codes.size(); i++)
    {
        if (this->m_codes[i] != sequence.m_codes[j++])
            return -1;
    }
    return start_index;
}

int Sequence::GetSolutionStartIndexOf(Sequence sequence)
{
    auto start_index = -1;
    for (int i = 0; i < this->m_solution.size(); i++)
    {
        if (this->m_solution[i].m_value == sequence.m_codes[0])
        {
            start_index = i;
            break;
        }
    }
    if (start_index < 0 || sequence.m_codes.size() < 2)
        return start_index;
    auto j = 0;
    for (int i = start_index; i < this->m_solution.size() && j < sequence.m_codes.size(); i++)
    {
        if (this->m_solution[i].m_value != sequence.m_codes[j++])
            return -1;
    }
    return start_index;
}

void Sequence::SetSolution(std::vector<Position> positions)
{
    this->m_solution = positions;
}