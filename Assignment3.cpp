//============================================================================
// Name        : Assignment3.cpp
// Author      : Anant_K
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node()
	{
		data=0;
		left=right=NULL;
	}
};

class tree
{
public:
	node* root;

	node* create();
	node* preorder(node*);
	node* insert(node*);
};

node* tree::create()
{
	node *p;
	int x;

	cout<<"\nEnter node: ";
	cin>>x;
	if(x==-1)
		return NULL;
	p=new node;
	p->data=x;
	cout<<"\nEnter Left child of "<<x;
	p->left=create();
	cout<<"\nEnter Right child of "<<x;
    p->right=create();

    return p;
}

node* tree::preorder(node* t)
{

	if(t!=NULL)
	{
		cout<<t->data<<"\t";
		preorder(t->left);
		preorder(t->right);
	}
	return NULL;
}

node* tree::insert(node* t)
{

}

int main()
{
	tree tr;
	tr.root=tr.create();
	tr.preorder(tr.root);


	return 0;
}
