/**
 * Copyright (c) 2018, Travelsky R&D Department
 * All rights reserved
 * 
 * @file link.cpp
 * @brief 
 * @author yujun@
 * @version 1.0
 * @date 18-9-7 
 **/

#include <gtest/gtest.h>
#include "dellinknode.h"

TEST(link, deleteNode)
{
  auto node1 = new Node(1, nullptr);
  node1->next = new Node(2, nullptr);
  node1->next->next = new Node(3, nullptr);
  node1->next->next->next = new Node(4, nullptr);

  node1 = DelLinkNode::deleteNode(node1, node1);
  DelLinkNode::printLink(node1);
  EXPECT_EQ(2, node1->value);
}

GTEST_API_ int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

