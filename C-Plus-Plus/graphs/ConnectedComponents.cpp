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
    cout<<c<<endl;
}
