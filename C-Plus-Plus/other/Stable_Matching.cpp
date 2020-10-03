/*Given n men and n women, where each person has ranked all members of the opposite sex in order of preference, marry the men and women together such that there are no two people of opposite sex who would both rather have each other than their current partners. When there are no such pairs of people, the set of marriages is deemed stable.
A matching is stable when there does not exist any match (A, B) which both prefer each other to their current partner under the matching.*/
#include <bits/stdc++.h>
using namespace std;

// Number of Men or Women 
int N;

// This function returns true if woman 'w' prefers man 'm1' over man 'm' 
bool wPrefersM1OverM(vector<vector < int>> &prefer, int w, int m, int m1)
{
	// Check if w prefers m over her current engagment m1 
	for (int i = 0; i < N; i++)
	{
		// If m1 comes before m in lisr of w, then w prefers her 
		// cirrent engagement, don't do anything 
		if (prefer[w][i] == m1)
			return true;

		// If m comes before m1 in w's list, then free her current 
		// engagement and engage her with m 
		if (prefer[w][i] == m)
			return false;
	}
}

void stableMarriage(vector<vector < int>> &prefer)
{
	int size = prefer[0].size();
	vector<int> wPartner(size, -1);

	vector<bool> mFree(size, false);

	int freeCount = N;

	// While there are free men 
	while (freeCount > 0)
	{
		// Pick the first free man (we could pick any) 
		int m;
		for (m = 0; m < N; m++)
			if (mFree[m] == false)
				break;

		for (int i = 0; i < N && mFree[m] == false; i++)
		{
			int w = prefer[m][i];

			// The woman of preference is free, w and m become partners 
			if (wPartner[w - N] == -1)
			{
				wPartner[w - N] = m;
				mFree[m] = true;
				freeCount--;
			}
			else	// If w is not free 
			{
				// Find current engagement of w 
				int m1 = wPartner[w - N];

				// If w prefers m over her current engagement m1, 
				// then break the engagement between w and m1 and 
				// engage m with w. 
				if (wPrefersM1OverM(prefer, w, m, m1) == false)
				{
					wPartner[w - N] = m;
					mFree[m] = true;
					mFree[m1] = false;
				}
			}
		}
	}

	// Print the solution 
	cout << " W" << "\t" << "M" << endl;
	for (int i = 0; i < N; i++)
		cout << " " << i + N << "\t" << wPartner[i] << endl;
}

// Driver program to test above functions 
int main()
{
	int testcases;
	cin >> testcases;
	while (testcases-- > 0)
	{
		int a;
		cin >> a;
		N = a;
		vector<vector < int>> prefer;
		//below is an empty 1D vector
		vector<int> one_D_vector(5, 0);
		//pushing back the above 1D vector to the 
		//empty 2D vector each time
		for (int i = 0; i < 2 * a; i++)
		{
			prefer.push_back(one_D_vector);
		}

		for (int i = 0; i < 2 * a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				int jj;
				cin >> jj;
				prefer[i][j] = jj;
			}
		}

		stableMarriage(prefer);
	}

	return 0;
}

/*Sample Input/Output
        1 
        4
        7 5 6 4 
        5 4 6 7 
        4 5 6 7 
        4 5 6 7 
        0 1 2 3 
        0 1 2 3 
        0 1 2 3 
        0 1 2 3 

         Woman   Man
         4      2
         5      1
         6      3
         7      0

time complexity: O(n^2)
space complexity: O(n^2)*/