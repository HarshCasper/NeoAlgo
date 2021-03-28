/* 
Implement strstr in C++.
Basically it takes two string as a input.Checks if first string has the occurance of second string.
If second string is present in first string, it will return the starting index of occurance.
else return -1
*/

#include<bits/stdc++.h>
using namespace std;

//return idx of the first occurance of s2 in s1
//if not found return -1
int strstr(string s1,string s2){

  //For every index of s1,checking if it is the starting index of s2
  for(int i=0;i<s1.size();i++)
  {
    int j;
    for(j=0;j<s2.size();j++)
    {
      if(s2[j]!=s1[i+j])break;
    }

    //Found
    if(j==s2.size())return i;
  }

  return -1;
}

int main(){

  //s2 to be searched in s1
  string s1,s2;
  cin>>s1>>s2;

  //Calling strstr function
  if(strstr(s1,s2)!=-1){
    cout<<"s2 found in s1 at index "<<strstr(s1,s2)<<endl;
  }
  else cout<<"Not Found"<<endl;

  return 0;
}

/*

Time Complexity: O(|s1|*|s2|)
Space Complexity: O(1)

Input1:
neoalgo abc

Output1:
Not Found 

Input2:
neoalgo algo

Output2:
s2 found in s1 at index 3

*/
