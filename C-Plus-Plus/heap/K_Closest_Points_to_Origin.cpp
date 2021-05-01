/*
K Closest Points to Origin
=================================

Problem Statement:
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k,
Print the k closest points to the origin i.e (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e, √(x1 - x2)^2 + (y1 - y2)^2).

Concept:
For all the pairs in the points array we calculate the eucledian distance between that point and the origin.
We store a pair of the point and the eucledian distance in a Min-Heap.
We use a Min-Heap because we need first K closest point i.e points with minimum distance from the origin.
At the end we print first K points from the Min-Heap.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
// made a user defined pair which would be of the form {distance, coordinate}
using user_defined_pair = pair<long long, vector<int>>; 

// calculate eucledian distance between point and (0, 0)
long long eucledian_distance(vector<int> coordinates) 
{
    int x = coordinates[0];
    int y = coordinates[1];
    return sqrt(x * x + y * y);
}

vector<vector<int>> kClosest(vector<vector<int>> points, int k)
{
    // syntax to create a min_heap
    priority_queue<user_defined_pair, vector<user_defined_pair>, greater<user_defined_pair>> min_heap; 
    vector<vector<int>> result;

    for (auto coordinates : points)
    {
        float distance = eucledian_distance(coordinates);
        user_defined_pair distance_coordinate_pair = {distance, coordinates};
        // push a pair of {distance, coordinate} in min_heap
        min_heap.push(distance_coordinate_pair); 
    }

    while (k != 0)
    {
        user_defined_pair distance_coordinate_pair = min_heap.top();
        // add first k coodinates in result vector
        result.push_back(distance_coordinate_pair.second); 
        min_heap.pop();
        k--;
    }

    return result;
}

int main()
{
    vector<vector<int>> points;
    vector<vector<int>> result;
    int k;
    int rows;
    int x;
    int y;

    cin >> rows;

    for (int i = 0; i < rows; i++)
    {
        vector<int> coordinate;
        cin >> x;
        cin >> y;
        coordinate.push_back(x);
        coordinate.push_back(y);
        points.push_back(coordinate);
    }

    cin >> k;

    result = kClosest(points, k);

    for (auto pair : result)
    {
        for (auto coordinate : pair)
        {
            cout << coordinate << " ";
        }
        cout << endl;
    }
}

/*
Time Complexity: O(NlogK)
Space Complexity: O(N)

Input:
points = [[1,3],[-2,2]]
k = 1

Output:
[[-2, 2]]

Explanation:
Eucledian Distance between [1,3] and origin i.e [0, 0] is sqrt(10).
Eucledian Distance between [-2,2] and origin i.e [0, 0] is sqrt(8).
As sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Input 2: 
points = [[3,3],[5,-1],[-2,4]]
k = 2

Output:
[[3,3],[-2,4]]
*/
