/* 
Floyd Warshall Algorithm is the All Source Shortest path algorithm, ie it gives the shortest path from each vertex 
 to the other vertices in the graph.
 1. It can work on the negative weighted edges.
 2. It can also be used to detect cycle in the graph.

 ALGORITHM:
 => Form a 2d matrix of distances dist[][]
          dist[i][j] denotes the distance to reach 'j' from 'i'
 
 => Now iterate over each dist[][] matrix k times (0<=k<=V) picking k as intermediate vertex for each dist[i][j]
   ie. we have to check if there is path to reach j from i through k
 
 => if the distance to reach j from i is greater than the distance to reach j from i taking k as intermediate 
    if(dist[i][j] > dist[i][k] + dist[k][j])
       then update the value 
        dist[i][j] = dist[i][k] + dist[k][j];
    else
      continue;

 => At the end the "dist" matrix contains the shortest distance from each vertex to all the other vertices

*/

#include <bits/stdc++.h>
#define inf 100000
using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>> graph)
{
    vector<vector<int>> dist(graph);
    int V = graph.size();
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

int main()
{
    // input the number of vertices and number of edges
    int n, e;
    cin >> n >> e;

    // we have initialise the distance of each node as infinity for start
    vector<vector<int>> graph(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
        graph[i][i] = 0;

    // input the edges with their distance
    while (e--)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x][y] = w;
    }

    auto final_distances = floyd_warshall(graph);

    for (int i = 0; i < final_distances.size(); i++)
    {
        for (int j = 0; j < final_distances.size(); j++)
        {
            cout << final_distances[i][j] << " ";
        }
        cout << endl;
    }
}

/*
INPUT
4 6 
0 1 3
0 3 5
1 0 2      
1 3 4
2 1 1
3 2 2     

OUTPUT
0 3 7 5
2 0 6 4
3 1 0 5
5 3 2 0
*/