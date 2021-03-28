#include<bits/stdc++.h>
using namespace std;

//return idx of the first occurance of s2 in s1
//if not found return -1
int strstr(string s1,string s2){

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