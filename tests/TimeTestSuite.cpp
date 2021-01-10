#include "gtest/gtest.h"
#include "../include/Time.hpp"
#include <utility>

namespace
{
    constexpr int Hour{10};
    constexpr int Minutes{30};
    const Time positiveTime{4, 0};
    const Time negativeTime{-4, 0};

    struct TimeTestSuite : public ::testing::Test
    {
        Time sut{Hour, Minutes};
    };

    TEST_F(TimeTestSuite, shouldCorrectlyConvertTimeToTotalInSeconds)
    {
        const Time time1{3, 10, 30};
        int expectedTotalTimeInSeconds = 11430;
        ASSERT_EQ(time1.getTotalTimeInSeconds(), expectedTotalTimeInSeconds);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyConvertNegativeTimeToTotalInSeconds)
    {
        const Time time1{-3, 10, 30};
        int expectedTotalTimeInSeconds = -11430;
        ASSERT_EQ(time1.getTotalTimeInSeconds(), expectedTotalTimeInSeconds);
    }
    
    TEST_F(TimeTestSuite, shouldCorrectlyCreateTimeObjectFromTotalTimeInSeconds)
    {
        int TotalTimeInSeconds = 11430;
        const Time expectedTime{3, 10, 30};
        ASSERT_EQ(Time::createTimeObjFromSeconds(TotalTimeInSeconds), expectedTime);
    }
    
    TEST_F(TimeTestSuite, shouldCorrectlyAddPositiveTimesWithSeconds)
    {
        const Time time1{3, 2, 30};
        const Time time2{-0, 1, 15};
        const Time timeResult{3, 3, 45};
        ASSERT_EQ(time1 + time2, timeResult);
    } 

    TEST_F(TimeTestSuite, shouldCorrectlyAddPositiveTimesWithSecondsInversed)
    {
        const Time time1{1, 1, 15};
        const Time time2{-3, 2, 30};
        const Time timeResult{21, 58, 45};
        ASSERT_EQ(time1 + time2, timeResult);
    } 
    
    TEST_F(TimeTestSuite, shouldCorrectlySubtractPositiveTimesWithSeconds)
    {
        const Time time1{3, 2, 30};
        const Time time2{0, 1, 15};
        const Time timeResult{3, 1, 15};
        ASSERT_EQ(time1 - time2, timeResult);
    }
    TEST_F(TimeTestSuite, shouldCorrectlySubtractPositiveTimesWithSecondsInversed)
    {
        const Time time1{3, 1, 15};
        const Time time2{0, 2, 30};
        const Time timeResult{2, 58, 45};
        ASSERT_EQ(time1 - time2, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddPositiveValueTime)
    {
        const Time timeResult{14, 30};
        ASSERT_EQ(sut + positiveTime, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddPositiveValueTimeWithMinutes)
    {
        const Time positiveTimeWithMinutes{4, 30};
        const Time timeResult{15, 0};
        ASSERT_EQ(sut + positiveTimeWithMinutes, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddNegativeValueTimeWithUnderflow)
    {
        const Time time1{1, 0};
        const Time time2{-2, 30};
        const Time timeResult{22, 30};
        ASSERT_EQ(time1 + time2, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddPositiveValueTimeWithMinutesBiggerInRightTime)
    {
        const Time positiveTimeWithMinutes{4, 50};
        const Time timeResult{15, 20};
        ASSERT_EQ(sut + positiveTimeWithMinutes, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddNegativeValueTime)
    {
        const Time timeResult{6, 30};
        ASSERT_EQ(sut + negativeTime, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlySubtractPositiveValueTimeWithMinutes)
    {
        const Time positiveTimeWithMinutes{4, 30};
        const Time timeResult{6, 00};
        ASSERT_EQ(sut - positiveTimeWithMinutes, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddNegativeNumber)
    {
        const Time time1{22, 00};
        const Time time2{-11, 30};
        const Time timeResult{10, 30};
        ASSERT_EQ(time1 + time2, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlySubtractBiggerTimeValueFromSmallerValueAndSwitchToPrevDay)
    {
        const Time positiveTimeWithMinutes{12, 50};
        const Time timeResult{21, 40};
        ASSERT_EQ(sut - positiveTimeWithMinutes, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlySubtractPositiveValueTimeWithMinutesBiggerInRightTime)
    {
        const Time positiveTimeWithMinutes{4, 50};
        const Time timeResult{5, 40};
        ASSERT_EQ(sut - positiveTimeWithMinutes, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlySubtractNegativeValueTime)
    {
        const Time timeResult{14, 30};
        ASSERT_EQ(sut - negativeTime, timeResult);
    }

    TEST_F(TimeTestSuite, shouldInCorrectlyAddTwoTimesTogether)
    {
        const Time timeResult{12, 30};
        ASSERT_NE(sut + positiveTime, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddTwoTimesAndHandleMinutesOverflow)
    {
        const Time overflownMinutes{1, 30};
        const Time timeResult{12, 00};
        ASSERT_EQ(sut + overflownMinutes, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddTwoTimeswithTimeOverflow)
    {
        const Time timeDifferenceTillMidnight{13, 30};
        const Time timeResult{0, 00};
        ASSERT_EQ(sut + timeDifferenceTillMidnight, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddTwoTimesAfterMidnightWithHourAndMinuteOverflow)
    {
        const Time timeDifferenceTill1Am{14, 30};
        const Time timeResult{1, 00};
        ASSERT_EQ(sut + timeDifferenceTill1Am, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlySubtractTimeToMidnight)
    {
        const Time timeDifference{-10, 30};
        const Time timeResult{0, 0};
        ASSERT_EQ(sut + timeDifference, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlySubtractTimeToBeforeMidnight)
    {
        const Time timeDifference{-11, 30};
        const Time timeResult{23, 0};
        ASSERT_EQ(sut + timeDifference, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddMorethan24Hours)
    {
        const Time timeDifference{25, 30};
        const Time timeResult{12, 0};
        ASSERT_EQ(sut + timeDifference, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyAddMorethanNegative24Hours)
    {
        const Time timeDifference{-25, 30};
        const Time timeResult{9, 0};
        ASSERT_EQ(sut + timeDifference, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlySubtractMorethan24Hours)
    {
        const Time timeDifference{-25, 30};
        const Time timeResult{12, 0};
        ASSERT_EQ(sut - timeDifference, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyCompareEqualTimes)
    {
        const Time timeResult{10, 30};
        ASSERT_EQ(sut, timeResult);
    }

    TEST_F(TimeTestSuite, shouldCorrectlyCompareNotEqualTimes)
    {
        const Time timeResult{11, 30};
        ASSERT_NE(sut, timeResult);
    }

    TEST_F(TimeTestSuite, shouldValidateTimeAndRealiseItsValid)
    {
        const Time validTime{11, 30};
        ASSERT_TRUE(sut.isTimeValid(validTime));
    }

    TEST_F(TimeTestSuite, shouldThrowExceptionWhenCreatingTimeWithInvalidValues)
    {
        try
        {
            const Time invalidTime_MinutesEqual60{11, 60};
            FAIL();
        }
        catch (const std::invalid_argument &e)
        {
            EXPECT_STREQ("Time Not Valid! Time Format (hours,minutes), minutes = [0,60)", e.what());
        }
        catch (...)
        {
            FAIL() << "Time Not Valid! Time Format (hours,minutes), minutes = [0,60)";
        }
    }

} // namespace