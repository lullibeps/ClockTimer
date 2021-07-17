#include "gtest/gtest.h"

#include "../ClockData.h"


class ClockDataSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        c.setFormatoData(FormatoData::europeo);
        c.setFormatoOrario(FormatoOrario::h24);
        c.setCustomData(10, 1, 2025, 15, 35, 10);
    }

    ClockData c;
};


TEST_F(ClockDataSuite, TestFormato) {
    c.setFormatoOrario(FormatoOrario::h12);

    ASSERT_EQ("10/1/2025 - 3:35", c.getClockData().substr(0, 16));
    ASSERT_EQ("PM", c.getClockData().substr(20, 2));

    c.setFormatoOrario(FormatoOrario::h24);
    ASSERT_EQ("10/1/2025 - 15:35", c.getClockData().substr(0, 17));

    c.setFormatoData(FormatoData::statunitense);
    ASSERT_EQ("1/10/2025 - 15:35", c.getClockData().substr(0, 17));

    c.setFormatoData(FormatoData::cinese);
    ASSERT_EQ("2025/1/10 - 15:35", c.getClockData().substr(0, 17));
}

