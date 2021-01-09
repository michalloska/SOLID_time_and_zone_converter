#include "../include/TimeZone.hpp"
#include <cmath>

TimeZone::TimeZone(Time utcOffset, const char *name) : utcTimeOffset(utcOffset),
                                                       timeZoneName(name)
{
}

Time TimeZone::GetTimeInUTCFormat() const
{
    return utcTimeOffset;
}

const char *TimeZone::GetName() const
{
    return timeZoneName;
}

Time TimeZone::CalculateTimeZoneDifferenceInUtc(const TimeZone &sourceTimeZone, const TimeZone &destinationTimeZone)
{
    auto sourceTime = sourceTimeZone.GetTimeInUTCFormat();
    auto destinationTime = destinationTimeZone.GetTimeInUTCFormat();

    auto calculatedUtcDifference = Time::calculateUtcTimeOffset(destinationTime, sourceTime);
    return calculatedUtcDifference;
}

std::ostream &operator<<(std::ostream &out, const TimeZone &timeZone)
{
    auto rawUtcValue = timeZone.GetTimeInUTCFormat();
    if (rawUtcValue.getHours() >= 0)
    {
        out << "+";
    }
    out << rawUtcValue.getHours() << ":" << rawUtcValue.getMinutes();
    return out;
}