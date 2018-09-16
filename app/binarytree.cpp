//
// Created by SuperMiao on 2018/9/16.
//

#include <gtest/gtest.h>
#include "binarytree.h"

TEST(test, binary_tree_test) {

    BinaryTreeNode<int> root;
    root.value = 12345;
    root.left = nullptr;
    root.right = nullptr;

    BinaryTree<int>::printFromToBottom(&root);

}

TEST(test, test_tuple)
{
    std::tuple<int, int, const char*> tp = std::make_tuple(1, 2, "123");
    int a = 0;
    int b = 0;
    const char* c = nullptr;
    std::tie(a, b, c) = tp;
    EXPECT_EQ(1, a);
    EXPECT_EQ(2, b);
    EXPECT_EQ("123", c);
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}