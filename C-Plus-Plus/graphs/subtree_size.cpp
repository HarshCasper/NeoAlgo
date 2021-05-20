/*Given the number of nodes and edges of graph print an array containg subtree size of each node*/

#include <bits/stdc++.h>
using namespace std;

//Adjacency List storing the graph
vector<int> arr[50];
//Visited array, it stores wheather the node is visited or not
vector<int> vis(50, 0);
//Subsize array, it stores the subtree size of each node
vector<int> subsize(50, 0);

int dfs(int node)
{
    /*We mark the node as visited and then 
    recursively visit every unvisited child on 
    each call we increament the size of subtree 
    till we reach the last child of that node */
    vis[node] = 1;
    int curr_size = 1;
    for (auto child : arr[node])
    {
        if (vis[child] == 0)
            curr_size += dfs(child);
    }
    subsize[node] = curr_size;
    return curr_size;
}

int main()
{
    int nodes, edges, u, v;
    cout << "Enter nodes and number of edges: ";
    cin >> nodes >> edges;
    cout << "Enter the edges:- \n";
    for (int i = 1; i <= edges; i++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1);
    cout << "Subtree size array : \n";
    for (int i = 1; i <= nodes; i++)
    {
        cout << subsize[i] << " ";
    }
}

/*
Sample Input Output :-

Enter nodes and number of edges: 6 5
Enter the edges:- 
1 2
1 3
2 4
2 5
3 6
Subtree size array :
6 3 2 1 1 1 

Time Complexity : O( N+E) // Nodes and Edges
Space Complexity : O( N )

*/