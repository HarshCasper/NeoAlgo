/*
Heap is a binary tree which satisfies two properties:
    1.Structure Property: All levels have maximum number of nodes except possibly the last level. In the last level, all nodes are to the left.
    2.Heap Order Property: (max heap)Key in any node N is greater than or equal to the keys in both children of N.
                           (min heap)Key in any node N is less than or equal to the keys in both children of N.
Representation of heap tree: 
    Sequential representation is good as heap is a complete binary tree. (No wasted array locations)
    We maintain the heap size in a variable. 
    Left child of a node at i is 2i+1 (When using array from index 0)
    Right child of a node at i is 2i+2
    Parent is (i-1)/2

In the following code both max heap and min heap are implemented.
*/
#include<bits/stdc++.h>

using namespace std;
class Maxheap {
  //Pointer to the start of array
  int * heap;
  //For the current size of heap
  int size;
  //The maximum number of nodes it can have
  int capacity;
  public:
    Maxheap(int cap): capacity {
      cap
    }, size {
      0
    } {
      heap = new int[capacity];
    }

  //Returns the index of left child 
  int left_child(int parent) {
    int index_of_left_child = 2 * parent + 1;
    if (index_of_left_child <= size) {
      return index_of_left_child;
    } else {
      return -1;
    }
  }

  //Returns the index of right child 
  int right_child(int parent) {
    int index_of_right_child = 2 * parent + 2;
    if (index_of_right_child <= size) {
      return index_of_right_child;
    } else {
      return -1;
    }
  }

  //Returns the index of parent 
  int parent(int child) {
    return (child - 1) / 2;
  }

  //Method to insert an item into the heap
  void insert_value(int data) {
    if (size == capacity) {
      cout << "Overflow, heap at max capacity" << endl;
      return;
    }
    size++;
    int index = size - 1;
    heap[index] = data;

    //Restoring the max_heap property
    //The new node added must be taken to its correct position based on the heap order property for max heap
    //Move the node up the tree until its less or equal to its parent or it becomes the root node
    while (index > 0 && heap[index] > heap[parent(index)]) {
      swap(heap[index], heap[parent(index)]);
      index = parent(index);
    }
  }

  //Method to delete an item from the heap
  //NOTE: That the element is always deleted from the top of a heap as it gives the maximum element
  int delete_value() {
    if (size == 0) {
      cout << "Underflow, heap is already empty" << endl;
      return -1;
    }
    //Storing the value of the item to be removed
    int max_value = heap[0];
    //Overwriting with the last value
    heap[0] = heap[size - 1];
    //Decreasing size
    size--;
    int index = 0;
    int l, r, largest;
    //Taking the overwritten value to its correct position
    //Move the new node down the tree until it is greater than both of its children
    while (index < size) {
      largest = index;
      l = left_child(index);
      r = right_child(index);
      //Check if the left child is larger than it
      if (l != -1 && heap[l] > heap[index]) {
        largest = l;
      }
      //Check if the right child is also large 
      if (r != -1 && heap[largest] < heap[r]) {
        largest = r;
      }
      //Condition that returns true if the node is larger or equal to both its children
      if (largest == index) break;
      //Move the largest(i.e from left and right child) up
      swap(heap[index], heap[largest]);
      index = largest;
    }
    //Returning the value of deleted item
    return max_value;
  }

  //Level order traversal of heap 
  void print() {
    for (int i = 0; i < size; i++) {
      cout << heap[i] << " ";
    }
    cout << endl;
  }
};

class Minheap {
  int * heap, size, capacity;
  public:
    Minheap(int cap): capacity {
      cap
    }, size {
      0
    } {
      heap = new int[capacity];
    }
  int left_child(int parent) {
    int index_of_left_child = 2 * parent + 1;
    if (index_of_left_child <= size) {
      return index_of_left_child;
    } else {
      return -1;
    }
  }
  int right_child(int parent) {
    int index_of_right_child = 2 * parent + 2;
    if (index_of_right_child <= size) {
      return index_of_right_child;
    } else {
      return -1;
    }
  }
  int parent(int child) {
    return (child - 1) / 2;
  }
  void insert_value(int data) {
    if (size == capacity) {
      cout << "Overflow, heap at max capacity" << endl;
      return;
    }
    size++;
    int index = size - 1;
    heap[index] = data;

    //Restoring the min_heap property
    //Move the node up the tree until it is larger than or equal to its parent node
    while (index > 0 && heap[index] < heap[parent(index)]) {
      swap(heap[index], heap[parent(index)]);
      index = parent(index);
    }
  }

  //Method to delete an item from the heap
  //NOTE: That the element is always deleted from the top of a heap as it gives the minimum element
  int delete_value() {
    if (size == 0) {
      cout << "Underflow, heap is already empty" << endl;
      return -1;
    }
    //Storing the value of the item to be removed
    int min_value = heap[0];
    //Overwriting with the last value
    heap[0] = heap[size - 1];
    //Decreasing size
    size--;
    int index = 0;
    int l, r, smallest;
    //Taking the overwritten value to its correct position
    //Move the node down the tree until it is less than or equal to both its children
    while (index < size) {
      smallest = index;
      l = left_child(index);
      r = right_child(index);
      if (l != -1 && heap[l] < heap[index]) {
        smallest = l;
      }
      if (r != -1 && heap[smallest] > heap[r]) {
        smallest = r;
      }
      if (smallest == index) break;
      swap(heap[index], heap[smallest]);
      index = smallest;
    }
    //Returning the value of deleted item
    return min_value;
  }
  void print() {
    for (int i = 0; i < size; i++) {
      cout << heap[i] << " ";
    }
    cout << endl;
  }
};
int main() {
  int n;
  cout << "Enter the capacity of your heap ";
  cin >> n;
  int choice;
  cout << "Input 1 if you want to use max heap and 2 if min heap: ";
  cin >> choice;
  if (choice == 1) {
    Maxheap my_heap(n);
    int a;
    cout << "Enter the values to be added in heap: ";
    for (int i = 0; i < n; i++) {
      cin >> a;
      my_heap.insert_value(a);
    }
    my_heap.print();
    cout << "Enter 1 to delete from the heap and 2 to exit: ";
    cin >> choice;
    if (choice == 1) {
      my_heap.delete_value();
      cout << "New heap: ";
      my_heap.print();
    }
  } else {
    Minheap my_heap(n);
    int a;
    cout << "Enter the values to be added in heap: ";
    for (int i = 0; i < n; i++) {
      cin >> a;
      my_heap.insert_value(a);
    }
    my_heap.print();
    cout << "Enter 1 to delete from the heap and 2 to exit: ";
    cin >> choice;
    if (choice == 1) {
      my_heap.delete_value();
      cout << "New heap: ";
      my_heap.print();
    }
  }
  return 0;
}
/*

I/O:
Enter the capacity of your heap 6
Input 1 if you want to use max heap and 2 if min heap: 2
Enter the values to be added in heap: 10 15 3 6 1 23
1 3 10 15 6 23
Enter 1 to delete from the heap and 2 to exit: 1
New heap: 3 6 10 15 23

Insertion time Compexity: O(logn) -> Since the height of a binary tree logn we will traverse max logn nodes.
Deletion time Complexity: O(logn) -> Same as insertion

Space Complexity for both: O(1)
*/
