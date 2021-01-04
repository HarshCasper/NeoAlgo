#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


#define MAX 20
#define TRUE 1
#define FALSE 0


int g[MAX][MAX];
int v[MAX];
int n;

void main()
{
    int v1, v2;
    char ans;
    void create();
    void Dfs(int);
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
        v[v1] = FALSE;
        printf("Enter the Vertex from which you want to traverse ");
        scanf("%d", &v1);
        if (v1 >= MAX)
            printf("Invalid Vertex\n");
        else
        {
            printf("The Depth First Search of the Graph is\n");
            Dfs(v1);
        }
        printf("\nDo you want to traverse By any other node?");
        ans = getchar();
    } while (ans == 'y');
}
void create()
{
    int ch, v1, v2, flag;
    char ans = 'y';
    printf("\n\t\t This is a program to create a Graph");
    printf("\n\t\t The Display Is In Depth First Manner");
    getch();


    printf("\nEnter no. of nodes");
    scanf("%d", &n);
    for (v1 = 0; v1 < n; v1++)
        for (v2 = 0; v2 < n; v2++)
            g[v1][v2] = FALSE;
    printf("\nEnter no. of nodes");
    scanf("%d", &n);
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
void Dfs(int v1)
{
    int v2;
    printf("% d",v1);
        v[v1] = TRUE;
    for (v2 = 0; v2 < MAX; v2++)
        if (g[v1][v2] == TRUE && v[v2] == FALSE)
            Dfs(v2);
}

/*
Sample Case : 
This is a Program To Create a Graph
The Display Is In Depth First Manner
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
Enter the Vertex from which you want to traverse : 1
The Depth First Search of the Graph is
1
0
2
3
Do you want to traverse from any other node?
*/
