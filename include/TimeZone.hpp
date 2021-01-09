#pragma once
#include "../interfaces/HasUtcFormat.hpp"
#include "Time.hpp"
#include <ostream>

class TimeZone : public HasUtcFormat
{
public:
    virtual ~TimeZone() override = default;
    TimeZone() = delete;
    TimeZone(Time utcOffset, const char *name);
    Time GetTimeInUTCFormat() const override;
    const char *GetName() const;
    static Time CalculateTimeZoneDifferenceInUtc(const TimeZone &l_timeZone, const TimeZone &r_timeZone);

protected:
    const Time utcTimeOffset;
    const char *timeZoneName;
};

std::ostream &operator<<(std::ostream &out, const TimeZone &timeZone);