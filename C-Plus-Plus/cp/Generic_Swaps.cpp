/* This programm is used to swap any data type 
   that is a number or a character and etc.
   It is make our code efficient and workful. */

#include <iostream>
using namespace std;

// This is a function template
// Calling the function by reference
template <class X> void swap(X *a,X *b)
{
	X temp;
	 temp = *a;
	 *a = *b;
	 *b = temp;
}

int main(){
	
	int n,m;
	   cout<<"\n Enter two Integer :";
	   cin >> n >> m;
	
	char a,b;
	  cout<<"\n Enter two Charcter :";
	  cin >> a >> b;
	
	swap(&n,&m);  //calling function to swap integer
	swap(&a,&b); // calling function to  swap char
	
	cout<<"\n Swapped n,m :"<< n <<" "<< m << endl;
        cout<<"\n Swapped a,b :"<< a <<" "<< b << endl;	
    
    return 0;
}
/*
Time-Complexity = O(N)
Space-Complexity = O(N)
*/

/*
Input:
1 2 or a b
Output:
2 1 or b a
*/



