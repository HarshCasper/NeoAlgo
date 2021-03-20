/* 
AIM :: To implement Priority Queue (PQ) using Linked List (LL).

            WHAT IS PRIORITY QUEUE ?
A priority queue is an abstract data type that behaves similarly to the normal queue except that each element has some priority, 
i.e., the element with the highest priority would come first in a priority queue. 
The priority of the elements in a priority queue will determine the order in which elements are removed from the priority queue.

*/

#include <iostream>
#include <stdlib.h> // for using malloc (DMA)
using namespace std;

struct node
{
    int data;          // to store data
    int prior;         // to store priority of data
    struct node *next; // to store next node's pointer
} * front;             // front pointer of PQ
typedef struct node PQ;

// prototypes
void enq();     // for insertion
void deq();     // for deletion
void display(); // for display

int main()
{
    int choice; //for storing the choice of user after viewing the options
    cout << "\n\t\tPQ IMPLEMENTATION" << endl;

    while (true)
    {
        // give the menu to user
        cout << "\n1. ENQ\n2. DEQ\n3. DISPLAY\n4. EXIT" << endl;
        cout << "Enter your choice :: ";
        cin >> choice;

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
            cout << "Exiting...";
            exit(0);
            break;

        default:
            cout << "Invalid choice :(" << endl;
        }
    }
    return 0;
}

void enq()
{
    //creating new node
    PQ *new_node = (PQ *)malloc(sizeof(PQ));
    new_node->next = NULL;

    //ask user to enter the data and priority of that data
    cout << "Enter the data :: ";
    cin >> new_node->data; // storing data into data field of newly created node

    cout << "Enter priority of " << new_node->data << " :: ";
    cin >> new_node->prior; // storing priority of that data

    // if linked list is empty or priority is less than first position
    if (front == NULL || new_node->prior <= front->prior)
    { // then insert at begin
        new_node->next = front;
        front = new_node;
    }
    else
    {
        PQ *temp = front;
        //traverse till the appropriate position
        while (temp->next != NULL && temp->next->prior <= new_node->prior)
            temp = temp->next;

        //inseting node at it's appropriate position
        new_node->next = temp->next;
        temp->next = new_node;
    }
    display(); // display the result
}

void deq()
{
    if (front == NULL) // means queue is empty
        cout << "QUEUE UNDERFLOW" << endl;
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
    if (front == NULL) // means queue is empty
        cout << "QUEUE UNDERFLOW" << endl;
    else
    {
        //temp_data to store and display the data of queue while traversing
        PQ *temp_data = front;

        //temp_priority to store and display the priority of data that are being displayed
        PQ *temp_priority = front;

        // displaying data in queue
        cout << "\nDATA     :: ";
        while (temp_data != NULL)
        {
            cout << temp_data->data << "    ";
            temp_data = temp_data->next;
        }

        // displaying priority of all the data in the queue
        cout << "\nPRIORITY :: ";
        while (temp_priority != NULL)
        {
            cout << temp_priority->prior << "     ";
            temp_priority = temp_priority->next;
        }
    }
}

/*
TEST CASE

                PQ IMPLEMENTATION

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
