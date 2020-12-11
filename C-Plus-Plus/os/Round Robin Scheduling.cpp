//WACp to execute round robin scheduling
#include<iostream>
using namespace std;
class RR{
    public:
	int i,j,k,l,n,tq,wt,tat,bt[50],bt2[50],id[50],t1,sum,wta[50],tata[50];
	char x;
	float awt,atat;
	void getn()
	{
		wt=0;
		tat=0;
		sum=1;
		cout<<"Enter the number of processes and the time quantum: ";
		cin>>n>>tq;
	}
	void getdata(){
		cout<<"Enter the process ID and CPU burst time for each process: ";
		for(i=0;i<n;i++)
		{
			cin>>x;
			cin>>id[i];
			cin>>bt[i];
			wta[i]=0;
			bt2[i]=bt[i];
		}
		while(sum!=0)
		{
			sum=0;
		for(i=0;i<n;i++)
		{
			sum+=bt[i];
		}
		if(sum!=0)
		{
		for(j=0;j<n;j++)
		{
			for(k=0;k<tq;k++)
			if(bt[j]==0)
			{
				j++;
				if(j>=n)
				break;
				k=0;
			}
			else
			{
			bt[j]-=1;
			for(l=0;l<n;l++)
			{
				if(bt[l]!=0)
				{
				if(l==j)
				continue;
				else
				wta[l]+=1;
			}
			}
			}
		}
	}
}
}
	void putdata(){
		for(i=0;i<n;i++)
		{
			tata[i]=wta[i]+bt2[i];
		}
		cout<<"Process ID\tCPU Burst Time\tWaiting Time\tTurnaround Time\n";
		for(i=0;i<n;i++)
		{
			cout<<"P"<<id[i]<<"\t\t"<<bt2[i]<<"\t\t"<<wta[i]<<"\t\t"<<tata[i]<<"\n";
		}
		for(i=0;i<n;i++)
		{
			wt=wt+wta[i];
			tat=tat+tata[i];
		}
		awt=(float)wt/n;
		atat=(float)tat/n;
		cout<<"The average waiting time is: "<<awt<<"ms"<<endl;
		cout<<"The average turnaround time is: "<<atat<<"ms";
	}
};
int main()
{
	RR a;
	a.getn();
	a.getdata();
	a.putdata();
}
