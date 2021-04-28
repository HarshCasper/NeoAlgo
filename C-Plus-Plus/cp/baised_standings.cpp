/*Problem Statement: 
Usually, results of competitions are based on the scores of participants. 
However, we are planning a change for the next year of IPSC. 
During the registration each team will be able to enter a single positive integer : 
their preferred place in the ranklist. We would take all these preferences into account, 
and at the end of the competition we will simply announce a ranklist that would please all of you.
But wait... How would that ranklist look like if it won't be possible to satisfy all the requests?
Suppose that we already have a ranklist. 
For each team, compute the distance between their preferred place and their place in the ranklist. 
The sum of these distances will be called the badness of this ranklist. */

#include<bits/stdc++.h>
using namespace std;

int SumDistances(int n,int arr[],int rank)
{
    int sum=0;
    int actual_rank=1;
    for(int i=1;i<=n;i++)
    {
        while(arr[i])
        {
            sum+=abs(actual_rank-i);
            arr[i]--;
            actual_rank++;
        }
    }
    return sum;
}

int main()
{
    int n,rank,arr[1000]={0};
    string name;
    cout<<"Enter the number of teams participating: "<<endl;
    cin>>n;
    cout<<"Enter the team names and preffered place respectively: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>name>>rank;
        arr[rank]++;
    }
    cout<<"The badness of the best ranklist: "<<SumDistances(n,arr,rank)<<endl;
    return 0;
}
/*
Example:
Input:-
Enter the number of teams participating:
7
Enter the team names and preffered place respectively:
noobz 1
llamas 2
winn3rz 2
5thwheel 1
notoricoders 5
strangecase 7
whoknows 2

Output:-
The badness of the best ranklist: 5

Time Complexity: O(n)
Space Complexity: O(n)
*/

