#pragma once
#include <vector>
#include <tuple>

class Time;
class TimeZone;

namespace ConsoleParsers
{
    using ConsoleArguments = std::vector<const char *>;
    using TimeConversionConsoleArguments = std::tuple<Time, TimeZone, TimeZone>;

    class ConsoleParser
    {
    public:
        ConsoleParser() = delete;
        virtual ~ConsoleParser() = default;
        static int readConsoleArguments(int argc, char **argv);

    protected:
        static ConsoleArguments readArguments;
    };

    class TimeConversionConsoleParser : public ConsoleParser
    {
    public:
        TimeConversionConsoleParser() = delete;
        static TimeConversionConsoleArguments ParseTimeConversionArguments(int argc, char **argv);
    private:
        static bool isTimeZoneImplemented(std::string timeZoneName);
    };

} // namespace ConsoleParsers
