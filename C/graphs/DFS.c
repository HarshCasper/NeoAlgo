
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void DFS(int);
int G[10][10],visited[10],n;
void main()
{	
int i,j;
system("clear");
printf("Enter number of vertices:"); 
scanf("%d",&n);
printf("\nEnter adjacency matrix of the graph:"); 
for(i=0;i<n;i++)
  for(j=0;j<n;j++) 
    scanf("%d",&G[i][j]);
for(i=0;i<n;i++)
visited[i]=0; DFS(0);
getch();
}
void DFS(int i)
{	
int j;
printf("\nGraph traversal :%d",i); 
visited[i]=1;
for(j=0;j<n;j++) 
  if(!visited[j]&&G[i][j]==1)
    DFS(j); }

/*
Enter number of vertices:4
Enter adjacency matrix of the graph: 0 1 1 0
1 0 1 1
1 1 1 1
1 0 1 1
DFS traversal:0 
DFS traversal:1
DFS traversal:2
DFS traversal:3
*/
