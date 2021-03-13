// This is a code of circular queue

#include<iostream>
#include<stdlib.h>

// Defining max size of the queue as 5

#define max 5

using namespace std;

// Writing a class where all the basic functions of the circular queue presides

class CircularQueue{
    // Defining all the variables as public variables.
    // (It is not necessory of define the variables as public,
    //  you can define the variables as private also)
    public:
    int front;
    int rear;
    int arr[max];

    // Initializing a default constructor of the class

    CircularQueue(){

    front = -1;
    rear = -1;
        for(int i = 0; i < max; i++){
            arr[i] = 0;
        }
    }

    // Defining the isFull function to check whether the queue is full or not

    bool isFull(){
        if ((rear + 1) % max == front)

            return true;


        else

            return false;

    }

    // Defining the isEmpty function to check whether the queue is empty or not
    bool isEmpty(){
        if (front == -1 && rear == -1)

            return true;


        else

            return false;

    }

    // Defining the enqueue function, to insert an item in the queue
    void enqueue(int item){
        if(isFull())
        {
            cout << "Queue is full" << endl;
        }

        else if (isEmpty()){
            front=rear=0;
            arr[rear] = item;
        }

        else {
            rear = (rear + 1) % 5;
            arr[rear] = item;
        }

    }

    // Defining the dequeue function, to delete item from the queue

    int dequeue(){
      int x = 0;       
        if(front == rear){
          x = arr[front];
          front = rear = -1;
          return x;
        }

        else
        {
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % 5;
            return x;
        }
    }

    // Defing display function to display the whole queue

    void display(){
            for (int i = 0; i < 5; i++)
            {
                cout << arr[i] <<endl;
            }   
    }
};

// Testing the above functions:

int main()
{
    // Declaring an object to the class

    CircularQueue Q1;

    // A menu driven program to check all the defined functions in the class

    while (1)
    {
        cout << "1. Insert an element in the queue - enqueue" << endl;
        cout << "2. Delete element from the queue - Dequeue" << endl;
        cout << "3. Display items in the queue" << endl;
        cout << "4. To check whether the queue is empty or not" << endl;
        cout << "5. To check whether the queue is full or not" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice" << endl;
        int n;

        cin >> n;

        switch(n){

            case 1:
                int item;
                cout << "Enter the item" << endl;
                cin >> item;
                Q1.enqueue(item);
                break;

            case 2:
                if(!Q1.isEmpty()){
                    cout << "The dequeued value is: " << Q1.dequeue() << endl;
                }
                else{
                    cout << "The queue is empty" << endl;
                }

                break;

            case 3:
                cout << "The Queue is" << endl;
                Q1.display();
                break; 

            case 4:
                if(Q1.isEmpty()){
                    cout<<"Queue is Empty"<<endl;
                }
                else{
                    cout<<"Queue is not Empty"<<endl;
                }

            break;

            case 5:
                if(Q1.isFull()){                    
                    cout<<"Queue is Full"<<endl;
                }
                else{
                    cout<<"Queue is not Full"<<endl;
                }
            break;         

            case 6:
                exit(1);  

            default:
                cout << "Choose the options correctly";
                break;        
        }
    } 
    return 0;
}

// NOTE:- 1)  The time complexity of all the operations is O(1), that is constant time
        // 2) The time complexity of display function is O(n), where n is the number of Elements in the queue 