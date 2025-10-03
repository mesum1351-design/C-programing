/*Write a program in C++ that accepts the base and height of a 
right-angle triangle from the user and displays the area of the triangle. 
(Hint: Formula for area of right angle triangle = (base*height)/2)*/ 
#include<iostream>
using namespace std;

int main()
{
	int base, height, area;
	
	cout<<"Enter the length of triangle: "<<endl;
	cin>> base;
	cout<<"Enter the base of trangle: "<<endl;
	cin>> height;
	
	area= base*height/2; // Formula of right angle triangle
	cout<<"Area of Right-Trangle is "<< area ;
}
