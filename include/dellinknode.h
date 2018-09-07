/**
 * Copyright (c) 2018, Travelsky R&D Department
 * All rights reserved
 * 
 * @file dellinknode.h
 * @brief 
 * @author yujun@
 * @version 1.0
 * @date 18-9-7 
 **/

#ifndef OFFER_DELLINKNODE_H
#define OFFER_DELLINKNODE_H

#include <iostream>

struct Node
{
  int value;
  Node* next;

  Node(int v, Node* n) : value(v), next(n)
  {

  }
};

class DelLinkNode
{
 public:

  static Node* deleteNode(Node* head, Node* toBeDelete)
  {
    //head ,  to be delete node is null
    if (head == nullptr || toBeDelete == nullptr)
    {
      return head;
    }

    //head == to be delete
    if (head == toBeDelete)
    {
      return head->next;
    }

    //the last node
    if (toBeDelete->next == nullptr)
    {
      Node* tmpNode = head;
      while (tmpNode->next != toBeDelete)
      {
        tmpNode = tmpNode->next;
      }

      tmpNode->next = nullptr;
    } else
    {
      toBeDelete->value = (toBeDelete->next)->value;
      toBeDelete->next = (toBeDelete->next)->next;
    }
    return head;
  }

  /**
   * @brief
   * @param root
   */
  static void printLink(const Node* root)
  {
    while (root != nullptr)
    {
      std::cout << root->value << "->";
      root = root->next;
    }
  }
};

#endif //OFFER_DELLINKNODE_H
