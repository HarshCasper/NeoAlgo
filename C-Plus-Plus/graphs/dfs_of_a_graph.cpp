/*
Depth first search is a graph traversal technique.
*/

#include<bits/stdc++.h>
using namespace std;
void dfs(int source, vector <int> adj[],bool visited[]){
    //visit the source
    cout<<source<<" ";
    //mark visited as true
    visited[source] = true;
    //Traverse all its adjacents
    for(auto s:adj[source]){
        //Check if the adjacent is not visited
        if(!visited[s]){
            //Do the same for this vertex i.e. call dfs for this adjacent as source
            //This lets you reach the depth of the graph, So you traverse down a hirearchy instead of going to all adjacents as we do in bfs
            dfs(s,adj,visited);
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    vector <int> adj[n];
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool visited[n];
    memset(visited,false,sizeof(visited));
    //Calling dfs for all non visited graphs to cover non connected compnents in graph
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited);
        }
    }cout<<endl;
    return 0;
}
/*
Input:
4 5
0 1
2 3
1 3
0 3
1 2
Output:
0 1 3 2

Time Complexity: O(n+m) //Sum of vertices and edges
Space Complexity: O(n)  //For the visited array
*/
