// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "Matrix.h"

Matrix::Matrix(const std::vector<std::vector<unsigned char>> &values)
    : m_values(values)
{
}

int Matrix::rowCount() const
{
    return static_cast<int>(m_values.size());
}

int Matrix::columnCount() const
{
    return !m_values.empty() ? static_cast<int>(m_values[0].size()) : 0;
}

unsigned char Matrix::value(int row, int column) const
{
    return m_values[row][column];
}

unsigned char Matrix::value(const Position &position) const
{
    return m_values[position.row()][position.column()];
}
