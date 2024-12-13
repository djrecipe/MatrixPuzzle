// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "Solution.h"

Solution::Solution()
{
}
void Solution::Append(Position* position, bool is_wasted)
{
    if (is_wasted)
        position->SetIsWasted(true);
    this->positions.push_back(position);
}

void Solution::Clear()
{
    if (this->positions.size() < 1)
        return;
    auto position = this->positions[this->positions.size()-1];
    while(!position->GetIsLocked())
    {
        position->SetIsWasted(false);
        this->positions.erase(this->positions.end()-1);
        if (this->positions.size() < 1)
            break;
        position = this->positions[this->positions.size()-1];
    }
}

std::vector<Position*> Solution::GetPositions() const
{
    return this->positions;
}

int Solution::GetValidMatchCount()
{
    int count = 0;
    for (auto pos : this->positions)
    {
        if (!pos->GetIsWasted())
            count++;
    }
    return count;
}

int Solution::GetWastedCount()
{
    int count = 0;
    for (auto pos : this->positions)
    {
        if (pos->GetIsWasted())
            count++;
    }
    return count;
}

int Solution::GetTotalCount()
{
    return this->positions.size();
}


Position* Solution::GetLastPosition()
{
    return this->positions[this->positions.size() - 1];
}

bool Solution::EraseLastPosition()
{
    if (this->positions.size() < 1)
        return true;
    if (this->positions[this->positions.size() - 1]->GetIsLocked())
        return false;
    this->positions[this->positions.size() - 1]->SetIsWasted(false);
    this->positions.erase(this->positions.end() - 1);
    return true;
}
