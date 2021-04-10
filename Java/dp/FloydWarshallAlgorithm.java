/*
    Floyd-Warshall Algorithm is an algorithm which is used for finding the shortest path
    between all the pairs of vertices in a weighted graph. This algorithm works for both
    the directed and undirected weighted graphs. But, it does not work for the graphs
    with negative cycles (where the sum of the edges in a cycle is negative).
    This algorithm follows the dynamic programming approach to find the shortest paths.
    Below is the Java implementation:
*/
import java.util.*;
import java.lang.*;
import java.io.*;

class FloydWarshallAlgorithm
{
    final static int INF = 99999, V = 4;
    void fWarshallFunction(int graph[][])
    {
        int dist[][] = new int[V][V];
        int i, j, k;
        /*
           Initialize the solution matrix
           same as input graph matrix.
           Or we can say the initial values
           of shortest distances
           are based on shortest paths
           considering no intermediate
           vertex.
        */
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = graph[i][j];
        /*
           Add all vertices one by one
           to the set of intermediate
           vertices.
          - Before start of an iteration,
               we have shortest
               distances between all pairs
               of vertices such that
               the shortest distances consider
               only the vertices in
               set {0, 1, 2, .. k-1} as
               intermediate vertices.
          - After the end of an iteration,
                vertex no. k is added
                to the set of intermediate
                vertices and the set
                becomes {0, 1, 2, .. k}
         */
        for (k = 0; k < V; k++)
        {
            // Pick all vertices as source one by one
            for (i = 0; i < V; i++)
            {
                for (j = 0; j < V; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        printResult(dist);
    }
    
    void printResult(int dist[][])
    {
        System.out.println("The following matrix shows the shortest distances between every pair of vertices");
        for (int i=0; i<V; ++i)
        {
            for (int j=0; j<V; ++j)
            {
                if (dist[i][j]==INF)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j]+"   ");
            }
            System.out.println();
        }
    }
    public static void main (String[] args)
    {/* Below is the graph which user will input
         for which we have to find the shortest path*/
        int n;
        Scanner sc = new Scanner(System.in );
        System.out.print("Enter size (N) of the 2D array representation for a graph of dimension NXN: ");
        n = sc.nextInt();
        System.out.print("Enter a NXN graph row wise (use 1111 for infinity): ");
        int[][] graph = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                graph[i][j] = sc.nextInt();
            }
        }
        FloydWarshallAlgorithm a = new FloydWarshallAlgorithm();
        // Printing the solution graph
        a.fWarshallFunction(graph);
    }
}
/*
 Sample Input/Output:
 Input: Enter size (N) of the 2D array representation for a graph of dimension NXN: 4
        Enter a NXN graph row wise (use INF for infinity):
        0    8    1111  15
        1111 0    4     1111
        1111 1111 0     2
        1111 1111 1111  0
        
 Output: The following matrix shows the shortest distances between every pair of vertices
         0   8   12   14
         INF 0   4   6
         INF INF 0   2
         INF INF INF 0

 Time and space complexity for this approach:
 Time Complexity: O(V^3)
 Auxiliary Space: O(V^2)
*/
