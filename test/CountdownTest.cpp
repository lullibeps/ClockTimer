#include "gtest/gtest.h"

#include "../Countdown.h"

TEST(Countdown, TimeTest) {
    Countdown t;
    ASSERT_FALSE(t.startTimer());
    ASSERT_FALSE(t.startTimer(0, -1));
    ASSERT_FALSE(t.startTimer(-1, 0));
    ASSERT_TRUE(t.startTimer(0, 1));
    sleep(1);
    t.pauseTimer();
    sleep(1);
    ASSERT_EQ("59", t.getCountdownTime().GetSeconds().ToString());
    ASSERT_TRUE(t.startTimer());
    sleep(1);
    ASSERT_EQ("58", t.getCountdownTime().GetSeconds().ToString());
    t.resetTimer();
    ASSERT_EQ("0", t.getCountdownTime().GetSeconds().ToString());

}
