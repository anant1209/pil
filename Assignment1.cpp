//============================================================================
// Name        : assignment1
// Author      : Anant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stack.h"
#include "stack.cpp"
#include <string.h>
#include <math.h>
using namespace std;

int precedence(char ch) {

	if (ch == '^')
		return 5;
	if (ch == '/')
		return 4;
	if (ch == '*')
		return 4;
	if (ch == '+' || ch == '-')
		return 2;
	if (ch == '(' || ch == ')')
		return 1;

}

void convertToPostfix(char *inp, char *postfix) {
	int i = 0;
	int p = 0;
	char ch;
	char ch1;
	char ch2;
	stack<char> s;

	while (inp[i] != NULL)

	{
		ch = inp[i];
		if (isalnum(ch)) {
			postfix[p] = ch;
			p++;
		} else if (ch == '(') {
			s.push(ch);
		} else if (ch == ')') {

			char l = s.getTop()->data;

			while ((s.getTop()->data) != '(') {
				ch1 = s.pop();

				postfix[p] = ch1;
				p++;

			}
			s.pop();
		} else {
			if (s.isEmpty()) {
				s.push(ch);
			} else {
				if (precedence(ch) == 5) {
					ch2 = s.getTop()->data;

					while (precedence(ch2) > precedence(ch) && !(s.isEmpty())) {
						ch2 = s.pop();
						postfix[p] = ch2;
						p++;
					}
					s.push(ch);
				} else {

					ch2 = s.getTop()->data;

					while (precedence(ch2) >= precedence(ch) && !(s.isEmpty())) {
						ch2 = s.pop();
						postfix[p] = ch2;
						p++;
					}
					s.push(ch);
				}
			}

		}

		i++;
	}

	while (!s.isEmpty()) {

		postfix[p] = s.pop();
		p++;
	}
}

void convertToPrefix(char *inp, char *postfix) {
	int i = 0;
	int p = 0;
	char ch;
	char ch1;
	char ch2;
	stack<char> s;

	while (inp[i] != NULL)

	{
		ch = inp[i];
		if (isalnum(ch)) {
			postfix[p] = ch;
			p++;
		} else if (ch == '(') {
			s.push(ch);
		} else if (ch == ')') {
			while ((s.getTop()->data) != '(' && (!s.isEmpty())) {
				ch1 = s.pop();
				postfix[p] = ch1;
				p++;

			}

			if (s.getTop()->data == '(')
				char c = s.pop();
		} else {
			if (s.isEmpty()) {
				s.push(ch);
			} else {
				ch2 = s.getTop()->data;

				while (precedence(ch2) >= precedence(ch) && !(s.isEmpty())) {
					ch2 = s.pop();
					postfix[p] = ch2;
					p++;
				}
				s.push(ch);
			}

		}

		i++;
	}

	while (!s.isEmpty()) {
		postfix[p] = s.pop();
		p++;
	}
}

int operation(char x, int a, int b) {
	switch (x) {
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	case '^':
		return pow(a, b);
	}
}

void EvaluatePost(char * inp) {
	char * changed;
	stack<int> integer;
	int length = strlen(inp);
	changed = new char(length);
	int i = 0;
	while (i < length) {
		char ch = *(inp + i);
		if (isalpha(ch)) {
			char x;
			cout << "Enter the value of " << ch << " : ";
			cin >> x;
			*(changed + i) = x;

		} else {
			*(changed + i) = ch;
		}
		i++;
	}

	i = 0;

	while (i < length) {
		char ch = *(inp + i);
		if (isdigit(ch)) {
			char *m;
			m = new char();
			*m = ch;
			int p = atoi(m);
			integer.push(p);
		} else {
			int operand2 = integer.pop();
			int operand1 = integer.pop();
			int c = operation(ch, operand1, operand2);
			integer.push(c);
		}

		i++;

	}
	cout << "The result is " << integer.pop();

}

void EvaluatePre(char * inp1) {
	char * inp;
	int j = 0;
	int length = strlen(inp1);
	while (j < length) {
		*(inp + j) = *(inp1 + length - j - 1);
		j++;
	}

	char * changed;
	stack<int> integer;
	changed = new char(length);
	int i = 0;
	while (i < length) {
		char ch = *(inp + i);
		if (isalpha(ch)) {
			int x;
			cout << "Enter the value of " << ch << " : ";
			cin >> x;
			*(changed + i) = x;

		} else {
			*(changed + i) = ch;
		}
		i++;
	}

	i = 0;

	while (i < length) {
		char ch = *(inp + i);
		if (isdigit(ch)) {
			char *m;
			m = new char();
			*m = ch;
			int p = atoi(m);
			integer.push(p);
		} else {
			int operand2 = integer.pop();
			int operand1 = integer.pop();
			int c = operation(ch, operand1, operand2);
			integer.push(c);
		}

		i++;

	}
	cout << "The result is " << integer.pop();

}

int main() {

	stack<char> s;
	char inp[100];
	char postfix[100];
	char prefix[100];
	char infix[100];
	int choice;
	int g;
	while (1) {
		cout << "\n\n****MENU****\n";

		cout
				<< "1.Infix to Postfix\n2.Infix to Prefix\n3.Evaluate Postfix\n4.Evaluate Prefix\n5.Exit";
		cout << "\nEnter your choice : ";
		cin >> choice;

		switch (choice) {

		case 1:
			cin.ignore();
			cout << "\nEnter the infix statement : ";
			cin.getline(inp, 98);
			convertToPostfix(inp, postfix);
			cout << "\nThe postfix statement is : ";
			for (int u = 0; u < strlen(inp); u++) {
				cout << postfix[u];
			}
			break;

		case 2:
			cin.ignore();
			cout << "\nEnter the infix statement : ";
			cin.getline(inp, 98);
			char inp1[100];
			g = 0;
			for (int u = strlen(inp) - 1; u >= 0; u--) {
				inp1[u] = inp[g];
				g++;
			}

			convertToPrefix(inp1, postfix);
			g = 0;
			for (int u = strlen(inp) - 1; u >= 0; u--) {
				prefix[u] = postfix[g];
				g++;
			}
			cout << "\nThe prefix statement is : ";
			for (int u = 0; u < strlen(inp); u++) {
				cout << prefix[u];
			}
			break;

		case 3:
			cout << "\nEnter the Postfix statement to be Evaluated :";
			cin.ignore();
			cin.getline(inp, 98);
			EvaluatePost(inp);
			break;

		case 4:
			cout << "\nEnter the Prefix statement to be Evaluated :";
			cin.ignore();
			cin.getline(inp, 98);
			EvaluatePre(inp);
			break;

		}
	}
}

