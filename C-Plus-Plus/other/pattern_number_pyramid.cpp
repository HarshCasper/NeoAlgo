/*
Print pyramid depending on the input:
If input is 5, then
Code to print the pattern
        1
      2 3 2
    3 4 5 4 3
  4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x=i;
        for(int j=i;j<n;j++)
        cout<<"  ";
        for(int k=0;k<i;k++)
        {
            cout<<x++<<" ";
        }
        for(int k=1;k<i;k++)
        {
            cout<<x-k-1<<" ";
        }
        cout<<"\n";
    }
}
/*
Time Complexity: O(n^2)
Input: n=3
Output:
    1 
  2 3 2 
3 4 5 4 3 
*/
