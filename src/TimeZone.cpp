#include "include/TimeZone.hpp"

TimeZone::TimeZone(int utcValue): utcTimeOffset(utcValue)
{

}

int TimeZone::GetTimeInUTCFormat() override
{
    return utcTimeOffset;
}