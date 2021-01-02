#pragma once

class HasTimeZone
{
    int utcTimeOffset; 
public:
    virtual int GetTimeInUTCFormat() = 0;
    
};