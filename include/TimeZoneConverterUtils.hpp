#pragma once
#include "TimeZone.hpp"

namespace TimeZoneConverterUtils
{
    const TimeZonesMap AvailableTimeZones =
        {
            {"PDT", TimeZone(Time(-8, 0), "PDT")},
            {"GMT", TimeZone(Time(0, 0), "GMT")},
            {"IRST", TimeZone(Time(3, 30), "IRST")}};
}