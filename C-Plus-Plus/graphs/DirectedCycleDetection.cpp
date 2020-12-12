/**
Cycle detection in a directed graph
using dfs. Here, ststus array shows if 
the node is in the path that we are 
currently on. This is used to detect 
any presence of back edges.
backegde present <=> cycle present 
**/

#include <bits/stdc++.h>
using namespace std;

bool cycle;

void dfs_visit(vector<vector<int>>& Graph, int src, vector<bool>& status, vector<bool>& visit) {
	visit[src] = 1;
	status[src] = 1;
	for(int i = 0; i < Graph[src].size(); i++)
		if(visit[Graph[src][i]] == 0)
		    dfs_visit(Graph, Graph[src][i], status, visit);
		else
			if(status[Graph[src][i]] == 1)
				cycle = 1;
    status[src] = 0;
}

void dfs(vector<vector<int>>& Graph, int v, vector<bool>& status) {
	vector<bool> visit(v);
	for(int i = 0; i < v; i++)
		if(visit[i] == 0)
			dfs_visit(Graph, i, status, visit);
}

void detect_cycle(vector<vector<int>>& Graph, int v) {
	vector<bool> status(v);
	dfs(Graph, v, status);
	if(cycle == 0)
		cout << "No cycle exits in the given graph \n";
	else
		cout << "Cycle exists in the given graph \n";
}

int main() {
	cycle = 0;
	int v, e, a, b;
	// all vertices are labelled from 0 to v-1
	cin >> v >> e;
	vector<vector<int>> Graph(v);
	// all directed edges
	for(int i = 0; i < e; i++) {
		cin >> a >> b;
		// edge a -> b
		Graph[a].push_back(b);
	} 
	detect_cycle(Graph, v);
	return 0;
}

/**
Input :
6 8
0 3
0 4
5 0
1 5
1 0
2 1
3 4
4 5
Output :
Cycle exists in the given graph

Time Complexity : O(v+e)
Space Complexity : O(v)
**/