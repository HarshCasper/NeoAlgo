import java.util.Scanner;

/**
 * @author Anshika Agrawal
 * @since 02-04-2021
 */

public class FloydWarshall {

	public static void main(String[] args) {
		
        /**
        
        Lets assume the Graph given below.
		
		Vertex 1 => Vertex 2 : cost=3
		Vertex 1 => Vertex 3 : no direct edge
		Vertex 1 => Vertex 4 : cost=7
		Vertex 2 => Vertex 1 : cost=8
		Vertex 2 => Vertex 3 : cost=2
		Vertex 2 => Vertex 4 : no direct edge
		Vertex 3 => Vertex 1 : cost=5
		Vertex 3 => Vertex 2 : no direct edge
		Vertex 3 => Vertex 4 : cost=1
		Vertex 4 => Vertex 1 : cost=2
		Vertex 4 => Vertex 2 : no direct edge
		Vertex 4 => Vertex 3 : no direct edge

        matrix representation of the graph :
		
        graph = {
            {0,3,10000,7},
            {8,0,2,10000},
            {5,10000,0,1},
            {2,10000,10000,0}
        }
		
		graph[i][j] represents the cost of edge from ith vertex to jth vertex
		10000 cost represents that there is no edge between i and j and so cost is infinite.
		
		we have taken 10000 as an infinite value because in case we need to add some value
		to check for minimum cost then value goes out of range of Integer.
		but in case of 10000, there is no risk of reaching out of range.
		
		values at diagonals should be 0 because i==j means cost from a vertex to same vertex. 

        */


		Scanner sc=new Scanner(System.in);
		
		System.out.println("Enter no. of vertices in the Graph.");
		int v=sc.nextInt();
		
		int[][] graph=new int[v][v];

        System.out.println("Enter costs of edges in the Graph.");
		
		for (int i=0; i<v; i++) {
			for (int j=0; j<v; j++) {
				graph[i][j]=sc.nextInt();
			}
		}
		
        // answer matrix where we will be stroing minimum cost between two pair of vertices.
		int[][] ans=new int[v][v];
		
		//just copy down values of graph into ans matrix.
		for (int i=0; i<v; i++) {
			for (int j=0; j<v; j++) {
				ans[i][j]=graph[i][j];
			}
		}
		
		
		//update the matrix by keeping each vertex as a main rout part once.
		for (int k=0; k<v; k++) {
			//k represents that we are keeping kth vertex constant.
			//means that path from i to j must pass from k.
			
			for (int i=0; i<v; i++) {
				for (int j=0; j<v; j++) {
					
					int oc=ans[i][j]; //old cost, already present at i,j
					int nc=ans[i][k] + ans[k][j]; //new cost, cost from i to k plus cost from k to j. 
					// Since we are assuming that path from to j passes through k.
					
					if (nc<oc) {
						ans[i][j]=nc;
					}
				}
			}
			
		}
		

        System.out.println("Matrix displaying minimum costs between the pairs of vertices.");
		
		//display final matrix after all the updations of shortest cost path from vertex i to j
		// value at i,j represents minimum cost from vertex i to vertex j.
		for (int i=0; i<v; i++) {
			for (int j=0; j<v; j++) {
				System.out.print (ans[i][j]+" ");
			}
			System.out.println();
		}
		

	}

}
