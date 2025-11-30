// Arrays
 
    //Array Declration
#include<iostream>
using namespace std;

int main()
{
	int marks[5]; // Array decleration
	cout<<"Enter the marks of all Subjects: "<<endl;
	for(int index = 0; index<5; index++){ // Loop for insert value in all indecs
		cin >>marks[5];//input the value in Array
	
	}
	for(int index =0 ; index<5; index++){
		cout<<"Marks of SUbject "<< index+1<<" is "<<marks[5]<<endl;
	}
	return 0;
}


//   Find smallest element from the Arary

#include<iostream>
using namespace std;

int main(){
	int array[5] = {3,4,5,2,1};
	int smallest=INT_MAX;
	for(int index =0 ;index<5;  index++)
	{
		if(array[index]<smallest)
		smallest = array[index];
		
	}
	cout<<"Smallest number is : "<<smallest;
}       	

// Find Largest element from the array

#include<iostream>
using namespace std;

int main(){
	
	int array[5] = {2,3,4,5,1};
	int Largest = INT_MIN;
	for(int index=0; index<5; index++)
	{
		if(array[index]>Largest)
		Largest = array[index];
		
	}
	cout<<"Largest Number is :" << Largest;
	return 0;
}  


// Sum of Element of the array; 

#include<iostream>
using namespace std;

int main()
{
	int array[10]= {1,2,3,4,5,6,7,8,9,10};
	int sum =0;
	for(int index =0; index< 10; index++){
		sum +=array[index];
		
	}
	cout<< " Sum of the elements of the array is "<<sum;
	return 0;
	
}  

//  How to find  Size of  the Array

# include<iostream>
using namespace std;

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	
	cout<< "Size of Array is;"<< sizeof(array)<<endl;
	cout<< "Number of Elements are : "<< sizeof(array)/sizeof(int);
} 

 //  Swaping
 // interchange the element

#include<iostream>
using namespace std;

int main(){
	int Array[5] ={12,43,67,89,24};
	swap(Array[0],Array[3]);
	for(int index= 0; index<5 ; index++){

	cout<<Array[index]<<" ";
	}
	return 0;
}    

//   Shifting  of the element
// Left shifting

# include<iostream>
using namespace std;

int main(){
	int Array[5] = { 12,43,67,89,24};
	 for(int index=0; index<4; index++ ){
	 	Array[index] =Array[index+1];
	 }
	 Array[4]= 0;
	 for(int index=0; index<5; index++){
	 	cout<<Array[index]<<"  ";
	 }	 
}

// Right Shifting

#include<iostream>
using namespace std;

int main(){
	int array[5] ={1,2,3,4,5};
	int last =0;
	for(int i=4; i>=0; i--){
		array[i]= array[i-1];
		
	}
	array[0]=0;
	for(int i=0; i<5; i++){
		cout<<array[i]<<" ";
	}
	
} 

//  RAndom Shufling
// Disorder of Element by using create new index

# include<iostream>
#include<cstdlib>  // standard librray jo use karty hai fuctions ka liya rand(), exit()
#include<ctime> // ya library har bar new number generate karta hai
using namespace std;

int main(){
	int arraysize=10;
	int list[arraysize] ={1,2,3,4,5,6,7,8,9,10};
	srand(time(0));
	for(int index=0; index<arraysize; index++){
		int randomindex = rand()%arraysize;
		
		int temp= list[index];
		list[index]= list[randomindex];
		list[randomindex]= temp;
	}

for(int index=0; index<arraysize; index++){
	cout<<list[index];
}
}  


 // Quiz 
 
#include<iostream>
using namespace std;

int main(){
	
	int arrayA[3];
	int arrayB[3];
	
	cout<<"Enter the Elements of First Array";
	for(int i=0; i<3; i++){
		
		cin>>arrayA[i];
	}
	cout<<"Enter the Elements of Second Array";
	for(int i=0; i<3; i++){
		
		cin>> arrayB[i];
	}
	int arrayC[3];
	for(int i=0; i<3; i++){
		
    arrayC[i]=arrayA[i]+arrayB[i];
	cout<<arrayC[i]<<"  ";}
} 


// 2D Array

