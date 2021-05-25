/*

FCFS: First Come First Serve algorithm 

It is a CPU scheduling algorithm, in which the process are taken on the basis of their arrival time. 
The process that arrives first, is alloted the CPU first for the execution. Its working is similar to 
that of the FIFO in queue. It is a non-preemptive algorithm which means that the next process cannot be 
scheduled in the middle of the ongoing execution of a process in CPU.  

Terms explanation:
1. Burst time is the time taken by a process to complete its execution.
2. Waiting time is the total time for which a process has to wait for its chance to get the CPU for execution.
3. Turn around time is the total time between the submission of a process and its completion.

Implementation of the code:
Step 1: The number of process are scanned along with their respective burst time.
Step 2: Waiting time for a process is calculated by adding the burst time of the previous process. Waiting time for first process is taken as 0.
Step 3: Turn around time of a process is calculated which is the sum of burst time and waiting time of that process.
Step 4: Average waiting time and average turn around time are calculated by diving the total waiting and turn around time by nummber of process.

*/

#include <stdio.h>

// Function to calculate waiting time 
void waitingTime(int process[], int wt[], int n, int bt[])
{
    int i,j;
	
    // waiting time for the first process is taken to be 0
	wt[0] = 0;

	// waiting time being calculated for a process by adding the burst time of previous process
	for (i = 1; i < n; i++)
	{
		wt[i] = 0;
		for (j = 0; j < i; j++)
			wt[i] = wt[i] + bt[j];
	}
}

// Function to calculate turn around time
void turnaroundtime(int process[], int n, int bt[], int wt[], int tat[])
{
    int i;
	
    //turn around time being calculated by adding waiting and burst time of each process
	for (i = 0; i < n; i++)
	{
		tat[i] = bt[i] + wt[i];
	}
}

// Funtion to calculate average waiting time and turn around time
void averageTime(int process[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0, i;

	// Function to calculate waiting time 
	waitingTime(process, wt, n, bt);

	// Function to calculate turn around time
	turnaroundtime(process, n, bt, wt, tat);

	// Printing the heaidngs 
	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

	// Calculating the total tota waiting and turn around time
	for (i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, bt[i], wt[i], tat[i]);
	}

	// Average waiting and turn around time is calculated
	float avg_wt = (float) total_wt / (float) i;
	float avg_tat = (float) total_tat / (float) i;
	printf("\n\nAverage Waiting Time:%f", avg_wt);
	printf("\nAverage Turnaround Time:%f", avg_tat);

}

// Driver code
int main()
{
	int n, bt[50], i, j, process[50];
	float avg_wt = 0, avg_tat = 0;

	//number of process is taken as input from the user
	printf("\nEnter total number of process(maximum 50):");
	scanf("%d", &n);

	//user is asked to enter the burst time for each process
	printf("\nEnter Process Burst Time");
	for (i = 0; i < n; i++)
	{
		printf("\nP[%d]:", i + 1);
		scanf("%d", &bt[i]);
	}

	// Function to calculate average time 
	averageTime(process, n, bt);
	return 0;
}

/*

Test case:
Input:
Enter total number of process(maximum 50):4

Enter Process Burst Time
P[1]:2

P[2]:6

P[3]:4

P[4]:8

Output:
Process         Burst Time      Waiting Time    Turnaround Time
P[1]            2               0               2
P[2]            6               2               8
P[3]            4               8               12
P[4]            8               12              20

Average Waiting Time:5.500000
Average Turnaround Time:10.500000

Complexities: 
Time complexity: O(n)
Space complexity: O(1)

*/
