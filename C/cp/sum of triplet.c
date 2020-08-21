/*Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all triplets of numbers which sum to target.
For example
input:
9
5 7 9 1 2 4 6 8 3
10
output:
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5
*/
#include<stdio.h>

void sort(int a[1000],int n)
{
	//using bubble sort
	int i,j,temp;
	for(i=0; i<n; i++)
	{   
	     
		for(j=0; j<=(n-2)-i; j++)
		{
			if(a[j] > a[j+1] ) // if a[j] > a[j+1] then swap them
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
void tripletSum(int a[1000],int n,int target)
{
	int i=0, j,k;
  for(i=0; i<n; i++ ) 
  {
  	j = i+1; k = n-1; // using 2 iterator approach
  	while(j<k)
	{
		if(a[i] + a[j] + a[k] == target) //if triplet sum is equal to target then print it
		{
			printf("%d, %d and %d\n",a[i],a[j],a[k]);
		    j++; k--;
		    
		}
		else if(a[i] + a[j] + a[k] > target)
		{
			k--;
		}
		else
		{
			j++;
		}
       	   
	}
	 
  }
	
}

int main()
{
	int a[1000],n,i,target;
	
	scanf("%d",&n); //input no. of elements in array
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]); //  input elements in array
	}
	
	scanf("%d",&target); //input the target number
	sort(a,n); // sort the array 
    
		
	tripletSum(a,n,target); //cal tripletSum() to find and print triplet 
	
	return 0;
}
/* Time Complexity of sort function : O(n^2)
   Time Complexity of tripletSum function : O(n^2)
   
*/

