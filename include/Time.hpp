#pragma once
#include <utility>
#include <ostream>

class Time
{
public:
    Time(int hours, int minutes);
    ~Time() = default;
    int getHours() const;
    int getMinutes() const;
    Time operator+(const Time &r_time) const;
    Time operator-(const Time &r_time) const;
    bool operator==(const Time &r_time) const;
    bool operator!=(const Time &r_time) const;
    bool isTimeValid(const Time &time) const;
    static Time calculateUtcTimeOffset(const Time &destinationTime, const Time &sourceTime);
private:
    Time negate();
    static bool doNumbersHaveOppositeSigns(int a, int b)
    {
        return ((a ^ b) < 0);
    }
    bool isHourAndMinutesValid(int hours, int minutes) const;
    
    int hours;
    int minutes;
};

std::ostream &operator<<(std::ostream &out, const Time &time);