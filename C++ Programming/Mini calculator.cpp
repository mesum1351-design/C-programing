/*	Write a program in C++ that accepts the values of two variables num1 and num2 from the user and 
"	Add them and store the result in a third variable sum. 
"	Subtract them and store the result in a fourth variable difference. 
"	Multiply them and store the result in a fifth variable product.*/
#include<iostream> 
using namespace std;

int main()
{   int num1, num2, sum, difference, product;
 
    cout<<"Enter num1: ";
    cin>> num1;
    cout<<"Enter num2: ";
    cin>> num2;
    
    sum= num1+num2;
    difference= num1-num2;
    product= num1*num2;
    
    cout<<"Sum : "<<sum<<endl;
    cout<<"Difference : "<<difference<<endl;
    cout<<"Product : ";
 

}
