// Query : Job Scheduling with Maximum Profit (using Recurssion)
/*
Task:
We are given X number of Jobs and their starting time, end time, and profit value of accomplishing them.
We have to find the maximum profit of any subset of them such that there is no overlapping between the time durations of the jobs.

Input is three arrays: BeginTime , EndTime , Profit
Output is an integer of Maximum profit of subset of Jobs

For example,
Example #1:
Input: startTime = [1,1], endTime = [5,6], profit = [12,17]
Output: 17
Explanation: We can choose the job with maximum profit i.e. second job .
Thus the output is 17

Example #2:
Input: startTime = [2,7], endTime = [7,12], profit = [2,8]
Output: 10
Explanation: We can complete both the jobs with maximum profit= profit by first job + profit by second job
as their time ranges does not clashes with each other
Thus the output is 10

*/

// *********Code Starts******************

// Including the libraries
#include<bits/stdc++.h>
using namespace std;

// Defining class for activity including the attributes of activities
class Activity
{
	public:
		int begin, end, profit; 
	
};

// Sorting the activities according to their ending times
static bool Sort_Order(Activity act1, Activity act2)
{
	return (act1.end < act2.end);
}

// Recursive solution for optimizing the maximum profits for activities without overlapping the activity duration
// Here A[]: Array of activities
// N : Number of activities available to schedule optimally

int Optimal_profit_R(Activity A[], int N)
{
	// Base cases
	if(N < 0)
		return 0;
	if (N == 1) 
		return A[N-1].profit;

	// Either include the activity or ignore it
	int append,out;
	
	int i=N-1;	
	int k=-1;
	int j=i;
	while (j>=0)
	{
		if (A[j].end <= A[i].begin){
			k=j; // FInd the nearest possible activity
			break;
		}
		j--;
	}
	
	//Including the profit
	append = A[i].profit + Optimal_profit_R(A, k+1);
	
	//Or exclude the activity
	out = Optimal_profit_R(A, N-1);

	// Retuen maximum profit from two available options
	return max(append , out );
}
int main()
{
	int N;
	cout << "Enter the number of Jobs:";
	cin >> N;

	// Declaring the activity array
	Activity A[N];

	cout << "Enter the credentials of Jobs in the order BeginTime , EndTime , Profit:\n";

	for(int i=0 ; i<N ; i++)
	{
		cout << "For Job #" << (i+1) << endl;

		cout<<"Enter The begin Time:";
		cin >> A[i].begin;

		cout<<"Enter The end Time:";
		cin >> A[i].end;

		cout<<"Enter The Profit value:";
		cin >> A[i].profit;


	}

	// Sort the activities according to their end times
	sort(A, A+N, Sort_Order);
	
	cout << "The maximum profit is for the optimal job selection is:" << Optimal_profit_R(A, N);
	return 0;
}

// time Complexity : O(N*2^N)
// Space Complexity : O(N)
