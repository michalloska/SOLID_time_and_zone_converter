#pragma once
#include "AvailableTimeZones.hpp"
#include "Time.hpp"
#include "TimeZone.hpp"
#include <cmath>
#include <iostream>

class TimeZoneConverter
{
public:
    static Time convert(const Time &sourceTime,
                        const TimeZone &sourceTimeZone,
                        const TimeZone &destinationTimeZone)
    {
        std::cout << "Converting " << sourceTime << sourceTimeZone.GetName() << " to " << destinationTimeZone.GetName() << std::endl;
        auto timeDifference =
            TimeZone::CalculateTimeZoneDifferenceInUtc(
                sourceTimeZone, destinationTimeZone);
                
        std::cout << "timeDifference = " << timeDifference << std::endl;
        // TODO: implement operator+
        // return sourceTime + timeDifference
        return Time(sourceTime + timeDifference);
    }
};