/******************************************************************************
Author - @Suvraneel 
        Suvraneel Bhuin

* Implementation of a dynamic, menu-driven Priority Queue using arrays in C++ *
******************************************************************************/

#include <iostream>
using namespace std;

//define queue's max capacity here 
#define capacity 1000
//global variable
int size = -1; 

// defines a structure for each element entered
struct item { 
    int priority;
	int data;
}priorityQ[capacity];

//function to check if queue is empty
bool isEmpty(){
    return (size == -1);
}

//function to check if queue is at capacity
bool isFull(){
    return (size == capacity-1);
}

//function to insert an element into queue
void push(int data, int priority) 
{ 
    // Increment in size
	size += 1; 
	// Insert the element 
    priorityQ[size].priority = priority;
	priorityQ[size].data = data;
    cout << "(" << priorityQ[size].data << ") " << "with priority: " << priorityQ[size].priority << " was enqueued"  << endl;
}

//function to print the entire queue in order of input entered by user
void printQ(){
    cout << "Priority\t" << "Data" << endl;
    for (int i = 0; i <= size; i++)
        cout << priorityQ[i].priority << "\t---->\t" << "(" << priorityQ[i].data << ")" << endl;    
}

// returns highest priority element without deleting it from queue
int peek() 
{
    //Initialising j (index for priority-Q)
    //objective of j is to keep track of the top priority element as of yet
    int j = -1;
    /*
    Set an element with minimum possible priority (i.e, INT_MIN) so that any value will replace the elephant
    *reference to "Elephants in Cairo" problem : 
    A piece of data that matches the search criteria purposefully inserted at the end of a search space, in order to make sure the search algorithm terminates; it is a humorous example of a sentinel value.
    */
	int elephant = INT_MIN; 

	// Check for the element with highest priority (=>definitely not the hypothetical INT_MIN)
	for (int i = 0; i <= size; i++) { 
        if (priorityQ[i].priority > elephant) { 
            //Set that element as highest priority as of yet
			elephant = priorityQ[i].priority;
            //Set j as current index
			j = i; 
		}
		// Priority Tie-breaker : highest data 
		else if (priorityQ[i].priority == elephant && priorityQ[i].data < priorityQ[j].data && j > -1) { 
			elephant = priorityQ[i].priority; 
			j = i; 
		}
	} 
	// Return index
	return j;
}

// Function to remove the element with the highest priority 
void pop() 
{ 
    //To pop the highest priority element, we use peek function
	//peek returns the top priority element when called... the one to be dequeued
	int deQ = peek();
    cout << "(" << priorityQ[deQ].data << ")" << " with priority: " << priorityQ[deQ].priority << " was dequeued";
	// Simply keep shifting all the elements by a slot towards deQ, hence replacing it
	for (int i = deQ; i < size; i++) { 
		priorityQ[i] = priorityQ[i + 1]; 
	}

	// Leads to decrement in size
	size -= 1; 
}

// Main Driver Code (menu-driven)
int main() 
{ 
    //main method
    int choice, entry, priority;
    cout << "1 - Enqueue an element..." << endl;
    cout << "2 - Dequeue an element..." << endl;
    cout << "3 - Display the top priority element" << endl;
    cout << "4 - Display number of elements in queue" << endl;
    cout << "5 - Display current queue" << endl;
    cout << "6 - Exit" << endl;

    while(1)
    {
        cout << endl << "Enter choice:\t";
        cin >> choice;
        switch(choice)
        {
            case 1:
                if (!isFull())
                {
                    cout << "Enter element to enqueue & its priority:";
                    cin >> entry >> priority;
                    push(entry, priority); 
                }
                else cout << "Queue Full";
                break;

            case 2:
                //provided queue isn't empty
                if (!isEmpty())
                    pop();
                break;

            case 3:{    
                int max_prior = peek(); 
                cout << "Element with maximum priority in queue: \n(" << priorityQ[max_prior].data << ") with priority: " << priorityQ[max_prior].priority << endl;
                break;
            }

            case 4:
                cout << "No. of elements in queue currently\t:" << size+1 << endl;
                break;

            case 5:
                printQ();
                break;

            case 6:
                cout << "Program terminated successfully.";
                exit(0);
        }
    }

	return 0; 
}

/*
Time Complexity:
    Enqueue : O(1)
    Peek : O(n)
    Dequeue : O(1) + O(n) for seek = O(n)

Space Complexity: O(n) for array

Sample Run Output:
1 - Enqueue an element...
2 - Dequeue an element...
3 - Display the top priority element
4 - Display number of elements in queue
5 - Display current queue
6 - Exit

Enter choice:   1
Enter element to enqueue & its priority:10 1
(10) with priority: 1 was enqueued

Enter choice:   1
Enter element to enqueue & its priority:20 2
(20) with priority: 2 was enqueued

Enter choice:   1
Enter element to enqueue & its priority:100 5
(100) with priority: 5 was enqueued

Enter choice:   1
Enter element to enqueue & its priority:50 3
(50) with priority: 3 was enqueued

Enter choice:   1
Enter element to enqueue & its priority:75 4
(75) with priority: 4 was enqueued

Enter choice:   5
Priority        Data
1       ---->   (10)
2       ---->   (20)
5       ---->   (100)
3       ---->   (50)
4       ---->   (75)

Enter choice:   4
No. of elements in queue currently      :5

Enter choice:   2
(100) with priority: 5 was dequeued
Enter choice:   4
No. of elements in queue currently      :4

Enter choice:   5
Priority        Data
1       ---->   (10)
2       ---->   (20)
3       ---->   (50)
4       ---->   (75)

Enter choice:   3
Element with maximum priority in queue: 
(75) with priority: 4

Enter choice:   6
Program terminated successfully.
*/

