//
// Created by Yu Jun on 30/08/2018.
//

#include <gtest/gtest.h>
#include "replacespace.h"
#include "onenumber.h"
#include "fibonacci.h"

TEST(test, repacesapce)
{
    std::string str = " are happy ";
    std::string str1 = "%20are%20happy%20";

    ReplaceSpace::replaceSpace(str);
    EXPECT_EQ(str1, str);
}

TEST(test, number_of_one)
{
    EXPECT_EQ(2, OneNumber::numberOfOne(9));
    EXPECT_EQ(32, OneNumber::numberOfOne(-1));
    EXPECT_EQ(0, OneNumber::numberOfOne(0));
}


TEST(test, power)
{
    EXPECT_EQ(4, Power::power(2, 2));
    EXPECT_EQ(0.25, Power::power(2, -2));
    EXPECT_EQ(-8, Power::power(-2, 3));
}

TEST(test, fibonacci)
{
    EXPECT_EQ(2, Fibonacci::fibonacci(3));
    EXPECT_EQ(3, Fibonacci::fibonacci(4));
    EXPECT_EQ(5, Fibonacci::fibonacci(5));
    EXPECT_EQ(8, Fibonacci::fibonacci(6));
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}