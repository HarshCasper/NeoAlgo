/*Given an array, print the Next Greater Element for every element.The Next greater Element
 for an element x is the first greater element on the right side of x in array. 
Elements for which no greater element exist, consider next greater element as -1.*/
	
// A Stack based C++ program to find next 
#include <bits/stdc++.h> 
using namespace std; 

/* function to print the pair */
void funcnew(int arr[], int n) { 
stack < int > s; 

// push the first element to stack
s.push(arr[0]); 

// iterate for rest of the elements 
for (int i = 1; i < n; i++) { 

	if (s.empty()) { 
	s.push(arr[i]); 
	continue; 
	} 

	/*if our stack is not empty and stack top element is less than array element 
     then print it and pop the stack element untill it is smaller*/
	
	while (s.empty() == false && s.top() < arr[i]) 
	{		 
		cout << s.top() << " -- " << arr[i] << endl; 
		s.pop(); 
	} 

	/* pushing array element to the stack*/
	s.push(arr[i]); 
} 

/* if iteration is complete there is no greater element then print -1 there*/
while (s.empty() == false) { 
	cout << s.top() << " -- " << -1 << endl; 
	s.pop(); 
} 
} 

/* Main function */
int main() { 
int n=5;
int arr[] = {6, 8, 0, 1, 3};  
funcnew(arr, n); 
return 0; 
}

/*
Output-
6 -- 8
0 -- 1
1 -- 3
3 -- -1
8 -- -1

Time Complexity - O(n)
Space  Complexity -O(n)

*/
