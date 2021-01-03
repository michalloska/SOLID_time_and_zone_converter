#include "include/Time.hpp"

std::ostream& operator<<(std::ostream & out, const Time & time)
{
    out << "Time: " << time.first << ":" << time.second;
    return out;
}