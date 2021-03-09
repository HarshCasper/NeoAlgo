#include <iostream>
#include <exception>

template <typename T>
class Deque {
private:
	T* data;
	int head;
	int tail;
	int size;
	//move circularly foreward
	int next(int of) {
		return (of + 1) % size;
	}
	//move circularly backward
	int prev(int of) {
		if (of == 0)return size - 1;
		return (of -1);
	}
public:
	Deque(int size):size(size+1) {
		data = new T[size+1];
		head = 0;
		tail = 0;
	}
	bool isEmpty() {
		return head == tail;
	}
	bool isFull() {
		return next(tail) == head;
	}
	void addFirst(T item) {
		if (!isFull()) {
			data[head] = item;
			head = prev(head);
			return;
		}
		throw std::exception(" Exception!!! Already Full");
		
	}
	void removeFirst() {
		if (!isEmpty()) {
			head = next(head);
			return;
		}
		throw std::exception("Exception!!!  Already empty");
		
	}
	void addLast(T item)
	{
		if (!isFull()) {
			tail = next(tail);
			data[tail] = item;
			return;
		}
		throw std::exception("Exception!!! Already Full");
	}
	void removeLast() {
		if (!isEmpty()) {
			tail = prev(tail);
			return;
		}
		throw std::exception("Exception!!! Already empty");

	}
	T first() {
		if (!isEmpty()) {
			return data[next(head)];
		}
		throw std::exception("Exception!!! Already Empty");
		
	}
	T last() {
		if (!isEmpty()) {
			return data[tail];
		}
		throw std::exception("Exception!!! Already empty");
		
	}
};

//unit test for deque
int main() {
	auto dq = new Deque<int>(5);
	try {
		dq->addFirst(5);
		dq->addFirst(7);
		dq->addFirst(8);
		dq->addLast(5);
		dq->removeFirst();
		dq->removeFirst();
		dq->removeFirst();
		dq->removeFirst();
		if (dq->isEmpty())std::cout << "empty" << std::endl;
		//std::cout << "first:" << dq->first() << std::endl;
		//std::cout << "last:" << dq->last() <<std::endl;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}