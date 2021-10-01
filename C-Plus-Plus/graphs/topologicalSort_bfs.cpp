//Print the topological sort of directed acyclic graph
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the nodes and edges: \n";
    cin >> n >> m;
    //For storing the graph in adjacency list
    vector<int> arr[n];
    //For storing the visited nodes
    vector<int> vis(n, 0);
    //For storing the indegree of nodes
    vector<int> indegree(n, 0);
    queue<int> q;
    cout << "Enter the edges\n";
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }
    //Calculating indegree of nodes
    for (int i = 0; i < n; i++)
    {
        for (auto child : arr[i])
        {
            if (vis[child] == 0)
            {
                indegree[child]++;
            }
        }
    }
    //Push the nodes with indegree 0 in queue
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    /*Implement bfs for each node in queue and as you visit
    the child node reduce its indegree and if its indegree is
    0 then push it inside queue */
    cout << "Topological Sort-> ";
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int child : arr[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
                q.push(child);
        }
    }
}
/*
Sample Input Output :-
Enter the nodes and edges: 
6 6
Enter the edges
5 0
4 0
4 1
3 1
5 2
2 3
Topological Sort-> 4 5 0 2 3 1 

Time Complexity : O( N+E) // Nodes and Edges
Space Complexity : O( N+E )+O(N)
*/