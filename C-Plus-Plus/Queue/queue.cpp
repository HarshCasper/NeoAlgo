#pragma once

#include <iostream>
#include <exception>
template <typename T>
class Queue {
	T* data;
	int first;
	int last;
	int size;
public:
	Queue(int size):size(size){
		data = new T[size];
		first = 0;
		last = 0;
	}
	bool isEmpty() {
		return first == last;
	}
	bool isFull() {
		return last == size ;
	}
	T front() {
		if (!isEmpty())return data[first];
		throw std::exception("Exception!! cant call front when queue is empty");
	}
	void enqueue(T item) {
		if (!isFull())data[last++] = item;
		else throw std::exception("Exception!!  already full ");

	}
	void dequeue() {
		if (!isEmpty())first++;
		else throw(std::exception("Exception!! already empty "));
	}

};

//unit test
int main() {
	try {
		auto q = new Queue<int>(3);
		q->enqueue(5);
		q->enqueue(2);
		q->enqueue(4);
		
		q->dequeue();
		q->dequeue();
		std::cout << q->front();
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
	

}