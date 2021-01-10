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

const char *TimeZone::getName() const
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
    out << timeZone.getName() << "(UTC";
    if (rawUtcValue.getHours() >= 0)
        out << "+";
    out << timeZone.GetTimeInUTCFormat() << ")";
    return out;
}

std::ostream &operator<<(std::ostream &out, const TimeZonesMap &TimeZoneMap)
{
    out << "Available Time Zones:" << std::endl;
    for (auto &timeZone : TimeZoneMap)
        out << timeZone.first << ": UTC" << timeZone.second << std::endl;
    return out;
}

bool operator==(const TimeZone & l_timeZone, const TimeZone & r_timeZone)
{
    return l_timeZone.GetTimeInUTCFormat() == r_timeZone.GetTimeInUTCFormat() and
           l_timeZone.getName() == r_timeZone.getName();
}
