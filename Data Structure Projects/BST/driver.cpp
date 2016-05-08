#include "stdafx.h"
#include <iostream>
using namespace std;

/* 
	COMPE 260
	Brandon Castro 816549663
*/
#include "BST.h"

int main()
{
	BST bst;
	cout<<"Constructing empty BST\n";
	cout<<"BST "<<(bst.empty() ? "is" : "is not")<<" empty\n";

	//Testing inorder
	cout<<"Inorder traversal of BST: \n";
	bst.inorder(cout);

	//Testing insert
	cout<<"\nNow insert a bunch of integers into the BST. Try items in/not in BST: \n";
	int number;
	for(;;)
	{
		cout<<"Item to insert (-999 to stop); ";
		cin>>number;
		if(number == -999) break;
		bst.insert(number);
	}
	bst.graph(cout);

	cout<<"\nInorder traversal of BST: \n";
	bst.inorder(cout);
	cout<<endl;

	//Testing search()
	cout<<"\n\nNow testing search(). Try items in/not in BST: \n";
	for(;;)
	{
		cout<<"Item to find (-999 to stop): ";
		cin>>number;
		if(number == -999) break;
		cout<<(bst.search(number) ? "Found" : "Not found")<<endl;
	}

	//Testing remove()
	cout<<"\nNow testing remove(). Try items both in/not in BST: \n";
	for(;;)
	{
		if(bst.empty())
		{
			cout<<"BST is empty\n";
			break;
		}
		
		cout<<"Item to remove (-999 to stop): ";
		cin>>number;
		if(number == -999) break;
		bst.remove(number);
		bst.graph(cout);
	}

	cout<<"\nInorder traversal of BST \n";
	bst.inorder(cout);
	cout<<endl;

	cout<<"Preorder traversal of BST: \n";
	bst.preorder(cout);
	cout<<endl;

	cout<<"Postorder traversal of BST: \n";
	bst.postorder(cout);
	cout<<endl;
}
