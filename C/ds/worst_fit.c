/*
The worst fit strategy is a reverse of the best-fit strategy. It allocates the largest block available in the storage list.
The idea behind worst-fit is to reduce the rate of production of small blocks. The below program is an implementation of
the worst fit algorithm using array data structure.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Block
{
    int size;
    int ID;
    int fragment;
} Block;

typedef struct process
{
    int Num;
    int size;
    Block block;
} process;

void initialiseBlocks(Block arr[], int sizes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i].size = arr[i].fragment = sizes[i];
        arr[i].ID = i + 1;
    }
}

void printResult(process arr2[], int numOfprocess)
{
    printf("Process No            Process Size          Block ID          Block Size         Block Fragment\n");
    for (int i = 0; i < numOfprocess; i++)
        printf("     %d                     %d                   %d                  %d                  %d\n", arr2[i].Num, arr2[i].size, arr2[i].block.ID, arr2[i].block.size, arr2[i].block.fragment);
}

void worstfit(Block arr[], int sizes[], int n, process arr2[], int numOfprocess)
{
    initialiseBlocks(arr, sizes, n);
    Block *maxBlock;
    for (int i = 0; i < numOfprocess; i++)
    {
        int max = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr2[i].size <= arr[j].fragment && arr[j].fragment > max)
            {
                max = arr[j].fragment;
                maxBlock = &arr[j];
            }
        }
        (*maxBlock).fragment = (*maxBlock).fragment - arr2[i].size;
        arr2[i].block = *maxBlock;
    }
    printf("\nWORST FIT ALLOCATION\n");
    printResult(arr2, numOfprocess);
}

int main()
{
    int sizes[] = {60, 20, 12, 35, 64, 42, 31, 35, 40, 50};
    Block arr[10];
    initialiseBlocks(arr, sizes, 10);
    printf("Enter the number of process for memory to be allocated\n");
    int numOfProcess;
    scanf("%d", &numOfProcess);
    printf("Enter the sizes required by the processes in the order of requirement\n");
    process *arr2 = (process *)malloc(sizeof(process) * numOfProcess);
    for (int i = 0; i < numOfProcess; i++)
    {
        scanf("%d", &arr2[i].size);
        arr2[i].Num = i + 1;
    }
    worstfit(arr, sizes, 10, arr2, numOfProcess);
    return 0;
}
/*
Sample I/O:
Enter the number of process for memory to be allocated
5
Enter the sizes required by the processes in the order of requirement
10 20 11 12 13

WORST FIT ALLOCATION
Process No            Process Size          Block ID          Block Size         Block Fragment
     1                     10                   5                  64                  54
     2                     20                   1                  60                  40
     3                     11                   5                  64                  43
     4                     12                   10                 50                  38
     5                     13                   5                  64                  30

Time complexity : O(n)
space complexity : O(n)

*/
