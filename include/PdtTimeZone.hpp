#pragma once
#include "TimeZoneBase.hpp"

class PdtTimeZone : public TimeZoneBase
{
public:
    ~PdtTimeZone() override = default;
    PdtTimeZone() = delete;
    PdtTimeZone(int utcValue);
};

