//
// Created by Yu Jun on 29/08/2018.
//


#include <gtest/gtest.h>
#include "arrayfind.h"

TEST(test, arrayfind) {

    std::vector<int> arr = {1, 2, 3};
    std::vector<int> arr2 = {4, 5, 6};

    std::vector<std::vector<int>> array;
    array.push_back(arr);
    array.push_back(arr2);

    EXPECT_EQ(true, ArrayFind::find(array, 3));
    EXPECT_EQ(false, ArrayFind::find(array, 7));
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
