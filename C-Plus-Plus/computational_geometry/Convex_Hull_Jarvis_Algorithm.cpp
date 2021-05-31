/*

Convex Hull (Jarvis's Algorithm)

Convex Hull is the outermost polygon that can be formed from a set of
points such that it encloses all other points in the set and none of its corners
are bent inwards.
*/

#include <bits/stdc++.h>
using namespace std;

// POINT data structure
typedef struct POINT
{
	int x;
	int y;
} POINT;

// Gives orientation of p->q->r
int orientation(POINT p, POINT q, POINT r)
{
	int slope = (p.y - r.y) * (p.x - q.x) - (p.y - q.y) * (p.x - r.x);
	// clockwise
	if (slope > 0)
		return 1;
	// anti-clockwise
	if (slope < 0)
		return -1;
	// collinear
	else
		return 0;
}

// Prints point
void printPoint(POINT a)
{
	cout << a.x << " " << a.y;
}

// Returns whether two points are same
bool isSame(POINT a, POINT b)
{
	return (a.x == b.x && a.y == b.y) ? 1 : 0;
}

// Prints the points in convex hull
void convexHull(POINT arr[], int n)
{
	if (n < 3)
		return;

	// Stores the points in convex hull
	vector<POINT> result;

	// Find the leftmost point
	int leftMost = 0; // Index of leftMost point
	for (int i = 0; i < n; i++)
	{
		if (arr[leftMost].x > arr[i].x)
		{
			leftMost = i;
		}
	}

	// leftMost point will be part of convex hull
	result.push_back(arr[leftMost]);

	int curr = leftMost;
	while (1)
	{
		// Index of next target which can potentially be in hull
		int nextTarget = (curr + 1) % n;

		// Checking whether nextTarget can be in hull
		// nextTarget will be part of hull if there doesnot exist a point which is
		// more anti-clockwise than curr -> nextTarget
		for (int i = 0; i < n; i++)
		{
			int o = orientation(arr[curr], arr[i], arr[nextTarget]);
			if (o == -1)
			{
				// curr -> i is more anticlockwise than curr -> nextTarget
				nextTarget = i;
			}
		}

		// If nextTarget comes back to start, it implies that there
		// are no more points to be added in hull
		if (nextTarget == leftMost)
			break;

		// Push nextTarget to hull
		result.push_back(arr[nextTarget]);
		curr = nextTarget;
	}

	for (int i = 0; i < result.size(); i++)
	{
		printPoint(result[i]);
		cout << endl;
	}
}

int main()
{

	int n;
	cin >> n;

	POINT arr[n];

	for (int i = 0; i < n; i++)
	{
		POINT p;
		cin >> p.x >> p.y;
		arr[i] = p;
	}

	convexHull(arr, n);
}

/*
Input:
6
0 3
2 2
0 1
0 2
0 0
-1 0
Output:
-1 0
0 3
2 2
0 0

Time Complexity: O(n*m) where n = Total points, m = Points in hull
*/

