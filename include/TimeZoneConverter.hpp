#pragma once

class Time;
class TimeZone;
class TimeZoneConverter
{
public:
    TimeZoneConverter() = delete;
    static Time convert(const Time &sourceTime,
                        const TimeZone &sourceTimeZone,
                        const TimeZone &destinationTimeZone);
};