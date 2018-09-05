//
// Created by Yu Jun on 29/08/2018.
//

#include <gtest/gtest.h>
#include "singleton.h"

TEST(test, count)
{
    EXPECT_NE(nullptr, Singleton::getInstance());
}

TEST(test, getCount)
{
    EXPECT_EQ(0, Singleton::getInstance()->getCount());
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}