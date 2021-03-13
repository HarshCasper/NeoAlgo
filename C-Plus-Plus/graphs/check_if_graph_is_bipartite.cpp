
/*
Here we need to check whether given graph
is bipartite or not. For that firstly we need to
Know what is a bipartite graph.
Graph which is 2-colorable is a bipartite means if
we can color the nodes of graph with just 2 colors
where every 2 nodes joined by a edge have different
colors
We can solve this problem by various methods like
BFS,DFS,Backtracking.
Also I am taking unweighted and undirected and connected graph
I am showing this problem by use of DFS and adjacency
list representation of graph
*/


#include <bits/stdc++.h>
using namespace std;

bool isbipartite(vector<int> adj[],int n,vector<bool> &visited,vector<int> &color){

   // n denotes node which is to be traversed

   for(auto u: adj[n]){
        // checking if node is visited on not
        if(visited[u]==false){
            // mark it visited
            visited[u]=true;
            // providing color to node
            color[u]=1-color[n];
            // traversing the edges of node u
            if(!isbipartite(adj,u,visited,color)){
                    return false;
            }
        }
        // if node is visited then it must have different color with n
        // else graph is not bipartite
        else if(color[u]==color[n]){
            return false;
        }
   }
   // we successfully traversed all edges of n and all nodes have different color
   return true;


}


int main() {
    int V; // no of vertex
    int E; // no of edges
    cin>>V>>E;
    vector<int> adj[V+1]; // list representation of graph

    vector<bool> visited(V+1); // to make sure we visit each vertex once
    vector<int> color(V+1); //assigning color to vertices and here 1 am using 2 colors 0 and 1

    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v; // there is a edge between u and v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // marking first node to be visited
    visited[1]=true;
    color[1]=0;
    if(isbipartite(adj,1,visited,color)){
        cout<<"Graph is bipartite\n";

        //  if we want to print color of each node
          for(int i=1; i<=V; i++){
             cout<<"Color of node "<<i<<" is: "<< color[i]<<"\n";
          }


    }
    else{
        cout<<"Graph is not bipartite\n";
    }


    return 0;
}
/*
Input
6 6
1 2
2 3
3 4
4 5
5 6
6 1

Output
Graph is bipartite
Color of node 1 is: 0
Color of node 2 is: 1
Color of node 3 is: 0
Color of node 4 is: 1
Color of node 5 is: 0
Color of node 6 is: 1

