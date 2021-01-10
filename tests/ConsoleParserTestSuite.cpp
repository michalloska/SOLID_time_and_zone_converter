#include "gtest/gtest.h"
#include "../include/ConsoleParser.hpp"
#include "../include/TimeZoneConverterUtils.hpp"

namespace
{
    using namespace ConsoleParsers;

    struct TimeTestSuite : public ::testing::Test
    {
        char **consoleArguments;
        char **consoleArgumentsNoSeconds;
        char **consoleArgumentsNoSecondsNoMinutes;
        const int amountOfConsoleArguments {4};

        TimeTestSuite()
        {
            consoleArguments = (char *[]){"omit_me", "12:34:56", "GMT", "PDT"};
            consoleArgumentsNoSeconds = (char *[]){"omit_me", "12:34", "GMT", "PDT"};
            consoleArgumentsNoSecondsNoMinutes = (char *[]){"omit_me", "12", "GMT", "PDT"};
        }
    };

    // TODO: TimeZoneConverterUtils::AvailableTimeZones should be a member of ConsoleParser
    TEST_F(TimeTestSuite, shouldProperlyReadInput)
    {
        auto parsedConsoleParameters =
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArguments,
                                                                      consoleArguments);
        TimeConversionConsoleArguments expectedOutput = std::make_tuple(
            Time{12, 34, 56},
            TimeZoneConverterUtils::AvailableTimeZones.at("GMT"),
            TimeZoneConverterUtils::AvailableTimeZones.at("PDT"));

        ASSERT_EQ(parsedConsoleParameters, expectedOutput);
    }

    TEST_F(TimeTestSuite, shouldProperlyReadInputWithoutSeconds)
    {
        auto parsedConsoleParameters =
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArguments,
                                                                      consoleArgumentsNoSeconds);
        TimeConversionConsoleArguments expectedOutput = std::make_tuple(
            Time{12, 34, 0},
            TimeZoneConverterUtils::AvailableTimeZones.at("GMT"),
            TimeZoneConverterUtils::AvailableTimeZones.at("PDT"));

        ASSERT_EQ(parsedConsoleParameters, expectedOutput);
    }

    TEST_F(TimeConversionConsoleParser, shouldProperlyReadInputWithoutSecondsAndMinutes)
    {
        auto parsedConsoleParameters =
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArguments,
                                                                      consoleArgumentsNoSecondsNoMinutes);
        TimeConversionConsoleArguments expectedOutput = std::make_tuple(
            Time{12, 0, 0},
            TimeZoneConverterUtils::AvailableTimeZones.at("GMT"),
            TimeZoneConverterUtils::AvailableTimeZones.at("PDT"));

        ASSERT_EQ(parsedConsoleParameters, expectedOutput);
    }

} // namespace