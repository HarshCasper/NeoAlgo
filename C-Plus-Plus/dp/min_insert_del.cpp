//This code computes the total number of insertions and deletions to convert string x into y
/** CONCEPT
   To convert x to y, we find out the length of the longest common subsequence and then find out the difference between the length of the first string and the longest common subsequence to find out the number of deletions.
   To find out the number of insertions we find out the difference between the length of the second string and the longest common subsequence
**/
#include<bits/stdc++.h>
using namespace std;

void minInsertDel(string x,string y,int n,int m)
{
    //Table
    int t[n+1][m+1];
    
    //Base conditions
    //For calculating the longest common subsequence
    //If the length of any one of the string is zero, then the length of common subsequence will be zero
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
            t[i][j]=0;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1]==y[j-1])
            t[i][j]=1+t[i-1][j-1];
            else 
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    
    //Displaying the minimum number of insertions and deletions
    cout<<"Minimum insertions="<<m-t[n][m]<<"\nMinimum deletions="<<n-t[n][m]<<"\n";

}


//Driver Code
int main()
{
    string x,y;
    cin>>x>>y;
    //Calculating the length of the string x and y
    int n=x.length();
    int m=y.length();
    minInsertDel(x,y,n,m);
}