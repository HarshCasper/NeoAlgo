/* Cicular Queue Using Linked List 
 * Author : Ravi Anand 
 */

#include<iostream>
using namespace std;

template<class T>
class Node{                //Node class for LinkedList
public:
	T data; 
	Node<T> *next;
	Node(T val){
		data = val;
		next = nullptr;
	}
};
	
template<class T>
class CQueue{             // CQueue class for circular queue
public:

	Node<T> *front, *rear;
};

template<class T>
void Enqueue(CQueue<T> *q){
	cout<<"Enter the item : "<<endl;
	T data; cin >> data;
	
	Node<T> *node = new Node<T>(data);
	
	if(q->front == nullptr)q->front = node;
	else q->rear->next = node;
	    
	q->rear = node;
	q->rear->next = q->front;
	
	cout<<"************Enqueue Successful**************"<<endl;
}

template<typename T>
void Dequeue(CQueue<T> *q){
	
	if(q->front == nullptr){
		cout<<"Circular Queue is Empty "<<endl;
		return;
	}
	
	cout<<"Deleted : "<<q->front->data<<endl;
	
	Node<T> *temp = q->front;
	while(temp->next != q->front){
		temp = temp->next;
		}
		
	temp->next = q->front->next;
	q->front = q->front->next;
	
	cout<<"*****************Dequeue Successful******************"<<endl;
	}

template<typename T>
void display(CQueue<T> *q){
	
	Node<T> *head = q->front;
	while(head->next != q->front){
		cout<<head->data<<"->";
		head = head->next;
	 }
	 cout<<head->data<<endl;
	}
	
int main(){
    CQueue<char> *q = new CQueue<char>();
    int ch;
    do{
		cout<<"\n1. Enqueue \n2. Dequeue \n3. Display\n4. Clear Screen \n5. Exit\n";
		cin >> ch;
		switch(ch){
			case 1: Enqueue(q); break;
			case 2: Dequeue(q); break;
			case 3: display(q); break;
			case 4: system("clear");
			case 5: exit(0);
			}
		}while(5);
	return 0;
	}

