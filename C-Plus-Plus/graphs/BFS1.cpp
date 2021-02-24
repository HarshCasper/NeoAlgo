//BFS stands for Breadth-first search,
//is an algorithm for traversing
//tree or graph data structures.
//It starts at the tree root (or some
//arbitrary node of a graph, sometimes
//referred to as a 'search key'[1]), and
//explores all of the neighbor nodes at
//the present depth prior to moving on
//to the nodes at the next depth level.
// This Program is to print BFS traversal
// from a given source vertex. BFS(int s)
// traverses vertices reachable from s.
// As Input it required No of Vertex, No of Edges
// which Edges are connected, Source Vertex.
//In Output we get the BFS traversal.
#include <iostream>

#include <list>

using namespace std;

class Graph {
    int V;

    list<int>* adj;

public:
    Graph(int V);

    void addEdge(int v, int w);

    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while (!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin();
             i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    int No_of_Vertex, No_of_Edges,
        i, Start_Vertex, A, B;
    cout << "Enter the No of vertex \n";
    cin >> No_of_Vertex;
    Graph g(No_of_Vertex);
    cout << "Enter the No of Edges \n";
    cin >> No_of_Edges;
    for (i = 0; i < No_of_Edges; i++) {
        cin >> A >> B;
        g.addEdge(A, B);
    }
    cout << "Enter the vertex to start BFS\n";
    cin >> Start_Vertex;
    cout << "Following is Breadth First Traversal"
         << "(starting from vertex )" << Start_Vertex
         << " \n";
    g.BFS(Start_Vertex);

    return 0;
}

//Time Complexity-O(|V|+|E|)
//Space Complexity-O(|V|)
//where V is the no of vertex in the graph
//and E is the no of Edges.
//Input
//4
//6
//0 1
//0 2
//1 2
//2 0
//2 3
//3 3
//2
//Output
//2 0 3 1

