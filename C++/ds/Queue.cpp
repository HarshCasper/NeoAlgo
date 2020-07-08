#include <iostream>
using namespace std;

class Queue{          //Declaring class Queue using Array
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
Queue()       //Initializing all class memebers in default constructor
{
    front=-1;
    rear=-1;
    size=10;
    Q=new int[size];
}
Queue(int size)   //Initializing Array size which is given as input from Main 
{
    front=-1;
    rear=-1;
    this->size=size;
    Q=new int[this->size];
}

void Enqueue(int x){
    if(rear==size-1)          //When Array is full,then Queue is full since no space to insert new element
    {
        cout <<"Queue is full" <<endl;
    }
    else
    {
        Q[rear+1] = x;
        rear++;
    }
}

int dequeue()
{
    int x=-1;
    if(front==rear)      //when no elements present in Queue, then Queue is empty
    {
        cout <<"Queue is empty" << endl;
    }
    else{
        x = Q[front+1];
        front++;
    }
return x;
}

void display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout <<Q[i] << " ";
    }
    cout << endl;
}
};


int main()
{
    int size,num;
    cout <<"Enter size of Queue: "<< endl;
    cin >>size;
    Queue q(size);                           //Here we pass the size through parameterized constructor
    cout <<"Enter the elements into Queue: "<< endl;
    for(int i=0;i<size;i++)
    {
        cin >> num;
        q.Enqueue(num);
    }
    cout <<"Displaying Elements in Queue: " << endl;  // To display elements in the Queue
    q.display();
    cout <<"To remove element from front of the Queue" <<endl;   //Queue removes elements from front in general
    int num2;
    num2=q.dequeue();
    cout <<"Removed "<< num2 << " from Queue" << endl; // Returns the removed element from front of the Queue
    return 0;
}
