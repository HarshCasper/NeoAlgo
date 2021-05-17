/* SPARSE MATRIX REPRESENTATION USING LINKED LIST
    Representing a sparse matrix by a 2D array leads to wastage of lots of memory.
    A sparse matrix can be effectively represented by storing the non- zero elements
    Here a Linked list is used wherein each node stores
        1. row number
        2. column number
        3. non-zero value
    This representation reduces memory wastage
*/

#include <stdio.h>
#include <stdlib.h>

/* Declare node with row,column and data for storing non-zero term of
   sparse matrix.
   next points to the subsequent node
*/
typedef struct node
{
    int row, column, data;
    struct node *next;
} node;
node *head;

//to represent and print sparse matrix
void sparse_matrix(int rows, int cols, int mat[10][10])
{
    // traverse the matrix row-wise
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //If a non-zero term is encountered
            if (mat[i][j] != 0)
            {
                //Store the non-zero term in a new node of the linked list
                node *new = malloc(sizeof(node));
                new->row = i;
                new->column = j;
                new->data = mat[i][j];
                new->next = NULL;
                //If the list is empty insert as first node
                if (head == NULL)
                    head = n;
                else
                {
                    node *ptr = head;
                    //Traverse till the end of the list
                    while (ptr->next != NULL)
                        ptr = ptr->next;
                    //insert as last node
                    ptr->next = new;
                }
            }
        }
    }
    node *ptr = head;
    printf("\nSPARSE MATRIX REPRESENTATION\nRow\tColumn\tValue\n");
    //Traverse the linked list and print each node
    while (ptr != NULL)
    {
        printf("%d\t%d\t%d\n", ptr->row, ptr->column, ptr->data);
        ptr = ptr->next;
    }
}

//driver code
int main()
{
    node *head = NULL;
    int matrix[10][10], rows, cols, count;
    //accept rows,columns and matrix entries as user input
    scanf("%d%d", &rows, &cols);
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    sparse_matrix(rows, cols, matrix);
}

/*
    Sample Input:
    5 5
    0 0 2 0 1
    3 0 0 0 0
    0 0 0 0 0
    0 5 0 4 2
    0 0 6 0 0

    Sample Output:
    Row     Column  Value
    0       2       2
    0       4       1
    1       0       3
    3       1       5
    3       3       4
    3       4       2
    4       2       6
*/

/*
    Time Complexity : O(rows*cols)
    Space Complexity : O(n), where n= number of non-zero terms
*/
