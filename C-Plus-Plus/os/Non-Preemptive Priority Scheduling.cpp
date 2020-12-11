//WACp to execute priority scheduling
#include<iostream>
using namespace std;
class Priority{
    public:
	int i,j,n,wt,tat,a[50],b[50],id[50],p[50],t1;
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
		cout<<"Enter the process ID, CPU burst time and priority for each process: ";
		for(i=0;i<n;i++)
		{
			cin>>x;
			cin>>id[i];
			cin>>a[i];
			cin>>p[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(p[i]>p[j])
				{
					t1=id[i];
					id[i]=id[j];
					id[j]=t1;
					t1=a[i];
					a[i]=a[j];
					a[j]=t1;
					t1=p[i];
					p[i]=p[j];
					p[j]=t1;
				}
			}
		}
	}
	void putdata(){
		cout<<"Process ID\tCPU Burst Time\tPriority\n";
		for(i=0;i<n;i++)
		{
			cout<<"P"<<id[i]<<"\t\t"<<a[i]<<"\t\t"<<p[i]<<"\n";
			b[i]=0;
			for(j=0;j<=i;j++)
			{
				b[i]=b[i]+a[j];
			}
		}
		for(i=0;i<n-1;i++)
		{
			wt=wt+b[i];
			tat=tat+b[i];
		}
		tat=tat+b[i];
		awt=(float)wt/n;
		atat=(float)tat/n;
		cout<<"The average waiting time is: "<<awt<<"ms"<<endl;
		cout<<"The average turnaround time is: "<<atat<<"ms";
	}
};
int main()
{
	Priority a;
	a.getn();
	a.getdata();
	a.putdata();
}
