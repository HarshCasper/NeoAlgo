//Swap Even and Odd Bits

//Time Complexity: O(1)
//Space Complexity: O(1)


/*Sample Input:
Example 1:- 
Enter number
50
Example 2:-
Enter number
994

Sample Output:
Example 1:- 
49
Example 2:-
997
*/
#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	unsigned int x ;
	cout<<"Enter number \n";
	cin>>x;

	// Get all even bits of x 
	unsigned int even_bits = x & 0xAAAAAAAA; 
       // cout<<even_bits<<"\n";
	// Get all odd bits of x 
	unsigned int odd_bits = x & 0x55555555; 
         // cout<<odd_bits<<"\n";
	even_bits >>= 1; // Right shift even bits 
	odd_bits <<= 1; // Left shift odd bits 

	cout<< (even_bits | odd_bits); // Combine even and odd bits 

} 

