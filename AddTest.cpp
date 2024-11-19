#include <gtest/gtest.h>
#include <string>
#include "AddFunction.h"

// Test for basic addition
TEST(AddFunctionTests, HandleNumbers)) {
    EXPECT_EQ(add("123", "456"), "579");
    EXPECT_EQ(add("0", "0"), "0");
    EXPECT_EQ(add("999", "1"), "1000");
}

// Test for handling negative numbers
TEST(AddFunctionTests, HandleNegativeNumbers) {
    EXPECT_EQ(add("-123", "456"), "333");
    EXPECT_EQ(add("123", "-456"), "-333");
    EXPECT_EQ(add("-123", "-456"), "-579");
}

// Test for handling large numbers
TEST(AddFunctionTests, HandleLargeNumbers) {
    EXPECT_EQ(add("9876543210123456789", "1234567899876543211"), "11111111110000000000");
}

// Test for cases where the result is 0
TEST(AddFunctionTests, SumEqualsZero) {
    EXPECT_EQ(add("123", "-123"), "0");
    EXPECT_EQ(add("-456", "456"), "0");
    EXPECT_EQ(add("0", "0"), "0");
    EXPECT_EQ(add("999999999", "-999999999"), "0");
}
