//
// Created by krisb on 5/17/20.
//

#include "stats.h"
#include "gtest/gtest.h"

TEST(ProptTest, ValidInput) {
    EXPECT_DOUBLE_EQ(PropTest(14, 100, 20, 100), 0.25870176105718945);
}

TEST(ProptTest, InvalidInput) {
    EXPECT_EQ(PropTest(0, 0, 0, 0), -1);
}

