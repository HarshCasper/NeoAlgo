/*
FIRST FIT MEMORY ALLOCATION
Available memory blocks are accepted as input from the user
The list of available storage is searched and as soon as a
free block of size >= N is found, the pointer of that block
is returned, after retaining residual space
*/

#include <bits/stdc++.h>
using namespace std;

//structure to represent memoryblock with id and size
typedef struct MemoryBlock
{
    int id;
    int size;
} MemoryBlock;

//to print the id of allocated memory block
void print_block(MemoryBlock block)
{
    if (block.id != -1 && block.size != -1 && block.size != 0)
        printf("Block #%d \n", block.id);
    else
        printf("Invalid Memory Block\n");
}

//linked list to store memory blocks
typedef struct MemoryManager
{
    MemoryBlock b;
    struct MemoryManager *llink, *rlink;
} MemoryManager;

//first fit memory allocation
MemoryBlock first_fit(MemoryManager *m, int memory)
{
    MemoryBlock bl;
    //if the list is empty
    if (m == NULL)
    {
        bl.id = -1;
        bl.size = -1;
    }
    else
    {
        MemoryManager *ptr = m, *ptr1, *ptr2, *p;
        while (ptr->rlink != NULL && ptr->b.size < memory)
            ptr = ptr->rlink;
        //if block of size greater than memory is found
        if (ptr->b.size >= memory)
        {
            bl = ptr->b;
            bl.size = ptr->b.size;
            ptr->b.size -= memory;
        }
        else
        {
            bl.id = -1;
            bl.size = -1;
        }
    }
    return bl;
}

//to add available memory blocks to linked list
void deallocate(MemoryManager *m, MemoryBlock memory)
{
    MemoryManager *ptr = m;
    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
    }
    MemoryManager *n = new MemoryManager;
    n->b = memory;
    ptr->rlink = n;
    n->llink = ptr;
    n->rlink = NULL;
}

//driver code
int main()
{
    //accept the number of memory blocks and sizes as user input
    MemoryManager *m = (MemoryManager *)malloc(sizeof(MemoryManager));
    int n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);
    printf("Enter the size of the blocks: ");
    for (int i = 0; i < n; i++)
    {
        int memory;
        scanf("%d", &memory);
        MemoryBlock *block = (MemoryBlock *)malloc(sizeof(MemoryBlock));
        block->id = i + 1;
        block->size = memory;
        deallocate(m, *block);
    }
    //display available memory blocks with id and size
    printf("AVAILABLE MEMORY BLOCKS\nBlock id\tSize\n");
    MemoryManager *ptr = m->rlink;
    while (ptr != NULL)
    {
        printf("    %d\t\t%d\n", ptr->b.id, ptr->b.size);
        ptr = ptr->rlink;
    }

    //accept required memory size as user input
    MemoryBlock block;
    int requested_memory;
    printf("Required Size: ");
    scanf("%d", &requested_memory);
    block = first_fit(m, requested_memory);
    //if suitable memory block is not found
    if (block.id == -1 || block.size == -1)
        printf("Memory Insufficient !\n");
    else
    {
        printf("Allocating ");
        print_block(block);
    }

    return 0;
}

/*
SAMPLE I/O:
Enter the number of memory blocks: 5
Enter the size of the blocks: 100 250 400 375 500
AVAILABLE MEMORY BLOCKS
Block id        Size
    1           100
    2           250
    3           400
    4           375
    5           500
Required Size: 300
Allocating Block #3

Time Complexity: O(n)
Space Complexity: O(n)
*/
