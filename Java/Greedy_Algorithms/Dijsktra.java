/*
/* Problem Description- This is a shortest path algorithm used in graphs which is used to find the shortest 
distance from a starting vertex to all the vertex. The edge between two vertices having minimum distance is 
considered and also no vertex is left alone and not connected.
 */

 import java.util.*;
 import java.lang.*;
 class dijsktra
 {
     static int Ver;
     int minDistance(int dist[], Boolean sptSet[])
     {
         // Minimum value intialized with maximum value
         int min = Integer.MAX_VALUE;
         int  min_index = -1; //setting minimum index to -1 as array index starts from zero.

         for (int v = 0; v < Ver; v++)
             if (sptSet[v] == false && dist[v] <= min) {
                 min = dist[v];
                 min_index = v;
             }

         return min_index;
     }

     // A utility function to print the constructed distance array
     void printSolution(int dist[])
     {
         System.out.println("Vertex \t  Distance from Source");
		 for (int i = 0; i < Ver; i++)
             System.out.println(i + " \t\t " + dist[i]);
	 }
	 //to implement dijkstra algorithm by finding the shortest distance
     void dijkstra(int graph[][], int src)
     {
         int dist[] = new int[Ver]; //This will have the shortest distance
         // sptSet[i] will true if vertex i is included in shortest
         Boolean sptSet[] = new Boolean[Ver];
         for (int i = 0; i < Ver; i++) {
             dist[i] = Integer.MAX_VALUE;//all distance initalized as infinite
             sptSet[i] = false;
         }
         dist[src] = 0; //since the sorce vertex will always have distance 0 from itself/

         // Find shortest path for all vertices
         for (int count = 0; count < Ver - 1; count++) {
             // Pick the minimum distance vertex from the set of vertices
             int u = minDistance(dist, sptSet);
             // Mark the picked vertex as processed
             sptSet[u] = true;
             for (int v = 0; v < Ver; v++)

                 // Update dist[v] only if is not in sptSet, there is an
                 // edge from u to v, and total weight of path from src to
                 // v through u is smaller than current value of dist[v]
                 if (!sptSet[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v])
                     dist[v] = dist[u] + graph[u][v]; //updating the distance
         }
         printSolution(dist);//calling the print function to print the distance form vertex.
     }
     public static void main(String[] args) //main class
     {
         Scanner sc=new Scanner(System.in);
         System.out.println("Enter number of vertices");
         Ver=sc.nextInt();
         int graph[][] = new int[Ver][Ver];
         System.out.println("Enter graph");
         for(int i=0;i<Ver;i++)
         {
             for(int j=0;j<Ver;j++)
             {
                 graph[i][j]=sc.nextInt();
				}
         } 
         dijkstra t = new dijkstra();
         t.dijkstra(graph, 0);
    }
 }


 /* 
 Input/Output -
 Enter number of vertices 3 
 Enter graph
 0
 0
 2
 0
 0
 0
 6
 7 
 0
Vertex  Distance from Source 
  0        0
  1        9
  2        2 

 Time Complexity: O(Ver)
 Space Complexity: O(Ver)
  */
