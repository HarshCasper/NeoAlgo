#include<bits/stdc++.h>
using namespace std;
//Function to find the minimum vertex
int findMinVertex(int* distance, bool visited[], int n) {
	//Initialize min value
	int minVertex = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
			minVertex = i;
		}
	}
	return minVertex;
}

//Dijkstra function
void dijkstra(int** edges, int n) {
	//hold the shortest distance from src to i
	int* distance = new int[n];
	//check if it is visited or not?
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		//Initialize all distances as INFINITE and visited[] as false
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	distance[0] = 0;
	//Now pick all corrosponding vertex and explore them
	for (int i = 0; i < n - 1; i++) {
		//finding min vertex i,e minimum then source
		int minVertex = findMinVertex(distance, visited, n);
		visited[minVertex] = true;
		//Now check its Neighbour
		for (int j = 0; j < n; j++ ) {
			if (edges[minVertex][j] != 0 && !visited[j]) {
				int dist = distance[minVertex] + edges[minVertex][j];
				if (dist < distance[j]) {
					distance[j] = dist;
				}
			}
		}
	}
	//print the constructed distance array
	cout << "Vertex\tDistance from Source\n";
	for (int i = 0; i < n - 1; i++) {
		cout << i << "          " << distance[i] << endl;
	}
}

//Main function
int main() {
	//Take input from user
	cout << "Enter value for node and edge -";
	int n, e;
	cin >> n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}
	cout << "Enter value for Adjacency Matrix -";
	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	//Calling  Disjkstra function
	cout << endl;
	dijkstra(edges, n);
}

/*
Sample Input Output

Enter value for node and edge -
5 6
Enter value for Adjacency Matrix -
0 1 4
0 2 8
1 3 5
1 2 2
2 3 5
2 4 9

Vertex	Distance from Source
0          0
1          4
2          6
3          9

Time Complexity -O(N^2)
*/
