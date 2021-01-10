#include "../include/Time.hpp"
#include <cmath>
#include <stdexcept>
#include <iomanip>
// DELETE:
#include <iostream>

Time::Time(int hours, int minutes, int seconds)
{
    if (not isHourAndMinutesValid(hours, minutes))
    {
        throw std::invalid_argument("Time Not Valid! Time Format (hours,minutes), minutes = [0,60)");
    }
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

int Time::getHours() const
{
    return hours;
}

int Time::getMinutes() const
{
    return minutes;
}

int Time::getSeconds() const
{
    return seconds;
}

bool Time::isTimeValid(const Time &time) const
{
    return isHourAndMinutesValid(time.getHours(), time.getMinutes());
}

bool Time::isHourAndMinutesValid(int hours, int minutes) const
{
    if (minutes < 0 or minutes >= 60)
        return false;
    return true;
}

Time Time::negate()
{
    this->hours = this->hours * -1;
    return *this;
}

bool Time::doNumbersHaveOppositeSigns(int a, int b)
{
    return ((a ^ b) < 0);
}

std::ostream &operator<<(std::ostream &out, const Time &time)
{
    auto paddingChar = '0';
    auto paddingLength = 2;
    out << time.getHours()
        << ":" << std::setfill(paddingChar) << std::setw(paddingLength) << time.getMinutes()
        << ":" << std::setfill(paddingChar) << std::setw(paddingLength) << time.getSeconds();
    return out;
}

bool Time::operator==(const Time &r_time) const
{
    return this->getHours() == r_time.getHours() and
           this->getMinutes() == r_time.getMinutes() and
           this->getSeconds() == r_time.getSeconds();
}

bool Time::operator!=(const Time &r_time) const
{
    return this->getHours() != r_time.getHours() or
           this->getMinutes() != r_time.getMinutes() or
           this->getSeconds() != r_time.getSeconds();
}

int Time::getTotalTimeInSeconds() const
{
    int totalSeconds;
    if (this->hours >= 0)
        totalSeconds = this->hours * 3600 + this->minutes * 60 + this->seconds;
    else if (this->hours < 0)
        totalSeconds = this->hours * 3600 - this->minutes * 60 - this->seconds;
    return totalSeconds;
}

Time Time::createTimeObjFromSeconds(int amoutOfSeconds)
{
    int hours = std::ceil(amoutOfSeconds / 3600);
    amoutOfSeconds -= 3600 * hours;
    int minutes = std::ceil(amoutOfSeconds / 60);
    amoutOfSeconds -= 60 * minutes;
    int seconds = amoutOfSeconds;
    return Time{hours, std::abs(minutes), std::abs(seconds)};
}

void Time::removeTimeOverflow()
{
    if (this->getHours() >= 24)
        this->hours = this->hours % 24;
    else if (this->getHours() <= -24)
        this->hours = this->hours % 24;
    if (this->getHours() < 0)
    {
        auto timeDifferenceInSeconds = 24 * 3600 + this->getTotalTimeInSeconds();
        *this = Time::createTimeObjFromSeconds(timeDifferenceInSeconds);
    }
}

bool Time::operator>(int amoutOfSeconds) const
{
    return this->getTotalTimeInSeconds() > amoutOfSeconds;
}

bool Time::operator>(const Time &r_time) const
{
    int l_totalMinutes;
    int r_totalMinutes;
    if (this->hours >= 0)
        l_totalMinutes = this->hours * 60 + this->minutes;
    else if (this->hours < 0)
        l_totalMinutes = this->hours * 60 - this->minutes;

    if (r_time.hours >= 0)
        r_totalMinutes = r_time.hours * 60 + r_time.minutes;
    else if (r_time.hours < 0)
        r_totalMinutes = r_time.hours * 60 - r_time.minutes;

    return l_totalMinutes > r_totalMinutes;
}

Time Time::operator+(const Time &r_time) const
{
    auto l_timeInSeconds = this->getTotalTimeInSeconds();
    auto r_timeInSeconds = r_time.getTotalTimeInSeconds();

    auto time = Time::createTimeObjFromSeconds(l_timeInSeconds + r_timeInSeconds);
    time.removeTimeOverflow();
    return time;
}

Time Time::operator-(const Time &r_time) const
{
    auto l_timeInSeconds = this->getTotalTimeInSeconds();
    auto r_timeInSeconds = r_time.getTotalTimeInSeconds();

    auto time = Time::createTimeObjFromSeconds(l_timeInSeconds - r_timeInSeconds);
    time.removeTimeOverflow();
    return time;
}

Time Time::calculateUtcTimeOffset(const Time &destinationTime, const Time &sourceTime)
{
    auto destinationTimeInSeconds = destinationTime.getTotalTimeInSeconds();
    auto sourceTimeInSeconds = sourceTime.getTotalTimeInSeconds();

    auto time = Time::createTimeObjFromSeconds(destinationTimeInSeconds - sourceTimeInSeconds);
    return time;
}