/*Problem Description
A vertex is said to be an articulation point in a graph if removal of the vertex and associated edges disconnects the graph.
You are given the nodes and edges . Find the articulation point.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

public class Articulation_Point {
        // Initialize all the required variables with their type. 
	private static int[] low =  new int[10001];
	private static int[] visited = new int[10001]; 
	private static int[] disc = new int[10001] ;
	private static int timer = 1;
	private static Set<Integer> hashset ;
        static ArrayList<Integer> adj[];
        //  This class will help us to create a graph and know the articulation point.
	static class Graph
	 {
		 static int v ;		
       		 // Creating graph 
		 Graph(int v)
		 {
			 Graph.v = v;
			 adj = new ArrayList[v+1];			 
			 for(int i = 0 ; i < v+1 ; i++)
			 {
				 adj[i] = new ArrayList<Integer>();
			 }
		 }		 
     	         // adding nodes with each other 
		 static void addEdge(int u , int v)
		 {
			 adj[u].add(v);
			 adj[v].add(u);
		 }
		// The method will help us to know the articulation point
		/*
		    Code flow : 
		    step 1 :  We need to calculate the lowest discovery number. 
		    step 2 : The algorithm then searches for its adjacent vertices.
		    step 3 : the algorithms take a pair of vertices and checks whether its an articulation point or not.
		    step 4 : There’s one special case when the root is an articulation point
		*/    
		 static void dfs(int node , int par)
			{
				visited[node] = 1 ;
				low[node] = disc[node] = timer++;
				int children = 0 ;
				for(int child : adj[node] )
				{
					if(child == par) continue;
					if(visited[child] == 0 )
					{
						children++;
						dfs(child , node );
						if(disc[node] <= low[child] && par != -1)
						{
							hashset.add(node );
						}
						low[node] = Math.min(low[node] , low[child] );
					}
					else
					{
						low[node] = Math.min(low[node], disc[child] );
					}									
				}
              		       // if root is articulation point
				if(par == 0  && children > 1)
				{
					hashset.add(node);
				}			
			}
	 }
	public static void main(String[] args) throws IOException 
	{ 
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of testcase");
		int test  = sc.nextInt();
		while(test-- > 0)
		{			
           		 // Clear all the values inside the array to start new fresh array for next test case
			 Arrays.fill(disc, 0);
			 Arrays.fill(visited, 0);
			 Arrays.fill(low, 0);
			 timer = 0 ;
            		 // hashset for storing the articulation point
			 hashset = new HashSet<Integer>();
             		 // No of nodes
			 System.out.println("Enter number of nodes");
			 int n = sc.nextInt();
           		 // No of edges  
			 System.out.println("Enter number of edges");
			 int m = sc.nextInt();
           		 // Create a graph with 10001 entries so it does not overflow
			 Graph g = new Graph(10001);  
			 // Add the nodes with each other
			 System.out.println("Enter values of edges");
			for(int i  = 1 ; i <= m ; i++)
			{
				int a = sc.nextInt();
				int b = sc.nextInt();
				g.addEdge(a,b);
			}
			// visit every element of nodes and accordingly call dfs function 			
			for(int i = 1 ; i < n + 1 ; i++ )
			{
				if(visited[i] == 0 )
					g.dfs(i , -1 );
			}		
			// Print all the articulation point
			for(Integer val : hashset)
			{
				System.out.print(val + " ");
			}	 
		}
  }	
}

/* Input
Enter number of testcase
1
Enter number of nodes
4
Enter number of edges
5
Enter values of edges
1 0
0 2
2 1
0 3
3 4

Output
0 3

Explanation :
From all the nodes we find that articulation point is 0 and 3.This will seperate the graph and can make many unconnect graph
Time Complexity : O(V + E)
Space Complexity : O(V + E)
*/
