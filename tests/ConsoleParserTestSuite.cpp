#include "gtest/gtest.h"
#include "../include/ConsoleParser.hpp"
#include "../include/TimeZoneConverterUtils.hpp"

namespace
{
    using namespace ConsoleParsers;
    char **consoleArguments = (char *[]){"omit_me", "12:34:56", "GMT", "PDT"};
    char **consoleArgumentsNoSeconds = (char *[]){"omit_me", "12:34", "GMT", "PDT"};
    char **consoleArgumentsNoSecondsNoMinutes = (char *[]){"omit_me", "12", "GMT", "PDT"};
    char **consoleArgumentsIncorrectSourceTimeZone = (char *[]){"omit_me", "12:34:56", "LOL", "PDT"};
    const int amountOfConsoleArguments = 4;
    const int amountOfConsoleArgumentsTooSmall = 3;

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

    TEST(TimeConversionConsoleParser, shouldThrowExceptionWhenProgramArgumentsDifferentThan4)
    {
        try
        {
            TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArgumentsTooSmall,
                                                                      consoleArgumentsNoSecondsNoMinutes);
            FAIL();
        }
        catch (const std::range_error &e)
        {
            EXPECT_STREQ("Program Accepts 3 input parameters, Time (hh:mm), TimeZone(name), TimeZone(name)", e.what());
        }
        catch (...)
        {
            FAIL() << "Program Accepts 3 input parameters, Time (hh:mm), TimeZone(name), TimeZone(name)";
        }
    }

    TEST(TimeConversionConsoleParser, shouldThrowExceptionWhenGivenTimeZoneIsNotImplemented)
    {
        try
        {
            auto parsedConsoleParameters =
                TimeConversionConsoleParser::ParseTimeConversionArguments(amountOfConsoleArguments,
                                                                          consoleArgumentsIncorrectSourceTimeZone);
            FAIL();
        }
        catch (const std::exception &e)
        {
            EXPECT_STREQ("LOL Is not a supported TimeZone (please add it in TimeZoneConverterUtils.hpp)", e.what());
        }
        catch (...)
        {
            FAIL() << "LOL Is not a supported TimeZone (please add it in TimeZoneConverterUtils.hpp)";
        }
    }

} // namespace