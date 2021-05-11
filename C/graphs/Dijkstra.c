/*
/* Problem Description- This is a shortest path algorithm used in graphs which is used to find the shortest 
distance from a starting vertex to all the vertex. The edge between two vertices having minimum distance is 
considered and also no vertex is left alone and not connected.
 */

#include <stdio.h>
#include <limits.h>
 int Ver;
     int minDistance(int dist[Ver], int sptSet[Ver])
     {
         // Minimum value intialized with maximum value
         int min = INT_MAX;
         int  min_index = -1;
          int v;
         for ( v = 0; v < Ver; v++)
             if (sptSet[v] == 0 && dist[v] <= min) {
                 min = dist[v];
                 min_index = v;
             }

         return min_index;
     }

     // A utility function to print the constructed distance array
     void printSolution(int dist[Ver])
     {
         printf("Vertex \t  Distance from Source\n");
         int i;
		 for ( i = 0; i < Ver; i++)
            printf("%d \t\t\t %d\n",i,dist[i]);
	 }
	 //to implement dijkstra algorithm by finding the shortest distance
     void dijkstra(int graph[Ver][Ver], int src)
     {
         int dist[Ver],sptSet[Ver];
         int i;
		 /*Intializing all distances to infinite*/
         for (i = 0; i < Ver; i++) {
             dist[i] = INT_MAX;
             sptSet[i] = 0;
         }
         dist[src] = 0;

         // Find shortest path for all vertices
         int count,v;
         for (count = 0; count < Ver - 1; count++) {
             // Pick the minimum distance vertex from the set of vertices
             int u=0;
              u = minDistance(dist, sptSet);
             // Mark the picked vertex as processed
             sptSet[u] = 1;
             for ( v = 0; v < Ver; v++)

                 // Update dist[v] only if is not in sptSet, there is an
                 // edge from u to v, and total weight of path from src to
                 // v through u is smaller than current value of dist[v]
                 if (!sptSet[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                     dist[v] = dist[u] + graph[u][v];
         }
		 /*Calling Print function*/
         printSolution(dist);
     }
	 /*Main Function*/
      void main() 
     {
         
         printf("Enter number of vertices\n");
         scanf("%d",&Ver);
         int graph[Ver][Ver];
         printf("Enter graph\n");
         int i,j;
         for(i=0;i<Ver;i++)
         {
             for(j=0;j<Ver;j++)
             {
                 scanf("%d",&graph[i][j]);
				}
         }
         dijkstra(graph,0);   
    }
 
 /*
 Time Complexity:O(Ver)
 Space Complexity:O(Ver)

 Input/Output:
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
*/
