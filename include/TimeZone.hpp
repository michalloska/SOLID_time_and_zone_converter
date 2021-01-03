#pragma once
#include <interfaces/HasUtcFormat.hpp>
#include "include/Time.hpp"
#include <ostream>

class TimeZone : public HasUtcFormat
{
protected:
    const Time utcTimeOffset;
public:
    // TODO: do protected: 
    const char* timeZoneName;

    virtual ~TimeZone() override = default;
    TimeZone() = delete;
    TimeZone(Time utcOffset, char * name);
    Time GetTimeInUTCFormat() const override;
    static Time CalculateTimeZoneDifferenceInUtc(const Time & left, const Time & right);
};

std::ostream& operator<<(std::ostream & out, const TimeZone & timeZone);