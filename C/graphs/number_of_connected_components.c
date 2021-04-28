/*
Given total number of nodes in an undirected graph
numbered from 1 to n [ number of nodes] and total number of edges in the graph.
Calculate the total number of connected components in the graph.
*/

#include <stdio.h>

int adj[10009][1009];
int visited[10009];

// this dfs function will visit the nodes
void dfs(int node, int nodes)
{
    /* for each node we will put  visited[node] = 1
    means that node is visited
    and then recursively will visit the
    adjacency matrix */
    visited[node] = 1;
    for(int i = 1; i <= nodes; i++)
    {
        if(adj[node][i] != 0 && visited[i] == 0)
        {
            dfs(i , nodes);
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
            dfs(i, nodes);
            connected_components++;
        }
    }
    return connected_components;
}

int main()
{
    printf( "Enter the nodes of the graph :\n");
    int nodes;
    scanf("%d",&nodes);
    printf( "Enter the adjacency matrix :\n");
    for(int i = 1; i <= nodes; i++)
    {
        for(int j = 1; j <= nodes; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    int connected_components = get_connected_components(nodes);

    printf("Number of Connected Components in this graph is: \n");
    printf("%d \n", connected_components);
}

/*
Standard Input and Output

Enter the nodes of the graph :
8
Enter the adjacency matrix :
0 1 1 0 1 0 1 1
0 1 1 0 1 0 1 1
1 1 1 0 0 1 0 1
0 0 0 1 1 0 1 1
0 1 1 0 0 1 1 1
1 1 0 0 1 1 1 1
1 0 1 0 0 1 1 0
1 0 1 0 1 0 1 0

Number of Connected Components in this graph is:
2

Time Complexity :  O(N*N) N = nodes

Space Complexity : O(N) N = nodes

*/
