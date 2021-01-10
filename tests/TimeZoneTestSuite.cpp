#include "gtest/gtest.h"
#include "../include/TimeZone.hpp"
#include "TimeZoneTestsUtils.hpp"

namespace
{
    using namespace TimeZoneTestUtils;

    TEST(TimeZoneTestWithUnevenTimes, shouldCorrectlyCalculateUtcOffsetBetweenTwoUtcPositiveZones)
    {
        Time expectedUtcOffset{4, 30};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_3:30"),
            timeZones.at("tz_8"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithUnevenTimes, shouldCorrectlyCalculateUtcOffsetBetweenTwoUtcPositiveZonesWithSeconds)
    {
        Time expectedUtcOffset{4, 29, 30};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_3:30:30"),
            timeZones.at("tz_8"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithUnevenTimes, shouldCorrectlyCalculateUtcOffsetBetweenTwoUtcPositiveZonesInversed)
    {
        Time expectedUtcOffset{-4, 30};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_8"),
            timeZones.at("tz_3:30"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithUnevenTimes, shouldCorrectlyCalculateUtcOffsetBetweenNegativeandPositiveUtcZones)
    {
        Time expectedUtcOffset{11, 30};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_-8"),
            timeZones.at("tz_3:30"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithUnevenTimes, shouldCorrectlyCalculateUtcOffsetBetweenNegativeandPositiveUtcZonesWithSeconds)
    {
        Time expectedUtcOffset{11, 30, 30};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_-8"),
            timeZones.at("tz_3:30:30"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithUnevenTimes, shouldCorrectlyCalculateUtcOffsetBetweenNegativeandPositiveUtcZonesInversed)
    {
        Time expectedUtcOffset{-11, 30};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_3:30"),
            timeZones.at("tz_-8"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithUnevenTimes, shouldCorrectlyCalculateUtcOffsetBetweenTwoUtcNegativeZones)
    {
        Time expectedUtcOffset{4, 30};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_-8"),
            timeZones.at("tz_-3:30"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithUnevenTimes, shouldCorrectlyCalculateUtcOffsetBetweenTwoUtcNegativeZonesWithSeconds)
    {
        Time expectedUtcOffset{4, 29, 30};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_-8"),
            timeZones.at("tz_-3:30:30"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithUnevenTimes, shouldCorrectlyCalculateUtcOffsetBetweenTwoUtcNegativeZonesInversed)
    {
        Time expectedUtcOffset{-4, 30};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_-3:30"),
            timeZones.at("tz_-8"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithEvenTimes, shouldCorrectlyCalculateUtcOffsetBetweenTwoUtcPositiveZones)
    {
        Time expectedUtcOffset{4, 0};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_4"),
            timeZones.at("tz_8"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithEvenTimes, shouldCorrectlyCalculateUtcOffsetBetweenTwoUtcPositiveZonesInversed)
    {
        Time expectedUtcOffset{-4, 0};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_8"),
            timeZones.at("tz_4"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithEvenTimes, shouldCorrectlyCalculateUtcOffsetBetweenNegativeandPositiveUtcZones)
    {
        Time expectedUtcOffset{12, 0};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_-8"),
            timeZones.at("tz_4"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithEvenTimes, shouldCorrectlyCalculateUtcOffsetBetweenNegativeandPositiveUtcZonesInversed)
    {
        Time expectedUtcOffset{-12, 0};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_4"),
            timeZones.at("tz_-8"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithEvenTimes, shouldCorrectlyCalculateUtcOffsetBetweenTwoUtcNegativeZones)
    {
        Time expectedUtcOffset{4, 0};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_-8"),
            timeZones.at("tz_-4"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }

    TEST(TimeZoneTestWithEvenTimes, shouldCorrectlyCalculateUtcOffsetBetweenTwoUtcNegativeZonesInversed)
    {
        Time expectedUtcOffset{-4, 0};
        auto calculatedUtcOffset = TimeZone::CalculateTimeZoneDifferenceInUtc(
            timeZones.at("tz_-4"),
            timeZones.at("tz_-8"));
        ASSERT_EQ(calculatedUtcOffset, expectedUtcOffset);
    }
} // namespace