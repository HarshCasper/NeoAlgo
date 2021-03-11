// Longest Consecutive Run of 1s
/*
For given n, return the length of the longest consecutive run of 1s in its binary representation.
*/


#include<bits/stdc++.h> 
using namespace std;

int solve(int n) 
{
    int count=0;
    while(n!=0){
        n = n & (n<<1);
        count++;
    }
    return count;
}

int main()
{
    int n; 
    cin>>n;
    cout<<solve(n)<<endl;
}

/*
Input
    n = 156 (10011100)
Output
    3
*/