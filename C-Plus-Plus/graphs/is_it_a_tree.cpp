/*Given the number of nodes and edges of graph check if it's a tree topology*/

#include <iostream>
#include <vector>
using namespace std;

int nodes, edges, u, v;
vector<int> arr[100001];    //Adjacency List storing the graph
vector<int> vis(100001, 0); //Visited array, it stores wheather the node is visited or not

void dfs(int v)
{
    /*We mark the node as visited and then 
    recursively visit every unvisited child*/

    vis[v] = 1;
    for (auto child : arr[v])
        if (vis[child] == 0)
        {
            dfs(child);
        }
}

int main()
{
    cout << "Enter nodes and number of edges: ";
    cin >> nodes >> edges;
    cout << "Enter the edges:- \n";
    for (int i = 1; i <= edges; i++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int cc_cnt = 0; //Inititalize the number of connected components

    //This loop counts the number of connected components in the graph
    for (int i = 1; i <= nodes; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
            cc_cnt++;
        }
    }

    //If the number of connected componets is equal to nodes-1 then it is a tree
    if (cc_cnt == 1)
    {
        cout << "This graph is a tree\n";
    }
    else
    {
        cout << "This graph is a tree\n";
    }
    return 0;
}

/*
Sample Input Output :-

Enter nodes and number of edges: 4 3
Enter the edges:- 
1 2
2 3
1 4
This graph is a tree

Time Complexity : O( N+E) // Nodes and Edges
Space Complexity : O( N )

*/