/*
AIM :: To implement Priority Queue (PQ) using Linked List (LL).

            WHAT IS PRIORITY QUEUE ?
A priority queue is an abstract data type that behaves similarly to the normal queue except that each element has some priority, 
i.e., the element with the highest priority would come first in a priority queue. 
The priority of the elements in a priority queue will determine the order in which elements are removed from the priority queue.

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;          //for storing data
    int prior;         // for storing priority of the data
    struct node *next; // for storing next node's address
} * front;
typedef struct node PQ;

//protorypes
void enq();     // for insertion
void deq();     // for deletion
void display(); // for display

int main()
{
    int choice;
    printf("\n\t\tPRIORITY QUEUE IMPLEMENTION USING LINKED LIST\n\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. ENQ\n2. DEQ\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice :: ");
        scanf("%d", &choice);

        switch (choice)
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
    PQ *new_node = (PQ *)malloc(sizeof(PQ));
    new_node->next = NULL;

    //take data and priority of that data form the user
    printf("\nenter data: ");
    scanf("%d", &new_node->data);

    printf("\nenter priority of %d: ", new_node->data);
    scanf("%d", &new_node->prior);

    // if queue is full then insert the new node at the beginning
    if (front == NULL || new_node->prior < front->prior)
    { // insertion at beginning
        new_node->next = front;
        front = new_node;
    }
    else
    {
        PQ *temp = front;

        //finding the appropriate position and insert the new node there
        while (temp->next != NULL && temp->next->prior <= new_node->prior)
            temp = temp->next;

        new_node->next = temp->next;
        temp->next = new_node;
    }
    display();
}

void deq()
{
    //if queue is already empty then display error message
    if (front == NULL)
        printf("\nPRIORITY QUEUE IS EMPTY :(\n");
    else
    {
        PQ *temp = front;

        //every time deleting the first
        front = front->next;
        temp->next = NULL;
        free(temp);

        display();
    }
}

void display()
{
    if (front == NULL)
        printf("\npriority queue is empty :(\n");
    else
    {
        //temp_data to store and display the data of queue while traversing
        PQ *temp_data = front;

        //temp_priority to store and display the priority of data that are being displayed
        PQ *temp_priority = front;

        // displaying data in queue
        printf("\nQUEUE     :: ");
        while (temp_data != NULL)
        {
            printf("%d  ", temp_data->data);
            temp_data = temp_data->next;
        }

        // displaying priority of all the data in the queue
        printf("\nPRIORIOTY :: ");
        while (temp_priority != NULL)
        {
            printf("%d  ", temp_priority->prior);
            temp_priority = temp_priority->next;
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

TIME COMPLEXITY
    INSERTION :: O(n)
    DELETION :: O(n)
    DISPLAY  :: O(n)
*/
