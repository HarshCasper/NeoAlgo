/*  Introduction 
    Given Two Strings s1 and s2, determine if they are isomorphic 
    Two strings s1 and s2 are isomorphic if the characters in s1 can be replaced to get s2.
    All occurrences of a character must be replaced with another character while preserving the order of characters.
    No two characters may map to the same character, but a character may map to itself.The Length of the 2 strings will be equal.
*/

/* Code/Solution */
#include<bits/stdc++.h>
using namespace std;

// checks whether 2 strings are Isomorphic 
bool isIsomorphic(string s1, string s2){
	unordered_map<char,char>mp;
	unordered_set<int>s;
	for(int i=0;i<s1.length();i++){
		
	//Check if the character is present in the map
	
		// Case-1 If the char is found
		if(mp.find(s1[i])!=mp.end()){
			/*if the element is not mapped to the previously mapped character */
			if(mp[s1[i]]!=s2[i])
			return false; //The Strings cannot be isomorphic
		}
		//Case-2 If the Char of First String is not present in the map ans the char of Second string is not present in the set
		if(mp.find(s1[i])==mp.end() && s.find(s2[i])==s.end()){
			//Insert into map
			mp[s1[i]]=s2[i];
			//Insert into set
			s.insert(s2[i]);
		}
		//If the char is mapped to someother element so duplicates cannot occur
		else if(mp.find(s1[i])==mp.end() && s.find(s2[i])!=s.end())
		return false; 
		}
	   return true;	
	}

// Driver Code
int main(){
	cout<<"Enter the Strings to check Isomorphism:"<<endl;
	cout<<"Enter the first String :";
	string s1,s2;
	cin>>s1;
	cout<<"Enter the Second String :";
	cin>>s2;
	
	//result stores boolean value returned by isIsomorphic Function
	bool result=isIsomorphic(s1,s2);
	if(result==true)
	cout<<"The given Strings are Isomorphic"<<endl;
	else
	cout<<"The given strings are not Isomorphic"<<endl;
	return 0;
}

/*

  Sample Test Case 1:
  Input:Enter the Strings to check Isomorphism:
        Enter the first String :egg
        Enter the Second String :add
         
  Output:The given Strings are Isomorphic
  
  Sample Test Case 2:
  Input:Enter the Strings to check Isomorphism:
        Enter the first String :foo
        Enter the Second String :bar
         
  Output1:The given strings are not Isomorphic
  
  Time/Space Complexity
  Time Complexity :  O(n)  
   where n is the length of string
  Space Complexity : O(n)
  
*/
