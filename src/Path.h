// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#pragma once

#include "Common.h"
#include "Position.h"

class Path
{
public:
    Path();
    Path(const std::vector<Position> &positions);

    const std::vector<Position> &positions() const;

    bool operator==(const Path &other) const;

    friend std::ostream &operator<<(std::ostream &stream, const Path &path);

    // You can add your own class members here.

private:
    std::vector<Position> m_positions;
};
