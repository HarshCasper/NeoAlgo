/*
minimum no. of swaps needed to sort the array in ascending
order having integer in range 1 to N. For example:
array is 1 2 3 5 4 ,here it can be easily sorted by 
swapping 5 and 4. Therefore, 1 swap needed here.
*/
#include<iostream>
using namespace std;

int min_swap_needed(int a[],int n)
{
    int swap=0;
    for(int i=0;i<n-1;i++)
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
    return swap;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int swap;
    swap=min_swap_needed(a,n);
    cout<<swap;
    return 0;
}
/*
input:
6
6 5 3 4 2 1
output:
2
*/

/*
Time-Complexity=O(N)
Space-Complexity=O(N)
*/
