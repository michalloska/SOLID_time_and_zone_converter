#pragma once
#include <interfaces/HasUtcFormat.hpp>
#include <ostream>

class TimeZone : public HasUtcFormat
{
protected:
    const int utcTimeOffset;
public:
    virtual ~TimeZone() override = default;
    TimeZone() = delete;
    TimeZone(int utcOffset);
    int GetTimeInUTCFormat() const override;
};

std::ostream& operator<<(std::ostream & out, const TimeZone & timeZone);