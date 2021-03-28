/*
Query : Job Scheduling with Maximum Profit (using Recursion)

Task:
We are given X number of Jobs and their starting time, end time, and profit value of accomplishing them.
We have to find the maximum profit of any subset of them such that there is no overlapping 
between the time durations of the jobs.

Input is three arrays: BeginTime , EndTime , Profit
Output is an integer of Maximum profit of subset of Jobs

*/
// Including the libraries
#include<bits/stdc++.h>
using namespace std;

/*Defining class for jobs 
The attributes of jobs as the 
members of the class namely:
 	a)begin: starting time of the job
 	a)end : ending time of the job
 	c)profit: profit you gain by completing that job
*/
class Jobs
{
	public:
		int begin, end, profit; 
	
};

/*Sorting the activities according to their 
ending times to get the correct ordering of 
the jobs
*/
static bool sort_Order(Jobs job1, Jobs job2)
{
	return (job1.end < job2.end);
}

/*
Recursive solution for optimizing the maximum 
profits for jobs without overlapping the job duration
 Here job[]: Array of jobs
	  job_curr : Current job
*/

int Optimal_profit_Rec(Jobs job[], int job_curr)
{
	if(job_curr < 0)
		return 0;
	if (job_curr == 1) 
		return job[job_curr-1].profit;

	int include,exclude;
	
	/*a) to include the current job:
	 We need to find the last job(nearest_job) that
	 doesn't overalp with current job(job_curr).
	 we can find that using linear search.
	  Then we will recursively find the result for all jobs till that job(nearest_job) and
		add profit of current job(job_curr) to the output.
	*/
	int nearest_job=-1;
	int job_idx;       // to iterate the jobs
	job_idx = job_curr - 1;
	
	while (job_idx>=0)
	{
		if (job[job_idx].end <= job[job_curr-1].begin){
			nearest_job=job_idx; // This is the last non-overlapping job
			break;
		}
		job_idx--;
	}
	
	
	//Including the job , hence adding the profit to the result
	include= job[job_curr-1].profit;
	
	if(nearest_job != -1)
	include = include + Optimal_profit_Rec(job, nearest_job+1);
	
	//b) exclude the job
	exclude = Optimal_profit_Rec(job, job_curr-1);

	// Return maximum profit from two available options
	return max(include , exclude );
}

/*main body*/
int main()
{
	
	int N;
	cout << "Enter the number of Jobs:";
	cin >> N;

	Jobs job[N];

	cout << "Enter the credentials of Jobs in the order BeginTime , EndTime , Profit:\n";

	for(int job_ind=0 ; job_ind<N ; job_ind++)
	{
		cout << "For Job #" << (job_ind+1) << endl;

		cout<<"Enter The begin Time:";
		cin >> job[job_ind].begin;

		cout<<"Enter The end Time:";
		cin >> job[job_ind].end;

		cout<<"Enter The Profit value:";
		cin >> job[job_ind].profit;


	}

	// Sort the jobs according to their ending time
	sort(job, job+N, sort_Order);
	
	cout << "The maximum profit for the optimal job selection is:" << Optimal_profit_Rec(job, N);
	return 0;
}

/*
	COMPLEXITY:
	Since it is a recursive solution
	 Time Complexity -> O(N*2^N)  
	 Space Complexity -> occupies space in call stack	

Sample Test Cases :

Example #1:
Input: startTime = [1,1], endTime = [5,6], profit = [12,17]
Output: 17
Explanation: 
We can choose the job with maximum profit i.e. second job .
Thus the output is 17

Example #2:
Input: startTime = [2,7], endTime = [7,12], profit = [2,8]
Output: 10
Explanation: 
We can complete both the jobs with maximum profit= 
				profit by first job + profit by second job
as their time ranges does not clash with each other
Thus the output is 10

*/
