/**
 * PROBLEM STATEMENT 
 * Finding the maximum value of the items that can be popacked into the knapsack if it is possible to take one item multiple times
 * DYNAMIC PROGRAMMING
 * Time Complexity O(n^2)
 * EXAMPLE
 * INPUT 
 * W=10
 * n=5
 * w[n] = 2 4 6 7 8
 * v[n] = 10 20 30 40 100
 * OUTPUT- 100
 * 
 * */

#include<bits/stdc++.h>
using namespace std;

int unboundedKnap(int w[],int v[],int W,int n)
{
    //table
    int t[n+1][W+1];

    //Base conditions
    //If the number of items in the knapsack is zero, then the value of the items taht can be packed is zero
    //If the weight of the knapsack is zero, then the value of the items taht can be packed into the knapsack will be zero too
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0)
            t[i][j]=0;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(w[i-1]<=j)
            t[i][j]=max(v[i-1]+t[i][j-w[i-1]],t[i-1][j]);
            if(w[i-1]>j)
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][W];
}
int main()
{
    int W;
    cin>>W;
    int n;
    cin>>n;
    int v[n],w[n];
    for(int i=0;i<n;i++)
    cin>>w[i]>>v[i];
    cout<<unboundedKnap(w,v,W,n)<<"\n";
}