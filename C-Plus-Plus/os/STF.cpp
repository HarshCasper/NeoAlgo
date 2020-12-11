#include<iostream>
using namespace std;
class FCFS{
    public:
	int i,j,n,wt,tat,a[50],b[50],id[50],t1,t2;
	char x;
	float awt,atat;
	void getn()
	{
		wt=0;
		b[0]=0;
		tat=0;
		cout<<"Enter the number of processes: ";
		cin>>n;
	}
	void getdata(){
		cout<<"Enter the process ID and CPU burst time for each process: ";
		for(i=0;i<n;i++)
		{
			cin>>x;
			cin>>id[i];
			cin>>a[i];
		}
	for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t1=a[i];
				a[i]=a[j];
				a[j]=t1;
				t2=id[i];
				id[i]=id[j];
				id[j]=t2;
			}
		}
	}
	void putdata(){
		for(i=0;i<n;i++)
		{
			b[i+1]=0;
			for(j=0;j<=i;j++)
			{
				b[i+1]=b[i+1]+a[j];
			}
		}
		
		cout<<"Process ID\tCPU Burst Time\tWT\t\tTAT\n";
		for(i=0;i<n;i++)
		{
		cout<<"P"<<id[i]<<"\t\t"<<a[i]<<"\t\t"<<b[i]<<"\t\t"<<b[i+1]<<"\n";
	}
		for(i=0;i<n;i++)
		{
			wt=wt+b[i];
			tat=tat+b[i+1];
		}
		awt=(float)wt/n;
		atat=(float)tat/n;
		cout<<"\n  The average waiting time is: "<<awt<<"ms"<<endl;
		cout<<"The average turnaround time is: "<<atat<<"ms";
	}
};
int main()
{
	FCFS a;
	a.getn();
	a.getdata();
	a.putdata();
}
