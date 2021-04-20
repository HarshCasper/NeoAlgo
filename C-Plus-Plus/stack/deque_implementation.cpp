/*

Implementation of Deque (using Circular Arrays)
======================================================
For implementing a Deque, a 1-d array is maintained.
To keep track of elements, front and rear are initialised.
They are wrapped in a class.

Operations performed ->

isFull()     : checks whether Deque is full or not
isEmpty()    : checks whether Deque is empty or not
insertfront(): adds an element at the front of Deque
insertrear() : adds an element at the rear of Deque
deletefront(): removes an element from the front of Deque
deleterear() : removes an element from the rear of Deque
getFront()   : gets the front element of the Deque
getRear()    : gets the last element of the Deque

*/

#include <iostream>
using namespace std;

// Maximum size of array or Dequeue
#define MAX 100

// A structure to represent a Deque
class Deque
{
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }

    // Operations on Deque:
    void insertfront(int key);
    void insertrear(int key);
    void deletefront();
    void deleterear();
    bool isFull();
    bool isEmpty();
    int getFront();
    int getRear();
    void printDeque();
};

// Checks whether Deque is full or not.
bool Deque::isFull()
{
    return ((front == 0 && rear == size - 1) ||
            front == rear + 1);
}

// Checks whether Deque is empty or not.
bool Deque::isEmpty()
{
    return (front == -1);
}

// Inserts an element at front
void Deque::insertfront(int key)
{
    // check whether Deque if full or not
    if (isFull())
    {
        cout << "Overflow\n"
             << endl;
        return;
    }

    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }

    // front is at first position of queue
    else if (front == 0)
        front = size - 1;

    else // decrement front end by '1'
        front = front - 1;

    // insert current element into Deque
    arr[front] = key;
}

// function to inset element at rear end
// of Deque.
void Deque ::insertrear(int key)
{
    if (isFull())
    {
        cout << " Overflow\n " << endl;
        return;
    }

    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }

    // rear is at last position of queue
    else if (rear == size - 1)
        rear = 0;

    // increment rear end by '1'
    else
        rear = rear + 1;

    // insert current element into Deque
    arr[rear] = key;
}

// Deletes element at front end of Deque
void Deque ::deletefront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << "Queue Underflow\n"
             << endl;
        return;
    }

    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
        if (front == size - 1)
        front = 0;

    else // increment front by '1' to remove current
        // front value from Deque
        front = front + 1;
}

// Delete element at rear end of Deque
void Deque::deleterear()
{
    if (isEmpty())
    {
        cout << " Underflow\n"
             << endl;
        return;
    }

    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size - 1;
    else
        rear = rear - 1;
}

// Returns front element of Deque
int Deque::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << " Underflow\n"
             << endl;
        return -1;
    }
    return arr[front];
}

// function return rear element of Deque
int Deque::getRear()
{
    // check whether Deque is empty or not
    if (isEmpty() || rear < 0)
    {
        cout << " Underflow\n"
             << endl;
        return -1;
    }
    return arr[rear];
}

void Deque::printDeque()
{
    if (front == -1)
    {
        cout << "Deque is empty !" << endl;
    }
    else if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        for (int i = front; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        for (int i = 0; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

// Driver program to test above function
int main()
{
    //Initialising an object of class Deque
    cout << "Enter the size of Deque required : ";
    int n;
    cin >> n;

    Deque dq(n);

    int num;

    //Inserting elements to front of Deque
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        dq.insertfront(num);
    }

    //Printing the current status of Deque after insertion to front end
    cout << "Showing the Deque after insertion from front :" << endl;
    dq.printDeque();

    //Acessing the element at front end of the array of Deque
    cout << "\n\nElement present at front = " << dq.getFront() << endl;

    //Acessing the element at rear end of the array of Deque
    cout << "\nElement present at rear = " << dq.getRear() << endl;

    //Deleting an element from front
    cout << "\nDeleting element from front." << endl;
    dq.deletefront();
    cout << "After deletion, status of Deque : " << endl;
    dq.printDeque();

    //Deleting an element from rear
    cout << "\n\nDeleting element from rear." << endl;
    dq.deleterear();
    cout << "After deletion, status of Deque : " << endl;
    dq.printDeque();

    //Inserting elements from rear end of Deque
    dq.insertrear(10);
    cout << "\n\nAfter inserting element (10) from the rear end : " << endl;

    //Printing the current status of Deque after insertion to rear end
    dq.printDeque();

    return 0;
}

/*
    OUTPUT 

    Enter the size of Deque required : 5
    1 2 3 4 5

    Showing the Deque after insertion from front :
    5 4 3 2 1 

    Element present at front = 5

    Element present at rear = 1

    Deleting element from front.
    After deletion, status of Deque : 
    4 3 2 1 

    Deleting element from rear.
    After deletion, status of Deque : 
    4 3 2 

    After inserting element (10) from the rear end : 
    4 3 2 10


*/
