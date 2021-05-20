/*
A pair of two consecutive members u and v on a line is considered average integer pair 
if their average is an integer,
i.e. (u+v)/2 is an integer. 
Given an array, arrange the elements, 
such that number of consecutive average integer pairs is maximised.
*/

#include<bits/stdc++.h>
using namespace std;

//Function to reorder elements such that number of consecutive average integer pairs is maximised.
void Maximum_consecutive_avgint_pair(int n, int arr[]) {
    
    int odd=0, even=0;
    //Count the no of even and odd nos in the array
    for( int i=0; i<n ; i++){
	    if( arr[i] % 2 != 0){
	        odd++;
	    }
	    else{
	        even++;
	    }
    }
   /*If the no of odd is greater than no of even print 
   the odd nos first followed by the even nos*/
	if( odd > even){
    	for( int i=0; i<n ; i++){
    	     if( arr[i] % 2 != 0){
    	         cout << arr[i] << " ";
    	     }
    	 }
    	for( int i=0; i<n ; i++){
    	     if( arr[i] % 2 == 0){
    	         cout << arr[i] << " ";
    	     }
    	 }	 
	}
   /*If the no of even is greater than no of odd print 
   the even nos first followed by the odd nos*/
	else{
	    for( int i=0; i<n ;i++){
    	     if( arr[i] % 2 == 0){
    	         cout << arr[i] << " ";
    	     }
    	 }
    	for( int i=0; i<n ;i++){
    	     if( arr[i] % 2 != 0){
    	         cout << arr[i] << " ";
    	     }
    	 }	 
	}

}

int main() {
	int  n;
	cout << "Enter the no of elements in array:" <<endl;
	cin >> n;
	int arr[n];
	cout << "Enter the elements in array:" <<endl;
	for( int i=0; i<n ;i++){
	    cin >> arr[i];
	}
	cout << "The reordered array is: "<<endl;
	Maximum_consecutive_avgint_pair(n, arr);
	return 0;
}

/*
Sample Input/Output:

Input:
Enter the no of elements in array:
8
Enter the elements in array:
10 9 13 15 3 16 9 13
Output:
The reordered array is: 
9 13 15 3 9 13 10 16 

Time complexity:-O(n) to compute odd and even numbers
Space complexity:- O(n)
*/
