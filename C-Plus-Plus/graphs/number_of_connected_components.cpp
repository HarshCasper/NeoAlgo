/*
Given total number of nodes in an undirected graph
numbered from 1 to n [ number of nodes] and total number of edges in the graph.
Calculate the total number of connected components in the graph.
*/

#include <bits/stdc++.h>
using namespace std;
vector < int > adj[10009];
int visited[10009];

// this dfs function will visit the nodes
void dfs(int node)
{
    /* for each node we will put  visited[node] = 1
    means that node is visited
    and then recursively will visit the
    adjacency vector
     */
    visited[node] = 1;
    for(auto child : adj[node])
    {
        if(visited[child] == 0)
        {
            dfs(child);
        }
    }
}

// this get_connected_components will count the number of connected components
int get_connected_components(int nodes)
{
    int connected_components = 0;
    for(int i = 1; i <= nodes; i++)
    {
        /* if the current visited[i] is zero , that means
        that node is not visited.
        so, we will make a dfs call
        and increment the connected_components
         */
        if(visited[i] == 0)
        {
            dfs(i);
            connected_components++;
        }

    }
    return connected_components;
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
    int connected_components = get_connected_components(nodes);

    cout << "Number of Connected Components in this graph is: \n";
    cout << connected_components << endl;
}

/*
Standard Input and Output

Enter the nodes and edges of the graph :
8 5
Enter the start and end points that have edges
1 2
2 3
2 4
3 5
6 7

Number of Connected Components in this graph is:
3

Time Complexity : O( E + N) // Edges and Nodes
Space Complexity : O( N )

*/
