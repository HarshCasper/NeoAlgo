#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;  // graph
  vector<pair<int, edge> > T;  // mst
  int *parent;
  int V;  // number of vertices/nodes in graph
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];

  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
}
void Graph::print() {
  cout << "Edge  :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cout << endl;
  }
}
int main() {
    int src, dest, weight;
  Graph g(6);
  for(int i = 0;i<8;i++){
    cout << "Source : ";
    cin >> src;
    cout << "Destination : ";
    cin >> dest;
    cout << "Weight : ";
    cin >> weight;
    g.AddWeightedEdge(src,dest,weight);
    }
  g.kruskal();
  g.print();
  return 0;
}

/*
Sample Input :
Source : 0
Destination : 1
Weight : 4 
Source : 0 
Destination : 2 
Weight : 4 
Source : 1 
Destination : 2 
Weight : 2 
Source : 2 
Destination : 3 
Weight : 3 
Source : 2 
Destination : 5 
Weight : 2 
Source : 2 
Destination : 4 
Weight : 4 
Source : 3 
Destination : 4 
Weight : 3 
Source : 5 
Destination : 4 
Weight : 3

Sample Output:

Edge : Weight

1 - 2 : 2

2 - 5 : 2

2 - 3 : 3

3 - 4 : 3

0 - 1 : 4

Let E denote the number of Edges and V denote the number of Vertices.
Time Complexity: `O(E log V)`
Space Complexity: `O(E+V)`
*/
