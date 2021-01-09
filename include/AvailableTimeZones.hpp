#pragma once
#include <map>
#include <iostream>
#include "TimeZone.hpp"
#include "Time.hpp"

// TODO: move to TimeZones.hpp
using TimeZonesMap = std::map<const char *, TimeZone>;

// template <Time offsetValue>
// constexpr Time UtcOffset = offsetValue;

TimeZonesMap AvailableTimeZones =
    {
        {"PDT", TimeZone(Time(-8, 0), "PDT")},
        {"GMT", TimeZone(Time(0, 0), "GMT")},
        {"IRST", TimeZone(Time(3, 30), "IRST")}};

std::ostream &operator<<(std::ostream &out, const TimeZonesMap &TimeZoneMap)
{
    out << "Available Time Zones:" << std::endl;
    for (auto &timeZone : TimeZoneMap)
        out << timeZone.first << ": UTC" << timeZone.second << std::endl;
    return out;
}