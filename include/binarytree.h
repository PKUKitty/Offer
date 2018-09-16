//
// Created by SuperMiao on 2018/9/16.
//

#ifndef OFFER_BINARYTREE_H
#define OFFER_BINARYTREE_H

#include <queue>

template <typename TT>
struct BinaryTreeNode
{
    TT value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


template <class TT>
class BinaryTree
{
public:
    BinaryTree() = default;

    static void printFromToBottom(BinaryTreeNode<TT>* root)
    {
        if(root != nullptr)
        {
            std::queue<BinaryTreeNode<TT>*> list;
            list.push(root);
            BinaryTreeNode<TT>* currNode = nullptr;

            while (!list.empty())
            {
                currNode = list.front();
                list.pop();
                std::cout << currNode->value<<" ";

                if(currNode->left != nullptr)
                {
                    list.push(currNode->left);
                }

                if(currNode->right != nullptr)
                {
                    list.push(currNode->right);
                }
            }
        }
    }
};

#endif //OFFER_BINARYTREE_H
