/** 
Problem:
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

Input Format:
The first line consists of an integer T which denotes the number of test cases.
For each test case we enter two strings to be merged alternatively

Output Format:
For each test case we get a alternatively merged string.

Sample input:
2
abc pqr
abcd pq

Sample Output:
apbqcr
apbqcd

Explanation:
First we alternatively add both the strings to the resultant string till the length of the smallest string (both strings can also be equal length). 
After that we add the substring of the remaining longer string to resultant string if the length of both strings are not equal.
**/

#include<bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string ans="";
    int less=min(word1.length(),word2.length()),i=0,j=0;
    while(i<less || j<less){
        if(j>=i){
            ans+=word1[i];
            i++;
        }
        else{
            ans+=word2[j];
            j++;
        }
    }
    if(word1.length()!=word2.length()){
        if(word1.length()>less){
            ans+=word1.substr(less,word1.length());
        }
        else{
            ans+=word2.substr(less,word2.length());
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string word1,word2;
        cin>>word1>>word2;
        cout<<mergeAlternately(word1,word2)<<endl;
    }
}