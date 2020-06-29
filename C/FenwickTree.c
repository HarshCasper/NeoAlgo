**Fenwick Tree**

#include <stdio.h>

int FWtree[100] = {0};
int SIZE;

int get_sum(int i)
{
	int sum = FWtree[i];
	while(i)
	{
		i -= (i & (-i));
		sum += FWtree[i];
	}
	return sum;
}

void add(int i, int value)
{
	while(i < SIZE)
	{
		FWtree[i] += value;
		i += (i & (-i));
	}
}

void init_fw_tree(int my_array[], int start, int end)
{
	SIZE = end-start+2;
	for(int i = 1; i <= end-start+2; i++)
	{
		add(i, my_array[ start+i-1 ]);
	}
}

int main()
{
	int my_array[] = {1, 3, 4, 6, 5 ,9, 6, 5 ,0, 2, 5, 3, 2, 2};
	init_fw_tree(my_array, 0, 13);

	//get sum of all the numbers in the array
	printf("Sum of all numbers in the array is= %d\n",get_sum(14));
	
	// update 5th index with value 9
	add(5,9);
	printf("New sum after updating 5th index with value 9 is = %d\n",get_sum(14));

	return 0;
}
