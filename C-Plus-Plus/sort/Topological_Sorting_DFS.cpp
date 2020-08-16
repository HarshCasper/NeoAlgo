// A C++ program to print topological sorting of a DAG (Directed Acyclic Graph) 
// using DFS approach

#include<iostream> 
#include <list> 
#include <stack> 
#include <conio.h>
using namespace std; 

class Graph 
{ 
	int V;	// V = number of vertices 
	list<int> *adj; 
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
	
	public: 
	Graph(int V); 
	void addEdge(int v, int w); 
	void topologicalSort(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{  
	adj[v].push_back(w); // directed connection between 2 nodes in the graph
} 

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) 
{ 
	visited[v] = true; 

	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			topologicalSortUtil(*i, visited, Stack); 

	Stack.push(v); 
} 

// The function is used to do Topological Sort. It uses recursive topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
	stack<int> Stack;  
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			topologicalSortUtil(i, visited, Stack); 

	// Print contents of stack 
	while (Stack.empty() == false) 
	{ 
		cout << Stack.top() << " "; 
		Stack.pop(); 
	} 
} 

int main() 
{ 
	/*
	int nodes, x, y;
	cout << "Enter the number of nodes in the graph: ";
	cin >> nodes;
	Graph g(nodes); 

	cout << "Enter the edges of the graph: \n";
	for(int i = 0; i < nodes; i++){
		cin >> x >> y;
		g.addEdge(x, y);
	}
	*/
	Graph g(6); 
	g.addEdge(5, 2); 
	g.addEdge(5, 0); 
	g.addEdge(4, 0); 
	g.addEdge(4, 1); 
	g.addEdge(2, 3); 
	g.addEdge(3, 1);

	cout << "\nFollowing is a Topological Sort of the given graph \n"; 
	g.topologicalSort(); 

	return 0; 
} 