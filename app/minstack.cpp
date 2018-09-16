//
// Created by SuperMiao on 2018/9/15.
//

#include <gtest/gtest.h>
#include "minstack.h"

TEST(test, min_stack) {
    MinStack<int> minStack;
    minStack.push(1);
    minStack.push(2);

    EXPECT_EQ(1, minStack.min());
    EXPECT_EQ(2, minStack.pop());
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}