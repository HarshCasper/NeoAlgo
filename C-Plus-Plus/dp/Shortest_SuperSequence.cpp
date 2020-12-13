
#include<bits/stdc++.h>
using namespace std;
int longestCommon(string text1, string text2,int n,int m){
        int dp[n+1][m+1];int i,j;
        for( i=0;i<=n;i++){
            for(j=0;j<=m;j++)
        {
        if(i==0||j==0)//if any of the string is 0 then put dp[i][j]=0;
        dp[i][j]=0; 
        else if(text1[i-1]==text2[j-1]) //else compare and put 1+dp[i-1][j-1]
            dp[i][j]=1+dp[i-1][j-1];
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//else take maximum
            }
        }
        return n+m-dp[n][m];//length of both strings - lcs(string1,string2)
    }
int main() {
	int t;
    cout<<"Enter the testcase";
	cin>>t;
	while(t--){
	    
	    string text1,text2;
        cout<<"Enter both the strings";
	    cin>>text1>>text2;
	    int n=text1.length();
	    int m=text2.length();
	    cout<<longestCommon(text1,text2,n,m);
	    cout<<endl;
	}
	return 0;
}
/*
Input: text1=ABCD text2=EFGH
OUTPUT:8
Time Complexity: O(n*m);
Space Complexity:O(n*m);
*/