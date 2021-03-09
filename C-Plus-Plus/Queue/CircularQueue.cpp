#include <exception>
#include <iostream>
template <typename T>
class Queue  {
private:
	T size;
	T * data;
	T front;
	T rear;
	int next(int of) {
		return (of + 1) % size;
	}
public:
	Queue(int size):size(size+1){
		data = new T[size+1];
		front = 0;
		rear = 0;
	}
	bool isFull(){
		return next(rear) == front;
	}
	bool isEmpty() {
		return front == rear;
	}
	void insert(T n) {
		if (!isFull()) {
			rear = next(rear);
			data[rear] = n;
			return;
		}
		throw(std::exception("Queue is full"));
	}
	T remove() {
		if (isEmpty()) {
			throw std::exception("Queue is already empty");
		}
		T val = data[next(front)];
		front = next(front);
		return val;
	}

};

//unit test for queue
int main(){
	Queue<int>* q = new Queue<int>(5);
	try {
		
		std::cout<<q->remove();
		std::cout<<q->remove();
		std::cout<<q->remove();
		std::cout<<q->remove();
		std::cout<<q->remove();
		q->insert(9);
		q->insert(6);
		q->insert(6);
		q->insert(6);
		q->insert(6);
		std::cout << q->remove();
		std::cout << q->remove();
		std::cout << q->remove();
		std::cout << q->remove();
		std::cout << q->remove();
	}
	catch (std::exception e) {
		std::cout<<e.what();
	}


}