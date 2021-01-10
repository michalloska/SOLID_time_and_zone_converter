#include "../include/Time.hpp"
#include <cmath>
#include <stdexcept>
#include <iomanip>

Time::Time(int hours, int minutes)
{
    if (not isHourAndMinutesValid(hours, minutes))
    {
        throw std::invalid_argument("Time Not Valid! Time Format (hours,minutes), minutes = [0,60)");
    }
    this->hours = hours;
    this->minutes = minutes;
}

int Time::getHours() const
{
    return hours;
}

int Time::getMinutes() const
{
    return minutes;
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
    out << "Time: " << time.getHours() << ":" << std::setfill(paddingChar) << std::setw(paddingLength) << time.getMinutes();
    return out;
}

bool Time::operator==(const Time &r_time) const
{
    return this->getHours() == r_time.getHours() and
           this->getMinutes() == r_time.getMinutes();
}

bool Time::operator!=(const Time &r_time) const
{
    return this->getHours() != r_time.getHours() or
           this->getMinutes() != r_time.getMinutes();
}

bool Time::operator>(int number) const
{
    int l_totalMinutes;
    if (this->hours >= 0)
        l_totalMinutes = this->hours * 60 + this->minutes;
    else if (this->hours < 0)
        l_totalMinutes = this->hours * 60 - this->minutes;

    return l_totalMinutes > number;
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
    int calculatedHours = this->hours + r_time.hours;
    int calculatedMinutes;

    if (r_time.getHours() >= 0)
        calculatedMinutes = this->minutes + r_time.minutes;
    else
        calculatedMinutes = this->minutes - r_time.minutes;
    auto calculatedMinutesAbsValue = std::abs(calculatedMinutes);

    if (calculatedMinutes >= 60)
    {
        calculatedHours += std::ceil(calculatedMinutes / 60);
        auto minutesOverflow = calculatedMinutes % 60;
        calculatedMinutes = minutesOverflow;
    }
    if (calculatedMinutes < 0 and calculatedMinutes > -60)
    {
        calculatedHours -= std::ceil(calculatedMinutesAbsValue / 60) + 1;
        auto minutesOverflow = calculatedMinutesAbsValue % 60;
        calculatedMinutes = minutesOverflow; 
    }
    if (calculatedHours >= 24)
    {
        calculatedHours = calculatedHours % 24;
    }
    return Time(std::abs(calculatedHours), calculatedMinutes);
}

Time Time::operator-(const Time &r_time) const
{
    int calculatedHours;
    if (std::abs(r_time.hours) > std::abs(this->hours))
        calculatedHours = this->hours - std::abs(r_time.hours);
    else
        calculatedHours = this->hours - r_time.hours;
    int calculatedMinutes = this->minutes - r_time.minutes;

    if (calculatedHours < 0)
    {
        calculatedHours = 24 + calculatedHours;
    }
    if (calculatedMinutes < 0)
    {
        calculatedHours -= std::ceil(calculatedMinutes / 60) + 1;
        auto minutesUnderflow = calculatedMinutes;
        calculatedMinutes = 60 - std::abs(minutesUnderflow);
    }
    return Time(std::abs(calculatedHours), calculatedMinutes);
}

Time Time::calculateUtcTimeOffset(const Time &destinationTime, const Time &sourceTime)
{
    int calculatedHours = destinationTime.hours - sourceTime.hours;
    int calculatedMinutes = destinationTime.minutes - sourceTime.minutes;
    calculatedMinutes = std::abs(calculatedMinutes);

    if (doNumbersHaveOppositeSigns(destinationTime.hours, sourceTime.hours))
    {
        return Time(calculatedHours, calculatedMinutes);
    }

    if (sourceTime.minutes > destinationTime.minutes)
    {
        if (calculatedMinutes != 0)
        {
            if (calculatedHours < 0)
                calculatedHours += std::ceil(calculatedMinutes / 60) + 1;
            else if (calculatedHours > 0)
                calculatedHours -= std::ceil(calculatedMinutes / 60) + 1;
            auto minutesOverflow = calculatedMinutes % 60;
            calculatedMinutes = std::abs(minutesOverflow);
            return Time(calculatedHours, calculatedMinutes);
        }
    }

    if (sourceTime.minutes < destinationTime.minutes)
    {
        if (calculatedHours < 0)
        {
            calculatedHours += std::ceil(calculatedMinutes / 60) + 1;
            auto minutesOverflow = calculatedMinutes % 60;
            calculatedMinutes = std::abs(minutesOverflow);
        }
        else if (calculatedHours > 0)
        {
            calculatedHours -= std::ceil(calculatedMinutes / 60) + 1;
            auto minutesOverflow = calculatedMinutes % 60;
            calculatedMinutes = std::abs(minutesOverflow);
        }
    }
    return Time(calculatedHours, calculatedMinutes);
}