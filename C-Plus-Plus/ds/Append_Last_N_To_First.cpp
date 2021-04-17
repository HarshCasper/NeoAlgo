/* 

You have been given a singly linked list of integers along with an integer 'N'.
Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.

*/

#include <bits/stdc++.h>
using namespace std;

// create a class node

class Node {
public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};


// taking input from the user for linked list

Node *takeinput() {
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1) {
		Node *newnode = new Node(data);
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		} else {
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}


//printing the linked list if head is given 

void print(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


//finding the length of the linked list

int length1(Node *head) {
	
    // Write your code here
	
    if(head == NULL)
        return 0;
    if(head->next == NULL)
        return 1;
    Node* temp = head;
    return 1 + length1(temp->next);
}


// function to append last n elements of linked list at front

Node *appendLastNToFirst(Node *head, int n) {
    Node * temp = head;
    int length = length1(temp);
    if(temp == NULL) {
        return temp;
      } else {
         while( temp->next != NULL) {    
         
        // finding the last node
		 
        temp = temp->next;                   
    }
	    
     // connecting the head to the last node
	    
    temp->next = head;                         
    temp = head;
	    
    // finding the node that is supposed to be the new head
	    
    for(int i = 1; i<=length-n-1; i++) {
        temp = temp->next;                   
    }
    head = temp->next ;                       
    temp->next = NULL;
    return head;
    } 
}
int main()
{
	cout << " Enter the elements of the linked list"<< endl;
	Node *head = takeinput();
	int n;
	cout << "Enter the number of last n nodes" << endl;
	cin >> n;
	head = appendLastNToFirst(head, n);
	
	cout << " the new linked list is" <<endl;
	print(head);
	return 0;
}

/* 

Time Complexity-
O(n)
space Complexity- 
O(1)


Sample input 1-
Enter the elements of the linked list
1 2 3 4 5 -1
Enter the number of last n nodes
3

Sample output 1-
the new linked list is
3 4 5 1 2


*/
