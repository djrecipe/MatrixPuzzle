// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "Matrix.h"

Matrix::Matrix(const std::vector<std::vector<unsigned char>> &values)
{
    // init
    col_count = values[0].size();
    row_count = values.size();
    positions = new Position*[row_count * col_count];

    // populate values
    for(int y=0; y< row_count; y++)
    {
        for(int x = 0; x<col_count; x++)
        {
            positions[y * col_count + x] = new Position(y, x, values[y][x]);
        }
    }

    // populate pointers
    for (int y = 0; y < rowCount(); y++)
    {
        for (int x = 0; x < columnCount(); x++)
        {
            auto position = positions[y * col_count + x];
            std::vector<Position*> col_neighbors;
            for (int xx = 0; xx < columnCount(); xx++)
            {
                if (xx == x)
                    continue;
                col_neighbors.push_back(positions[y * columnCount() + xx]);
            }
            position->SetNeighbors(SearchRow, std::move(col_neighbors));

            std::vector<Position*> row_neighbors;
            for (int yy = 0; yy < rowCount(); yy++)
            {
                if (yy == y)
                    continue;
                row_neighbors.push_back(positions[yy * columnCount() + x]);
            }
            position->SetNeighbors(SearchColumn, std::move(row_neighbors));
        }
    }
    return;
}

int Matrix::rowCount() const
{
    return row_count;
}

int Matrix::columnCount() const
{
    return col_count;
}

unsigned char Matrix::value(int row, int column) const
{
    auto ptr = this->positions[row * col_count + column];
    return ptr->value();
}

unsigned char Matrix::value(const Position &position) const
{
    auto ptr = this->positions[position.row() * col_count + position.column()];
    return ptr->value();
}

Position* Matrix::positionAt(int row, int column) const
{
    return this->positions[row * col_count + column];
}

void Matrix::ClearDisqualifications()
{
    for (int y = 0; y < this->rowCount(); y++)
    {
        for (int x = 0; x < this->columnCount(); x++)
        {
            auto ptr = this->positions[y * col_count + x];
            ptr->ClearDisqualifications();
        }
    }
}

void Matrix::ClearAll()
{
    for (int y = 0; y < this->rowCount(); y++)
    {
        for (int x = 0; x < this->columnCount(); x++)
        {
            auto ptr = this->positions[y * col_count + x];
            ptr->SetIsWasted(false);
            ptr->SetIsLocked(false);
            ptr->SetIsOccupied(false);
            ptr->ClearDisqualifications();
        }
    }
}

void Matrix::Disqualify(int row, int column, int match_index)
{
    this->positions[row * col_count + column]->DisqualifyForMatchIndex(match_index);
}

bool Matrix::GetAllRowsDisqualified(int column, int match_index)
{
    for (int y = 0; y < this->rowCount(); y++)
    {
        auto ptr = this->positions[y * col_count + column];
        if (!ptr->GetIsDisqualifiedForMatchIndex(match_index))
            return false;
    }
    return true;
}

bool Matrix::GetAllColumnsDisqualified(int row, int match_index)
{
    for (int x = 0; x < this->columnCount(); x++)
    {
        auto ptr = this->positions[row * col_count + x];
        if (!ptr->GetIsDisqualifiedForMatchIndex(match_index))
            return false;
    }
    return true;
}

void Matrix::SetOccupied(std::vector<Position> positions_in, bool value) const
{
    for(auto &pos_in : positions_in)
    {
        auto pos_out = this->positions[pos_in.row() * col_count + pos_in.column()];
        pos_out->SetIsOccupied(value);
    }
}


std::string Matrix::ToString() const
{
    std::ostringstream stream;
    for(int y=0; y<this->rowCount(); y++)
    {
        for(int x=0; x<this->columnCount(); x++)
        {
            auto ptr = this->positions[y * col_count + x];
            stream << std::hex << (int)ptr->value() << " ";
        }
        stream << "\n";
    }
    return stream.str();
}
