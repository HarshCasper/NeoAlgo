//WACp to executre SJF with Arrival Time
#include<iostream>
using namespace std;
class SJFWAT{
    public:
	int i,j,n,wt,tat,bt[50],wta[50],tata[50],id[50],at[50],ct[50],rt[50],t1,t2,cpuft[50];
	char x;
	float awt,atat;
	void getn()
	{
		wt=0;
		tat=0;
		cout<<"Enter the number of processes: ";
		cin>>n;
	}
	void getdata(){
		cout<<"Enter the process ID, CPU burst time and arrival time for each process: ";
		for(i=0;i<n;i++)
		{
			cin>>x;
			cin>>id[i];
			cin>>bt[i];
			cin>>at[i];
		}
		cpuft[0]=0;
	for(i=1;i<n;i++)
	for(j=i+1;j<n;j++)
		{
			
			if(a[i]>a[j])
			{
				t1=bt[i];
				bt[i]=a[j];
				bt[j]=t1;
				t2=id[i];
				id[i]=id[j];
				id[j]=t2;
				t1=at[i];
				at[i]=at[j];
				at[j]=t1;
			}
		}
	}
	void putdata(){
		ct[0]=at[0]+bt[0];
		cpuft[1]=at[0];
		for(i=1;i<n;i++)
		{
					ct[i]=ct[i-1]+bt[i];
		}
		for(i=2;i<n+2;i++)
		{
			cpuft[i]=ct[i-2];
		}
		
		cpuft[i]=ct[i-1]+bt[i];
		for(i=0;i<n;i++)
		{
			    rt[i]=cpuft[i+1]-at[i];
				tata[i]=ct[i]-at[i];
				wta[i]=tata[i]-bt[i];
		}
		for(i=0;i<n;i++)
		{
			wt=wt+wta[i];
			tat=tat+tata[i];
		}
		cout<<"Process ID\tAT\tCPU Burst Time\t\tCT\t\tWT\t\tTAT\t\tRT\n";
	//	cout<<"\nP"<<id[0]<<"\t\t"<<at[0]<<"\t\t"<<a[0]<<"\t\t"<<ct[0]<<"\t\t"<<wta[0]<<"\t\t"<<tata[0]<<"\t\t"<<rt[0]<<"\n";
		for(i=0;i<n;i++)
		{
		cout<<"P"<<id[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<ct[i]<<"\t\t"<<wta[i]<<"\t\t"<<tata[i]<<"\t\t"<<rt[i]<<"\n";
	}
		awt=(float)wt/n;
		atat=(float)tat/n;
		cout<<"\nThe average waiting time is: "<<awt<<"ms"<<endl;
		cout<<"The average turnaround time is: "<<atat<<"ms";
		cout<<"\n";
		for(i=0;i<n;i++)
		cout<<"----";
		cout<<"\n";
		cout<<"|  |";
		for(i=0;i<n;i++)
		{
		cout<<"|"<<"P"<<id[i];
	}
	   cout<<"|";
	cout<<"\n";
		for(i=0;i<n;i++)
		cout<<"----";
	cout<<"\n";
	for(i=0;i<n+1;i++)
		cout<<cpuft[i]<<"  ";
		cout<<cpuft[i];
	}
};
int main()
{
	SJFWAT a;
	a.getn();
	a.getdata();
	a.putdata();
}
