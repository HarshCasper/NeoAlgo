/*Problem Statement:
There are n white and n black dots equally spaced in a line
You want to connect each white dot with some one black dot,
with a minimum total length of the wire.
Find the total length needed. */

#include<bits/stdc++.h>
using namespace std;

int connectDots(int a1[],int a2[],int white,int black)
{
    int ans=0;
    sort(a1,a1+white);
    sort(a2,a2+black);
    for(int i=0;i<white;i++)
    {
        int temp=abs(a1[i]-a2[i]);
        ans+=temp;
    }
    return ans;
}

int main()
{
    int white,black;
    cout<<"Enter total number of white and black dots: "<<endl;
    cin>>white>>black;
    int a1[100],a2[100];
    for(int i=0;i<white;i++)
    {
        cin>>a1[i];
    }
    for(int j=0;j<black;j++)
    {
        cin>>a2[j];
    }
    cout<<"Total length needed is: "<<connectDots(a1,a2,white,black)<<endl;
    return 0;
}
/*
Example: 

Input:-
Enter total number of white and black dots:
3 3
3 4 1
2 5 6

Output:-
Total length needed is: 5

Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

