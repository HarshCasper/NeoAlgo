/*

Problem:
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

Input Format:
The first line consists of an integer T which denotes the number of test cases.
For each test case we enter two strings to be merged alternatively

Output Format:
For each test case we get a alternatively merged string.

Explanation:
First we alternatively add both the strings to the resultant string till the length of the smallest string (both strings can also be equal length). 
After that we add the substring of the remaining longer string to resultant string if the length of both strings are not equal.

*/

#include<bits/stdc++.h>
using namespace std;

/* A function that will take 2 string as input and return the resultant merged string formed alternatively from the inputted strings */
string mergeAlternately(string word1, string word2) {
    string ans="";

    /* A variable that will take the size of the smallest string among word1 and word2 */
    int less=min(word1.length(),word2.length());    
    int i=0,j=0; 

    /* Loop to alternatively add word by word from each string to resultant string */
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

    /* If both strings are of unequal sizes then add the rest of substring to the resultant string */
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

/*

Time complexity: O(N) where N is the length of the longest string.
Space complexity: O(M) where M is the summation of length of both strings.

Sample input:
2
abc pqr
abcd pq

Sample Output:
apbqcr
apbqcd

*/
