#include<stdio.h>

void sort(int a[1000], int n)
{
	//using bubble sort
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= (n - 2) - i; j++)
		{
			if (a[j] > a[j + 1]) // if a[j] > a[j+1] then swap them
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void tripletSum(int a[1000], int n, int target)
{
	int i = 0, j, k;
	for (i = 0; i < n; i++) // to traverse the whole array we need a foor loop from i to n-1
	{
		j = i + 1;
		k = n - 1; // using 2 iterator approach
		while (j < k) // loop will stop when j==k
		{
			if (a[i] + a[j] + a[k] == target) //if triplet sum is equal to target then print it
			{
				printf("%d, %d and %d\n", a[i], a[j], a[k]);
				j++;
				k--; //update both iterator as we have find a triplet sum equal to target

			} else if (a[i] + a[j] + a[k] > target) // if triplet sum is less than target then decrement the 3 iterator k
			{
				k--;
			} else // increment the 2nd iterator j as triplet sum is greater than target
			{
				j++;
			}
		}
	}
}

int main()
{
	int a[1000], n, i, target;

	scanf("%d", & n); //input no. of elements in array
	for (i = 0; i < n; i++)
	{
		scanf("%d", & a[i]); //  input elements in array
	}

	scanf("%d", & target); //input the target number

	/* We need to sort the array as the output is in sorted form, also it would be easier to check the triplets in forward direction */
	sort(a, n); // sort the array

	//the solution is based on 2 pointer approach to find pair sum equal to target
	tripletSum(a, n, target); //call tripletSum() to find and print triplet

	return 0;
}

/*
Take as input N, the size of the array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all triplets of numbers which sum to target.
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

Time Complexity of sort function: O(n^2)
Time Complexity of tripletSum function: O(n^2)

Space Complexity of  sort function: O(1) because only 1 extra space is required for temp
Space Complexity of  tripletSum function: O(1) because no extra space is required
*/
