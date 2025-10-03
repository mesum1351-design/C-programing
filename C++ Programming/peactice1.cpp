
/* Wrte a program in which ask user to 
   his name andf age */

#include<iostream>
using namespace std;

int main()
{
	int age;
	string name;
	
	cout<<"Enter Your name:  ";
	getline(cin,name);    /* Manage inpute with spaces*/
	cout<<"Enter Your Age:  ";
	cin>>age ;
	cout<<"\n Hi"<<name<<" You are "<<age<<" Year old";
	return 0;
}

