//Implementation of all the basic functionality of queue using array .

#include<iostream>
using namespace std;

template<typename T>
class QueueUsingArray{
    T *data;
    int nextindex;    //Index where the element should be inserted
    int firstindex;    //Index where top value is store
    int size;    //The no. of elements present in queue
    int capacity;    //The total size of queue

public:
    QueueUsingArray(int s){
        data = new T[s];    //create an array 
        nextindex = 0;
        firstindex = -1;    //firstindex is initialised by -1 because till now we don't have any element as top .
        size = 0;
        capacity = s;
    }

    int getSize(){    //Return the number of elements present in queue
        return size;
    }

    bool isEmpty(){    //Indicate whether the queue is empty or not
        return size == 0;
    }

    void enqueue(T element){    //function to insert an element at the rear of the queue 
        if(size == capacity){
            cout<<"Queue is Full !"<<endl;
            return;
        }
        data[nextindex]=element;
        nextindex = (nextindex+1)% capacity;    //If number of elements in queue less than capacity
        if(firstindex == -1){
            firstindex = 0;
        }
        size++;    //increament the size when a new  element is inserted
    }

    T front(){    //Return the top value of queue
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        return data[firstindex];

    }

    T dequeue(){    //function to delete an element from the front of the queue 
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        T ans = data[firstindex];
        firstindex = (firstindex+1)% capacity;    //modify the firstindex value to top value index
        size--;
        return ans;
    }
};

int main() {
	QueueUsingArray<int> q(5);    // Create a queue of capacity 5
	
	q.enqueue(10);    //insert 10 in the queue
	q.enqueue(20);    //insert 20 in the queue
	q.enqueue(30);    //insert 30 in the queue
	q.enqueue(40);    //insert 40 in the queue
	q.enqueue(50);    //insert 50 in the queue
	q.enqueue(60);    //insert 60 in the queue


	cout << "Top value of queue : "<<q.front() << endl;     
	cout << "Pop  value from the queue : "<<q.dequeue() << endl;
	cout << "Pop  value from the queue : "<<q.dequeue() << endl;
	cout << "Pop  value from the queue : "<<q.dequeue() << endl;

	cout << "Total element in the queue : "<<q.getSize() << endl;
	cout << "Isempty "<<q.isEmpty() << endl;
	
	return 0;
}


