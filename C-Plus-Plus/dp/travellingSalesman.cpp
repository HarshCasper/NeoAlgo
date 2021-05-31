/*
Given a list of cities numbered from 0 to N-1 and a matrix “distances” consisting of N rows and N columns 
denoting the distances between each pair of cities, what is the shortest possible route that visits each 
city exactly once and returns to the starting city?
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int getMinDistance(int mask, int currentCity, vector<vector<int>> &dp, vector<vector<int>> &distance)
{
	int n = distance.size();

	// All cities being visited.
	if (mask == (1 << n) - 1)
	{
		return distance[currentCity][0];
	}

	// If the current state (mask, currentCity) is visited before.
	if (dp[mask][currentCity] != -1)
	{
		return dp[mask][currentCity];
	}

	int ans = 1e9 + 5;

	// Trying for every possible city and computing the shortest possible route.
	for (int city = 0; city < n; city++)
	{
		if ((mask & (1 << city)) == 0)
		{
			int tmpAns = distance[currentCity][city] + getMinDistance(mask | (1 << city), city, dp, distance);
			ans = min(ans, tmpAns);
		}
	}

	// Memorizing and return the ans.
	return dp[mask][currentCity] = ans;
}

int shortestRoute(vector<vector<int>> &distance)
{
	int n = distance.size();

	vector<vector<int>> dp((1 << n) + 1, vector<int>(n + 1, -1));

	// Return the ans returned by getMinDistance.
	return getMinDistance(1, 0, dp, distance);

}

int main()
{
    int N;
    cout<<"Enter number of cities: "<<endl;
    cin>>N;
    cout<<"Enter the distances: "<<endl;
    vector<vector<int>> distance;
    int val;
    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < N; j++){
            cin >> val;
            temp.push_back(val);
        }
        distance.push_back(temp);
        temp.clear();
    }
    cout<<"The shortest possible route that visits each city exactly once and returns to the starting city: "<<endl;
    cout<<shortestRoute(distance);
}

/*
    Time Complexity : O(2^N * N)
    Space Complexity : O(2^N * N)
    where N is the size in the given array.
    
    Sample Input:
    Enter number of cities: 
    4
    Enter the distances: 
    0 20 42 25
    20 0 30 34
    42 30 0 10
    25 34 10 0
    
    Sample Output:
    The shortest possible route that visits each city exactly once and returns to the starting city: 
    85
*/
