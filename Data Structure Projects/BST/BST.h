#include "stdafx.h"
#include <iostream>
#include <new>

/* 
	COMPE 260
	Brandon Castro 816549663
*/

#ifndef BINARY_SEARCH_TREE
#define	BINARY_SEARCH_TREE

class BST
{
public:
	//function members
	BST();
	bool empty() const;
	bool search(const int &item) const;
	void insert(const int &item);
	void remove(const int &item);
	void inorder(ostream &out) const;
	void preorder(ostream &out) const;
	void postorder(ostream &out) const;
	void graph(ostream &out) const;

	//Node Class
	class BinNode
	{
	public:
		int data;
		BinNode *left;
		BinNode *right;
		//Default Constructor
		BinNode() 
			: left(0), right(0)
		{}
		//Explicit Value Constructor
		BinNode(int item) 
			: data(item), left(0), right(0)
		{}

	};
	typedef BinNode *BinNodePointer;
	BinNodePointer myRoot;

private:
	//private function members
	void insertAux(BST::BinNodePointer &subtreeRoot, const int &item);
	void search2(const int &item, bool &found, BST::BinNodePointer &locptr, BST::BinNodePointer &parent) const;
	void inorderAux(ostream &out, BST::BinNodePointer subtreePtr) const;
	void preorderAux(ostream &out, BST::BinNodePointer subtreePtr) const;
	void postorderAux(ostream &out, BST::BinNodePointer subtreePtr) const;
	void graphAux(ostream &out, int indent, BST::BinNodePointer subtreeRoot) const;
};

ostream& operator<< (ostream &out, BST &a);

inline BST::BST()
: myRoot(0)
{}

inline bool BST::empty() const
{ return myRoot == 0; }

#endif