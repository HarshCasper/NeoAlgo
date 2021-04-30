// Deque or Double Ended Queue is a generalized version of Queue data structure that allows insert 
// and delete at both ends.In previous post we had discussed introduction of deque. 
// Now in code we see how we "implement deque Using circular array". 

#include<iostream>
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
    public :
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
	int getRear();
};

// Checks whether Deque is full or not.
bool Deque::isFull()
{
	return ((front == 0 && rear == size-1)||
			front == rear+1);
}

// Checks whether Deque is empty or not.
bool Deque::isEmpty ()
{
	return (front == -1);
}

// Inserts an element at front
void Deque::insertfront(int key)
{
	// check whether Deque if full or not
	if (isFull())
	{
		cout << "OVERFLOW\n" << endl;
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
		front = size - 1 ;

	else // decrement front end by '1'
		front = front-1;

	// insert current element into Deque
	arr[front] = key ;
}

// function to inset element at rear end
// of Deque.
void Deque ::insertrear(int key)
{
	if (isFull())
	{
		cout << " OVERFLOW\n " << endl;
		return;
	}

	// If queue is initially empty
	if (front == -1)
	{
		front = 0;
		rear = 0;
	}

	// rear is at last position of queue
	else if (rear == size-1)
		rear = 0;

	// increment rear end by '1'
	else
		rear = rear+1;

	// insert current element into Deque
	arr[rear] = key ;
}

// Deletes element at front end of Deque
void Deque ::deletefront()
{
	// check whether Deque is empty or not
	if (isEmpty())
	{
		cout << "UNDERFLOW\n" << endl;
		return ;
	}

	// Deque has only one element
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
		// back to initial position
		if (front == size -1)
			front = 0;

		else // increment front by '1' to remove current
			// front value from Deque
			front = front+1;
}

// Delete element at rear end of Deque
void Deque::deleterear()
{
	if (isEmpty())
	{
		cout << "UNDERFLOW\n" << endl ;
		return ;
	}

	// Deque has only one element
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (rear == 0)
		rear = size-1;
	else
		rear = rear-1;
}


// function return rear element of Deque
int Deque::getRear()
{
	// check whether Deque is empty or not
	if(isEmpty() || rear < 0)
	{
		cout << "UNDERFLOW\n" << endl;
		return -1 ;
	}
	return arr[rear];
}

// Main code to check whether the above operations work or not......
int main()
{
	int n, m, k;
	Deque dq(n);
	cout << "Insert element at end :  \n";
	cin>> n;
	dq.insertrear(n);

	cout << "Insert 2nd element at end :  \n";
	cin>>m;
	dq.insertrear(m);	

	cout << "Get rear element -->" << " "
		<< dq.getRear() << endl;

	dq.deleterear();
	cout << "After deletion new rear"
		<< " become " << dq.getRear() << endl;

	cout << "Inserting element at front : \n";
	cin>>k;
	dq.insertfront(k);

	return 0;
}

/*
	TEST CASES:
	
	1--> 

	Input = n , m , k
	values are 2, 6, 8

	Insert element at end :  
	2
	Insert 2nd element at end :  
	6
	Get rear element --> 6
	After deletion new rear become 2
	Inserting element at front :    
	8


	2-->
	
	Input = n , m , k
	values are 4, 7, 9

	Insert element at end :  
	4
	Insert 2nd element at end :  
	7
	Get rear element --> 7
	After deletion new rear become 4
	Inserting element at front :    
	9


	3-->

	Input = n , m , k
	values are 12, 17, 19

	Insert element at end :  
	12
	Insert 2nd element at end :  
	17
	Get rear element --> 17
	After deletion new rear become 4
	Inserting element at front :    
	19





	Time Complexity : 
	insertfront() : O(1).
	insertlast() : O(1).
	deletefront(): O(1).
	deletelast() : O(1).
*/