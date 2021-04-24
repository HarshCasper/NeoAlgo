#include <stdio.h>
#include <stdbool.h>

bool array_mirror_inverse(int[], int);
int main()
{
	int n;
	bool f;
	printf("Enter the size of the array:");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements:");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	f = array_mirror_inverse(arr, n);
	if (f)
		printf("The given array is mirror-inverse");
	else
		printf("The given array is not the mirror-inverse");
}

// Boolean Function which return if the array is mirror-inverse or not
bool array_mirror_inverse(int arr[], int n)
{
	bool f = true;
	for (int i = 0; i < n; ++i)
	{
		if (arr[arr[i]] != i)
		{
			f = false;
		}
	}

	return f;
}

/*
Time Complexity: O(N)

Sample Output
Enter the size of the array:5
Enter the elements:1 0 2 4 3
The given array is mirror-inverse
*/

