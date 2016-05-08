#include "stdafx.h"

class TreeNode
{
	friend class BST;

public:
    TreeNode();  //default constructor
    TreeNode(int i, TreeNode *L = 0; TreeNode *R = 0); //explicit value constructor
    int getItem () const; // accessor function

private:
    int item;
    TreeNode *Lchild;
    TreeNode *Rchild;

};

TreeNode::TreeNode()
{
    Lchild = Rchild = NULL;
}

TreeNode::TreeNode(int i, TreeNode *L = 0, TreeNode *R = 0) : item(i), Lchild(L), Rchild(R)
{}

int TreeNode::getItem() const
{
    return item;
}