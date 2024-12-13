// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include "Position.h"

class Solution
{
public:
    Solution();
    void Append(Position* position, bool is_wasted = false);
    void Clear();
    bool EraseLastPosition();
    int GetValidMatchCount();
    int GetWastedCount();
    std::vector<Position*> GetPositions() const;
    Position* GetLastPosition();
    int GetTotalCount();
private:
    std::vector<Position*> positions;

};
