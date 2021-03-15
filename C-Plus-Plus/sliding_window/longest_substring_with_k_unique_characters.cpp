/*
 Problem Statement:-
 A string is given.We need to print the size of longest possible substring that has exactly k unique characters.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	//taking input from user
	string s;
	int k;
	cin>>s;
	cin>>k;
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
		//store frequency of element int each window
		mp[s[j]]++;
		//unique elements less than required
		if(mp.size()<k)
			//increment j
			j++;
		//if unique element equals to required 
		//we need to check if on increasing the window size whether repetitbe element is present or not
		//i.e whether size of map reamains same or not
		//increment j untill size of map is same
		else if(mp.size()==k)
		{
			ans=max(ans,j-i+1);
			j++;
		}
		//size of map greater than required
		else if(mp.size()>k)
		{	
			while(mp.size()>k)
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
Input Format:
string
k

Output Format:
size of longest substring

Test case:
Input 1:
aabcbcbcbd
3

Output 1:
9

Input 2:
perepeereyjjjjj
3

Output 2:
9

Time complexity: O(n*k)
Space complexity:O(n)

	
*/