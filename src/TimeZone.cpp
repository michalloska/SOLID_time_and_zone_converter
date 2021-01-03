#include "include/TimeZone.hpp"


TimeZone::TimeZone(int utcOffset): utcTimeOffset(utcOffset)
{

}

int TimeZone::GetTimeInUTCFormat() const
{
    return utcTimeOffset;
}

std::ostream& operator<<(std::ostream & out, const TimeZone & timeZone)
{
    auto rawUtcValue = timeZone.GetTimeInUTCFormat();
    if (rawUtcValue >= 0)
    {
        out << "+";
    }
    out << rawUtcValue;
    return out;
}
