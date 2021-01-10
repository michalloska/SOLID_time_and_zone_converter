#include <iostream>
#include "include/TimeZoneConverter.hpp"
#include "include/TimeZone.hpp"
#include "include/AvailableTimeZones.hpp"
#include "include/Time.hpp"

TimeZonesMap AvailableTimeZones =
    {
        {"PDT", TimeZone(Time(-8, 0), "PDT")},
        {"GMT", TimeZone(Time(0, 0), "GMT")},
        {"IRST", TimeZone(Time(3, 30), "IRST")}};

int main()
{

    std::cout << AvailableTimeZones << std::endl;

    auto destTime = TimeZoneConverter::convert(Time(10, 30),
                                               AvailableTimeZones.at("PDT"),
                                               AvailableTimeZones.at("IRST"));

    std::cout << destTime << std::endl;
    auto destTimeInversed = TimeZoneConverter::convert(Time(22, 00),
                                                       AvailableTimeZones.at("IRST"),
                                                       AvailableTimeZones.at("PDT"));

    std::cout << destTimeInversed << std::endl;
}