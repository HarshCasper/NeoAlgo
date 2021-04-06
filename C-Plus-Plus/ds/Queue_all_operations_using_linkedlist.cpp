/*Queue is a data structure which works on FIFO principle i.e First In First Out. Element inserted first will also get deleted first.
Insertion will always take place at front and Deletion from Rear. 
You can understand Queue with the example of a Queue at Ticket counter. The people keep on adding in Queue from End and Exist from Beginning. */
#include<bits/stdc++.h>//Header file for all standard library
using namespace std;
struct Node //Structure of node of linked list
{
 public:
    int info;//Will store integer type data 
    Node *next;//Since this progrm is implemented through linked list therfore to point the next node we have next pointer which will store the address of next adjacent node
} * ptr, *save, *rear, *front, *NEW;//Some of the pointers of Node type
Node *CN(int y) // For creating node
{
    ptr = new Node;// initializing a new node
    ptr->info = y;// assinging the data entered by the user to info part of the node
    ptr->next = NULL;// Putting Null in the next pointer of node 
    return ptr;
}
void insert(Node *NEWPTR)// For inserting node
{
    if (front == NULL)// firstly we will check whether our front of queue is null if yes it means our queue doesn't contain any element so, we will insert our node
    {
      front = rear = NEWPTR;// Now our front and end both are at same point because there is only one node in Queue.                
  
    }
    else // If the above condition is not true it means there are some elements in queue
    {
        rear->next = NEWPTR;//So we know that insertion in queue take place from rear end therfore we will link the rear element of the queue to the new node which was null previously  
        rear = NEWPTR;//Update the new node to be rear
    }
}
void Delete() //for deleting a node
{

    if (front == NULL)//checking whether the front is null if yes it means queue is empty
        cout << "\nUnderflow!!";//So underflow condition arises.

    else// If the above condition is not true means queue has some nodes in it so we will delete them and we know deletion takes place from front of queue
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

    do// This is will generate a menu and perform the operation acc. to your choice. You will get clear when you will run this 
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
