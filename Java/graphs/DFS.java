import java.util.Scanner;

public class DFS{

	//dfs function for connected graph
	public static void dfsHelper(int[][] edges,
	 int noVertices, int startVertex, boolean[] visited){

	 	System.out.print(startVertex +  " ");
	 	visited[startVertex] = true;

	 	for(int i = 0; i < noVertices; i++){
	 		if(i == startVertex)
	 			continue;

	 		/*If there is an edge b/w starting vertex
	 		and curr vertex, call print on curr vertex */
	 		if(edges[startVertex][i] == 1){

	 			/*If we have already visited curr vertex,
	 			we will not call print on it */
	 			if(visited[i])
	 				continue;

	 			dfsHelper(edges, noVertices, i, visited);
	 		}
	 	}

	}

	//this works for disconnected graph also
	public static void dfs(int[][] edges, int noVertices){
		boolean[] visited = new boolean[noVertices];

		for(int i = 0; i < noVertices; i++){
			if(!visited[i])
				dfsHelper(edges, noVertices, i, visited);
		}

	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.println("Enter the number of vertices in Graph : ");
		int n = scanner.nextInt();  // no. of vertices

		System.out.println("Enter the number of edges in the Graph : ");
		int e = scanner.nextInt();  // no. of edges

		// Adjacency Matrix
		int[][] edges = new int[n+1][n+1];

		//Take input of all edges
		System.out.println("Enter the edges :");
		for(int i = 0; i < e; i++){
			int firstVertex = scanner.nextInt();
			int secondVertex = scanner.nextInt();
			edges[firstVertex][secondVertex] = 1;
			edges[secondVertex][firstVertex] = 1;;
		}

		System.out.println("DFS Traversal : ");
		dfs(edges, n);
	}
}

/*
Sample Case : 
Enter the number of vertices in Graph : 
10
Enter the number of edges in the Graph : 
8
Enter the edges :
1 2
1 3
2 4
4 6
3 5
5 0
7 8
8 9
DFS Traversal : 
0 5 3 1 2 4 6 7 8 9
*/
	 
