// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include "Common.h"
#include "Position.h"

class Matrix
{
public:
    Matrix(const std::vector<std::vector<unsigned char>> &values);

    int rowCount() const;
    int columnCount() const;

    unsigned char value(int row, int column) const;
    unsigned char value(const Position &position) const;

    // You can add your own class members here.
    Position* positionAt(int row, int column) const;
    void ClearAll();
    void ClearDisqualifications();
    void Disqualify(int row, int column, int match_index);
    bool GetAllRowsDisqualified(int column, int match_index);
    bool GetAllColumnsDisqualified(int row, int match_index);
    void SetOccupied(std::vector<Position> positions, bool value) const;
    std::string ToString() const;
    Position** positions = nullptr;
    int row_count = 0;
    int col_count = 0;

private:
    std::vector<std::vector<unsigned char>> m_values;
};
