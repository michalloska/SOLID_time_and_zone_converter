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
    Time negate();
private:
    bool isHourAndMinutesValid(int hours, int minutes) const;
    
    int hours;
    int minutes;
};

std::ostream &operator<<(std::ostream &out, const Time &time);