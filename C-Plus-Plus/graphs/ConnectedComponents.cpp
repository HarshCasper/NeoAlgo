/*
Connected Components:- In an undirected graph, a connected component is a subgraph such that there exists at least one path connecting any of the two nodes of that graph.
Purpose: Given an undirected graph with N nodes and M edges where each node is numbered between 1 and N find the total number of connected components in the graph.
Method: Depth-First Search
Intuition: For every node of the graph that is not yet visited,
        1. we will call DFS() function to traverse the graph and marking the nodes visited.
        2. increase the count of connected components by 1
Time Complexity:  O(N+M)
Space Complexity: O(N)
*/

//                                 **********************Number of Connected Components In a Graph***************************

#include<bits/stdc++.h>
using namespace std;
 
vector<int> adj[10000001];
bool visited[10000001];
 
void dfs(int node){
    if(visited[node])
        return;
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++){
        dfs(adj[node][i]);
    }
}
 
int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<10000001;i++){
        adj[i].clear();
        visited[i]=false;
    }
    cout<<"Enter edges "<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    int c=0;
    for(int i=1;i<=n;i++){
        if(!visited[i-1]){
            dfs(i-1);
            c++;
        }
    }
    cout<<"Number of connected components "<<c<<endl;
}

/*
Sample TestCase 1:
        1-----------2         4    7
        |           |         |   /
        |           |         |  /
        |           |         | /
        |           |         |/
        3-----------5         6
7 6
Enter edges:
1 2
1 3
2 5
3 5
4 6
6 7
Number of connected components:  2

Sample Test Case 2:
8 5
Enter edges:
1 2
2 3
2 4
3 5
6 7
Number of connected components:  3
*/
