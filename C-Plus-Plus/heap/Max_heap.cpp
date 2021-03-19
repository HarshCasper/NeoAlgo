/*This is a (binary) Maximum heap data structure which is an array object that we can view as a
nearly complete binary tree. Property - the value of a node is at most the value of its parent. Thus, the largest
element in a max-heap is stored at the root, and the subtree rooted at a node contains values no larger than 
that contained at the node itself.
Here the Max-heap is implemented using array data structure. */

#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

// template for using the code with any arbitrary type
template<class H>
class HeapClass{
	H *array;
	int heap_size;
	public:
		// functions which support the implementation of Priority Queues. 
		HeapClass();
		int parent_node(int);
		int left_node(int);
		int right_node(int);
		void max_heapify(H arr[], int index);
		H heap_max();
		H heap_extract_max();
		void heap_increase_key(H arr[], int index, H key);
		void heap_insert( H key);
		int count();
		bool empty();
		void display();
		
};

// constructor
template<class H>
HeapClass<H>::HeapClass(){
	array=new H[50];
	heap_size=0;
}

// function which returns the total number of elements present in the heap
template<class H>
int HeapClass<H>::count(){
	return heap_size;
}

//function which checks whether the heap is empty or not.
template<class H>
bool HeapClass<H>::empty(){
	return heap_size==0;
}


// function which returns the index of parent of the heap
template<class H>
int HeapClass<H>::parent_node(int index){
	if(index%2==0)
	return (index/2)-1;
	else
	return index/2;
}

// function which returns index of left child of a node in the heap
template<class H>
int HeapClass<H>::left_node(int index){
	return 2*index+1;
}

// function which returns index of right child of a node in the heap.
template<class H>
int HeapClass<H>::right_node(int index){
	return 2*(index+1);
}

/*It is a recursive function to maintain Max-heap property. When it is called, it assumes that the binary
trees rooted at LEFT and Right of a node are maxheaps, but it could be the case that node might be smaller than
its children, thus violating the max-heap property. Hence it will update the parent node accordingly.
*/
template<class H>
void HeapClass<H>::max_heapify(H arr[], int index){
 int largest_element=0;
 int left_index=left_node(index);
 int right_index=right_node(index);
 if(left_index<=heap_size && arr[left_index]>arr[index])
    largest_element = left_index;
 else 
    largest_element=index;
 if(right_index<=heap_size && arr[right_index]>arr[largest_element])
    largest_element=right_index;
   
 if(largest_element!=index){
	H temp=arr[index];
	arr[index]=arr[largest_element];
	arr[largest_element]=temp;
	max_heapify(arr,largest_element);
}

}

// function which returns the maximum element of the heap
template<class H>
H HeapClass<H>::heap_max(){
	return array[0];
}

//function which removes and returns the element of heap with the largest key value.
template<class H>
H HeapClass<H>::heap_extract_max(){
 H maximum_element;
 maximum_element=array[0];
 array[0]=array[heap_size-1];
 heap_size--;
 max_heapify(array,0);
 return maximum_element;
}

/*function which increases the value of some element x’s key value to the new value, which is assumed to be at
least as large as x’s current key value. */
template<class H>
void HeapClass<H>::heap_increase_key(H arr[], int index, H key){
	if (key<arr[index])
	    cout<<"new key is smaller than current key";
	arr[index]=key;
	while(index>0 && arr[parent_node(index)]<arr[index]){
		H temp=arr[index];
		arr[index]=arr[parent_node(index)];
		arr[parent_node(index)]=temp;
		index=parent_node(index);
	}
}

//function which inserts the element x into the heap using heap_increase_key function 
template<class H>
void HeapClass<H>::heap_insert(H key){
	heap_size++;
	array[heap_size-1]=-1;
	heap_increase_key(array,heap_size-1,key);
}

// function which displays the constructed heap
template<class H>
void HeapClass<H>::display(){
	for(int i=0; i<heap_size; i++){
	
		cout<<array[i]<<",";
	}
}
