// ---------------------------------------------------------------------------------------------
// PLEASE DO NOT MODIFY, RENAME OR REMOVE ANY OF CLASSES, METHODS AND VARIABLES BELOW.
// YOU CAN ADD YOUR OWN METHODS AND VARIABLES TO THE EXISTING CLASSES AND USE THEM IN YOUR WORK.
// ---------------------------------------------------------------------------------------------

#include "Path.h"

Path::Path()
{
}

Path::Path(const std::vector<Position>& positions)
    : m_positions(positions)
{
}

Path::Path(const std::vector<Position*>& positions)
{
    for(auto pos : positions)
    {
        this->m_positions.push_back(Position(pos->row(), pos->column(), pos->value()));
    }
}

const std::vector<Position> &Path::positions() const
{
    return m_positions;
}

bool Path::operator==(const Path &other) const
{
    return m_positions == other.m_positions;
}

Path& Path::operator+=(const Path& path)
{
    for (size_t i = 0; i < path.m_positions.size(); ++i)
    {
        this->m_positions.push_back(path.m_positions[i]);
    }
    return *this;
}

Position Path::last()
{
    return this->m_positions.back();
}

Path& Path::skip(int count)
{
    std::vector<Position> vec;
    for (int i = count; i < this->m_positions.size(); i++)
        vec.push_back(this->m_positions[i]);
    this->m_positions = vec;
    return *this;
}

bool Path::empty()
{
    return this->m_positions.empty();
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

std::size_t Path::size()
{
    return this->m_positions.size();
}
