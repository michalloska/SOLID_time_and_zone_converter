#include <iostream>
#include "include/TimeZoneConverter.hpp"
#include "include/TimeZone.hpp"
#include "include/Time.hpp"
#include "include/ConsoleParser.hpp"

TimeZonesMap AvailableTimeZones =
    {
        {"PDT", TimeZone(Time(-8, 0), "PDT")},
        {"GMT", TimeZone(Time(0, 0), "GMT")},
        {"IRST", TimeZone(Time(3, 30), "IRST")}};

int main(int argc, char **argv)
{

    auto consoleParameters =
        ConsoleParsers::TimeConversionConsoleParser::ParseTimeConversionArguments(argc, argv);
    std::cout << "Converting " << std::get<0>(consoleParameters) << " " << std::get<1>(consoleParameters) << " to " << std::get<2>(consoleParameters) << std::endl;
    auto destTime = TimeZoneConverter::convert(std::get<0>(consoleParameters),
                                               std::get<1>(consoleParameters),
                                               std::get<2>(consoleParameters));

    std::cout << "Outcome Time:" << destTime << std::endl;
}