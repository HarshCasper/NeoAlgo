/*Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, 
such that the minimum distance between any two of them is as large as possible. 
What is the largest minimum distance?*/

#include <bits/stdc++.h>
using namespace std;

bool canplacecows(int stalls[], int n, int c, int min_sep)
{
	int last_cow = stalls[0];
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (stalls[i] - last_cow >= min_sep)
		{
			last_cow = stalls[i];
			cnt++;
			if (cnt == c)
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	int stalls[100], n, cows;
	cout<<"Enter the the total no of stalls and cows: ";
	cin >> n >> cows;

	for (int i = 0; i < n; ++i)
	{
		cin >> stalls[i];
	}

	int start = 0;
	int end = stalls[n - 1] - stalls[0];
	int ans = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		bool canplacecow = canplacecows(stalls, n, cows, mid);
		
		if (canplacecow)
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << "the largest minimum distance: " << ans << "\n";
	return 0;
}
/* Example :
1)Input :
5 3
1 2 4 8 9
Output : 3

Time Complexity : O(nlog n)
Space Complexity : O(n)

*/
