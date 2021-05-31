/*Problem Statement: 
Two chopsticks in a pair of chopsticks need not be of the same length. 
A pair of sticks can be used to eat as long as the difference in their length is at most D. 
The Chef has N sticks in which the ith stick is L[i] units long. 
A stick can't be part of more than one pair of chopsticks. 
Help the Chef in pairing up the sticks to form the maximum number of usable pairs of chopsticks. */

#include<bits/stdc++.h>
using namespace std;

int pairs(vector<int> v,int diff,int total)
{
    int res=0;
    for(int i=0;i<total-1;)
    {
        if(v[i+1]-v[i]<=diff)
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
    int total,diff,len;
    vector<int> v;
    cout<<"Enter number of chopsticks and difference respectively: "<<endl;
    cin>>total>>diff;
    cout<<"Enter length: "<<endl;
    for(int i=0;i<total;i++)
    {
        cin>>len;
        v.push_back(len);
    }
    sort(v.begin(),v.end());
    cout<<"Maximum pairs of chopsticks: "<<pairs(v,diff,total)<<endl;
    return 0;
}

/*
Example:-

Input:-
Enter number of chopsticks and diffifference respectively:
5 2
Enter length:
1 3 3 9 4

Output:-
Maximum pairs of chopsticks: 2

Time Complexity: O(n)
Space Compplexity: O(n)
*/

