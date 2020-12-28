
/*Input:
First line contains two space separated integers,(N,M) 
N- no of vertices, M- no of edges.
Then M lines follow, each line has 3 space separated integers ui ,vi ,wi which denotes edge from vertex ui to vi with weight wi.
In the given graph, detect wheather any negative cycle is present or not.


TEST CASE
4 4
1 2 1
2 3 -1
3 4 -1
4 1 -1

OUTPUT
Negative Cycle Present */


#include<bits/stdc++.h>
using namespace std;

struct Edge { 
  int src, dest, weight; 
}; 

struct Graph { 
  int V, E; 
  struct Edge* edge; 
}; 
  
struct Graph* createGraph(int V, int E) 
{ 
  struct Graph* graph = new Graph; 
  graph->V = V; 
  graph->E = E; 
  graph->edge = new Edge[E]; 
  return graph; 
} 

bool containNegativeCycle(struct Graph* graph, int src){
  int V = graph->V; 
  int E = graph->E; 
  int dist[V];

  for (int i = 0; i < V; i++) 
    dist[i] = INT_MAX; 
  dist[src] = 0;

  for(int i=0;i<V-1;i++){
    for (int j = 0; j < E; j++){
      int u = graph->edge[j].src; 
      int v = graph->edge[j].dest; 
      int w = graph->edge[j].weight; 
      if (dist[u] != INT_MAX && dist[u] + w < dist[v]) 
        dist[v] = dist[u] + w;
    }
  }

  for (int i = 0; i < E; i++) { 
    int u = graph->edge[i].src; 
    int v = graph->edge[i].dest; 
    int weight = graph->edge[i].weight; 
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {  
      return true; 
    } 
  } 
  return false;
}

int main(){
  int n,m;
  cin>>n>>m;
  struct Graph* graph = createGraph(n, m);
    
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    graph->edge[i].src = u-1; 
    graph->edge[i].dest = v-1; 
    graph->edge[i].weight = w;
  }

  bool negativeCycle=containNegativeCycle(graph,0);
  if(negativeCycle){
  	cout<<"Negative Cycle is Present"<<endl;
  }
  else{
  	cout<<"No negative cycle present"<<endl;
  }
  return 0;
}

/*
Time- complexity
    O(VE)
    If there are 'n' vertices, then there can be n(n-1)/2 edges thus the worst case time complexity is O(n^3).
Space Complexity-
    O(V)
*/
