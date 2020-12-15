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

	cout << "Enter <1> To push elements \n"
	     "<2> To pop (last) element \n"
	     "<3> To get front element \n"
	     "<4> To get back element\n"
	     "<5> To check if vector is empty \n"
	     "<6> To get size of vector \n"
	     "<7> To get capacity of vector \n"
	     "<8> To get iterator to start of vector \n"
	     "<9> To get iterator to the end of vector \n"
	     "<10> To clear vector \n"
	     "<11> To print the vector \n"
	     "<12> To exit program \n\n";

	cout << "Enter Choice: ";

	// Declaring a vector
	Vector<int> v;

	int choice;

	while (cin >> choice) {

		switch (choice) {

		case 1: cout << "Enter elements to push until -1: ";
			int x;
			cin >> x;
			while (x != -1) {
				v.push_back(x);
				cin >> x;
			} break;

		case 2: if(!v.empty()) v.pop_back(); 
			else cout<<"Vector is empty"<<endl;
			break;
		case 3: if(!v.empty()) cout << v.front() << endl; 
			else cout<<"Vector is empty"<<endl;
			break;
		case 4: if(!v.empty()) cout << v.back() << endl; 
			else cout<<"Vector is empty"<<endl;
			break;
		case 5: cout << v.empty() << endl; break;
		case 6: cout << v.size() << endl; break;
		case 7: cout << v.capacity() << endl; break;
		case 8: cout << v.begin() << endl; break;
		case 9: cout << v.end() << endl; break;
		case 10: v.clear(); break;
		case 11: printVector(v); break;

		default: exit(0);
		}

		cout << "Enter Choice: ";

	}
}

/*
Console output:

Enter <1> To push elements
<2> To pop elements
<3> To get front element
<4> To get back element
<5> To check if vector is empty
<6> To get size of vector
<7> To get capacity of vector
<8> To get iterator to start of vector
<9> To get end of vector
<10> To clear vector
<11> To print the vector
<12> To exit program
Enter Choice: 1
Enter elements to push until -1: 1 2 3 -1
Enter Choice: 11
1 2 3
Enter Choice: 2
Enter Choice: 11
1 2
Enter Choice: 3
1
Enter Choice: 4
2
Enter Choice: 5
0
Enter Choice: 6
2
Enter Choice: 7
4
Enter Choice: 8
0x6a0f68
Enter Choice: 9
0x6a0f70
Enter Choice: 10
Enter Choice: 11

Enter Choice: 12

*/
