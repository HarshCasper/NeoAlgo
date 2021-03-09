/* 
What is DFS?
Depth-first searchis an algorithm for traversing or searching tree or graph data structures. One starts at the root
and explores as far as possible along each branch before backtracking. A version of depth-first search was
investigated in the 19th century French mathematician Charles Pierre Trémaux as a strategy for solving mazes.
Depth-first search is a systematic way to find all the vertices reachable from a source vertex. Like breadth-first
search, 
DFS traverse a connected component of a given graph and defines a spanning tree. 
The basic idea of depth-first search is methodically exploring every edge. We start over from a different vertices as necessary. As soon as
we discover a vertex, DFS starts exploring from it
*/

//STEPS:
/*
Start by putting any one of the graph's vertices on top of a stack.
Take the top item of the stack and add it to the visited list.
Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the top of the stack.
Keep repeating steps 2 and 3 until the stack is empty
*/


#include <iostream>
#include <list>
using namespace std;

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

   public:
  Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
};

// Initialize graph
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];

  cout << vertex << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}

int main() {
    //creates a grapgh of 4 vertices
  Graph g(4);
  //the below code snippet adds edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 // DFS from the below given vertex
 cout<<"The DFS traversal from the given below vertex is as below:\n";
  g.DFS(1);

  return 0;
}

/*
Output:
The DFS traversal from the given below vertex is as below:                                                                          
1 2 3 0  */


