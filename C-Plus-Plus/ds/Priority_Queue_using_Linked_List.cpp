//AIM :: To implement Priority Queue (PQ) using Linked List (LL).

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
    int ch;
    cout << "\n\t\tPQ IMPLEMENTATION" << endl;

    while (true)
    {
        // give the menu to user
        cout << "\n1. ENQ\n2. DEQ\n3. DISPLAY\n4. EXIT" << endl;
        cout << "Enter your choice :: ";
        cin >> ch;

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
    PQ *ptr = (PQ *)malloc(sizeof(PQ));
    ptr->next = NULL;

    //ask user to enter the data and priority of that data
    cout << "Enter the data :: ";
    cin >> ptr->data; // storing data into data field

    cout << "Enter priority of " << ptr->data << " :: ";
    cin >> ptr->prior; // storing priority of that data

    // if linked list is empty
    if (front == NULL || ptr->prior <= front->prior) // then insert at begin
    {
        ptr->next = front;
        front = ptr;
    }
    else
    {
        PQ *temp = front;
        //traverse till the appropriate position
        while (temp->next != NULL && temp->next->prior <= ptr->prior)
            temp = temp->next;

        //inseting node at it's appropriate position
        ptr->next = temp->next;
        temp->next = ptr;
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
        PQ *TD = front, *TP = front;

        // displaying data in queue
        cout << "\nDATA     :: ";
        while (TD != NULL)
        {
            cout << TD->data << "    ";
            TD = TD->next;
        }

        // displaying priority of all the data in the queue
        cout << "\nPRIORITY :: ";
        while (TP != NULL)
        {
            cout << TP->prior << "     ";
            TP = TP->next;
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
