/*
BEST FIT MEMORY ALLOCATION
Available memory blocks are accepted as input from the user
This strategy will continue searching for a block whose 
size is closest to the requested block size. Pointer to 
the block is returned after retaining residual space
*/

#include <stdio.h>
#include <stdlib.h>

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

//best fit memory allocation
MemoryBlock best_fit(MemoryManager *m, int memory)
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
        MemoryBlock best;
        best.id = -1;
        best.size = -1;
        int count = 0;
        //to find the most suitable memory block
        while (ptr->rlink != NULL)
        {
            if (count == 0)
            {
                if (ptr->b.size >= memory)
                {
                    best.id = ptr->b.id;
                    best.size = ptr->b.size;
                    count = 1;
                }
            }
            else
            {
                if (ptr->b.size >= memory && ptr->b.size < best.size)
                {
                    best.id = ptr->b.id;
                    best.size = ptr->b.size;
                }
            }
            ptr = ptr->rlink;
        }
        best.size = memory;
        bl = best;
        ptr = m;
        //to remove the memory allocated from the block
        while (ptr->rlink != NULL)
        {
            if (ptr->b.id == best.id)
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
    MemoryManager *n = malloc(sizeof(MemoryManager));
    n->b = memory;
    ptr->rlink = n;
    n->llink = ptr;
    n->rlink = NULL;
}

//driver code
int main()
{
    MemoryManager *m = (MemoryManager *)malloc(sizeof(MemoryManager));
    int n;
    //accept the number of memory blocks and sizes as user input
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
    int requested_memory;
    //accept required memory size as user input
    printf("Required Size: ");
    scanf("%d", &requested_memory);
    block = best_fit(m, requested_memory);
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
Required Size: 350                                                                                                                              
Allocating Block #4   

Time Complexity: O(n)
Space Complexity: O(n)
*/
