/*
BFS stands for Breadth First Search. DFS stands for Depth First Search.
DFS and BFS are both used to traverse in a graph.
DFS uses Stack data structure.
BFS uses Queue data structure.
*/

#include <stdio.h>
int a[20][20], queue[20], visited[2][20], n, front = -1, rear = -1;
int linearSearch(int);
void bfs(int v)
{
    for (int i = 0; i < n; i++) // check all the vertices in the graph
    {
        if (a[v][i] != 0 && visited[0][i] == 0) // adjacent to v and not visited
        {
            rear = rear + 1;
            queue[rear] = i;   // insert them into queue
            visited[0][i] = 1; // mark the vertex visited
            printf("%d  ", visited[1][i]);
        }
    }
    front = front + 1;     // remove the vertex at front of the queue
    if (front <= rear)     // as long as there are elements in the queue
        bfs(queue[front]); // peform bfs again on the vertex at front of the queue
}
void dfs(int v)
{
    int j = v;
    printf("%d  ", visited[1][j]);
    visited[0][v] = 1;

    for (int i = 0; i < n; i++)
       if(a[v][i]==1 && !visited[0][i])
           dfs(i);
}
void main()
{
    int v, i, j;
    printf("\nEnter the number of vertices:");
    scanf("%d", &n);
    // mark all the vertices as not visited
    for (i = 0; i < n; i++)
    {
        visited[0][i] = 0;
    }
    //input the vertices of the graph
    printf("\nEnter the vertices : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &visited[1][i]);
    }
    printf("\nEnter graph data in adjacency matrix of the graph :\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter the starting vertex :");
    scanf("%d", &v);
    //logic for bfs traversal
    front = rear = 0;
    queue[rear] = v;
    visited[0][linearSearch(v)] = 1; // mark the starting vertex as visited
    printf("\nBFS traversal is : ");
    printf("%d  ", v);
    bfs(linearSearch(v));
    if (rear != n - 1)
        printf("\nBFS is not possible");
    //mark all the vertices as not visited
    for (i = 0; i < n; i++)
    {
        visited[0][i] = 0;
    }
    //logic for dfs traversal
    printf("\nDFS traversal is : ");
    dfs(linearSearch(v));
}
int linearSearch(int element)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[1][i] == element)
            return i;
    }
}

/*
Test case :
Enter the number of vertices:8
Enter the vertices : 1 2 3 6 7 8 9 12
Enter graph data in adjacency matrix of the graph :
0 1 0 0 1 1 0 0
1 0 1 1 0 0 0 0
0 1 0 0 0 0 0 0
0 1 0 0 0 0 0 0
1 0 0 0 0 0 0 0
1 0 0 0 0 0 1 1
0 0 0 0 0 1 0 0
0 0 0 0 0 1 0 0
Enter the starting vertex :1
BFS traversal is : 1  2  7  8  3  6  9  12
DFS traversal is : 1  2  3  6  7  8  9  12

Time Complexity of BFS = O(V+E) where V is vertices and E is edges.
Time Complexity of DFS = O(V+E) where V is vertices and E is edges.
*/