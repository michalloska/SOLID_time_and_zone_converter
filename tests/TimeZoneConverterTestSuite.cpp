#include "gtest/gtest.h"
#include "../include/TimeZoneConverter.hpp"
#include "../include/TimeZoneConverterUtils.hpp"
#include "TimeZoneTestsUtils.hpp"

namespace
{
    using namespace TimeZoneTestUtils;

    TEST(TimeZoneConverterNegativeAndPositiveUtcTimeOffsetTest, shouldCorrectlyConvertTimeFromUtcN8ToUtcP3_30)
    {
        const Time sourceTime{10, 30};
        const TimeZone sourceTimeZone = timeZones.at("tz_-8");
        const TimeZone destinationTimeZone = timeZones.at("tz_3:30");
        const Time expectedDestinationTime{22, 00};
        const Time calculatedDestinationTime =
            TimeZoneConverter::convert(sourceTime,
                                       sourceTimeZone,
                                       destinationTimeZone);
        ASSERT_EQ(calculatedDestinationTime, expectedDestinationTime);
    }

    TEST(TimeZoneConverterNegativeAndPositiveUtcTimeOffsetTest, shouldCorrectlyConvertTimeFromUtcP3_30ToUtcN8)
    {
        const Time sourceTime{22, 00};
        const TimeZone sourceTimeZone = timeZones.at("tz_3:30");
        const TimeZone destinationTimeZone = timeZones.at("tz_-8");
        const Time expectedDestinationTime{10, 30};
        const Time calculatedDestinationTime =
            TimeZoneConverter::convert(sourceTime,
                                       sourceTimeZone,
                                       destinationTimeZone);
        ASSERT_EQ(calculatedDestinationTime, expectedDestinationTime);
    }

    TEST(TimeZoneConverterNegativeUtcOffsetTimeTest, shouldCorrectlyConvertTimeFromUtcN3_30ToUtcN8)
    {
        const Time sourceTime{10, 00};
        const TimeZone sourceTimeZone = timeZones.at("tz_-3:30");
        const TimeZone destinationTimeZone = timeZones.at("tz_-8");
        const Time expectedDestinationTime{5, 30};
        const Time calculatedDestinationTime =
            TimeZoneConverter::convert(sourceTime,
                                       sourceTimeZone,
                                       destinationTimeZone);
        ASSERT_EQ(calculatedDestinationTime, expectedDestinationTime);
    }

    TEST(TimeZoneConverterNegativeUtcOffsetTimeTest, shouldCorrectlyConvertTimeFromUtcN8ToUtcN3_30)
    {
        const Time sourceTime{10, 00};
        const TimeZone sourceTimeZone = timeZones.at("tz_-8");
        const TimeZone destinationTimeZone = timeZones.at("tz_-3:30");
        const Time expectedDestinationTime{14, 30};
        const Time calculatedDestinationTime =
            TimeZoneConverter::convert(sourceTime,
                                       sourceTimeZone,
                                       destinationTimeZone);
        ASSERT_EQ(calculatedDestinationTime, expectedDestinationTime);
    }

    TEST(TimeZoneConverterNegativeUtcOffsetTimeTest, shouldCorrectlyConvertTimeFromUtcN8ToUtcN3_30_30)
    {
        const Time sourceTime{10, 00};
        const TimeZone sourceTimeZone = timeZones.at("tz_-8");
        const TimeZone destinationTimeZone = timeZones.at("tz_-3:30:30");
        const Time expectedDestinationTime{14, 29, 30};
        const Time calculatedDestinationTime =
            TimeZoneConverter::convert(sourceTime,
                                       sourceTimeZone,
                                       destinationTimeZone);
        ASSERT_EQ(calculatedDestinationTime, expectedDestinationTime);
    }

    TEST(TimeZoneConverterPositiveUtcOffsetTimeTest, shouldCorrectlyConvertTimeFromUtcP3_30ToUtcP8)
    {
        const Time sourceTime{10, 00};
        const TimeZone sourceTimeZone = timeZones.at("tz_3:30");
        const TimeZone destinationTimeZone = timeZones.at("tz_8");
        const Time expectedDestinationTime{14, 30};
        const Time calculatedDestinationTime =
            TimeZoneConverter::convert(sourceTime,
                                       sourceTimeZone,
                                       destinationTimeZone);
        ASSERT_EQ(calculatedDestinationTime, expectedDestinationTime);
    }

    TEST(TimeZoneConverterPositiveUtcOffsetTimeTest, shouldCorrectlyConvertTimeFromUtcP8ToUtcP3_30)
    {
        const Time sourceTime{10, 00};
        const TimeZone sourceTimeZone = timeZones.at("tz_8");
        const TimeZone destinationTimeZone = timeZones.at("tz_3:30");
        const Time expectedDestinationTime{5, 30};
        const Time calculatedDestinationTime =
            TimeZoneConverter::convert(sourceTime,
                                       sourceTimeZone,
                                       destinationTimeZone);
        ASSERT_EQ(calculatedDestinationTime, expectedDestinationTime);
    }

    TEST(TimeZoneConverterPositiveUtcOffsetTimeTest, shouldCorrectlyConvertTimeFromUtcP8ToUtcP3_30_30)
    {
        const Time sourceTime{10, 00};
        const TimeZone sourceTimeZone = timeZones.at("tz_8");
        const TimeZone destinationTimeZone = timeZones.at("tz_3:30:30");
        const Time expectedDestinationTime{5, 30, 30};
        const Time calculatedDestinationTime =
            TimeZoneConverter::convert(sourceTime,
                                       sourceTimeZone,
                                       destinationTimeZone);
        ASSERT_EQ(calculatedDestinationTime, expectedDestinationTime);
    }
} // namespace