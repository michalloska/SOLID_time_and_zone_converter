#pragma once
#include "../include/Time.hpp"

class HasUtcFormat
{
public:
    virtual ~HasUtcFormat() = default;
    virtual Time GetTimeInUTCFormat() const = 0;
};