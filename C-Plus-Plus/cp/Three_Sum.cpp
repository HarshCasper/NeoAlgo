/*
Description :   
Three Sum Problem - In this problem, user will provide an array and we
                    have find wether there is any "three" numbers are 
                    present in the array who's sum is equal to the target 
		            provided. If it is present then it will show true else 
                    it will show false.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// n= size of an array
	int n;
	cout << "Enter the size of an array : " << endl;
	cin >> n;
	//target = the number who's sum we have find.
	int target;
	cout << "Enter the target you want to set : " cin >> target;

	//n size of array
	vector<int> a(n);
	//taking input in the array
	cout << "Enter " << n << " number of elements : " << emdl;
	for (auto &i : a)
	{
		cin >> i;
	}
	bool found = false;
	//sorting the array
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
	{
		int low = i + 1, high = n - 1;
		while (low < high)
		{
			int current = a[i] + a[low] + a[high];
			if (current == target)
			{
				found = true;
			}
			if (current < target)
			{
				low++;
			}
			else
			{
				high--;
			}
		}
	}
	if (found)
	{
		cout << "True : Target value is present !";
	}
	else
	{
		cout << "False : Target value is not present !";
	}
}

/*
Time Complexity  : O(n*n)
Space Complexity : O(n)

Test Cases :
Test Case  1: 
    Input :
	Enter the size of an array : 
	6
	Enter the target you want to set : 
	24
	Enter 6 number of elements : 
	102 3 6 9 34 24

	Output : True  : Target value is present !

Test Case 2:
    Input :
	Enter the size of an array : 
	6
	Enter the target you want to set : 
	24
	Enter 6 number of elements : 
	2 3 6 9 3 25

	Output : False : Target value is not present !
*/
