/*Queue is a data structure which works on FIFO principle i.e First In First Out. Element inserted first will also get deleted first.Insertion will always take place at front and Deletion from Rear. You can understand Queue with the example of a Queue at Ticket counter. The people keep on adding in Queue from End and Exist from Beginning. */
#include<bits/stdc++.h>//Header file for all standard library
using namespace std;
struct Node //Structure of node of linked list
{
 public:
    int info; 
    Node *next;
} * ptr, *save, *rear, *front, *NEW;
Node *CN(int y) // For creating node
{
    ptr = new Node;
    ptr->info = y;
    ptr->next = NULL;
    return ptr;
}
void insert(Node *NEWPTR)// For inserting node
{
    if (front == NULL)
    {
      front = rear = NEWPTR;                
  
    }
    else
    {
        rear->next = NEWPTR;  
        rear = NEWPTR;
    }
}
void Delete() //for deleting a node
{

    if (front == NULL)
        cout << "\nUnderflow!!";

    else
    {
        ptr = front;
        front = front->next;
        delete ptr;
        cout << "\nValue got deleted";
    }
}
/*Time complexity:- O(n)
   Space Complexity:- O(n)*/
void Display(Node *D) //for displaying the queue
{
    if (D != NULL)
    {
        while (D != NULL)
        {
            cout << D->info << "-->";
            D = D->next;
        }
    }
    else
        cout << "Empty!:(";
}

int main()
{
    int a, x;
    char ch = 'y';
    do 
    {
        cout << "\nWhat do u want to do with Queue\n1. Insert a node \n2. Delete a node \n3. Display\n Enter your choice:";
        cin >> a;
        switch (a)
        {

        case 1:
        {
            cout << "\nEnter the data of new node :";
            cin >> x;
            NEW = CN(x);
            insert(NEW);
            cout << "\nNew node with value " << x << " is inserted in Queue.";
        }
        break;
        case 2:
        {
            Delete();
            cout << "\nFront node is Deleted Successfully!!";
        }
        break;
        case 3:
        {
            cout << "\nYour queue is:";
            Display(front);
        }
        break;

        default:
            cout << "\nWANT TO DO NOTHING! IT's OK!";
        }
        cout << "\nWant to insert or delete an another node?(Y/N):";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
/* Time complexity for both insertion and deletion is:- O(1)
   Space Complexity:- O(n)*/
/* Test case
Sample Input:
What do u want to do with Queue
1. Insert a node
2. Delete a node
3. Display
 Enter your choice: 1
Enter the data of new node : 23
Sample Output:
New node with value 23 is inserted in queue.
*/