//Insrt elements of Array in 2 dimention

#include<iostream>
using namespace std;

int main(){

	int array[3][3] ;
	cout<<"Enter the element of Matrix Row Wise: ";
	for(int i= 0; i<3; i++){
		for(int j=0; j<3; j++){
			cin>> array[i][j];
		}
	}
	for(int i= 0; i<3; i++){
		
		for(int j=0 ;j<3; j++){
		  cout<<array[i][j]<<" ";
		  
		  }
		  	cout<<endl;
	}
}  

//Sum of Row


#include<iostream>
using namespace std;

int main(){
	int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int sum=0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
		sum += matrix[i][j];	
		}
		cout<<"Sum of row "<<sum<<endl;
	}
} 
// Sum of Secondary Digonal of matreix

#include<iostream>
using namespace std;

int main(){int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int sum=0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i+j==2)
		
		sum += matrix[i][j];	
		}}
		cout<<"Sum of Secondary Digonal is:  "<<sum<<endl;	
return 0;
}

// Sum of Secondary Digonal

#include<iostream>
using namespace std;

int main(){int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int sum=0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i=j)
		
		sum += matrix[i][j];	
		}}
		cout<<"Sum of Primary Digonal is:  "<<sum<<endl;
	}  */
	
	
// Sum of Lower Digonal of Matrix

#include<iostream>
using namespace std;

int main(){int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int sum=0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i>j)
		
		sum += matrix[i][j];	
		}}
		cout<<"Sum of Lower Digonal is:  "<<sum<<endl;
	}   */
	
//Sum of Lower Digonal of matrix

#include<iostream>
using namespace std;

int main(){int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int sum=0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i<j)
		
		sum += matrix[i][j];	
		}}
		cout<<"Sum of Uper Trangle  is:  "<<sum<<endl;
	}  
	
// Sum of Two Matrix

#include<iostream>
using namespace std;

int main(){
       
	   
	   int matrixA[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	   int matrixB[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int matrixC[3][3];
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
		
		matrixC[i][j]= matrixA[i][j] + matrixB[i][j];	

		cout<<matrixC[i][j]<<"   ";
	}cout<<endl;}
}

//Sum of Lower Digonal of matrix

#include<iostream>
using namespace std;

int main(){int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int transposematrix[3][3];
		cout<<"Transpose of matrix is:  "<<endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
		
		
		transposematrix[i][j]= matrix[j][i];	
		
		
		cout<< transposematrix[i][j];
	}
	cout<<endl;
	}}

	
//Matrix Multiplication	
	
	
 #include<iostream>
 using namespace std;
 
 int main(){
 	
 	int A[2][2]={{1,2},
	 {3,4}};
 	int B[2][2]={{5,6},
	 {7,8}};
 	
 	int C[2][2];
 	for(int i=0; i<2; i++){
 		for(int j=0; j<2; j++){
		C[i][j]=0;
 			for(int k=0; k<2; k++){
 				
 				C[i][j] += A[i][k]*B[k][j];
 		}}}
 			for(int i=0; i<2; i++){
			 
			 for(int j=0; j<2; j++)	{
			 cout<< C[i][j]<<"  ";
		}
		cout<<endl;
		 }
}  



// Matrix Multiplication


#include<iostream>
using namespace std;

  
int main() {
    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int B[3][2] = {
        {1, 2},
        {4, 5},
        {6, 7}
    };

    int C[2][2];  // result is 2×2

    for(int i = 0; i < 2; i++) {          // rows of A
        for(int j = 0; j < 2; j++) {      // columns of B
            C[i][j] = 0;
            for(int k = 0; k < 3; k++) {  // A columns = B rows
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Result Matrix:\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}   

// Transpose of Matrix

# include<iostream>
using namespace std;

int main(){
	
	int matrixA[2][3] ={{1,2,3},{4,5,6}};
	int matrixB[3][2];
	
	
	    
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++)
		{
	    
			
			matrixB[j][i]=matrixA[i][j];
			
		}}
		for(int i=0; i<3; i++){
			for(int j=0; j<2; j++){
				 cout <<matrixB[i][j]<<"  ";
			}
			cout<<endl;
		}
		return 0;
}
