#include<bits/stdc++.h>
using namespace std;
//nodes 1 to n
void createAdjList(vector<int> adj[], vector<vector<int>> &edges)
{
    int m = edges.size();
    for(int i=0; i<m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);

    }
}

void dfsVisit(vector<int> &visited, vector<int> adj[], int src)
{
    visited[src] = 1;
    for(int i=0; i<adj[src].size(); i++)
    {
        if(!visited[adj[src][i]])
        {
            dfsVisit(visited, adj, adj[src][i]);
        }
    }
    cout << src << " ";
}

void dfs(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n+1];  
    vector<int> visited(n+1, 0);
    createAdjList(adj, edges);
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
            dfsVisit(visited, adj, i);
    }

}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for(int i = 0; i < m; i++) 
    {
        cin >> edges[i][0] >> edges[i][1];
    }
    cout << "DFS ordering with src=1 is " << endl;
    dfs(n, edges);
    cout << endl;
    
    return 0;
}

/*
Input
6 
6
1 6
2 6
2 5
1 3
3 4
4 5

Output
DFS ordering with src=1 is 
3 4 5 2 6 1 

Complexity:
Space: O(V+E)
Time: O(V+E)

*/