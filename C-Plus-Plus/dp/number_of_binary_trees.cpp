/* This program finds the number of binary trees given the length of the preorder sequence = n.
    A tree is an acyclic graph . A binary tree is a tree where each node has 0, 1 or 2 children. 
    Preorder traversal means traversing a tree in the following order : Root - Left child - Right child.  
    
    We use the dynamic programming approach where our root is fixed and the rest of the n-1 nodes
        are split as left and right children. Hence, we calculate the number of binary trees possible
        while exploring splits varying from 0 to n-1.
    
    Time Complexity - O(n^2)
    Space Complexity - O(n)
    
    Note:- The approach is similar to finding the nth catalan number.
    */

#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli PossibleBinaryTrees(int n)
{
    lli *Dp=(lli *)malloc((n+1)*sizeof(lli));
    
    Dp[0]=1,Dp[1]=1;                        //Since number of trees that can be formed for n=0/1 is 1
    
    for(int i=2;i<=n;i++)                   //Calculating possible number of binary trees for all i<=n and storing them for future use-Tabulation Method
    {
        Dp[i]=0;
        for(int j=0;j<i;j++)                //We loop over the possible splits from 0 to i-1
        {
            Dp[i]+=(Dp[j]*Dp[i-j-1]);
        }
    }
    
    lli ans=Dp[n];
    
    free(Dp);
    
    return ans;
}

int main()                                  //Driver function
{
    int n;                                  //Enter length of preorder sequence
    cin>>n;
    cout<<PossibleBinaryTrees(n)<<endl;
    return 0;
}
/* Sample input:-
        n = 5;
        Output = 42;
        */
