/*
The knapsack problem or rucksack problem is a problem in combinatorial optimization: Given a set of items, each with a weight and a value, determining the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.
*/
#include <stdio.h>
#include<stdlib.h>
//returning maximum value
int max(int a, int b) { return (a > b) ? a : b; }
//intialising global variables
int capacity;
int *val;
int *wt; 
//implementation of knapsack problem 
int F(int capacity, int n)
{
	if (n == 0 || capacity == 0)
		return 0;
	if (wt[n - 1] < capacity)
		return F(capacity, n - 1);
	else
		return max(
			val[n - 1]+ F(capacity - wt[n - 1],n - 1),F(capacity, n - 1));
}
//driver code
int main()
{	int n;
	 printf("Enter maximum capacity");
	 scanf("%d",&capacity);
	 printf("enter no of items");
	 scanf("%d",&n);
	 val = (int*)malloc( n*sizeof(int)); 
	 wt= (int*)malloc( n*sizeof(int)); 
	 printf("enter the values");
	 for (int i=0;i<n;i++){
		 scanf("%d",&val[i]);
	 }
	 printf("enter its corresponing weights ");
	 for (int i=0;i<n;i++){
		 scanf("%d",&wt[i]);
	 }
	printf("The maximum value that can be put in a knapsack of capacity %d is: %d",capacity, F(capacity, n));
	return 0;
}
/*
Sample I/O and O/P
Enter maximum capacity5
enter no of items4
enter the values12 10 20 15
enter its corresponing weights 2 1 3 2
The maximum value that can be put in a knapsack of capacity 5 is: 37

Time Complexity: O(2^n) where n is no of items .
Auxiliary Space :O(1) As no extra data structure has been used for storing values.
*/
