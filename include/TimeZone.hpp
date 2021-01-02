#pragma once
#include "interfaces/HasTimeZone.hpp"

class TimeZone : public HasTimeZone
{
public:
    TimeZone() = delete;
    TimeZone(int utcValue);
    int GetTimeInUTCFormat() override;
};

