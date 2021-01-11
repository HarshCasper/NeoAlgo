#include <iostream>
using namespace std;

/*Consider a linear queue which is full - 1 2 3 4 5 6. If we implement three consecutive deletions,

then the queue becomes - _ _ 3 4 5 6. Now, if we try to add a new element in this, the isEmpty() func

will return 'true' and thus, despite having space insertion won't take place.

This is where Circular Queues are used.*/

class CircularQ{
    private:
    int front, rear, size;
    int *arr;

    public:
    CircularQ(int s) {
        front = -1;
        rear = -1;
        size = s;
        arr = new int[s];
        for(int i = 0; i < size; i++) {
        	arr[i] = 0;
		}
    }
    //check for empty queue
    bool isEmpty() {
        if (front == -1 && rear == -1) 
            return true;
        else 
            return false;
    }
    //check for overflow in queue
    bool isFull() {
        if (((rear + 1) % size) == front) 
            return true;
        else
            return false;
    }
	void enqueue(int);
	int dequeue();
	void display();
};

//inserting values in queue
void CircularQ:: enqueue(int value) {
	if (isFull()) {
        cout << "\n!!!Overflow State!!!\n";
        return;
    } else if (isEmpty()) {
        rear = 0;
        front = 0;
        arr[rear] = value;
    } else {
        rear = (rear + 1) % size;
        arr[rear] = value;
    }		
}

//deleting values from queue
int CircularQ:: dequeue() {
	int element = 0;
        if(isEmpty()) {
        	cout << "\n!!!Empty Queue!!!\n";
        	return element;
		} else if(front == rear) {
			element = arr[front];
			front = rear = - 1;
			return element;
		}  else {
			cout << "\nFront value: " << front << endl;
			element = arr[front];
			arr[front] = 0;
			front = (front + 1) % size;
			return element;
		}
}

//displaying contents of queue
void CircularQ::display() {
	for (int i = 0; i < size; i++){
    	cout << arr[i] << " ";
	}
}

int main() {
	int QueueSize;
	cout << "Enter size of Circular Queue\n";
	cin >> QueueSize;
    CircularQ cq(QueueSize);
    int choice, value;
    
    do {
		cout << "\n\nSelect from the following options:\n";
    	cout << "1. Enqueue\n"
            "2. Dequeue\n"
            "3. isEmpty\n"
            "4. isFull\n"
            "5. display\n"
            "Press 0 to exit.\n";
    	cin >> choice;
        switch (choice) {
            case 0:
                break;
            
            case 1:
                cout << "\nInput value to Enqueue\n";
                cin >> value;
                cq.enqueue(value);
                break;
            
            case 2: 
                cout << "\nDequeue Operation...\n";
                cout << cq.dequeue() << endl;
                break;
            
            case 3:
                if (cq.isEmpty())
                    cout << "\nQueue is Empty\n";
                else 
                    cout << "\nQueue is not Empty\n";
                break;
            
            case 4:
                if (cq.isFull())
                    cout << "\nOverflow State\n";
                else 
                    cout << "\nQueue is not Full\n";
                break;
            
            case 5: 
                cout << "\nQueue elements displayed: \n";
                cq.display();
                break;
            
            default:
                cout << "\n!!!Invalid choice. Try Again!!!\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

/*Console Output:

Enter size of Circular Queue
5


Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
3

Queue is Empty


Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
4

Queue is not Full


Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
1

Input value to Enqueue
3


Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
1

Input value to Enqueue
2


Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
1

Input value to Enqueue
4


Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
5

Queue elements displayed:
3 2 4 0 0

Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
3

Queue is not Empty


Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
4

Queue is not Full


Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
2

Dequeue Operation...

Front value: 0
3


Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
5

Queue elements displayed:
0 2 4 0 0

Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
2

Dequeue Operation...

Front value: 1
2


Select from the following options:
1. Enqueue
2. Dequeue
3. isEmpty
4. isFull
5. display
Press 0 to exit.
5

Queue elements displayed:
0 0 4 0 0
*/