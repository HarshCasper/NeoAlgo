#include<bits/stdc++.h>
using namespace std;

//Using dp approach
int longestCommon(string text1, string text2,int n,int m){
        int dp[n+1][m+1];int i,j;

        for( i=0;i<=n;i++){
            for(j=0;j<=m;j++)
        {
        if(i==0||j==0)//if any of the string is not present mmake dp[i][j]=0;
        dp[i][j]=0; 
        else if(text1[i-1]==text2[j-1]) //else compare both the strings if they are equal then add 1 at the dp[i][j]
            dp[i][j]=1+dp[i-1][j-1];
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//else take maximum out of the two option
            }
        }
        return n+m-dp[n][m];//length of 1st string+2nd string -lcs(text1,text2) 
    }
int main() {
	int t;
	cin>>t;
	while(t--){
	    
	    string text1,text2;
        cout <<"Enter first string: ";
        cout <<"Enter Second string: ";

	    cin>>text1>>text2;
	    int n=text1.length();
	    int m=text2.length();
	    cout<<longestCommon(text1,text2,n,m);
	    cout<<endl;
	}
	return 0;
}
/*
Input: Text1 = abcd, text2 = xycd
Output: 6
Time Complexity: O(n*m);
Space Complexity:O(n*m);
*/
