//WACp to executre Shortest Remaining Time Next (SRTN)
#include<iostream>
using namespace std;
class SRTN{
    public:
	int i,j,n,wt,tat,bt[50],wta[50],tata[50],id[50],at[50],ct[50],rt[50],t1,t2,cpuft[50],ptimee,ptimen,bt2[50];
	char x;
	float awt,atat;
	void getn()
	{
		wt=0;
		tat=0;
		ptimen=0;
		ptimee=0;
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
			bt2[i]=bt[i];
			wta[i]=0;
		}
		cpuft[0]=0;
	//for(i=0;i<n;i++)
	for(j=1;j<n;j++)
		{
			ptimen=at[j];
			bt[0]=bt[0]-(ptimen-ptimee);
			ptimee=ptimen;
			if(bt[0]>bt[j])//if(a[i]>a[j])
			{
				t1=bt[0];
				bt[0]=bt[j];
				bt[j]=t1;
				t2=id[0];
				id[0]=id[j];
				id[j]=t2;
				t1=at[0];
				at[0]=at[j];
				at[j]=t1;
				t1=bt2[0];
				bt2[0]=bt2[j];
				bt2[j]=t1;
			//	wta[j]+=bt[0];
			}
		wta[j]=bt[0];
		}
		for(j=1;j<n;j++)
		{
			for(i=j+1;i<n;i++)
			{
				if(bt[j]>bt[i])
				{
				t1=bt[i];
				bt[i]=bt[j];
				bt[j]=t1;
				t2=id[i];
				id[i]=id[j];
				id[j]=t2;
				t1=at[i];
				at[i]=at[j];
				at[j]=t1;
				t1=bt2[i];
				bt2[i]=bt2[j];
				bt2[j]=t1;
				t1=wta[i];
				wta[i]=wta[j];
				wta[j]=t1;
				//wta[i]+=bt[j];	
				}
			}
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<i;j++)
		{
			wta[i]+=bt[j];
		}
		}
		for(i=0;i<n;i++)
		{
			if(wta[i]<0)
			{
				wta[i]=0;
			}
		}
		
	}
	void putdata(){
		for(i=0;i<n;i++)
		{
		tata[i]=bt2[i]+wta[i];
		ct[i]=bt2[i]+wta[i]+at[i];
		}
		cout<<"Process ID\tAT\tCPU Burst Time\t\tWT\t\tTAT\t\tCT\n";
	//	cout<<"\nP"<<id[0]<<"\t\t"<<at[0]<<"\t\t"<<a[0]<<"\t\t"<<ct[0]<<"\t\t"<<wta[0]<<"\t\t"<<tata[0]<<"\t\t"<<rt[0]<<"\n";
		for(i=0;i<n;i++)
		{
		cout<<"P"<<id[i]<<"\t\t"<<at[i]<<"\t\t"<<bt2[i]<<"\t\t"<<wta[i]<<"\t\t"<<tata[i]<<"\t\t"<<ct[i]<<"\n";
	}
	for(i=0;i<n;i++)
	{
		wt+=wta[i];
		tat+=tata[i];
	}
		awt=(float)wt/n;
		atat=(float)tat/n;
		cout<<"\nThe average waiting time is: "<<awt<<"ms"<<endl;
		cout<<"The average turnaround time is: "<<atat<<"ms";
		cout<<"\n";
	/*	for(i=0;i<n;i++)
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
		cout<<cpuft[i];*/
	}
};
int main()
{
	SRTN a;
	a.getn();
	a.getdata();
	a.putdata();
}
