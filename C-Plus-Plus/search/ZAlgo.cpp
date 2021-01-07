/*
Z algorithm is a linear time string matching algorithm which runs in O(n) complexity. 
It is used to find all occurrence of a pattern P in a string S, 
which is common string searching problem. 
*/ 
#include<bits/stdc++.h> 
using namespace std; 

void ZAlgo(string str, int Z[]); 

// prints all occurrences of pattern in text using Z algo 
void PatternSearch(string text, string pattern) 
{ 
	// Creation of concatenated string  
	string concat = pattern + "$" + text; 
	int length = concat.length(); 

	// Creation of Z array 
	int Z[length]; 
	ZAlgo(concat, Z); 

	//iteration through Z array for matching 
	for (int i = 0; i < length; ++i) 
	{ 
		// if Z[i] (matched region) is equal to pattern 
		if (Z[i] == pattern.length()) 
			cout << "Pattern found at index "
				<< i - pattern.length() -1 << endl; 
	} 
} 


void ZAlgo(string str, int Z[]) 
{ 
	int n = str.length(); 
	int left, right, k; 
 
	left = right = 0; 
	for (int i = 1; i < n; ++i) 
	{  
		if (i > right) 
		{ 
			left = right = i; 
			while (right<n && str[right-left] == str[right]) 
				right++; 
			Z[i] = right-left; 
			right--; 
		} 
		else
		{ 
			k = i-left; 

			if (Z[k] < right-i+1) 
				Z[i] = Z[k]; 

			else
			{ 
				left = i; 
				while (right<n && str[right-left] == str[right]) 
					right++; 
				Z[i] = right-left; 
				right--; 
			} 
		} 
	} 
} 

// Driver program 
int main() 
{ 
	string S = "GITHUB"; 
	string P = "HUB"; 
	PatternSearch(S, P); 
	return 0; 
} 
