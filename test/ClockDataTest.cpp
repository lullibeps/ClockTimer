#include "gtest/gtest.h"

#include "../ClockData.h"

TEST(ClockData, GetData
) {
ASSERT_EQ("-", ClockData::getClockData(1).substr(2, 1));
ASSERT_EQ("-", ClockData::getClockData(1).substr(5, 1));
ASSERT_EQ("/", ClockData::getClockData(2).substr(2, 1));
ASSERT_EQ("/", ClockData::getClockData(2).substr(5, 1));
ASSERT_EQ("-", ClockData::getClockData(3).substr(2, 1));
ASSERT_EQ("-", ClockData::getClockData(3).substr(5, 1));
ASSERT_EQ("/", ClockData::getClockData(4).substr(2, 1));
ASSERT_EQ("/", ClockData::getClockData(4).substr(5, 1));
}


TEST(GameCharacter, GetFormat
) {
ASSERT_EQ(4,

ClockData::getNumOfFormat()

);
}
