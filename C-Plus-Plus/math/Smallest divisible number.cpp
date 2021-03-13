/*Given a number n find the smallest number evenly divisible by each number 1 to n.

##Example :

Input : n = 4
Output : 12
Explanation : 12 is the smallest numbers divisible
              by all numbers from 1 to 4

Input : n = 10
Output : 2520

Input :  n = 20
Output : 232792560


##Approach:

If you observe carefully the ans must be the LCM of the numbers 1 to n.
To find LCM of numbers from 1 to n –

1.Initialize ans = 1.
2. Iterate over all the numbers from i = 1 to i = n.
At the i’th iteration ans = LCM(1, 2, …….., i). This can be done easily as LCM(1, 2, …., i) = LCM(ans, i).
Thus at i’th iteration we just have to do –
ans = LCM(ans, i) 
         = ans * i / gcd(ans, i) [Using the below property,
                                 a*b = gcd(a,b) * lcm(a,b)]

*/

#include<bits/stdc++.h> 
using namespace std; 

// Function returns the lcm of first n numbers 
long long lcm(long long n) 
{ 
	long long ans = 1;	 
	for (long long i = 1; i <= n; i++) 
		ans = (ans * i)/(__gcd(ans, i)); 
	return ans; 
} 

// Driver program to test the above function 
int main() 
{ 
	long long n = 20; 
	cout << lcm(n); 
	return 0; 
} 

