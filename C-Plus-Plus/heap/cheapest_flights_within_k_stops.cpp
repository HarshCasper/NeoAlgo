/*
	Question link :https://leetcode.com/problems/cheapest-flights-within-k-stops/
	
	There are n cities connected by m flights. 
	Each flight starts from city u and arrives at v with a price w.
	Now given all the cities and flights, together with starting city src
 	and the destination dst, 
	your task is to find the cheapest price from src to dst with up to k stops. 
	If there is no such route, output -1.

	Example :
	Input: 
	n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
	src = 0, dst = 2, k = 1
	Output: 200

*/

#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{

    vector<vector<pair<int, int>>> a(n);
    for (vector<int> &f : flights)
        a[f[0]].push_back({f[1], f[2]});

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    //We push the distance,source and the number of edges
    pq.push({0, src, K + 1});

    while (!pq.empty())
    {
        vector<int> t = pq.top();
        pq.pop();

        //get the distance,vertex and number of edges

        int u = t[1];
        int distance = t[0];
        int edges = t[2];

        //if the destination becomes equal to the vertex we return the  distance
        if (dst == u)
            return distance;

        //If we can add any edges
        if (edges > 0)
        {
            //We search all the neighbours and push the distance and vertex level of the neighbour
            for (pair<int, int> &v : a[u])
                pq.push({distance + v.second, v.first, edges - 1});
        }
    }
    return -1;
}

int main()
{
    int n, src, dst, k, temp;
    cin >> n >> src >> dst >> k;

    vector<vector<int>> edges(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            cin >> edges[i][j];
        }
    }
    int price = findCheapestPrice(n, edges, src, dst, k);
    //Print the cheapest price
    cout << price;
    return 0;
}
/*
   		Time complexity:O(nlogn)
   		Space Complexity:O(n)
   */
/*
    Input:
	3 0 2 1
   
	0 1 100
	1 2 100
	0 2 500
	
	Output:
	200
	*/
