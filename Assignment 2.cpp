//============================================================================
// Name        : Assignment.cpp
// Author      : Anant_K
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#include"queue.cpp"
#include"queue.h"
using namespace std;

typedef struct details {
	char id[5];
	char name[10];
	char bg[4];
	char phn[10];
	char disease[15];
	char address[20];
	int priority;
} details;

int pri(details d)
{
	if(!strcmp(d.disease,"cancer"))
	{

		return 3;
	}

	if(!strcmp(d.disease,"typhoid"))
	{
		return 2;
	}

	if(!strcmp(d.disease,"fever"))
	{
		return 1;
	}
	return 0;
}

int main() {
	int choice;
	details d[10];
	details dd;
	queue<details> q;
	int i=0;
	while (1) {
		cout << "\n******MENU*******\n";
		cout << "1.Insert\n2.Serve\n3.Display\n\nEnter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:

				cout<<"\nFor Patient "<<i+1<<endl;
				cout << "\nEnter ID: ";
				cin>>d[i].id;
				cout << "Enter Name: ";
				cin>>d[i].name;
				cout << "Enter Blood Group: ";
				cin>>d[i].bg;
				cout << "Enter Phone Number: ";
				cin>>d[i].phn;
				cout << "Enter Disease: ";
				cin>>d[i].disease;
				cout << "Enter address: ";
				cin>>d[i].address;
				d[i].priority=pri(d[i]);
				q.enqueue(d[i]);
				i++;


				break;

		case 2:
			cout<<"Details are:\n";
			dd=q.dequeue();
			cout<<dd.id<<endl;
			cout<<dd.name<<endl;
			cout<<dd.bg<<endl;
			cout<<dd.disease<<endl;
			cout<<dd.address<<endl;
			break;

		case 3:	cout<<"\n\nList of Patients :\n\n";
				details* arr;
				arr=new details[100];
				int x = q.display(arr);
				int m=0;
				while(i<x)
				{
					cout<<"\nPatient No. "<<(m+1)<<endl;
					cout<<"ID : "<<arr[m].id<<endl;
					cout<<"Name : "<<arr[m].name<<endl;
					cout<<"Bloodgroup : "<<arr[m].bg<<endl;
					cout<<"Phone : "<<arr[m].phn<<endl;
					cout<<"Disease : "<<arr[m].disease<<endl;
					m++;
				}
					break;

		}

	}

	return 0;
}
