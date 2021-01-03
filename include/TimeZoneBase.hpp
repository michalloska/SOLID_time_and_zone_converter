#pragma once
#include <interfaces/HasUtcFormat.hpp>

class TimeZoneBase : public HasUtcFormat
{
protected:
    const int utcTimeOffset;
public:
    virtual ~TimeZoneBase() override = default;
    TimeZoneBase() = delete;
    TimeZoneBase(int);
    int GetTimeInUTCFormat() override;
};
