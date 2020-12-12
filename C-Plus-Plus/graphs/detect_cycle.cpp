#include<bits/stdc++.h>
#define Graph unordered_map<int, vector<int>>
#define vb vector<bool>
using namespace std;

bool dfs (int curr, vb visited, Graph graph) {
  if(!visited[curr]) {

    visited[curr] = true;
    for(int i=0; i < graph[curr].size(); i++)
      return dfs(graph[curr][i], visited, graph);

  } else
    return true;
}

bool detectCycle(int edges, Graph graph) {

  vb visited(edges, false);

  for(auto it : graph) {
    visited[it.first] = true;
    int sz = it.second.size();

    for(int i=0; i<sz; i++) {
        // do dfs and check for visited is once againg visiting or not
        if(dfs( it.second[i], visited, graph))
          return true;
    }
    visited[it.first] = false;
  }

  // dfs checked for all vertices and there we found no Cycle
    return false;
}

int main() {
  std::cout << "Enter total number of edges in your graph : ";

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  int edges;
  cin>>edges;

// data structure used for creation of graph
  Graph graph;

// creation of graph
int traversegde = edges;
  while (traversegde--) {
    int x;
    int y;
    cin >> x >> y;
    graph[x].push_back(y);
  }

  detectCycle( edges, graph )
  ? std::cout << "Yes there is Cycle in graph" << '\n'
  : std::cout << "No there isn't any Cycle in graph" << '\n';

  return 0;
}
