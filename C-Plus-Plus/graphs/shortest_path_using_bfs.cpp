#include<bits/stdc++.h>
using namespace std;
void bfs(int source,vector <int> adj[],bool visited[],int parent[]){
    //Initializing a queue and pushing the source into it and marking visited for source as true
    queue<int> q; 
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        //Traversing all the adjacents of the node
        for(auto s: adj[curr]){
            //Checking if this adjacent is visited or not
            if(!visited[s]){
                //Pushing into the queue
                q.push(s);
                //Marking visited as true
                visited[s] = true;
                //If not visited, this parent is the one closet to the source, i.e from 0->curr->s is the shortest path till s
                parent[s] = curr;
            }
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
    //Parents array for storing the parent a nodes parent closest to the source
    int parent[n];
    //Considering 0 as the source
    parent[0] = -1;
    bfs(0,adj,visited,parent);
    //Printing shortest paths for each node from node 0
    for(int i=1;i<n;i++){
        int curr = i;
        vector<int> ans;
        while(curr!=-1){
            ans.push_back(curr);
            curr = parent[curr];
        }
        reverse(ans.begin(),ans.end());
        for(auto s: ans){
            cout<<s<<" ";
        }cout<<endl;
    }
    return 0;
}
/*
Input:
6 7
0 1
1 2
2 0
0 3
3 4
4 5
1 5

Output:
0 1 
0 2 
0 3 
0 3 4 
0 1 5

Time complexity : O(n+m)
Space complexity : O(n)
*/
