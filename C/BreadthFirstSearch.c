BFS Implementation In C:
#include<stdio.h>
#include<stdlib.h>
 
#define MAX 100  

int n;    
int adj[MAX][MAX];          //adjacency matrix, where adj[i][j] = 1, denotes there is an  edge from i to j
int visited[MAX];             //visited[i] can be 0 / 1, 0 : it has not yet printed, 1 : it has been printed 
void create_graph();
void BF_Traversal();
void BFS();
 
int queue[MAX], front = -1,rear = -1;
void push_queue(int vertex);
int pop_queue();
int isEmpty_queue();
 
int main()
{
   create_graph();
   BFS();
   return 0;
}

 
void BFS()
{
    int v;
   
   for(v=0; v<n; v++)
      visited[v] = 0;
   
   printf("Enter Start Vertex for BFS: \n");
   scanf("%d", &v);
   
   
   int i;
   
   push_queue(v);
   
   while(!isEmpty_queue())
   {
       
      v = pop_queue( );
       if(visited[v])              //if it has already been visited by some other neighbouring vertex, it should not be printed again.
           continue;
           
      printf("%d ",v);
      visited[v] = 1;
      
      for(i=0; i<n; i++)
      {
         if(adj[v][i] == 1 && visited[i] == 0)
         {
            push_queue(i);
         }
      }
   }
   printf("\n");
}
 
void push_queue(int vertex)
{
   if(rear == MAX-1)
      printf("Queue Overflow\n");
   else
   {
      if(front == -1)
         front = 0;
      rear = rear+1;
      queue[rear] = vertex ;
   }
}
 
int isEmpty_queue()
{
   if(front == -1 || front > rear)
      return 1;
   else
      return 0;
}
 
int pop_queue()
{
   int delete_item;
   if(front == -1 || front > rear)
   {
      printf("Queue Underflow\n");
      exit(1);
   }
   
   delete_item = queue[front];
   front = front+1;
   return delete_item;
}
 
void create_graph()
{
   int count,max_edge,origin,destin;
 
   printf("Enter number of vertices : ");
   scanf("%d",&n);
   max_edge = n*(n-1);         //assuming each vertex has an edge with remaining (n-1) vertices
 
   for(count=1; count<=max_edge; count++)
   {
      printf("Enter edge %d( -1 -1 to quit ) : ",count);
      scanf("%d %d",&origin,&destin);
 
      if((origin == -1) && (destin == -1))
         break;
 
      if(origin>=n || destin>=n || origin<0 || destin<0)
      {
         printf("Invalid edge!\n");
         count--;
      }
      else
      {
         adj[origin][destin] = 1;
         adj[destin][origin] = 1; // assuming it is a bi-directional graph, we are pushing the reverse edges too.
      }
   }
}
