// Karatsuba algorithm for bit string multiplication.
//Time Complexity: O(n^1.59)

#include<bits/stdc++.h>
using namespace std; 

int makeEqualLength(string &str1, string &str2) 
{ 
	int len1 = str1.size(); 
	int len2 = str2.size(); 
	if (len1 < len2) 
	{ 
		for (int i = 0 ; i < len2 - len1 ; i++) 
			str1 = '0' + str1; 
		return len2; 
	} 
	else if (len1 > len2) 
	{ 
		for (int i = 0 ; i < len1 - len2 ; i++) 
			str2 = '0' + str2; 
	} 
	return len1; // If len1 >= len2 
} 

//Function that adds two bit sequences and returns the addition 
string addBitStrings( string first, string second ) 
{ 
	string result; 

	// make the lengths same before adding 
	int length = makeEqualLength(first, second); 
	int carry = 0; // Initialize carry 

	// Add all bits one by one 
	for (int i = length-1 ; i >= 0 ; i--) 
	{ 
		int firstBit = first.at(i) - '0'; 
		int secondBit = second.at(i) - '0'; 

		int sum = (firstBit ^ secondBit ^ carry)+'0'; 

		result = (char)sum + result; 
 
		carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry); 
	} 

	// if overflow, then add a leading 1 
	if (carry) result = '1' + result; 

	return result; 
} 

//function to multiply single bits of strings a and b 
int multiplyiSingleBit(string a, string b) 
{ return (a[0] - '0')*(b[0] - '0'); } 

// The main function that multiplies two bit strings X and Y 
long int multiply(string X, string Y) 
{ 
	// Find the maximum of lengths of x and Y and make length 
	// of smaller string same as that of larger string 
	int n = makeEqualLength(X, Y); 

	if (n == 0) return 0; 
	if (n == 1) return multiplyiSingleBit(X, Y); 

	int fh = n/2; // First half of string, floor(n/2) 
	int sh = (n-fh); // Second half of string, ceil(n/2) 

	// Find the first half and second half of first string. 
	string Xl = X.substr(0, fh); 
	string Xr = X.substr(fh, sh); 

	// Find the first half and second half of second string 
	string Yl = Y.substr(0, fh); 
	string Yr = Y.substr(fh, sh); 

	// Recursively calculate the three products of inputs of size n/2 
	long int P1 = multiply(Xl, Yl); 
	long int P2 = multiply(Xr, Yr); 
	long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr)); 

	// Combine the three products to get the final result. 
	return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2; 
} 

int main() 
{ 
	string s1,s2;
	cin>>s1>>s2;
	int ans=multiply(s1,s2);
	cout<<ans<<endl; 
	
} 

/*
Sample input: 1100 1010 
Sample ouptut: 120  
*/