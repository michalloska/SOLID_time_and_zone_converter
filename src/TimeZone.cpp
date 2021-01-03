#include "include/TimeZone.hpp"
#include <cmath>

TimeZone::TimeZone(Time utcOffset, char * name): utcTimeOffset(utcOffset),
                                                 timeZoneName(name)
{

}

Time TimeZone::GetTimeInUTCFormat() const
{
    return utcTimeOffset;
}

std::ostream& operator<<(std::ostream & out, const TimeZone & timeZone)
{
    auto rawUtcValue = timeZone.GetTimeInUTCFormat();
    if (rawUtcValue.second != 0)
    {
        out << "+";
    }
    out << rawUtcValue.first << "," << rawUtcValue.second;
    return out;
}

Time TimeZone::CalculateTimeZoneDifferenceInUtc(const Time & left, const Time & right)
{
    return Time(left.first - right.first,
                left.second - right.second);
}

