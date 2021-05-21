/*
Given total number of nodes in an undirected graph
numbered from 1 to n [ number of nodes] and total number of edges in the graph.
Find  minimum distance of each node using SSSP (Single Source Shortest Path) on trees
by DFS.
*/

#include <stdio.h>

int adj[10009][1009];
int visited[10009];
int distance_array[10009];

// this function will print the minimum distance
void print_minimum_distance_of_each_nodes(int nodes)
{
    for(int i = 1; i <= nodes; i++)
    {
        printf("%d ", distance_array[i]);
    }
    printf("\n");
}

// this get_number_of_divisors will count the number of divisors of the number
void dfs(int node, int dist, int nodes)
{
    /* for each node we will put  visited[node] = 1
    means that node is visited
    and put distance_array[node] = dist means current distance.
    and then recursively will visit the
    adjacency matrix
     */
    visited[node] = 1;
    distance_array[node] = dist;
    for(int i = 1; i <= nodes; i++)
    {
        if(adj[node][i] != 0 && visited[i] == 0)
        {
            dfs(i , distance_array[node] + 1, nodes);
        }
    }

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

    /* here dfs call(1, 0)
    from 1th node distance is 0
    */
    dfs(1, 0, nodes);
    printf( "Minimum Distance of Each Nodes: \n");
    print_minimum_distance_of_each_nodes(nodes);

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

Minimum Distance of Each Nodes:
0 1 2 0 4 3 5 5

Time Complexity :  O(N*N) N = nodes

Space Complexity : O(N) N = nodes

*/
