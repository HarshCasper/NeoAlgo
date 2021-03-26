/*
About Round Robin Scheduling:-
It is a CPU scheduling technique in which each process is given a fixed time quantum/slice.
Once the time quantum is over for a process, the CPU gets preempted to another process in the ready queue.
    -It is a preemptive scheduling technique.
    -As all processes get fair share of CPU, it a starvation-free CPU scheduling algorithm.
    -The disadvantage of it is more overhead of context switching.

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

#include<stdio.h>
#include<stdlib.h>

//Structure for queue
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

//push function for queue
void push(int x)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));  
    new->data=x;
    new->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=new;
    }
    else
    {
        rear->next=new;
        rear=new;
    }
}

//pop function for queue
int pop()
{
    int x;
    if(front==rear)
    {
        struct node *t=front;
        x=t->data;
        free(t);
        front=rear=NULL;
        return x;
    }
    else
    {
        struct node *t=front;
        x=t->data;
        front=front->next;
        free(t);
        return x;
    }
}

void GanttChartFormation(int *b1,int *at,int *gc,int tq,int *total_time,int N)
{
    int i,j,x,c;
    //pushes processes into ready queue with arrival time=0 
    i=0;
    while(i<N)
    {
        if(at[i]==0)
        push(i);
        i++;
    }
    printf("\nReady Queue: ");
    while(front!=NULL && rear!=NULL)
    {
        x=pop();
        printf("P%d  ",x);
        c=0;
        for(j=0;j<tq;j++)
        {
            if(b1[x]>0)
            {
                gc[*total_time]=x;
                b1[x]-=1;
                *total_time+=1;
                c++;
            }
        } 
        for(i=0;i<N;i++)
        {
            if(at[i]<=*total_time && at[i]>(*total_time-c))
            {
                push(i);
            }
        }
        if(b1[x]>0)
        push(x);
    }
}

//Calculates completion time,turn around time,waiting time,response time
void TimeCalculations(int *at,int *bt,int *ct,int *tat,int *wt,int *rt,int *gc,int total_time,int N)
{
    int i,j,k;
    for(j=0;j<N;j++)
    {
        for(i=total_time-1;i>=0;i--)
        {
            if(j==gc[i])
            {
                ct[j]=i+1;
                tat[j]=ct[j]-at[j];
                wt[j]=tat[j]-bt[j];
                break;
            }
        }
        for(k=0;k<total_time;k++)
        {
            if(j==gc[k])
            {
                rt[j]=k-at[j];
                break;
            }
        }
    }
}

/*Displays completion time,turn around time,waiting time,response time and
also calculates total waiting and turn around time*/
void DisplayTime(int at[],int bt[],int ct[],int wt[],int tat[],int rt[],int N)
{
    float total_wt=0,total_tat=0;
    printf("\nProcesses\tArrival time\tBurst time\tCompletion Time\t\tWaiting time\tTurn around time\tResponse time\n"); 
	for(int i=0;i<N;i++) 
	{ 
		total_wt=total_wt+wt[i]; 
		total_tat=total_tat+tat[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\t\t\t%d\n",i,at[i],bt[i],ct[i],wt[i],tat[i],rt[i]);
	} 
	printf("\nAverage waiting time = %2.3f",total_wt/N); 
	printf("\nAverage turn around time = %2.3f ",total_tat/N);
}

int main()
{
    int N,MAX=0;
    printf("Enter the no. of processes: ");
    scanf("%d",&N);

    int bt[N],at[N],wt[N],ct[N],tat[N],rt[N],b1[N],i,total_time=0,tq;
    for(i=0;i<N;i++)
	{
        printf("\nEnter arrival time for process %d: ",i);
		scanf("%d",&at[i]); 
		printf("Enter burst time for process %d: ",i);
		scanf("%d",&bt[i]);
        b1[i]=bt[i];	
        MAX+=bt[i];
	}

    int gc[MAX];
    printf("\nEnter time quantum for each process: ");
    scanf("%d",&tq);

    GanttChartFormation(b1,at,gc,tq,&total_time,N);
    
    //displays the gantt chart
    printf("\nGantt Chart: ");
    for(i=0;i<total_time;i++)
    {
        printf("P%d   ",gc[i]);
    }
    printf("\n\nTotal time to complete all processes: %d",total_time);
    TimeCalculations(at,bt,ct,tat,wt,rt,gc,total_time,N);   
    DisplayTime(at,bt,ct,wt,tat,rt,N);
    return 0;
}

/*
Output:-

Enter the no. of processes: 4

Enter arrival time for process 0: 0
Enter burst time for process 0: 2

Enter arrival time for process 1: 1
Enter burst time for process 1: 3

Enter arrival time for process 2: 1
Enter burst time for process 2: 5

Enter arrival time for process 3: 2
Enter burst time for process 3: 4

Enter time quantum for each process: 2

Ready Queue: P0  P1  P2  P3  P1  P2  P3  P2
Gantt Chart: P0   P0   P1   P1   P2   P2   P3   P3   P1   P2   P2   P3   P3   P2

Total time to complete all processes: 14
Processes       Arrival time    Burst time      Completion Time         Waiting time    Turn around time        Response time
P0              0               2               2                       0               2                       0
P1              1               3               9                       5               8                       1
P2              1               5               14                      8               13                      3
P3              2               4               13                      7               11                      4

Average waiting time = 5.000
Average turn around time = 8.500
*/
