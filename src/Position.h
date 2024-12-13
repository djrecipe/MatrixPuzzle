// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include "Common.h"

class Position
{
public:
    Position(int row, int column);

    int row() const;
    int column() const;

    bool operator==(const Position &other) const;

    friend std::ostream &operator<<(std::ostream &stream, const Position &position);

    // You can add your own class members here.

private:
    int m_row;
    int m_column;
};
