#include <stdio.h>
#include <math.h>
//Bellman Ford Function
int Bellman_Ford(int k, int *A, int *B, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        *(B + (k + 1) * n + i) = *(B + k * n + i);
        for (j = 0; j < n; j++)
        {
            if (*(B + (k + 1) * n + i) > *(B + k * n + j) + *(A + *(B + j) * n + *(B + i)))
                *(B + (k + 1) * n + i) = *(B + k * n + j) + *(A + *(B + j) * n + *(B + i));
        }
    }
    if (k < n)
        Bellman_Ford(k + 1, A, B, n);
}
//Main Function Began
int main()
{
    int n, i, j, k, a;
    printf("Please enter the number of vertices:");
    scanf("%d", &n);
    int A[n][n], B[n + 2][n];
    printf("\nEnter the value of Adjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nEnter the Source vertex number:");
    scanf("%d", &a);

    /*Calculation for the first vertex*/
    B[0][0] = a - 1;
    B[1][0] = 0;
    for (j = 1; j < n; j++)
    {
        if (j > a - 1)
            B[0][j] = j;
        else
            B[0][j] = j - 1;
    }
    for (j = 1; j < n; j++)
        B[1][j] = 99;
    //calling bellman function
    Bellman_Ford(1, A, B, n);
    //check for negative cycle
    for (i = 0; i < n; i++)
    {
        if (B[n + 1][i] != B[n][i])
        {
            printf("\n Negative edge-cycle Present");
            return 0;
        }
    }
    //print the output
    printf("\n\tOUTPUT:\n");
    for (i = 1; i < n; i++)
        printf("\nWeight of vertex no.%d is %d", B[0][i] + 1, B[n + 1][i]);
}
//main ends here

/* Sample Input Output
Please enter the number of vertices: 5
Enter the value of Adjacency Matrix:
0
3
8
99
-4

99
0
99
1
7

99
4
0
99
99

2
99
5
0
99

99
99
99
6
0

Enter the Source vertex number: 1

OUTPUT:
Weight of vertex no.2 is 3
Weight of vertex no.3 is 7
Weight of vertex no.4 is 2
Weight of vertex no.5 is -4

Time Complexity : O(V*E)
where V is noumber of vertices and E is no. of edges in the graph.
*/
