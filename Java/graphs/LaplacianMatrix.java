/* Java Program to Find Laplacian Matrix of an Undirected Graph
FORMULA USED :
Laplacian matrix = Degree matrix – Adjacency matrix

BASIC DEFINITIONS:
Adjacency matrix: Value can be either 0 or 1 according to graph vertices are connected to each other. 
Degree matrix: Number of vertices adjacent to a vertex.

NOTE:
This code contains pre defined values. To get the user defined values, use Scanner class.
*/
public class LaplacianMatrix {
    class Edge {
        int src, dest;
    }
    int vertices, edges;
    Edge[] edge;
    LaplacianMatrix(int vertices, int edges)
    {
        this.vertices = vertices;
        this.edges = edges;
        edge = new Edge[edges];
        for (int i = 0; i < edges; i++) {
            edge[i] = new Edge();
        }
    }
    public static void main(String[] args)
    {
        int i, j;
        int numberOfVertices = 6;
        int numberOfEdges = 7;
        int[][] adjacency_matrix = new int[numberOfEdges][numberOfEdges];
        int[][] degree_matrix = new int[numberOfEdges][numberOfEdges];
        int[][] laplacian_matrix = new int[numberOfEdges][numberOfEdges];
        LaplacianMatrix g = new LaplacianMatrix(numberOfVertices, numberOfEdges);
        // Adding edges with source and destination
        g.edge[0].src = 1;
        g.edge[0].dest = 2; 
        g.edge[1].src = 1;
        g.edge[1].dest = 5;
        g.edge[2].src = 2;
        g.edge[2].dest = 3;
        g.edge[3].src = 2;
        g.edge[3].dest = 5;
        g.edge[4].src = 3;
        g.edge[4].dest = 4;
        g.edge[5].src = 4;
        g.edge[5].dest = 6;
        g.edge[6].src = 5;
        g.edge[6].dest = 4;
  
        // Adjacency Matrix
        for (i = 0; i < numberOfEdges; i++) {
            for (j = 0; j < numberOfEdges; j++) {
                adjacency_matrix[g.edge[i].src][g.edge[i].dest] = 1;
                adjacency_matrix[g.edge[i].dest][g.edge[i].src] = 1;
            }
        }
        System.out.println("Adjacency matrix : ");
        for (i = 1; i < adjacency_matrix.length; i++) {
            for (j = 1; j < adjacency_matrix[i].length;j++) {
                System.out.print(adjacency_matrix[i][j]+ " ");
            }
            System.out.println();
        }
        System.out.println("\n");
  
        // Degree Matrix
        for (i = 0; i < numberOfEdges; i++) {
            for (j = 0; j < numberOfEdges; j++) {
                degree_matrix[i][i]+= adjacency_matrix[i][j];
            }
        }
        System.out.println("Degree matrix : ");
        for (i = 1; i < degree_matrix.length; i++) {
            for (j = 1; j < degree_matrix[i].length; j++) {
                System.out.print(degree_matrix[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("\n");
  
        // Laplacian Matrix
        System.out.println("Laplacian matrix : ");
        for (i = 0; i < numberOfEdges; i++) {
            for (j = 0; j < numberOfEdges; j++) {
                laplacian_matrix[i][j] = degree_matrix[i][j] - adjacency_matrix[i][j];
            }
        }
        for (i = 1; i < laplacian_matrix.length; i++) {
            for (j = 1; j < laplacian_matrix[i].length;
                 j++) {
                System.out.printf("%2d",laplacian_matrix[i][j]);
                System.out.printf("%s", "  ");
            }
            System.out.println();
        }
    }
}

/*
PROGRAM OUTPUT :
Adjacency matrix : 
0 1 0 0 1 0 
1 0 1 0 1 0 
0 1 0 1 0 0 
0 0 1 0 1 1 
1 1 0 1 0 0 
0 0 0 1 0 0 
Degree matrix : 
2 0 0 0 0 0 
0 3 0 0 0 0 
0 0 2 0 0 0 
0 0 0 3 0 0 
0 0 0 0 3 0 
0 0 0 0 0 1 
Laplacian matrix : 
 2  -1   0   0  -1   0  
-1   3  -1   0  -1   0  
 0  -1   2  -1   0   0  
 0   0  -1   3  -1  -1  
-1  -1   0  -1   3   0  
 0   0   0  -1   0   1  
 
COMPLEXITY :
Space complexity : O(N^2) [To create and fill n*n matrix O(N^2) space is required.]
Time complexity : O(N^2) [Checking edge between every pair is required, O(N(N*1)/2)=O(N)]
 
 */
