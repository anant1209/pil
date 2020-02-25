//============================================================================
// Name        : Assignment4.cpp
// Author      : Anant_K
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

struct node {
	char data;
	node* left;
	node* right;

};

class tree {
public:
	node* root;
	node* newNode(int v) {
		//cout<<"IN";
		node *temp = new node;
		temp->left = temp->right = NULL;
		temp->data = v;
		return temp;
	}


	int isOperator(char c) {
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
			return 1;
		return 0;
	}

	void inorder(node *t) {
		if (t) {
			inorder(t->left);
			printf("%c ", t->data);
			inorder(t->right);
		}
	}

	void preorder(node *t) {
		if (t) {

			printf("%c ", t->data);
			inorder(t->left);
			inorder(t->right);
		}
	}

	void postorder(node *t) {
		if (t) {

			inorder(t->left);
			inorder(t->right);
			printf("%c ", t->data);
		}
	}

	void NonRecInorder(node* T)
	{
		stack<node*> s;
		int Break=1;
		while(Break==1)
		{
			while(T!=NULL)
			{
				s.push(T);
				T=T->left;
			}
			if(s.empty()==true)
			{
				Break=0;
			}
			else
			{
				T=s.top();
				s.pop();
				cout<<T->data;
				T=T->right;
			}
		}
	}

	node* constructTree(char postfix[]) {
		stack<node*> st;
		node *t;
		node *t1;
		node *t2;

		//cout<<"In the function";
		for (int i = 0; i < strlen(postfix); i++) {

			if (!isOperator(postfix[i])) {
				t = newNode(postfix[i]);
				//cout<<"Push hone vala";
				st.push(t);
			} else {
				t = newNode(postfix[i]);

				t1 = st.top();
				st.pop();
				t2 = st.top();
				st.pop();

				t->right = t1;
				t->left = t2;

				st.push(t);
			}
		}

		t = st.top();
		st.pop();

		return t;
	}

	node* constructTree1(char prefix[]) {
		stack<node*> st;
		node *t;
		node *t1;
		node *t2;


		for (int i = strlen(prefix)-1; i>=0 ; i--) {

			if (!isOperator(prefix[i])) {
				t = newNode(prefix[i]);
				st.push(t);
			} else {
				t = newNode(prefix[i]);

				t1 = st.top();
				st.pop();
				t2 = st.top();
				st.pop();

				t->left = t1;
				t->right = t2;

				st.push(t);
			}
		}

		t = st.top();
		st.pop();

		return t;
	}

};

int main() {

	char postfix[100];

	char prefix[100];
	int ch;
	tree tr;
	while (1) {
		cout << "\n***********MENU************\n";
		cout << "1.Postfix\n2.Prefix\n3.EXIT\n\nEnter choice: ";
		cin >> ch;

		switch (ch) {
		case 1:
			cout << "Enter Expression: ";
			cin >> postfix;
			tr.root = tr.constructTree(postfix);
			printf("\nInfix expression is: ");
					tr.inorder(tr.root);
			printf("\nPostfix expression is: ");
					tr.postorder(tr.root);
			printf("\nPrefix expression is: ");
					tr.preorder(tr.root);
			break;

			case 2:
				cout << "Enter Expression: ";
				cin >> prefix;
				tr.root = tr.constructTree1(prefix);
				printf("\nInfix expression is: ");
						tr.inorder(tr.root);
				printf("\nPostfix expression is: ");
						tr.postorder(tr.root);
				printf("\nPrefix expression is: ");
						tr.preorder(tr.root);
				break;

				case 3:
					return 0;

		}
	}

	return 0;

}
