#include <iostream>
#include <memory>
#include "include/TimeZoneConverter.hpp"
#include "include/PdtTimeZone.hpp"


int main(){
    // auto tzc = TimeZoneConverter();
    // availableTimeZones = std::map<char*, TimeZoneBase
    auto pdtTimeZone = PdtTimeZone(-8);
    auto gmtTimeZone = PdtTimeZone(0);
    std::cout << pdtTimeZone.GetTimeInUTCFormat() << std::endl;
    std::cout << gmtTimeZone.GetTimeInUTCFormat() << std::endl;
}