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
        data = new T[s];
        nextindex = 0;
        firstindex = -1;
        size = 0;
        capacity = s;
    }

    int getSize(){    //Return the number of elements present in queue
        return size;
    }

    bool isEmpty(){    //Indicate whether the queue is empty or not
        return size == 0;
    }

    void enqueue(T element){    //To insert the elements
        if(size == capacity){
            cout<<"Queue is Full !"<<endl;
            return;
        }
        data[nextindex]=element;
        nextindex = (nextindex+1)% capacity;
        if(firstindex == -1){
            firstindex = 0;
        }
        size++;
    }

    T front(){    //Return the top value of queue
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        return data[firstindex];

    }

    T dequeue(){    //Pop the top element
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        T ans = data[firstindex];
        firstindex = (firstindex+1)% capacity;
        size--;
        return ans;
    }
};

int main() {
	QueueUsingArray<int> q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);


	cout << "Top value of queue "<<q.front() << endl;
	cout << "Pop "<<q.dequeue() << endl;
	cout << "Pop "<<q.dequeue() << endl;
	cout << "Pop "<<q.dequeue() << endl;

	cout << "Size "<<q.getSize() << endl;
	cout << "Isempty "<<q.isEmpty() << endl;
}

/*INPUT
10 20 30 40 50 60
OUTPUT
Queue is full!
Top value of queue  10
Pop 10
Pop 20
Pop 30
Size 2
Isempty 0
*/

