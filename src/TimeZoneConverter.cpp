#include "../include/TimeZoneConverter.hpp"
#include "../include/Time.hpp"
#include "../include/TimeZone.hpp"
#include <iostream>

Time TimeZoneConverter::convert(const Time &sourceTime,
                                const TimeZone &sourceTimeZone,
                                const TimeZone &destinationTimeZone)
{
    auto timeDifference =
        TimeZone::CalculateTimeZoneDifferenceInUtc(
            sourceTimeZone, destinationTimeZone);
    return Time(sourceTime +  timeDifference);
}