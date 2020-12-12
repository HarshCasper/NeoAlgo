/*
Vector
-------
A vector is a re-sizeable array. Internally, vectors use a dynamically allocated array
to store their elements. If the array is full and new elements have to be added
in it, then a new array of twice the size is declared and all the elements from the
previous array are copied onto the new array. This is an expensive operation

push_back() Time Complexity: O(current size)

*/

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Vector {

	int cs; // Current Size : Gives count of the elements currently in vector
	int ms; // Maximum Size : Gives count of the maximum elements that can be in vector
	T *arr;	// Array declared
public:
	// Constructor
	Vector() {
		cs = 0;
		ms = 1;
		// Array is dynamically allocated memory space
		arr = new T[ms];
	}

	// Inserts new element into the vector from back
	void push_back(const T d) {

		if (cs == ms) {
			// Array is full
			T *oldArr = arr;
			// arr points to a new memory location with twice memory space
			arr = new T[2 * ms];
			ms = 2 * ms;
			// Copy elements from oldArr
			for (int i = 0; i < cs; i++) {
				arr[i] = oldArr[i];
			}
			// clear the old memory
			delete [] oldArr;
		}

		// Insert new element
		arr[cs] = d;
		cs++;
	}

	// Removes last element from the vector
	void pop_back() {
		cs--;
	}

	// Returns the element at the front of the vector
	T front() const {
		return arr[0];
	}

	// Returns the element at the back of the vector
	T back() const {
		return arr[cs - 1];
	}

	// Returns whether vector is empty
	bool empty() const {
		return cs == 0;
	}

	// Returns current size of the vector
	int size() const {
		return cs;
	}

	// Returns maximum size of the vector
	int capacity() const {
		return ms;
	}

	// Returns iterator to the start of the vector
	T* begin() const {
		return arr;
	}

	// Returns iterator to the end of the vector
	T* end() const {
		return arr + cs;
	}

	// Returns element at ith index
	T operator[](const int i) {
		return arr[i];
	}

	// Clears the vector
	void clear() {
		cs = 0;
	}
};

void printVector(Vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	} cout << endl;
}

int main() {

	// Declaring a vector
	Vector<int> v;

	int num;

	while (cin >> num) {
		v.push_back(num);
	}

	printVector(v);

	cout << "Size = " << v.size() << endl;
	cout << "Capacity = " << v.capacity() << endl;
	cout << "Front = " << v.front() << endl;
	cout << "Back = " << v.back() << endl;
	v.clear();
	cout << "Size after clearing = " << v.size() << endl;
	cout << "Capacity after clearing = " << v.capacity();
}

/*
Sample Input:
1 2 3

Sample Output:
1 2 3
Size = 3
Capacity = 4
Front = 1
Back = 3
Size after clearing = 0
Capacity after clearing = 4

*/
