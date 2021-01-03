#pragma once
#include <map>
#include <iostream>
#include "include/TimeZone.hpp"
#include "include/Time.hpp"

using TimeZonesMap = std::map<const char*, TimeZone>;

template <Time offsetValue>
constexpr Time UtcOffset = offsetValue;

TimeZonesMap AvailableTimeZones = 
{
    {"PDT", TimeZone(UtcOffset<Time(-8,0)>, "PDT")},
    {"GMT", TimeZone(UtcOffset<Time(0,0)>, "GMT")},
    {"TEST", TimeZone(UtcOffset<Time(4,5)>, "TEST")}
};

std::ostream& operator<<(std::ostream& out, const TimeZonesMap & TimeZoneMap)
{
    for (auto& timeZone: TimeZoneMap)
        out << timeZone.first << ": UTC" << timeZone.second << std::endl;
    return out;
}