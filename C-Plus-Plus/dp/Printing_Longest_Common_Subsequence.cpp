/*
 This problem will be solved using dp.
 We will be given two strings and we have to find the longest
 common string b/w two and will have to print it's subsequence.
*/

#include <bits/stdc++.h>
using namespace std;
int t[1001][1001];

string longestSubsequence(string X,string Y,int m,int n){
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
    
    int i=m,j=n;
    string result;
    /*
     We will start from last cell of the matrix and will check
     if character od X and Y are equal then we will add character to the the element and will decrease both row and column by 1
     else we will check which cell has greater value if by decreasing row is greater we will decrease row by 1 else will decrease column by 1
     */
    while(i>0 && j>0){
        if(X[i-1] == Y[j-1]){
            result += X[i-1];
            i--;
            j--;
        }
        else{
        if(t[i-1][j] > t[i][j-1]){
            i--;
        }
        else{
            j--;
        }
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string X,Y;
    cin>>X>>Y;
    int m = X.length();
    int n = Y.length();
    //memset(t,-1,sizeof(t));
    cout<<longestSubsequence(X,Y,m,n);
    return 0;
}
/*
Input -
Enter string X and string Y -
abcdaf
aebcf
Output -
Longest Common Subsequence -
abcf
Time Complexity - O(m*n)
Space Complexity - O(m*n)
*/
