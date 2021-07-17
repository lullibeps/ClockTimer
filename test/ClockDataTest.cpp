#include "gtest/gtest.h"

#include "../ClockData.h"

TEST(ClockData, DefaultConstructor) {
    ClockData c;
    ASSERT_EQ(FormatoOrario::h24, c.getFormatoOrario());
    ASSERT_EQ(FormatoData::europeo, c.getFormatoData());
    ASSERT_FALSE(c.isUseCustomData());
}


TEST(ClockData, TestCustomData) {
    ClockData c;
    c.setCustomData(1, 2, 3, 4, -121, 10);
    ASSERT_EQ("1/2/3 - 1:59", c.getClockData().substr(0, 12));
    c.setCustomData(-1, 2, 3, 4, 2, 10);
    ASSERT_EQ("30/1/3 - 4:2", c.getClockData().substr(0, 12));
    ASSERT_TRUE(c.isUseCustomData());
    c.setUseCustomData(false);
    ASSERT_FALSE(c.isUseCustomData());
}
