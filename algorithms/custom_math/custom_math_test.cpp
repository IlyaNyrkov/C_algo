#include "gtest/gtest.h"
extern "C" {
#include "custom_math.h"
}

TEST(power, zero_base) {
    ASSERT_EQ(power(0, 1), 0);
}

TEST(power, zero_power) {
    ASSERT_EQ(power(0, 1), 0);
}

TEST(power, zero_power_zero_base) {
    ASSERT_EQ(power(0, 0), 1);
}

TEST(power, non_zero_power_and_base) {
    ASSERT_EQ(power(2, 10), 1024);
}

TEST(power, big_result) {
    ASSERT_EQ(power(2, 30), 1073741824);
}