/*
WORST FIT MEMORY ALLOCATION
Available memory blocks are accepted as input from the user
Allocates largest block available in storage list
This aims to reduce the production of small blocks, 
which is common in best fit strategy
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

//worst fit memory allocation
MemoryBlock worst_fit(MemoryManager *m, int memory)
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
        MemoryBlock worst;
        worst.id = -1;
        worst.size = -1;
        //to find the largest memory block
        while (ptr != NULL)
        {
            if (ptr->b.size >= memory && ptr->b.size > worst.size)
            {
                worst.id = ptr->b.id;
                worst.size = ptr->b.size;
            }
            ptr = ptr->rlink;
        }
        worst.size = memory;
        bl = worst;
        ptr = m;
        //to remove the memory allocated from the block
        while (ptr->rlink != NULL)
        {
            if (ptr->b.id == worst.id)
            {
                ptr->b.size -= memory;
                break;
            }
            ptr = ptr->rlink;
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
    MemoryManager *n = new MemoryManager ;
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

    MemoryBlock block;
    //accept required memory size as user input
    int requested_memory;
    printf("Required Size: ");
    scanf("%d", &requested_memory);
    block = worst_fit(m, requested_memory);
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
Allocating Block #5   

Time Complexity: O(n)
Space Complexity: O(n)
*/
