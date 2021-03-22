/*
AIM :: TO IMPLEMENT DESCENDING PRIORITY QUEUE 

            WHAT IS DESCENDING PRIORITY QUEUE ?
 In descending order priority queue, a higher priority number is given as a higher priority in a priority. For example, 
 we take the numbers from 1 to 5 arranged in descending order like 5, 4, 3, 2, 1; 
 therefore, the largest number, i.e., 5 is given as the highest priority in a priority queue.

*/

#include <iostream>
using namespace std;

//Prototypes
void enq(int *, int &, int &, int); // for insertion
void deq(int *, int &, int &, int); // for deletion
void display(int *, int, int);      // for display

// for checking queue is full or not
int q_full(int, int);
// for checking queue is empty or not
int q_empty(int, int);

int main()
{
    int size = 100, choice;
    int Q[size];

    /*
    Initially front and rear will be at -1
    deletion will be done from front end & insertion will be done from rear end
    */
    int front = -1;
    int rear = -1;

    cout << "\t\t\nDESCENDING PRIORITY QUEUE" << endl;

    while (true)
    {
        cout << "\n1. ENQ\n2. DEQ\n3. DISPLAY\n4. EXIT" << endl;
        cout << "Enter your choice :: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enq(Q, front, rear, size);
            break;

        case 2:
            deq(Q, front, rear, size);
            break;

        case 3:
            display(Q, front, rear);
            break;

        case 4:
            cout << "\nexiting..." << endl;
            exit(0);
            break;

        default:
            cout << "\nInvalid choice :(" << endl;
            break;
        }
    }
    return 0;
}

void enq(int Q[], int &front, int &rear, int size)
{
    int data, temp;

    if (q_full(front, size))
        cout << "QUEUE OVERFLOW" << endl;
    else
    {
        cout << "Enter the data :: ";
        cin >> data;

        //inserting for first time
        if (front == -1)
            front++;

        //find the appropriate place for the data given by the user
        for (temp = rear; temp >= 0 && data > Q[temp]; temp--)
            Q[temp + 1] = Q[temp];

        // insert data at it's right place
        Q[temp + 1] = data;
        rear++;

        display(Q, front, rear);
    }
}

void deq(int Q[], int &front, int &rear, int size)
{
    if (q_empty(front, rear))
        cout << "\nQUEUE UNDERFLOW";
    else
    {
        //storing data which is to be deleted
        int data = Q[front];

        //if front and rear is equal means there was only one element left ,So now reset front and rear
        if (front == rear)
            front = rear = -1;
        else
            front++;

        display(Q, front, rear);
    }
}

void display(int Q[], int front, int rear)
{
    if (q_empty(front, rear))
        cout << "\nQUEUE IS EMPTY :(" << endl;
    else
    {
        cout << "\nQUEUE :: ";
        for (int i = front; i <= rear; i++)
            cout << Q[i] << "    ";
        cout << '\n';
    }
}

int q_full(int rear, int size)
{
    if (rear >= size)
        return 1;

    return 0;
}

int q_empty(int front, int rear)
{
    if (front == -1 || front > rear)
        return 1;

    return 0;
}

/*
TEST CASE


DESCENDING PRIORITY QUEUE

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 1
Enter the data :: 10

QUEUE :: 10

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 1
Enter the data :: 20

QUEUE :: 20    10

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 1
Enter the data :: 15

QUEUE :: 20    15    10

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 1
Enter the data :: 5

QUEUE :: 20    15    10    5

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 2

QUEUE :: 15    10    5

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 2

QUEUE :: 10    5

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 2

QUEUE :: 5

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 2

QUEUE IS EMPTY :(

1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
Enter your choice :: 4

exiting...

TIME COMPLEXITY 
    INSERTION O(n)
    DELETION O(1)
*/
