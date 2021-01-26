#pragma once
#include "TimeZone.hpp"
#include <iostream>

namespace TimeZoneConverterUtils
{
    const TimeZonesMap AvailableTimeZones =
        {
            {"PDT", TimeZone(Time(-8, 0), "Pacific Daylight Time")},
            {"GMT", TimeZone(Time(0, 0), "Greenwich Mean Time")},
            {"IRST", TimeZone(Time(3, 30), "Iran Standard Time")}};

    inline void displayAvailableTimeZones()
    {
        std::cerr << std::endl
                  << "Available Timezones:" << std::endl;
        for (auto &timeZone : AvailableTimeZones)
        {
            std::cerr << timeZone.first << " - " << timeZone.second << std::endl;
        }
    }

} // namespace TimeZoneConverterUtils