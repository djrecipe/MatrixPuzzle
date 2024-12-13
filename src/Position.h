// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include <optional>

#include "Common.h"
#include "Enums.h"

class Position
{
public:
    Position(int row, int column);

    int row() const;
    int column() const;

    bool operator==(const Position &other) const;

    friend std::ostream &operator<<(std::ostream &stream, const Position &position);

    // You can add your own class members here.
    Position(int row, int column, unsigned char value);
    unsigned char value() const;
    Position* FindNeighbor(SearchAreas search_area, std::optional<unsigned char> value, int match_index);
    bool GetAllNeighborsDisqualifiedForMatchIndex(SearchAreas search_area, int match_index);
    bool GetIsLocked() const;
    bool GetIsOccupied() const;
    bool GetIsWasted() const;
    bool GetIsDisqualifiedForMatchIndex(int index);
    std::vector<Position*> GetNeighbors(SearchAreas search_area);
    void SetNeighbors(SearchAreas search_area, const std::vector<Position*>& neighbors);
    void SetIsLocked(bool value);
    void SetIsOccupied(bool value);
    void SetIsWasted(bool value);
    void DisqualifyForMatchIndex(int index);
    void ClearDisqualifications();
    bool m_iswasted;
    bool m_isoccupied;
    bool m_islocked;
    unsigned char m_value;
    std::vector<int> disqualifications;
    std::vector<Position*> rowNeighbors;
    std::vector<Position*> colNeighbors;
    Position* FindColNeighbor(std::optional<unsigned char> value, int match_index);
    Position* FindRowNeighbor(std::optional<unsigned char> value, int match_index);

private:
    int m_row;
    int m_column;
};
