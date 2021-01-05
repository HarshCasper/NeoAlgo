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

    bool isEmpty() {
        if (front == -1 && rear == -1) 
            return true;
        else 
            return false;
    }

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

void CircularQ:: enqueue(int value) {
	if (isFull()) {
        cout << "\n!!!Queue is Full!!!\n";
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
