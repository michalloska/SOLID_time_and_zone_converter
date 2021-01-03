#pragma once
#include "include/AvailableTimeZones.hpp"
#include "include/Time.hpp"
#include "include/TimeZone.hpp"
#include <cmath>
#include <iostream>

class TimeZoneConverter
{
public:
    static Time convert(const Time& sourceTime, 
                        const TimeZone& sourceTimeZone,
                        const TimeZone& destinationTimeZone)
    {
        std::cout << "Converting " << sourceTime << sourceTimeZone.timeZoneName << " to " << destinationTimeZone.timeZoneName << std::endl;
        auto timeDifference = 
            TimeZone::CalculateTimeZoneDifferenceInUtc(
                sourceTimeZone.GetTimeInUTCFormat(),
                destinationTimeZone.GetTimeInUTCFormat());

        // TODO: implement operator+
        // return sourceTime + timeDifference
        return Time(sourceTime.first - timeDifference.first,
                    sourceTime.second - timeDifference.second);
    }
};