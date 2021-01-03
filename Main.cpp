#include <iostream>
#include "include/TimeZoneConverter.hpp"
#include "include/TimeZone.hpp"
#include "include/AvailableTimeZones.hpp"
#include "include/Time.hpp"


int main()
{

    std::cout << AvailableTimeZones << std::endl;
    
    auto destTime = TimeZoneConverter::convert(Time(10,30), 
                                               AvailableTimeZones.at("PDT"), 
                                               AvailableTimeZones.at("GMT"));

    std::cout << destTime << std::endl;

    // std::cout << AvailableTimeZones.at("PDT") << std::endl;
    // std::cout << AvailableTimeZones.at("GMT") << std::endl;

    // std::cout << AvailableTimeZones.at("PDT").GetTimeInUTCFormat() << std::endl;
    // std::cout << AvailableTimeZones.at("GMT").GetTimeInUTCFormat() << std::endl;
}