#include <iostream>
#include "include/TimeZoneConverter.hpp"
#include "include/TimeZone.hpp"
#include "include/AvailableTimeZones.hpp"
#include "include/Time.hpp"

int main()
{

    std::cout << AvailableTimeZones << std::endl;

    auto destTime = TimeZoneConverter::convert(Time(10, 30),
                                               AvailableTimeZones.at("PDT"),
                                               AvailableTimeZones.at("IRST"));

    std::cout << destTime << std::endl;
}