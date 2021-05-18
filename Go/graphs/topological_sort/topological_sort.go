/* This program prints the topological sorted ordering of vertices
of a directed acyclic graph(DAG). Topological sort is the linear
ordering of vertices in a directed acyclic graph(DAG). It is useful
in solving many other applications on DAG.*/

package main

import (
	"fmt"
)

var cnt int

// This function calls the DFS recursively for adjacency list of a vertex
func DFS_VISIT(Graph [][]int, source int, sorted, visited []int) {

	// Mark the current vertex as visited
	visited[source] = 1
	// Visit its adjacency list recursively
	for i := 0; i < len(Graph[source]); i++ {
		if(visited[Graph[source][i]] == 0) {
			DFS_VISIT(Graph, Graph[source][i], sorted, visited)
		}
	}
	// After the adjacency list has been visited, add vertex to the list
	sorted[cnt] = source
	cnt -= 1
}

// This is trhe depth first search function
func DFS(Graph [][]int, vertices int, sorted []int) {

	// List of all visited vertices
	visited := make([]int, vertices)
	// Visit all the vertices
	for i := 0; i < vertices; i++ {
		if(visited[i] == 0) {
			DFS_VISIT(Graph, i, sorted, visited)
		}
	}
}

// This function uses DFS and prints the topological sorted ordering
func topologicalSort(Graph [][]int, vertices int) {

	// Array to store the topological sorted ordering
	sorted := make([]int, vertices)

	// Call DFS
	DFS(Graph, vertices, sorted)

	// Print the sorted ordering of vertices
	for i := 0; i < vertices; i++ {
		fmt.Print(sorted[i], " ")
	}
	fmt.Print("\n")
}

func main() {

	var vertices int
	var edges int

	// Take number of vertices in graph as input
	fmt.Print("Enter the number of vertices: ")
	fmt.Scan(&vertices)

	// Take number of edges in graph as input
	fmt.Print("Enter the number of edges: ")
	fmt.Scan(&edges)

	cnt = vertices - 1

	// Take vertex pair forming edges as input
	fmt.Print("Enter all the vertex pairs forming an edge: \n")
	var Graph = make([][]int, vertices)

	var u int
	var v int

	for i := 0; i < edges; i++ {
		fmt.Scan(&u, &v)
		Graph[u] = append(Graph[u], v)
	}

	// Call the function and print the topological sorted ordering
	fmt.Print("\nThe topological sorting of vertices is: ")
	topologicalSort(Graph, vertices)
}

/*
Sample I/O:

Enter the number of vertices: 6
Enter the number of edges: 8
Enter all the vertex pairs forming an edge: 
0 3
0 4
0 5
1 5
1 0
2 1
3 4
4 5

The topological sorting of vertices is: 2 1 0 3 4 5 

Time Complexity: O(V + E)

Space Complexity: O(V + E), as adjacency list is used.

Here V is the number of vertices and E is the number of edges in the graph.

*/

