/*An integer x is said to be Noble given an array 
if the number of integers greater than x are equal to x.
If noble integer is not found output is -1.
*/
#include <bits/stdc++.h>
using namespace std;
int nobleint(int[], int);
int main()
{
	int num, i, x, arr[10000];
	cout << "Enter the number of elements:";
	cin >> num;
	cout << "Enter the elements:";
	for (int i = 0; i < num; i++)
	{
		cin >> x;
		arr[i] = x;
	}
	cout << nobleint(arr, num);
	return 0;
}

// To find the noble integer from the given array
int nobleint(int arr[], int num)
{
	int x = 0, i;
	sort(arr, arr + num);
	for (i = 0; i < num - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			continue;
		}

		if (arr[i] == num - i - 1)
		{
			x = 1;
			return (num - i - 1);
			break;
		}
	}
	if (x == 0)
		return (-1);
}

/*
Sample Output

Enter the number of elements:4
Enter the elements:7 3 9 81
3
Enter the number of elements:3
Enter the elements:2 2 2
-1

Complexities
Time Complexity:O(nlogn)
Space Complexity:O(1)
*/

