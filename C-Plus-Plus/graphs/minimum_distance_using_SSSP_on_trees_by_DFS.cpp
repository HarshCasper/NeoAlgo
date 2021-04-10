/*
Given total number of nodes in an undirected graph
numbered from 1 to n [ number of nodes] and total number of edges in the graph.
Find  minimum distance of each node using SSSP (Single Source Shortest Path) on trees
by DFS.
*/

#include <bits/stdc++.h>
using namespace std;
vector < int > adj[10009];
int visited[10009];
int distance_array[10009];

// this function will print the minimum distance
void print_minimum_distance_of_each_nodes(int nodes)
{
    for(int i = 1; i <= nodes; i++)
    {
        cout << distance_array[i] << ' ';
    }
    cout << endl;
}

// this dfs function will visit the nodes
void dfs(int node, int dist)
{
    /* for each node we will put  visited[node] = 1
    means that node is visited
    and put distance_array[node] = dist means current distance.
    and then recursively will visit the
    adjacency vector
     */
    visited[node] = 1;
    distance_array[node] = dist;
    for(auto child : adj[node])
    {
        if(visited[child] == 0)
        {
            // will update the distance each step
             dfs(child , distance_array[node] + 1);
        }
    }

}

int main()
{
    cout << "Enter the nodes and edges of the graph :\n";
    int nodes, edges;
    cin >> nodes >> edges;
    cout << "Enter the start and end points that have edges \n";
    for(int i = 1; i <= edges; i++)
    {
        int point1, point2;
        cin >> point1 >> point2;
        adj[point1].push_back(point2);
        adj[point2].push_back(point1);

    }
    /* here dfs call(1, 0)
    from 1th node distance is 0
    */
    dfs(1, 0);

    cout << "Minimum Distance of Each Nodes: \n";
    print_minimum_distance_of_each_nodes(nodes);
}

/*
Standard Input and Output

Enter the nodes and edges of the graph :
6 5
Enter the start and end points that have edges
1 2
1 3
1 4
2 5
2 6

Minimum Distance of Each Nodes:
0 1 1 1 2 2

Time Complexity : O( E + N) // Edges and Nodes
Space Complexity : O( N )

*/
