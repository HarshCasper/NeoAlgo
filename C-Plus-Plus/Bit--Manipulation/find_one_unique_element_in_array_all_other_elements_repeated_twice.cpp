#include<iostream>
using namespace std;

void uniqnum(int [],int);
int main()
{
    int n;
    cout<<"\nEnter the no. of elements in your array = ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the values into the array --> ";
    for(int i=0;i<n;i++)
    {cin>>a[i];}
    uniqnum(a,n);
    return 0;
}

void uniqnum(int a[], int n) // The time complexity in this case is O(log(n)).
{
	int k=0;
    for(int i=0;i<n;i++)
		{
			k = k^a[i];
		}
	cout<<k<<" is the unique element."<<endl;
}

/* 
 * This method is inefficient because it has time coplexity O(n^2).
 * 
void uniqnum(int a[], int n)
{
	int k,pos=0;
    for(int i=0;i<n;i++)
		{
			k=0;
			for(int j=0;j<n;j++)
				{
					if(i==j)
						{continue;}
						
					if((a[i]^a[j]) == 0)
						{
							k=1;
							break;
						}
				}
			if(k==0){pos = i;}
		}
	cout<<a[pos]<<" is the unique element."<<endl;
}*/
