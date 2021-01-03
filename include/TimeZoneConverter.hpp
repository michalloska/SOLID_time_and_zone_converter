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
        auto timeDifference = sourceTimeZone.GetTimeInUTCFormat()
                              - destinationTimeZone.GetTimeInUTCFormat();
        if (auto minutes = timeDifference % 1 != 0)
        {
            std::cout << "1";
            return Time(sourceTime.first - std::ceil(timeDifference), sourceTime.second - minutes);
        }

        std::cout << timeDifference << std::endl;
        return Time(sourceTime.first - timeDifference, sourceTime.second);
    }
};