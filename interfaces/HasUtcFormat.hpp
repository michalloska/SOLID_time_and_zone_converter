#pragma once

class HasUtcFormat
{
public:
    virtual ~HasUtcFormat() = default;
    virtual int GetTimeInUTCFormat() const = 0;
};