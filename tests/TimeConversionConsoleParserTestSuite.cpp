#include "gtest/gtest.h"
#include "../include/TimeConversionConsoleParser.hpp"
#include "../include/TimeZoneConverterUtils.hpp"

namespace
{
    using namespace ConsoleParsers;
    char **consoleArguments = (char *[]){"omit_me", "12:34:56", "GMT", "PDT"};
    char **consoleArgumentsTimeZero = (char *[]){"omit_me", "0", "GMT", "PDT"};
    char **consoleArgumentsNoSeconds = (char *[]){"omit_me", "12:34", "GMT", "PDT"};
    char **consoleArgumentsNoSecondsNoMinutes = (char *[]){"omit_me", "12", "GMT", "PDT"};
    char **consoleArgumentsIncorrectSourceTimeZone = (char *[]){"omit_me", "12:34:56", "LOL", "PDT"};
    char **consoleArgumentsTimeNotANumber = (char *[]){"omit_me", "a:34:56", "GMT", "PDT"};
    char **consoleArgumentsTimeNotANumberInSeconds = (char *[]){"omit_me", "12:34:b", "GMT", "PDT"};
    char **consoleArgumentsHoursTooBig = (char *[]){"omit_me", "25:34:56", "LOL", "PDT"};
    const int amountOfConsoleArguments = 4;
    const int amountOfConsoleArgumentsTooSmall = 3;
    const int amountOfConsoleArgumentsTooBig = 5;

    TEST(TimeConversionConsoleParser, shouldProperlyReadInput)
    {
        TimeConversionConsoleArguments parsedConsoleParameters =
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArguments,
                                                                      consoleArguments);
        TimeConversionConsoleArguments expectedOutput = std::make_tuple(
            Time{12, 34, 56},
            TimeZoneConverterUtils::AvailableTimeZones.at("GMT"),
            TimeZoneConverterUtils::AvailableTimeZones.at("PDT"));

        ASSERT_EQ(std::get<0>(parsedConsoleParameters), std::get<0>(expectedOutput));
    }

    TEST(TimeConversionConsoleParser, shouldProperlyReadInputWithoutSeconds)
    {
        auto parsedConsoleParameters =
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArguments,
                                                                      consoleArgumentsNoSeconds);
        TimeConversionConsoleArguments expectedOutput = std::make_tuple(
            Time{12, 34, 0},
            TimeZoneConverterUtils::AvailableTimeZones.at("GMT"),
            TimeZoneConverterUtils::AvailableTimeZones.at("PDT"));

        ASSERT_EQ(std::get<0>(parsedConsoleParameters), std::get<0>(expectedOutput));
    }

    TEST(TimeConversionConsoleParser, shouldProperlyReadInputWithoutSecondsAndMinutes)
    {
        auto parsedConsoleParameters =
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArguments,
                                                                      consoleArgumentsNoSecondsNoMinutes);
        TimeConversionConsoleArguments expectedOutput = std::make_tuple(
            Time{12, 0, 0},
            TimeZoneConverterUtils::AvailableTimeZones.at("GMT"),
            TimeZoneConverterUtils::AvailableTimeZones.at("PDT"));

        ASSERT_EQ(std::get<0>(parsedConsoleParameters), std::get<0>(expectedOutput));
    }

    TEST(TimeConversionConsoleParser, shouldProperlyReadInputWithTimeSpecifiedAsZero)
    {
        auto parsedConsoleParameters =
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArguments,
                                                                      consoleArgumentsTimeZero);
        TimeConversionConsoleArguments expectedOutput = std::make_tuple(
            Time{0, 0, 0},
            TimeZoneConverterUtils::AvailableTimeZones.at("GMT"),
            TimeZoneConverterUtils::AvailableTimeZones.at("PDT"));

        ASSERT_EQ(std::get<0>(parsedConsoleParameters), std::get<0>(expectedOutput));
    }

    TEST(TimeConversionConsoleParser, shouldExitWhenTimeIsNotANumber)
    {
        std::string expectedErrorMessage = "\"a\" Is not a number !";
        ASSERT_EXIT(
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArguments,
                                                                      consoleArgumentsTimeNotANumber),
            ::testing::ExitedWithCode(1), expectedErrorMessage);
    }
    TEST(TimeConversionConsoleParser, shouldExitWhenSecondsInTimeIsNotANumber)
    {
        std::string expectedErrorMessage = "\"b\" Is not a number !";
        ASSERT_EXIT(
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArguments,
                                                                      consoleArgumentsTimeNotANumberInSeconds),
            ::testing::ExitedWithCode(1), expectedErrorMessage);
    }

    TEST(TimeConversionConsoleParser, shouldExitProgramWhenTooLittleArgumentsArePassedIn)
    {
        std::string expectedErrorMessage = "Wrong amount of console arguments were passed in!";
        ASSERT_EXIT(
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArgumentsTooSmall,
                                                                      consoleArgumentsNoSeconds),
            ::testing::ExitedWithCode(1), expectedErrorMessage);
    }

    TEST(TimeConversionConsoleParser, shouldExitProgramWhenTooManyArgumentsArePassedIn)
    {
        std::string expectedErrorMessage = "Wrong amount of console arguments were passed in!";
        ASSERT_EXIT(
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArgumentsTooBig,
                                                                      consoleArgumentsNoSeconds),
            ::testing::ExitedWithCode(1), expectedErrorMessage);
    }

    TEST(TimeConversionConsoleParser, shouldExitProgramWhenGivenTimeZoneIsNotImplemented)
    {
        std::string expectedErrorMessage = "LOL Is not a supported TimeZone";
        ASSERT_EXIT(
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArguments,
                                                                      consoleArgumentsIncorrectSourceTimeZone),
            ::testing::ExitedWithCode(1), expectedErrorMessage);
    }
    
} // namespace