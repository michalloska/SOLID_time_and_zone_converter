#pragma once

class HasUtcFormat
{
public:
    virtual ~HasUtcFormat() = default;
    virtual int GetTimeInUTCFormat() = 0;
};