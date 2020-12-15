/*
Bipartite Graph Check
----------------------
Problem:
Divide all vertices of the graph in two sets such that
all the edges of the graph are from set1 to set2

Similar to 2 coloring problem

Algorithm:
1) If graph is a tree, then YES Bipartite.
2) If it is not a tree(=> cycle is present)
	Odd length cycle => NOT Bipartite
	Even length cycle => YES Bipartite

*/
#include <bits/stdc++.h>
using namespace std;

// Helper function to run dfs from src node
bool dfs_helper(vector<int> graph[], int src, int visited[], int parentOf[], int color) {

	// Mark the current node
	visited[src] = color;

	// Visit all the neighbours of src
	for (int nbr : graph[src]) {
		// If neighbour has not been visited yet
		if (!visited[nbr]) {
			// Mark src to be the parent of src
			parentOf[nbr] = src;
			// Instantiate dfs call at nbr
			bool oddLenCycleFound = dfs_helper(graph, nbr, visited, parentOf, 3 - color);
			// If odd length cycle is found at nbr, then immediately return false
			if (oddLenCycleFound) return 0;
		} else {
			// nbr potentially contributes to a cycle
			if (parentOf[src] == nbr) {
				// Not a cycle
			} else {
				// Yes a cycle
				// nbrs of src should not have same color
				if (visited[nbr] == color) return 0;
			}

		}
	}
	return true;
}

bool isBipartite(vector<int> graph[], int n) {

	// Keeps track of visited nodes
	int visited[n] = {0};
	// 0 -> Not visited
	// 1,2 -> Visited and color is 1,2

	// Stores parent of each node
	int parentOf[n];
	for (int i = 0; i < n; i++) {
		parentOf[i] = i; // Initially each node is a parent of itself
	}

	bool ans = dfs_helper(graph, 0, visited, parentOf, 1);

	// Print colour of each node
	for (int i = 0; i < n; i++) {
		cout << i << " color=" << visited[i] << endl;
	}

	return ans;
}

int main() {
	// n : Number of vertices
	// m : Number of edges
	int n, m;
	cin >> n >> m;

	// Ajacency List : graph[i] stores all the neighbours of i
	vector<int> graph[n];

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cout << isBipartite(graph, n);
}

/*
Input:
5 5
0 1
1 2
2 3
3 4
4 0

Output:
0 color=1
1 color=2
2 color=1
3 color=2
4 color=1
0

*/
