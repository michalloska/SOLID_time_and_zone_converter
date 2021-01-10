#pragma once
#include <ostream>
#include <stdexcept>

class Time
{
public:
    Time(int hours, int minutes, int seconds = 0);
    ~Time() = default;
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    Time operator+(const Time &r_time) const;
    Time operator-(const Time &r_time) const;
    bool operator==(const Time &r_time) const;
    bool operator!=(const Time &r_time) const;
    bool operator>(const Time &r_time) const;
    bool operator>(int) const;
    bool isTimeValid(const Time &time) const;
    static Time calculateUtcTimeOffset(const Time &destinationTime, const Time &sourceTime);
    int getTotalTimeInSeconds() const;
    static Time createTimeObjFromSeconds(int amoutOfSeconds);

private:
    Time negate();
    static bool doNumbersHaveOppositeSigns(int a, int b);
    bool isHourAndMinutesValid(int hours, int minutes) const;

    int hours;
    int minutes;
    int seconds;
};

std::ostream &operator<<(std::ostream &out, const Time &time);