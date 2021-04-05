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

Objective:
to get max profit and sheduled jobs.
*/
#include<iostream>
#include<algorithm>
using namespace std;
void JSD_algo(int[],int[],int[],int);
int main()
{
  int n,k;
  cout<<"enter the no. of jobs:"<<endl;
  cin>>n;
  int jobs[n],profit[n],deadlines[n];
  cout<<"enter the profit in decreasing order:"<<endl;
  for(k=0;k<n;k++)
      cin>>profit[k];
  cout<<"enter the respective deadline:"<<endl;
  for(k=0;k<n;k++)
      cin>>deadlines[k];
  cout<<"enter the respective job serial no.:"<<endl;
  for(k=0;k<n;k++)
      cin>>jobs[k];
  JSD_algo(jobs,profit,deadlines,n);
}

void JSD_algo(int jobs[],int p[],int d[],int n)
{
  int profit=0,i,max_dl,j;
  max_dl=*max_element(d,d+n); /* finding max deadline*/
  int sub_job[max_dl]={0}; /* no. of maximum jobs can be sheduled will be equal to max deadline */
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

/* 
Time complexity:O(n^2) becase we are using loop inside a loop .(nxn)
space complexity:O(1)
--------------------------------------------------------------------------------------------------------
input:
enter the no. of jobs:
6
enter the profit in decreasing order:
100 85 74 65 60 43
enter the respective deadline:
4 1 3 1 2 2
enter the respective job serial no.:
6 5 2 3 1 4
output:
sheduled jobs:
5 1 2 6
max profit:319
*/
