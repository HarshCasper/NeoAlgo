/*
Given an integer n, return true if it is a power of four.Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4^x.
A number is power of 4 if only single binary bit is set and the count of zero bits before the set bit is even. 
*/
#include<bits/stdc++.h>
using namespace std;

/* Function to check whether the number is power of 4 or not */
bool isPowerOfFour(int n){
	
	int count=0; //variable to count number of 0 bits before set bit
	
/* To check if only single bit is set  */
	if(n && !(n&(n-1))){
		
		/* to count 0 bits before the set bit */
		while(n>1)
		{
			n>>=1; // shifting one bit right and assigning to itself
			count++;
		}
		if(count % 2 == 0)
		return true;
		
/*  If count of 0 bits is odd */
		return false;
	}
	return false;
}

/* Drivers Code   */
int main() {
	int n;
	cout<<"Enter the Number which is to found power of 4 or not: ";
	cin>>n;
	
	if(isPowerOfFour(n))
	cout<<n<<" is a power of 4"<<endl;
	else
	cout<<n<<" is not a power of 4"<<endl;
	return 0;
}

/*

 Input: Enter the Number which is to found power of 4 or not: 64
 Output: 64 is a power of 4
 
 Input: Enter the Number which is to found power of 4 or not: 8
 Output: 8 is not a power of 4
 
 TIME COMPLEXITY -->  O(log n), where n is the size of binary number
 SPACE COMPLEXITY --> O (1) 
 
*/
