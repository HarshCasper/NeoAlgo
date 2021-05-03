/*
About Preemptive Priority Scheduling:-
It is a method of scheduling processes that is based on priority. 
In this algorithm, the scheduler selects the tasks to work as per the priority.
If two processes have the same priority, then the job with the shortest burst time is executed first.

Time related to each process-
Arrival Time(AT)-The time at which process enters into the ready queue.
Burst Time(BT)-The total time required by the CPU to execute the whole process.
Completion Time(CT)-The time at which the process enters into completion state.
Turn Around Time(TAT)-The total amount of time spent by the process from its completion.
                      It is calculated as - TAT=CT-AT
Waiting Time(WT)-The total time for which the process waits for the CPU to be assigned.
                 It is calculated as - WT=TAT-BT
Response Time(RT)-The difference between arrival time and the time at which the process first gets the CPU.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50
const int N;

//structure of priority queue
struct queue
{
	int burst_time;
	int process;
	int priority;
	struct queue * next;
};
struct queue *q = NULL;

//push function for queue
void push(int n, int p, int b)
{
	struct queue *new = (struct queue *) malloc(sizeof(struct queue));
	new->process = n;
	new->priority = p;
	new->burst_time = b;
	new->next = NULL;
	if (q == NULL)
	{
		q = new;
	}
	else
	{
		struct queue *t1, *t2;
		t1 = q;
		while (t1 != NULL && t1->priority <= p)
		{
			if (t1->priority < p)
			{
				t2 = t1;
				t1 = t1->next;
			}
			else
			{
				if (t1->burst_time > b)
				{
					break;
				}
				else
				{
					t2 = t1;
					t1 = t1->next;
				}
			}
		}

		if (t1 == q)
		{
			new->next = t1;
			q = new;
		}
		else if (t1 == NULL)
		{
			t2->next = new;
		}
		else
		{
			new->next = t1;
			t2->next = new;
		}
	}
}

//pop function for queue
int pop()
{
	struct queue *t = q;
	int x;
	x = t->process;
	q = q->next;
	free(t);
	return x;
}

void GanttChartFormation(int *p, int *pr, int *b1, int *at, int *gc, int *total_time)
{
	int i = 1, x;
	while (i <= N)
	{
		if (at[i] == 0)
		{
			push(p[i], pr[i], b1[i]);
		}

		i++;
	}

	while (q != NULL)
	{
		x = pop();
		if (b1[x] > 0)
		{
			gc[*total_time] = p[x];
			(*total_time) ++;
			b1[x]--;
			push(p[x], pr[x], b1[x]);
		}

		for (i = 1; i <= N; i++)
		{
			if (at[i] == (*total_time))
			{
				push(p[i], pr[i], b1[i]);
			}
		}
	}
}

//Calculates completion time,turn around time,waiting time,response time
void TimeCalculations(int *at, int *bt, int *ct, int *tat, int *wt, int *rt, int *gc, int total_time)
{
	int i, j, k;
	for (j = 1; j <= N; j++)
	{
		for (i = total_time - 1; i > 0; i--)
		{
			if (j == gc[i])
			{
				ct[j] = i + 1;
				tat[j] = ct[j] - at[j];
				wt[j] = tat[j] - bt[j];
				break;
			}
		}

		for (k = 0; k < total_time; k++)
		{
			if (j == gc[k])
			{
				rt[j] = k - at[j];
				break;
			}
		}
	}
}

/*Displays completion time,turn around time,waiting time,response time and
also calculates total waiting and turn around time*/
void DisplayTime(int p[], int pr[], int at[], int bt[], int ct[], int wt[], int tat[], int rt[])
{
	float total_wt = 0.0, total_tat = 0;
	printf("\nProcesses\tPriority\tA.T\tB.T\tC.T\tW.T\tT.A.T\tR.T\n");
	for (int i = 1; i <= N; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf("P%d\t\t%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i], pr[i], at[i], bt[i], ct[i], wt[i], tat[i], rt[i]);
	}

	float s = total_wt / N;
	float t = total_tat / N;
	printf("\nAverage waiting time = %2.3f", s);
	printf("\nAverage turn around time = %2.3f ", t);
}

int main()
{
	printf("Enter the no. of processes: ");
	scanf("%d", &N);
	int p[N], bt[N], at[N], pr[N], wt[N], ct[N], tat[N], rt[N], b1[N], gc[MAX], i, total_time = 0;
	for (i = 1; i <= N; i++)
	{
		p[i] = i;
		printf("\nEnter priority number(Lower no. means higher priority)for process %d: ", p[i]);
		scanf("%d", &pr[i]);
		printf("Enter arrival time for process %d: ", p[i]);
		scanf("%d", &at[i]);
		printf("Enter burst time for process %d: ", p[i]);
		scanf("%d", &bt[i]);
		b1[i] = bt[i];
	}

	GanttChartFormation(p, pr, b1, at, gc, &total_time);

	//displays the gantt chart
	printf("\nGantt Chart: ");
	for (i = 0; i < total_time; i++)
	{
		printf("P%d   ", gc[i]);
	}

	printf("\nTotal time to complete all processes: %d", total_time);
	TimeCalculations(at, bt, ct, tat, wt, rt, gc, total_time);
	DisplayTime(p, pr, at, bt, ct, wt, tat, rt);
	return 0;
}

/*
Output:-
Enter the no. of processes: 5

Enter priority number(Lower no. means higher priority)for process 1: 1
Enter arrival time for process 1: 0
Enter burst time for process 1: 6

Enter priority number(Lower no. means higher priority)for process 2: 2
Enter arrival time for process 2: 1
Enter burst time for process 2: 8

Enter priority number(Lower no. means higher priority)for process 3: 3
Enter arrival time for process 3: 2
Enter burst time for process 3: 7

Enter priority number(Lower no. means higher priority)for process 4: 4
Enter arrival time for process 4: 3
Enter burst time for process 4: 3

Enter priority number(Lower no. means higher priority)for process 5: 3
Enter arrival time for process 5: 1
Enter burst time for process 5: 5

Gantt Chart: P1   P1   P1   P1   P1   P1   P2   P2   P2   P2   P2   P2   P2   P2   P5   P5   P5   P5   P5   P3   P3   P3   P3   P3   P3   P3   P4   P4   P4
Total time to complete all processes: 29
Processes       Priority        A.T     B.T     C.T     W.T     T.A.T   R.T
P1              1               0       6       6       0       6       0
P2              2               1       8       14      5       13      5
P3              3               2       7       26      17      24      17
P4              4               3       3       29      23      26      23
P5              3               1       5       19      13      18      13

Average waiting time = 11.600
Average turn around time = 17.400 
*/
