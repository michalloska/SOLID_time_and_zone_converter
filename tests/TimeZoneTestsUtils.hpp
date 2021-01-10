#pragma once
#include "../include/TimeZone.hpp"

namespace TimeZoneTestUtils
{

    const TimeZonesMap timeZones{
        {"tz_-8", TimeZone(Time(-8, 0), "tz_-8")},
        {"tz_-4", TimeZone(Time(-4, 0), "tz_-4")},
        {"tz_-3:30", TimeZone(Time(-3, 30), "tz_-3:30")},
        {"tz_0", TimeZone(Time(0, 0), "tz_0")},
        {"tz_3:30", TimeZone(Time(3, 30), "tz_3:30")},
        {"tz_4", TimeZone(Time(4, 0), "tz_4")},
        {"tz_8", TimeZone(Time(8, 0), "tz_8")}};

}
