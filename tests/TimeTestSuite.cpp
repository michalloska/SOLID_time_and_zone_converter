#include "gtest/gtest.h"
#include "../include/Time.hpp"
#include <utility>

namespace
{

    constexpr int Hour = 10;
    constexpr int Minutes = 30;
    constexpr Time positiveTime(4, 0);
    constexpr Time negativeTime(-4, 0);

    struct TimeTestSuite : public ::testing::Test
    {
        Time sut{};

        TimeTestSuite()
        {
            sut = std::make_pair(Hour, Minutes);
        }
    };

    TEST_F(TimeTestSuite, shouldCorrectlyAddPositiveValueTime)
    {
        const Time additionResult(14, 30);
        ASSERT_EQ(sut + positiveTime, additionResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddNegativeValueTime)
    {
        const Time additionResult(6, 30);
        ASSERT_EQ(sut + negativeTime, additionResult);
    }

    TEST_F(TimeTestSuite, shouldInCorrectlyAddTwoTimesTogether)
    {
        const Time additionResult(12, 30);
        ASSERT_NE(sut + positiveTime, additionResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddTwoTimesAndHandleMinutesOverflow)
    {
        const Time overflownMinutes(1, 30);
        const Time additionResult(12, 00);
        ASSERT_EQ(sut + overflownMinutes, additionResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddTwoTimeswithTimeOverflow)
    {
        const Time timeDifferenceTillMidnight(13, 30);
        const Time additionResult(0, 00);
        ASSERT_EQ(sut + timeDifferenceTillMidnight, additionResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddTwoTimesAfterMidnightWithHourAndMinuteOverflow)
    {
        const Time timeDifferenceTill1Am(14, 30);
        const Time additionResult(1, 00);
        ASSERT_EQ(sut + timeDifferenceTill1Am, additionResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddTwoTimesWithTimeUndeflow)
    {
        const Time timeDifference(-10, 30);
        const Time additionResult(0, 00);
        ASSERT_EQ(sut + timeDifference, additionResult);
    }

} // namespace