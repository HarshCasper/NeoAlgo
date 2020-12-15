/* this the program of the bipartite check
 Bipartite is the type of graph whose vertices can be divided into two different sets and 
 every edge in the graph is from set 1 to set 2

 This can be done using the coloring the vertices with two different colours such that no two 
 neighbouring vertices should have a same color.
 If we are able to do so then the graph is bipartite else it is not
 
 1. A Tree is always a bipartite graph
 2. Graph with a cycle and odd number of vertices is always a non-bipartite */

#include <bits/stdc++.h>
using namespace std;
// creating a class of Graph...
class Graph
{
	int v;
	list<int> *l; // list containing the edges of the graph

public:
	Graph(int v)
	{
		this->v = v;
		l = new list<int>[v];
	}
	void addEdge(int x, int y)
	{
		l[x].push_back(y); // the graph is not directed
		l[y].push_back(x);
	}
	// function to check the bipartite
	// we are using the DFS algorithm in here to check for the Bipartite graph
	// the colour value can be either 1 or 2....(for two colors)

	bool bipartiteCheck(int start, int parent, int colour, int *visited)
	{
		//mark start node as visited and color it
		visited[start] = colour;
		// iterate over the neighbours of the start node
		for (auto nbr : l[start])
		{
			// check if the node is visited and coloured
			if (visited[nbr] == 0)
			{
				// recursive call and toggle the colour
				bool ans = bipartiteCheck(nbr, start, 3 - colour, visited);
				if (!ans)
					return false;
			}
			// check if visited nbr node is not parent and its colour is not equal to the colour of the parent
			else if (nbr != parent and colour == visited[nbr])
				return false;
		}
		return true;
	}
};

int main()
{
	int V, E; // number of vertices and edges
	cin >> V >> E;
	Graph g(V); // initialising the object of the graph with v vertices
	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;
		g.addEdge(a, b); // adding the edges to the graph
	}

	/* plan to color the vertices 
	0-> no color, 
	1 -> color, 
	2 - color */
	int *visited = new int[V]; // maintaing an array of the vertices to store the colour
	for (int i = 0; i < V; i++)
		visited[i] = 0;

	bool ans = g.bipartiteCheck(0, -1, 1, visited);
	if (ans)
		cout << "Bipartite" << endl;
	else
		cout << "Not a bipartite" << endl;

	return 0;
}