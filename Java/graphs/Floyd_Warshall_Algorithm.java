/**

The Floyd Warshall Algorithm is used to find minimum distances between
every pair of vertices in a given edge weighted directed Graph.
The Floyd-Warshall algorithm is an example of dynamic programming. 
It breaks the problem down into smaller subproblems, then combines 
the answers to those subproblems to solve the big, initial problem. 

*/

import java.util.Scanner;

public class Floyd_Warshall_Algorithm {

	public static void display(int v, int[][] answerMatrix) {

		System.out.println("Matrix displaying minimum costs between the pairs of vertices.");

		// display final matrix after all the updations of shortest cost path from
		// vertex i to j
		// value at i,j represents minimum cost from vertex i to vertex j.
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				System.out.print(answerMatrix[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void floydWarshallAlgorithm(int v, int[][] graph) {

		// answer matrix where we will be storing minimum cost between two pair of
		// vertices.
		int[][] answerMatrix = new int[v][v];

		// just copy down values of graph into ans matrix.
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				answerMatrix[i][j] = graph[i][j];
			}
		}

		// update the matrix by keeping each vertex as a main rout part once.
		for (int k = 0; k < v; k++) {
			// k represents that we are keeping kth vertex constant.
			// means that path from i to j must pass from k.

			for (int i = 0; i < v; i++) {
				for (int j = 0; j < v; j++) {

					int oc = answerMatrix[i][j];
					int nc = answerMatrix[i][k] + answerMatrix[k][j];

					if (nc < oc) {
						answerMatrix[i][j] = nc;
					}
				}
			}
		}

		display(v, answerMatrix);
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		System.out.println("Enter no. of vertices in the Graph.");
		int v = sc.nextInt();

		int[][] graph = new int[v][v];

		System.out.println("Enter costs of edges in the Graph.");

		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				graph[i][j] = sc.nextInt();
			}
		}

		floydWarshallAlgorithm(v, graph);
	}
}

/**
 
Time Complexity : O(V^3)
Space Complexity : O(V^2)

Sample Test case 1 :

4
0 3 10000 7
8 0 2 10000
5 10000 0 1
2 10000 10000 0

Output :

Matrix displaying minimum costs between the pairs of vertices.
0 3 5 6 
5 0 2 3 
3 6 0 1 
2 5 7 0 

*/
