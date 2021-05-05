/*About FCFS:
First Come First Serve algorithm is a operating system scheduling algorithm, in which the processes are taken on the basis of their arrival time. The process that arrives first, is alloted the CPU first for the execution.

Variables used:
1. bt is burst time.
2. wt is waiting time .
3. tat is turn around time (tat= wt+bt).
4. avg_wt is average waiting time.
5. avg_tat is average turn around time.
*/

#include<stdio.h>

 int main()

{

    int n,bt[50],wt[50],tat[50],i,j;
    float avg_wt=0,avg_tat=0;

    //number of processes is taken as input from the user
    printf("\nEnter total number of processes(maximum 50):");
    scanf("%d",&n);

    //user is asked to enter the burst time for each process
    printf("\nEnter Process Burst Time");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]:",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;// waiting time for the first process is taken to be 0

    /*waiting time for all the processes except for the first process is calculated
    by adding the burst time of previous processes*/
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]=wt[i]+bt[j];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    //turn around time is calculated by adding waiting and burst time of each process
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avg_wt=avg_wt+wt[i];
        avg_tat=avg_tat+tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }

    //average waiting time and average turn around time are calculated
    avg_wt=avg_wt/i;
    avg_tat=avg_tat/i;
    printf("\n\nAverage Waiting Time:%f",avg_wt);
    printf("\nAverage Turnaround Time:%f",avg_tat);

    return 0;
}



/*
Output:

Enter total number of processes(maximum 50):4

Enter Process Burst Time
P[1]:2

P[2]:6

P[3]:4

P[4]:8

Process         Burst Time      Waiting Time    Turnaround Time
P[1]            2               0               2
P[2]            6               2               8
P[3]            4               8               12
P[4]            8               12              20

Average Waiting Time:5.500000
Average Turnaround Time:10.500000
*/
