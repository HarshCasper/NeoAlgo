/*Problem Statement:
SuperComputer Inc. have built a super-fast computer server consisting of N hyper-scalar lightning-fast processors 
Beta 007. These processors are numbered from 1 to N and are used to process independent jobs.
Every new incoming job is assigned to an arbitrary processor. 
Sometimes, a processor may be assigned too many jobs while other processors have a relatively light load 
(or even wait idly). 
In that case, the whole system undergoes rebalancing.
Rebalancing proceeds in rounds. In each round, every processor can transfer at most one job to each of its neighbors 
on the bus. 
Neighbors of the processor i are the processors i-1 and i+1 (processors 1 and N have only one neighbor each, 
2 and N-1 respectively). 
The goal of rebalancing is to achieve that all processors have the same number of jobs.
Given the number of jobs initially assigned to each processor, 
you are asked to determine the minimal number of rounds needed to achieve the state when every processor has the 
same number of jobs, or to determine that such rebalancing is not possible. */

#include <bits/stdc++.h>
using namespace std;

int balanceLoad(int n,int arr[],int load,int max_load,int diff)
{
		load=load/n;
		diff=0;
		for(int i=0;i<n;i++)
		{
			diff+=(arr[i]-load);
			int ans=max(diff,-diff);
			max_load=max(max_load,ans);
		}
	return max_load;
}
int main()
{
	int arr[9000];
	int n,i,val,diff;
	int max_load=0,load=0;
	cout<<"Enter the number of processors: "<<endl;
	cin>>n;
	cout<<"Enter the jobs: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		load+=arr[i];
	}
	if(load%n!=0)
	{
		cout<<"-1"<<endl;
	}
	cout<<"minimal number of rounds: "<<balanceLoad(n,arr,load,max_load,diff)<<endl;
	return 0;
}
/*Example:
Input:-
Enter the number of processors:
3
Enter the jobs:
0 99 3
Output:-
minimal number of rounds: 34
Time Complexity: O(n)
Space Complexity: O(n)
*/

