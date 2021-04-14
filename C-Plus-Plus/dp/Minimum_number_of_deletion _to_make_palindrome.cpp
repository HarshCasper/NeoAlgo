/*
 This problem will be solved using dp.
 We will be given one strings and we have to print the
 Minimum number of deletion in a string to make it a palindrome.
*/

#include <bits/stdc++.h>
using namespace std;
int t[1001][1001];

int longestSubsequence(string X,string Y,int m,int n){
    // if length of any string is 0 then we cannot find common string
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0)
            t[i][j] = 0;
        }
    }

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            //if letters of both string are equal then we will decrease row and column both by 1
            if(X[i-1] == Y[j-1]){
                t[i][j] = t[i-1][j-1] + 1;
            }
            //if letters of both string are not equal then first we will decrease row by 1 and then column by 1 and find maximum value b/w two
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    
    return m - t[m][n];
}

int main() {
    string X;
    cin>>X;
    string Y = X;
    reverse(Y.begin(),Y.end());
    int m = X.length();
    int n = Y.length();
    //memset(t,-1,sizeof(t));
    cout<<longestSubsequence(X,Y,m,n);
    return 0;
}
/*
Input - 
Enter string X
bbbab
Output -  
Minimum number of deletion in a string to make it a palindrome
4
Time Complexity - O(m*n)
Space Complexity - O(m*n)
*/
