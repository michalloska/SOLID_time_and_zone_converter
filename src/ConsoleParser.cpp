#include "../include/ConsoleParser.hpp"
#include "../include/TimeZone.hpp"
#include "../include/TimeZoneConverterUtils.hpp"
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sstream>

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

        std::string timeArgument = argv[1];
        auto timeSections = splitStringByDelimiter(timeArgument, ':');
        auto hours = timeSections.at(0);
        std::string minutes;
        std::string seconds;
        if (timeSections.size() == 3)
        {
            minutes = timeSections.at(1);
            seconds = timeSections.at(2);
        }
        else if (timeSections.size() == 2)
        {
            minutes = timeSections.at(1);
            seconds = "0";
        }
        else if (timeSections.size() == 1)
        {
            minutes = "0";
            seconds = "0";
        }
        std::string sourceTimeZoneArgument = argv[2];
        std::string destinationTimeZoneArgument = argv[3];
        isTimeZoneImplemented(sourceTimeZoneArgument);
        isTimeZoneImplemented(destinationTimeZoneArgument);

        return std::make_tuple(
            Time{std::stoi(hours), std::stoi(minutes), std::stoi(seconds)},
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
            throw std::invalid_argument(timeZoneName + " Is not a supported TimeZone (please add it in TimeZoneConverterUtils.hpp)");
        }
        return true;
    }

    std::vector<std::string> splitStringByDelimiter(const std::string &text, char delimiter)
    {
        std::stringstream ss(text);
        std::string item;
        std::vector<std::string> elems;
        while (std::getline(ss, item, delimiter))
        {
            elems.push_back(item);
        }
        return elems;
    }

} // namespace ConsoleParsers