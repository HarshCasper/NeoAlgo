/*
Program by :: Anand Dasani 
Date :: 17-March-2021
AIM :: To implement Priority Queue (PQ) using Linked List (LL).

                                ALGO
1. Take  data from the user 
2. Take priority of that data from the user 
3. According to priority traverse the linked list 
    (a) if linked list is empty then insert the node at the beginning 
    (b) else insert that data at it's appropriate place 
4. Deletion will be done by front only 
    (a) if linked list is empty then so error message "PQ UNDERFLOW"
    (b) else delete the first node everytime user want the deq 
5. Exit 

TIME COMPLEXITY
    INSERTION :: O(n)
    DELETION :: O(n)
    DISPLAY  :: O(n)
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    int prior;
    struct node *next;
} * F;
typedef struct node PQ;

//protorypes
void enq();     // for insertion
void deq();     // for deletion
void display(); // for display

int main()
{
    int ch;
    printf("\n\t\tPRIORITY QUEUE IMPLEMENTION USING LINKED LIST\n\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. ENQ\n2. DEQ\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice :: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enq();
            break;

        case 2:
            deq();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nexiting...\n");
            exit(0);
            break;

        default:
            printf("\nINVALID CHOICE :(\n");
            break;
        }
    }
    return 0;
}

void enq()
{
    // creating new node
    PQ *ptr = (PQ *)malloc(sizeof(PQ));
    ptr->next = NULL;

    //take data and priority of that data form the user
    printf("\nenter data: ");
    scanf("%d", &ptr->data);

    printf("\nenter priority of %d: ", ptr->data);
    scanf("%d", &ptr->prior);

    // if queue is full then insert the new node at the beginning
    if (F == NULL || ptr->prior < F->prior)
    { // insertion at beginning
        ptr->next = F;
        F = ptr;
    }
    else
    {
        PQ *temp = F;

        //finding the appropriate position and insert the new node there
        while (temp->next != NULL && temp->next->prior <= ptr->prior)
            temp = temp->next;

        ptr->next = temp->next;
        temp->next = ptr;
    }
    display();
}

void deq()
{
    //if queue is already empty then display error message
    if (F == NULL)
        printf("\nPRIORITY QUEUE IS EMPTY :(\n");
    else
    {
        PQ *temp = F;
        F = F->next;
        temp->next = NULL;
        free(temp);
        display();
    }
}

void display()
{
    if (F == NULL)
        printf("\npriority queue is empty :(\n");
    else
    {
        PQ *tq = F, *tp = F;

        printf("\nQUEUE     :: ");
        while (tq != NULL)
        {
            printf("%d  ", tq->data);
            tq = tq->next;
        }

        printf("\nPRIORIOTY :: ");
        while (tp != NULL)
        {
            printf("%d  ", tp->prior);
            tp = tp->next;
        }
        printf("\n");
    }
}

/*
TEST CASE

               PRIORITY QUEUE IMPLEMENTION USING LINKED LIST

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 1
Enter the data :: 30
Enter priority of 30 :: 2

DATA     :: 30
PRIORITY :: 2

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 1
Enter the data :: 10
Enter priority of 10 :: 1

DATA     :: 10    30
PRIORITY :: 1     2

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 2

DATA     :: 30
PRIORITY :: 2

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 4

Exiting...
*/
