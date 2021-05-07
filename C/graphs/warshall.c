/* A program for warshall algorithm.It is a shortest path algorithm which is used to find the 
distance from source node,which is the first node,to all the other nodes.
If there is no direct distance between two vertices then it is considered as -1
*/
#include <stdio.h>


/*The size of graph*/
int ver;


void warshall(int g[ver][ver])
{
  int i,j,k;
  /*A 2d matrix to store distance*/
  int dist[ver][ver];
  for (i = 0; i < ver; i++)
        for (j = 0; j < ver; j++)
		/*Initially storing all the distance
		in the dist matrix*/
            dist[i][j] = g[i][j];
 
    for (k = 0; k < ver; k++)
    {
		for (i = 0; i < ver; i++)
        {
            for (j = 0; j < ver; j++)
            {
               /*To find the smallest distance between two vertex if it exists*/
                if (dist[i][k] + dist[k][j] < dist[i][j] && dist[i][k]!=-1&& dist[k][j]!=-1)
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
	/*Printing the calculated distance matrix*/
	printf("The distance graph is:\n");
  for(i=0;i<ver;i++)
    {
        for(j=0;j<ver;j++)
        {
            if(dist[i][j]>=0)
           printf("%d ",dist[i][j]);
           else
           printf("%d ",-1);
        }
        printf("\n");
    }
}
/*Main function*/
int main()
{
        printf("Enter number of vertices\n");
        scanf("%d",&ver);
        int graph[ver][ver];
		/*Creation of graph*/
        printf("Enter graph\n");
        int i,j;
        for( i=0;i<ver;i++)
        {
            for(j=0;j<ver;j++)
            {
               scanf("%d",&graph[i][j]);
            }
        } 
		/*Calling of function*/
        warshall(graph);
    return 0;
}

/*
Time Complexity:O(Ver^3)
Space Complexity:O(Ver^2)

Input/Output:-
Enter number of vertices
4
Enter graph
0
8
-1
1
-1
0
1
-1
4
-1
0
-1
-1
2
9
0
The distance graph is:
0 3 -1 1 
-1 0 1 -1 
4 -1 0 -1 
-1 2 3 0 
*/
