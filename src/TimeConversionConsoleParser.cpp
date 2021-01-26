#include "../include/TimeConversionConsoleParser.hpp"
#include "../include/TimeZone.hpp"
#include "../include/TimeZoneConverterUtils.hpp"
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sstream>

namespace ConsoleParsers
{
    TimeConversionConsoleArguments TimeConversionConsoleParser::ParseTimeConversionArguments(int argc, char **argv)
    {
        validateCorrectAmountOfArgumentsWasPassed(argc);

        std::string sourceTimeZoneArgument = argv[2];
        std::string destinationTimeZoneArgument = argv[3];
        validateTimeZoneIsImplemented(sourceTimeZoneArgument);
        validateTimeZoneIsImplemented(destinationTimeZoneArgument);

        std::string timeArgument = argv[1];
        auto timeSections = validateTimeInCorrectFormat(timeArgument);

        return std::make_tuple(
            Time{std::stoi(timeSections["hours"]), std::stoi(timeSections["minutes"]), std::stoi(timeSections["seconds"])},
            TimeZoneConverterUtils::AvailableTimeZones.at(sourceTimeZoneArgument),
            TimeZoneConverterUtils::AvailableTimeZones.at(destinationTimeZoneArgument));
    }

    bool TimeConversionConsoleParser::isStringANumber(const std::string &text)
    {
        return !text.empty() && std::find_if(text.begin(),
                                             text.end(), [](unsigned char c) { return !std::isdigit(c); }) == text.end();
    }

    TimeConversionRawConsoleArguments TimeConversionConsoleParser::validateTimeInCorrectFormat(std::string timeAsString)
    {
        auto timeSections = splitStringByDelimiter(timeAsString, ':');
        unsigned int timeSectionIter = 0;
        const unsigned int hoursTimeSection = 0;
        const unsigned int minutesTimeSection = 1;
        const unsigned int secondsTimeSection = 2;
        TimeConversionRawConsoleArguments fullTimeElements{
            {"hours", "0"},
            {"minutes", "0"},
            {"seconds", "0"}};

        for (auto &timeSection : timeSections)
        {
            if (not isStringANumber(timeSection))
            {
                std::cerr << "Provided Time is Invalid! Supported Format: (hh:mm:ss)" << std::endl
                          << "\"" << timeSection << "\" Is not a number !" << std::endl;
                exit(1);
            }
            if (timeSectionIter == hoursTimeSection)
            {
                fullTimeElements["hours"] = timeSection;
                auto hoursDecimal = std::stoi(fullTimeElements["hours"]);
                if (hoursDecimal < 0 or hoursDecimal > 24)
                {
                    std::cerr << std::endl
                              << "Provided Time is Invalid! Supported Format: (hh:mm:ss)" << std::endl
                              << timeSection << " Is not within the range [0;24]" << std::endl;
                    exit(1);
                }
            }
            else if (timeSectionIter == minutesTimeSection)
            {
                fullTimeElements["minutes"] = timeSection;
                auto minutesDecimal = std::stoi(fullTimeElements["minutes"]);
                if (minutesDecimal < 0 or minutesDecimal > 60)
                {
                    std::cerr << std::endl
                              << "Provided Time is Invalid! Supported Format: (hh:mm:ss)" << std::endl
                              << timeSection << " Is not within the range [0;60]" << std::endl;
                    exit(1);
                }
            }
            else if (timeSectionIter == secondsTimeSection)
            {
                fullTimeElements["seconds"] = timeSection;
                auto minutesDecimal = std::stoi(fullTimeElements["seconds"]);
                if (minutesDecimal < 0 or minutesDecimal > 60)
                {
                    std::cerr << std::endl
                              << "Provided Time is Invalid! Supported Format: (hh:mm:ss)" << std::endl
                              << timeSection << " Is not within the range [0;60]" << std::endl;
                    exit(1);
                }
            }
            ++timeSectionIter;
        }
        return fullTimeElements;
    }

    bool TimeConversionConsoleParser::validateTimeZoneIsImplemented(std::string timeZoneName)
    {
        try
        {
            TimeZoneConverterUtils::AvailableTimeZones.at(timeZoneName);
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << std::endl
                      << timeZoneName << " Is not a supported TimeZone (please add it in TimeZoneConverterUtils.hpp)" << std::endl;
            TimeZoneConverterUtils::displayAvailableTimeZones();
            exit(1);
        }
        return true;
    }

    bool TimeConversionConsoleParser::validateCorrectAmountOfArgumentsWasPassed(unsigned int numbersOfArguments)
    {
        if (numbersOfArguments == EXPECTED_AMOUNT_OF_ARGUMENTS)
            return true;

        std::cerr << std::endl
                  << "Wrong amount of console arguments were passed in!" << std::endl
                  << "EXPECTED 3: Time, Source Time Zone, Destination Time Zone" << std::endl
                  << "Eg: make run TIME=11:55:45 SRCT=GMT DESTT=PDT" << std::endl;
        TimeZoneConverterUtils::displayAvailableTimeZones();
        exit(1);
    }

    std::vector<std::string> splitStringByDelimiter(const std::string &text, char delimiter)
    {
        std::stringstream ss(text);
        std::string item;
        std::vector<std::string> timeElements;
        while (std::getline(ss, item, delimiter))
        {
            timeElements.push_back(item);
        }
        return timeElements;
    }

} // namespace ConsoleParsers