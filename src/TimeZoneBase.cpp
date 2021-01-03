#include "include/TimeZoneBase.hpp"

TimeZoneBase::TimeZoneBase(int utcValue): utcTimeOffset(utcValue)
{

}

int TimeZoneBase::GetTimeInUTCFormat()
{
    return utcTimeOffset;
}
