//Problem: Given a string, find the longest palindromic substring in it.
//Idea: To generate all odd and even length palindromes and keep track of longest pailindrome so far.
// This idea is also called as Expanding Around the Center.
//It is better than Dynamic Programming Approach in terms of Space complexity.
//Time Complexity: O(n^2)
//Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

string LongestPalinSubstr(string str){
	int maxLen=1;
	int start=0;
	int n=str.length();
	int low,high;

	for(int i=1;i<n;i++){

		//longest even palindrome.
		//center points of palindrome are i-1 and i.
		low=i-1;
		high=i;

		while(low>=0 && high<n && str[low]==str[high]){
			if(high-low+1>maxLen){
				start=low;
				maxLen=high-low+1;
			}
			low--;
			high++;
		}
		
		//longest odd palindrome.
		//center point of palindrome is i
		low=i-1;
		high=i+1;

		while(low>=0 && high<n && str[low]==str[high]){
			if(high-low+1>maxLen){
				start=low;
				maxLen=high-low+1;
			}
			low--;
			high++;
		}

	}
	return str.substr(start,maxLen);
}

int main(){
	string str;
	cin>>str;

	string LongestPalindrome=LongestPalinSubstr(str);
	cout<<LongestPalindrome<<endl;
}

/*Sample Input: babad
Sample Output: bab */