#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define size 20
#define TRUE 1
#define FALSE 0

int g[size][size];
int visit[size];
int Q[size];
int n;

void main()
{
    int v1, v2;
    char ans = 'y';
    void create(), bfs();
    create();
    printf("The Adjacency Matrix for the graph is \n");
    for (v1 = 0; v1 < n; v1++)
    {
        for (v2 = 0; v2 < n; v2++)
            printf("%d", g[v1][v2]);
        printf("\n");
    }
    getchar();
    do
    {
        for (v1 = 0; v1 < n; v1++)
            visit[v1] = FALSE;


        printf("Enter the Vertex from which you want to traverse ");
        scanf("%d", &v1);
        if (v1 >= n)
            printf("Invalid Vertex\n");
        else
        {
            printf("The Breadth First Search of the Graph is\n");
            bfs(v1);
            getchar();
        }
        printf("\nDo you want to traverse from any other node?");
        ans = getchar();
    } while (ans == 'y');
    exit(0);
}
void create()
{
    int v1, v2;
    char ans = 'y';
    printf("\n\t\t This is a program to create a Graph");
    printf("\n\t\t The Dispaly Is In Breadth First Manner");
    printf("\nEnter no. of nodes");
    scanf("%d", &n);
    for (v1 = 0; v1 < n; v1++)
        for (v2 = 0; v2 < n; v2++)
            g[v1][v2] = FALSE;
    printf("\nEnter the vertices no. starting from 0");
    do
    {
        printf("\nEnter the vertices v1 & v2");
        scanf("%d%d", &v1, &v2);
        if (v1 >= n || v2 >= n)
            printf("Invalid Vertex Value\n");
        else
        {
            g[v1][v2] = TRUE;
            g[v2][v1] = TRUE;
        }
        printf("\n\nAdd more edges??(y/n)");
        ans = getchar();
    } while (ans == 'y');
}
void bfs(int v1)
{
    int v2, front, rear;
    visit[v1] = TRUE;
    front = rear = -1;
    Q[++rear] = v1;
    while (front != rear)
    {
        v1 = Q[++front];
        printf("%d\n", v1);
        for (v2 = 0; v2 < n; v2++)
        {
            if (g[v1][v2] == TRUE && visit[v2] == FALSE)
            {
                Q[++rear] = v2;
                visit[v2] = TRUE;
            }
        }
    }
}


/*
Sample Case : 
This is a Program To Create a Graph
The Display Is In Breadth First Manner
Enter no. of nodes 4
Enter the vertices no. starting from 0
Enter the vertices v1 & v2
0 1
Add more edges??(y/n)y
Enter the vertices v1 & v2
0 2
Add more edges??(y/n)y
Enter the vertices v1 & v2
1 3
Add more edges??(y/n)y
Enter the vertices v1 & v2
2 3
Add more edges??(y/n)
The Adjacency Matrix for the graph is
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter the Vertex from which you want to traverse : 0
The Breadth First Search of the Graph is
0 
1 
2 
3
Do you want to traverse from any other node?
Enter the Vertex from which you want to traverse 1
The Breadth First Search of the Graph is
1 
0 
3 
2
Do you want to traverse from any other node?
*/
