// C Code for Activity Selection
//Greedy Algorithm approach
#include <stdio.h>
#include <conio.h>
//swap function to check and swap values
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
//Main function start
int main()
{
	int num,i,j,prev=0,count=1;
	int *start,*finish;
	//Dynamic Memory Allocation for arrays
	start = (int*) malloc(num * sizeof(int));
	finish = (int*) malloc(num * sizeof(int));
	//Take number of activites as a input
	printf("Enter the number of activities :");
	scanf("%d",&num);
	//Take start and finish time as a input
	printf("\nEnter the start and finish time of activities :\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&start[i]);
		scanf("%d",&finish[i]);
	}
	//sorting starts here
	//Bubble sort - compare adjacent element and swap it
	for(i=0;i<num;i++)
	{
		//In bubble sort, maximum value is placed at last index
		//In each pass we left the last index i.e num-1-i
		for(j=0;j<num-1-i;j++)
		{
			if(finish[j]>finish[j+1])
			{
				//call swap function
				//pass by address
				swap(&finish[j],&finish[j+1]);
				swap(&start[j],&start[j+1]);
			}
		}
	}
	//condition for Activity selection
	//update prev each time with current of start i.e i
	//count variable will take care of number of activites possible
	for(i=1;i<num;i++)
	{
		if(start[i]>=finish[prev])
		{
			count++;
			prev=i;
		}
	}
	//print the output
	printf("\tOUTPUT\n");
	printf("\nTotal number of activities person can perform at a time is -> %d \n",count);
	return 0;
}
//Main function end 

/*Sample Input Output
Enter the number of activities : 6
Enter the start and finish time of activities :
1 2
3 4
2 6
5 7
8 9
5 9
	OUTPUT
Total number of activities person can perform at a time is -> 4

*/

/*
Time Complexity :
The complexity of this problem is O(n log n) when the list is not sorted.
When the sorted list is provided the complexity will be O(n)
*/
	
