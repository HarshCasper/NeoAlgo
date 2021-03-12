/*minimum no. of swaps needed to sort the array in ascending
order having integer in range 1 to N */
#include<iostream>
using namespace std;
int main()
{
	int swap=0,n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n-1;i++)
	{
		int j=a[i],temp;
		if((i+1)!=a[i])
		{
			temp=a[i];
			a[i]=a[j-1];
			a[j-1]=temp;
			swap++;
		}
	}
	cout<<swap;
}
/*
input:
6
1 5 3 4 2 6
output:
1
*/

/*
Time-Complexity=O(N)
*/

