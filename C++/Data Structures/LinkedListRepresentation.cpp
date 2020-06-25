#include<bits/stdc++.h>
using namespace std;

// Structure of the Linked List
class Node{
	public:
		int data;
		Node *next;
};

// Push a New Node
void push(Node **head_ref, int new_data){
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

// Print the Linked List
void printList(Node *head){	
	if(head == NULL){
		cout<<"Nothing to print"<<endl;
		return;
	}
	while(head != NULL){
		cout<<" "<<head->data;
		head = head->next;
	}
}

int main(){
	Node *head = NULL;	
	push(&head, 6);	// Passing a reference of the head
	printList(head);
	return 0;
}
