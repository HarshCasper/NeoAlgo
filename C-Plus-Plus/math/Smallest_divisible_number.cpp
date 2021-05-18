//Given a number n find the smallest number evenly divisible by each number 1 to n.

#include<bits/stdc++.h> 
using namespace std; 

// Function returns the gcd of first n numbers 
long long gcd(long long a,long long b )
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function returns the lcm of first n numbers 
long long lcm(long long n) 
{ 
	long long ans = 1;	 
	for (long long i = 1; i <= n; i++) 
		ans = (ans  *  i) /  (gcd(ans, i)); 
	return ans; 
} 
// Driver program to test the above function 
int main() 
{ 
	long long n;
	cout<< "Enter the number: ";
	cin>>n;             
	cout << lcm(n); 
	return 0; 
} 

/*
##Example :

1.Input : Enter the number: 4
  Output: 12

Explanation : 12 is the smallest numbers divisible by all numbers from 1 to 4

2.Input : Enter the number: 6
  Output: 60

##Time Complexity:O(nlogn)
##Space Complexity:O(1)								 

*/
