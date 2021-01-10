#include "../include/ConsoleParser.hpp"
#include "../include/TimeZone.hpp"
#include "../include/TimeZoneConverterUtils.hpp"
#include <cstring>
#include <iostream>
#include <stdlib.h>

namespace ConsoleParsers
{
    ConsoleArguments ConsoleParser::readArguments{};

    int ConsoleParser::readConsoleArguments(int argc, char **argv)
    {
        for (int i = 0; i < argc; ++i)
        {
            readArguments.push_back(argv[i]);
        }
        return 0;
    }

    TimeConversionConsoleArguments TimeConversionConsoleParser::ParseTimeConversionArguments(int argc, char **argv)
    {
        if (argc != 4)
            throw std::range_error("Program Accepts 3 input parameters, Time (hh:mm), TimeZone(name), TimeZone(name)");

        auto timeArgument = argv[1];
        std::string sourceTimeZoneArgument = argv[2];
        std::string destinationTimeZoneArgument = argv[3];
        
        auto hours = std::strtok(timeArgument, ":");
        if (hours == nullptr)
            throw std::invalid_argument("Time invalid! accepted format:(hh:mm)");
        
        auto minutes = std::strtok(nullptr, ":");
        if (minutes == nullptr)
            return std::make_tuple(
                Time{atoi(hours), 0},
                TimeZoneConverterUtils::AvailableTimeZones.at(sourceTimeZoneArgument),
                TimeZoneConverterUtils::AvailableTimeZones.at(destinationTimeZoneArgument));

        isTimeZoneImplemented(sourceTimeZoneArgument);
        isTimeZoneImplemented(destinationTimeZoneArgument);
        
        return std::make_tuple(
            Time{atoi(hours), atoi(minutes)},
            TimeZoneConverterUtils::AvailableTimeZones.at(sourceTimeZoneArgument),
            TimeZoneConverterUtils::AvailableTimeZones.at(destinationTimeZoneArgument));
    }

    bool TimeConversionConsoleParser::isTimeZoneImplemented(std::string timeZoneName)
    {
        try
        {
            TimeZoneConverterUtils::AvailableTimeZones.at(timeZoneName);
        }
        catch (const std::exception &e)
        {
            std::cout << timeZoneName << " Is not a supported TimeZone (please add it in TimeZoneConverterUtils.hpp)" << '\n';
        }
        return true;
    }

} // namespace ConsoleParsers