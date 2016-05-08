#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;

/* 
	COMPE 260
	Brandon Castro 816549663
*/
#include "BST.h"

void BST::insert(const int &item)
{
	insertAux(myRoot, item);
}

void BST::insertAux(BST::BinNodePointer &subtreeRoot, const int &item)
{
	//recursive insert operation
	if(subtreeRoot == 0)
		subtreeRoot = new BST::BinNode(item);
	else if(item < subtreeRoot->data)
		insertAux(subtreeRoot->left, item);
	else if(item > subtreeRoot->data)
		insertAux(subtreeRoot->right, item);
	else
		cerr<<"Item already exists in tree\n";
}

void BST::remove(const int &item)
{
	bool found;
	BST::BinNodePointer
		x, //ptr to node to be deleted
		parent; //ptr to parent of xSucc
	search2(item, found, x, parent);

	if(!found)
	{
		cout<<"Item is not in the BST\n";
		return;
	}

	if(x->left != 0 && x->right != 0)
	{
		BST::BinNodePointer xSucc = x->right;
		parent = x;
		while(xSucc->left != 0)
		{
			parent = xSucc;
			xSucc = xSucc->left;
		}

		//move data of xSucc to x, change x to point to succ, which will be removed
		x->data = xSucc->data;
		x = xSucc;
	}

	BST::BinNodePointer subtree = x->left;
	if(subtree == 0)
		subtree = x->right;
	if(parent == 0)
		myRoot = subtree;
	else if(parent->left == x)
		parent->left = subtree;
	else
		parent->right = subtree;
	delete x;
}

void BST::search2(const int &item, bool &found, BST::BinNodePointer &locptr, BST::BinNodePointer &parent) const
{
	locptr = myRoot;
	parent = 0;
	found = false;
	
	while(!found && locptr->data)
	{
		if(item < locptr->data) //descend left
		{
			parent = locptr;
			locptr = locptr->left;
		}
		else if(item > locptr->data) //descend right
		{
			parent = locptr;
			locptr = locptr->right;
		}
		else
			found = true;
	}
}

bool BST::search(const int &item) const
{
	BST::BinNodePointer locptr = myRoot;
	bool found = false;

	while(!found && locptr != 0)
	{
		if(item < locptr->data) //descend left
			locptr = locptr->left;
		else if(locptr->data < item) //descend right
			locptr = locptr->right;
		else
			found = true;
	}
	return found;
}

void BST::inorder(ostream &out) const
{
	inorderAux(out, myRoot);
}

void BST::preorder(ostream &out) const
{
	preorderAux(out, myRoot);
}	

void BST::postorder(ostream &out) const
{
	postorderAux(out, myRoot);
}

void BST::inorderAux(ostream &out, BST::BinNodePointer subtreeRoot) const
{
	if(subtreeRoot != 0)
	{
		inorderAux(out, subtreeRoot->left); //L
		out<<subtreeRoot->data<<" "; //V
		inorderAux(out, subtreeRoot->right); //R
	}
}

void BST::preorderAux(ostream &out, BST::BinNodePointer subtreeRoot) const
{
	out<<subtreeRoot->data<<" "; //V
	preorderAux(out, subtreeRoot->left); //L
	preorderAux(out, subtreeRoot->right); //R
}

void BST::postorderAux(ostream &out, BST::BinNodePointer subtreeRoot) const
{
	postorderAux(out, subtreeRoot->left); //L
	postorderAux(out, subtreeRoot->right); //R
	out<<subtreeRoot->data<<" "; //V
}

void BST::graph(ostream &out) const
{ 
	graphAux(out, 0, myRoot);
}

void BST::graphAux(ostream &out, int indent, BST::BinNodePointer subtreeRoot) const
{
	if(subtreeRoot != 0)
	{
		graphAux(out, indent + 8, subtreeRoot->right);
		out<<setw(indent)<<" "<<subtreeRoot->data<<endl;
		graphAux(out, indent + 8, subtreeRoot->left);
	}
}

ostream& operator<< (ostream &out, BST &a)
{
	a.graph(out);
	return out;
}