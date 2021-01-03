#pragma once
#include <map>
#include <iostream>
#include "include/TimeZone.hpp"

using TimeZonesMap = std::map<const char*, TimeZone>;

template <int offsetValue>
constexpr int UtcOffset = offsetValue;

TimeZonesMap AvailableTimeZones = 
{
    {"PDT", TimeZone(UtcOffset<-8>)},
    {"GMT", TimeZone(UtcOffset<0>)}
};

std::ostream& operator<<(std::ostream& out, const TimeZonesMap & TimeZoneMap)
{
    for (auto& timeZone: TimeZoneMap)
        out << timeZone.first << ": UTC" << timeZone.second << std::endl;
    return out;
}