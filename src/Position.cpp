// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "Position.h"

Position::Position(int row, int column)
    : m_row(row)
    , m_column(column)
{
}

int Position::row() const
{
    return m_row;
}

int Position::column() const
{
    return m_column;
}

bool Position::operator==(const Position &other) const
{
    return m_row == other.m_row && m_column == other.m_column;
}

std::ostream &operator<<(std::ostream &stream, const Position &position)
{
    return stream << "{" << position.m_row << ", " << position.m_column << "}";
}
