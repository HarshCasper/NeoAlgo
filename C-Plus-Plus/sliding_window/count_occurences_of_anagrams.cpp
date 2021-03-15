/*
Problem Statement:-
	Two strings s1 and s2 are given. Count the number of occurences of anagrams of s2 in s1.
	given size of s1 greater than size of s2
	
	Anagram:Word or phrase formed by rearrangement of letter in another word or phrase.
		-->	To generate anagrams, we can jumble it in any way
		-->	Number of letters before should be equal to number of letters after and their quantity is also same.
		--> only continuous can be chosen, discontinuous can't form anagrams.

	 Approach 1: Let us find all the anagrams of s2. Number of anagrams will be of order n factorial , So generating factorial will increase our time complexity.
	 			 So, we have to look for another approach.
	 Approach 2: (By sliding window) As we know , pattern comes in continuous manner and size of pattern always remains same.
	 			 Therefore window size (k) should be taken as same as that of size of s2 as we are maintaining the size of number of letters and quantity.

*/	

#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	//size of strings
	
	int n=s1.length();
	int k=s2.length();
	int ans=0;
	//defining map to store frequency of each elemt of s2
	map<char,int>mp;
	for(int i=0;i<k;i++)
		//storing frquency of each element
		mp[s2[i]]++;
	int count=mp.size();
	//initalizing two pointer i and j at start and end respectively
	int i=0,j=0;
	//iterate until end pointer of window reaches to and of string
	while(j<n){
			
			mp[s1[j]]--;
			//if occurence of any characeter reduces to zero then decrease count
		if(mp[s1[j]]==0)
			count--;
		//increase j until we hit the size of window
		if(j-i+1<k)
			j++;
		//on hitting size of window if countreaches 0 then its anagram
		//store it in ans
		else if(j-i+1==k)
		{if(count==0)
				ans++;
				//element present in map
			if(mp.find(s1[i])!=mp.end())
				//increase its count
                mp[s1[i]]++;
           
			//increase the count id element found again
			if(mp[s1[i]]==1)
				count++;
			//slide the window
			i++;
			j++;
		}
	


	}
	cout<<ans<<endl;
}

/*
	Input format:
	 s1
	 s2

	Output format:
	 no. of anagrams

	Test Cases:

	 Input 1: 
	 xforfxorffxdofrf
	 ffor

	 Output 1:
	 3

	 Explaination: forf orff ofrf are the possible anagrams of s2 which are present in s1
	 

	 Input 2:
	 aabaabaa
	 aaba

	 Output 2:
	 3

	 Explaination:
	 aaba abaa abaa are possible

	Time complexity: O(n)
	space complexity: O(k)
	k is size of pattern


*/
