// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "Path.h"

Path::Path()
{
}

Path::Path(const std::vector<Position> &positions)
    : m_positions(positions)
{
}

const std::vector<Position> &Path::positions() const
{
    return m_positions;
}

bool Path::operator==(const Path &other) const
{
    return m_positions == other.m_positions;
}

std::ostream &operator<<(std::ostream &stream, const Path &path)
{
    stream << "Path({";
    for (size_t i = 0; i < path.m_positions.size(); ++i)
    {
        stream << path.m_positions[i];
        if (i < path.m_positions.size() - 1)
            stream << ", ";
    }
    stream << "})";

    return stream;
}
