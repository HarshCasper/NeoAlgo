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
		/* Checking if the placing of cows is greater
		ie the next cows placed aren't next to each other */
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

// Time Complexity : O(nlogn)
int main()
{
	int stalls[100];
	int n;
	int cows;
	cin >> n >> cows;
	//Input of the stall coordinates
	for (int i = 0; i < n; ++i)
	{
		cin >> stalls[i];
	}

	int s = 0;
	int e = stalls[n - 1] - stalls[0];
	int ans = 0;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		bool canplacecow = canplacecows(stalls, n, cows, mid);
		
		//Checking if it is possible to place the cows far from each other
		if (canplacecow)
		{
			ans = mid;
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}

	cout << ans << "\n";
	return 0;
}
/* Example :
1)Input :
5 3
1 2 4 8 9
Output : 3

2) Input :
6 4
1 3 5 7 8 10
Output : 2  */