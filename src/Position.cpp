// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "Position.h"

#include <optional>

Position::Position(int row, int column, unsigned char value)
    : m_iswasted(false), m_isoccupied(false), m_islocked(false)
{
    this->m_row = row;
    this->m_column = column;
    this->m_value = value;
}
Position::Position(int row, int column)
    : m_iswasted(false), m_isoccupied(false), m_islocked(false), m_value(-1)
{
    this->m_row = row;
    this->m_column = column;
}


int Position::row() const
{
    return m_row;
}

int Position::column() const
{
    return m_column;
}

unsigned char Position::value() const
{
    return m_value;
}

void Position::SetNeighbors(SearchAreas search_area, const std::vector<Position*>& neighbors)
{
    switch(search_area)
    {
    case SearchRow:
        this->rowNeighbors = neighbors;
        break;
    case SearchColumn:
        this->colNeighbors = neighbors;
        break;
    }
}

void Position::SetIsLocked(bool value)
{
    this->m_islocked = value;
}

void Position::SetIsOccupied(bool value)
{
    this->m_isoccupied = value;
}

void Position::SetIsWasted(bool value)
{
    this->m_iswasted = value;
}

void Position::DisqualifyForMatchIndex(int index)
{
    this->disqualifications.push_back(index);
}

void Position::ClearDisqualifications()
{
    this->disqualifications.clear();
}


Position* Position::FindNeighbor(SearchAreas search_area, std::optional<unsigned char> value, int match_index)
{
    switch(search_area)
    {
    case SearchRow:
        return FindRowNeighbor(value, match_index);
    case SearchColumn:
        return FindColNeighbor(value, match_index);
    }
    return nullptr;
}

bool Position::GetAllNeighborsDisqualifiedForMatchIndex(SearchAreas search_area, int match_index)
{
    Position* ptr = nullptr;
    switch (search_area)
    {
    case SearchRow:
        ptr = FindRowNeighbor(std::nullopt, match_index);
        break;
    case SearchColumn:
        ptr =  FindColNeighbor(std::nullopt, match_index);
        break;
    }
    return ptr == nullptr;
}

bool Position::GetIsLocked() const
{
    return this->m_islocked;
}

bool Position::GetIsOccupied() const
{
    return this->m_isoccupied;
}

bool Position::GetIsWasted() const
{
    return this->m_iswasted;
}

bool Position::GetIsDisqualifiedForMatchIndex(int index)
{
    //if (this->m_isoccupied)
    //    return true;
    for(int i=0; i<this->disqualifications.size(); i++)
    {
        if (disqualifications[i] == index)
            return true;
    }
    return false;
}

std::vector<Position*> Position::GetNeighbors(SearchAreas search_area)
{
    switch(search_area)
    {
    case SearchRow:
        return this->rowNeighbors;
    case SearchColumn:
        return this->colNeighbors;
    }
    return std::vector<Position*>();
}


Position* Position::FindRowNeighbor(std::optional<unsigned char> value, int match_index)
{
    for(int i=0; i<this->rowNeighbors.size(); i++)
    {
        if ((value == std::nullopt || this->rowNeighbors[i]->value() == value)
            && !this->rowNeighbors[i]->GetIsDisqualifiedForMatchIndex(match_index))
            return this->rowNeighbors[i];
    }
    return nullptr;
}

Position* Position::FindColNeighbor(std::optional<unsigned char> value, int match_index)
{
    for (int i = 0; i < this->colNeighbors.size(); i++)
    {
        if ((value == std::nullopt || this->colNeighbors[i]->value() == value)
            && !this->colNeighbors[i]->GetIsDisqualifiedForMatchIndex(match_index))
            return this->colNeighbors[i];
    }
    return nullptr;
}

bool Position::operator==(const Position &other) const
{
    return m_row == other.m_row && m_column == other.m_column;
}

std::ostream &operator<<(std::ostream &stream, const Position &position)
{
    return stream << "{" << position.m_row << ", " << position.m_column << "}";
}
