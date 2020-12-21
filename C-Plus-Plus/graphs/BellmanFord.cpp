
/*Input:
First line contains two space separated integers,(N,M) 
N- no of vertices, M- no of edges.
Then M lines follow, each line has 3 space separated integers ui ,vi ,wi which denotes edge from vertex ui to vi with weight wi.
Find shortest distance from vertex 1 to all other vertices.


TEST CASE
5 5
1 2 5
1 3 2
3 4 1
1 4 6
3 5 5

OUTPUT
5 2 3 7 */


#include<bits/stdc++.h>
using namespace std;

vector<int>edges[1000001];
int dist[1000001];

void bellmanFord(int n){
  for(int i=0;i<n-1;i++){
    int k=0;
    while(edges[k].size()>0){
      int u=edges[k][1],v=edges[k][2],w=edges[k][0];
      if(dist[v]>dist[u]+w){
        dist[v]=dist[u]+w;
      }
      k++;
    }
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    edges[i].clear();
    dist[i]=1e9;
  }
    
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edges[i].push_back(w);
    edges[i].push_back(u-1);
    edges[i].push_back(v-1);
  }
  dist[0]=0;

  bellmanFord(n);

  cout<<"Shortest distance to all vertices from vertex 1 is- "<<endl;
  for(int i=1;i<n;i++){
  cout<<dist[i]<<" ";
  }
}
/*
Time- complexity
    O(VE)
    If there are 'n' vertices, then there can be n(n-1)/2 edges thus the worst case time complexity is O(n^3).
Space Complexity-
    O(V)

Bellman Ford algorithm can handle negative weights which dijkstra couldn't. However it cannot handle negative cycles and have more complexity than Dijkstra.
*/
