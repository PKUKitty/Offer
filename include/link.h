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

class Link
{
 public:

    /**
     * find the Kth node from tail
     * @param head
     * @param k
     * @return
     */
    static Node* findKthToTail(Node* head, int k)
    {
      if(head == nullptr || k < 1)
      {
        return nullptr;
      }

      Node* pointer = head;

      for(int i = 1; i < k; ++i)
      {
        if(pointer->next != nullptr)
        {
          pointer = pointer->next;
        }
        else
        {
          return nullptr;
        }
      }

      while (pointer->next != nullptr)
      {
          head = head->next;
          pointer = pointer->next;
      }
      return head;
    }


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

  static Node* reverseList(Node* head)
  {
    Node* reverseNode = nullptr;
    Node* currNode = head;
    Node* preNode = nullptr;
    Node* nextNode = nullptr;

    while (currNode != nullptr)
    {
      reverseNode = currNode;
      nextNode = currNode->next;
      currNode->next = preNode;
      preNode = currNode;
      currNode = nextNode;
    }
    return reverseNode;
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
