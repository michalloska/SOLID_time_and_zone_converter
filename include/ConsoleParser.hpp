#pragma once
#include <vector>
#include <tuple>
#include <map>

class Time;
class TimeZone;

namespace ConsoleParsers
{
    using TimeConversionConsoleArguments = std::tuple<Time, TimeZone, TimeZone>;
    using TimeConversionRawConsoleArguments = std::map<std::string, std::string>;

    class TimeConversionConsoleParser
    {
    public:
        TimeConversionConsoleParser() = delete;
        static TimeConversionConsoleArguments ParseTimeConversionArguments(int argc, char **argv);

    private:
        static TimeConversionRawConsoleArguments validateTimeInCorrectFormat(std::string timeAsString);
        static bool validateCorrectAmountOfArgumentsWasPassed(unsigned int numbersOfArguments);
        static bool isStringANumber(const std::string &s);
        static bool validateTimeZoneIsImplemented(std::string timeZoneName);
        static constexpr unsigned int EXPECTED_AMOUNT_OF_ARGUMENTS = 4;
        static constexpr unsigned int VALIDATION_ERROR_CODE = 1;
    };

    std::vector<std::string> splitStringByDelimiter(const std::string &text, char delim);

} // namespace ConsoleParsers
