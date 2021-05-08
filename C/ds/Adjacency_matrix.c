/*
Adjacency matrix is a representation of graph using a square matrix.
This an efficient representation of graph and it has many applications.
The below program is an implementation of adjacency matrix
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct AdjacencyMatrix
{
    int arr[10][10];
} AdjacencyMatrix;
void insert_to_graph(AdjacencyMatrix *g, int parent, int value)
{
    g->arr[parent][value] = 1;
}

void print_graph(AdjacencyMatrix *g)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", g->arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    AdjacencyMatrix *g = (AdjacencyMatrix *)malloc(sizeof(AdjacencyMatrix));
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            g->arr[i][j] = 0;
    while (1)
    {
        printf("Enter the Edge to insert into the graph (v1,v2)\n");
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        insert_to_graph(g, v1, v2);
        printf("Do you want to continue (Y/N)\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n')
        {
            break;
        }
    }
    print_graph(g);
    return 0;
}

/*
Sample I/O:

Enter the Edge to insert into the graph (v1,v2)
0 1
Do you want to continue (Y/N)
y
Enter the Edge to insert into the graph (v1,v2)
2 4
Do you want to continue (Y/N)
y
Enter the Edge to insert into the graph (v1,v2)
1 2
Do you want to continue (Y/N)
n
0 1 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

Time Complexity : O(n^2)
Space Complexity : O(n^2)
*/
