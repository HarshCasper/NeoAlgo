/*
Given:
1. 'n' jobs.
2.  an array containing respective deadlines.
3.  an array containing respective profits. 
4. all jobs takes unit time to complete.
5. Initially all the jobs are at t=0;

Assumption:
 profit array is in descending order.

Problem statement:
select the subset of given n-jobs, such that the jobs which are selected must be completed
within their deadlines and get maximum profit. 

objective:
to get max profit and sheduled jobs.

eg:
n=4,<j1,j2,j3,j4>
<p1---p4>=<100,15,10,40>
<d1---d4>=<2,1,2,1>
solution:
 max profit=140(subset={j1,j4})

explanation:
understanding deadlines:
d1=2 means that j1 should complete till t=2. so j1 has two options either it can be completed in t=2 or t=1.
d2=1 means that j2 should complete till t=1. so j2 has only one option it should complete in t=1.

general approach:

1. select the job with max profit.
2. shedule it in its last deadline(i.e, if d1=5 than 
we will shedule j1 in t=5 not in t=4 or any less value.) (greedy approach.) 

A key point to remember:
the size of sub-job array can't exceed maximum deadline.
*/
#include<iostream>
#include<algorithm>
using namespace std;
void JSD_algo(int[],int[],int[],int);
int main()
{
  int jobs[]={1,2,3,4,5,6};
  int profit[]={100,85,74,65,60,43};
  int deadlines[]={4,1,3,1,2,2};
  int n=sizeof(jobs)/sizeof(jobs[0]);
  JSD_algo(jobs,profit,deadlines,n);
}

void JSD_algo(int jobs[],int p[],int d[],int n)
{
  int profit=0,i,max_dl,j;
  max_dl=*max_element(d,d+n); /* finding max deadline*/
  int sub_job[max_dl]={0};
  for(i=0;i<n;i++)
     {
         for(j=d[i]-1;j>=0;j--)
         {
           if(sub_job[j]==0)
           {
              profit=profit+p[i];
              sub_job[j]=jobs[i];
              break;
           }
         }  
     }
     cout<<"sheduled jobs:\n";
     for(int k=0;k<max_dl;k++)
         cout<<sub_job[k]<<" ";
     cout<<"\nmax profit:"<<profit;
}

/* ans:
sheduled jobs:
2 5 3 1
max profit:319
*/
