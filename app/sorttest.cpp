//
// Created by SuperMiao on 2018/9/26.
//

#include <gtest/gtest.h>
#include "sort.h"

TEST(test, bubble_sort)
{
    int a[] = {3,1,4,5,7,6,8};
    Sort<int>::bubbleSort(a, GTEST_ARRAY_SIZE_(a));
    for(auto iter : a)
    {
        std::cout << iter << ",";
    }
}

TEST(test, select_sort)
{
    int a[] = {3,1,4,5,7,6,8};
    Sort<int>::selectSort(a, GTEST_ARRAY_SIZE_(a));
    for(auto iter : a)
    {
        std::cout << iter << ",";
    }
}

TEST(test, inset_sort)
{
    int a[] = {3,1,4,5,7,6,8};
    Sort<int>::insertSort(a, GTEST_ARRAY_SIZE_(a));
    for(auto iter : a)
    {
        std::cout << iter << ",";
    }
}

TEST(test, quick_sort)
{
    int a[] = {3,1,4,5,7,6,8};
    Sort<int>::quickSort(a, 0, GTEST_ARRAY_SIZE_(a) - 1);
    for(auto iter : a)
    {
        std::cout << iter << ",";
    }
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}