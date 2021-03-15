/*
 Problem Statement:-
 A string s is given, Find the longest substring without repeating characters.

  No repetition means all unique characters
  therefore we need to find longest substring with all unique characters 
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	//taking input from user
	string s;
	
	cin>>s;
	
	//two pinters are nedded of which one points to start of window and other to the end of windoe
	int i=0,j=0;
	//size of string
	int n=s.length();

	//map for keeping count of unique character
	map<char,int>mp;
	//size of map shows number of unique character
	//initializing answer variable with 0
	int ans=0;
	//iterate through the string until it  reaches to the end
	while(j<n){
		//store frequency of element in each window
		mp[s[j]]++;
		//size of map cannot be greater than window size that's why that case is excluded
		//size of map equals window size
		//we need to check if on increasing the window size whether repetitve element is present or not
		//i.e whether size of map reamains same or not
		//increment j untill size of map is same
		 if(mp.size()==j-i+1)
		{
			ans=max(ans,j-i+1);
			j++;
		}
		//size of map greater than window size
		else if(mp.size()<j-i+1)
		{	
			while(mp.size()<j-i+1)
			{	//remove s[i] from map therefore decreasing it's frequency
				mp[s[i]]--;
				//if frequency of element equals zero,we need to remove it from map	
				if(mp[s[i]]==0)
					mp.erase(s[i]);
				//increment start pointer
				i++;	
			}
			//move forward
			j++;

		}


	}
	cout<<ans<<endl;
}


/*
	Input format:
	string

	Output format:
	length of longest substing with unique characters

	Test case:
	Input:
	xzvxzzvxxx

	Output:
	3

	Time complexity:O(n^2)
	Space complexity:O(n)
*/