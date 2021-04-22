/*Problem Statement: 
Two chopsticks in a pair of chopsticks need not be of the same length. 
A pair of sticks can be used to eat as long as the difference in their length is at most D. 
The Chef has N sticks in which the ith stick is L[i] units long. 
A stick can't be part of more than one pair of chopsticks. 
Help the Chef in pairing up the sticks to form the maximum number of usable pairs of chopsticks. */

#include<bits/stdc++.h>
using namespace std;

int pairs(vector<int> v,int d,int n)
{
    int res=0;
    for(int i=0;i<n-1;)
    {
        if(v[i+1]-v[i]<=d)
        {
            res++;
            i+=2;
        }
        else
        {
            i++;
        }
    }
    return res;
}

int main()
{
    int n,d,a;
    vector<int> v;
    cout<<"Enter number of chopsticks and difference respectively: "<<endl;
    cin>>n>>d;
    cout<<"Enter length: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    cout<<"Maximum pairs of chopsticks: "<<pairs(v,d,n)<<endl;
    return 0;
}
/*
Example:-

Input:-
Enter number of chopsticks and difference respectively:
5 2
Enter length:
1 3 3 9 4

Output:-
Maximum pairs of chopsticks: 2

Time Complexity: O(n)
Space Compplexity: O(n)
*/

