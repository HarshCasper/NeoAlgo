/* 
"Copyright [2021] <Anshika Dubey>"
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
        temp = temp->next;                    // finding the last node
    }
    temp->next = head;                         // connecting the head to the last node
    temp = head;
    for(int i = 1; i<=length-n-1; i++) {
        temp = temp->next;                    // finding the node that is supposed to be the new head
    }
    head = temp->next ;                       
    temp->next = NULL;
    return head;
    } 
}
int main()
{
	int t;                            // taking input for number of test cases
	cin >> t;
	while (t--) {
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}

/* 

Time Complexity-
O(n)
space Complexity- 
O(1)


Sample input 1-
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5
Sample output 1-
3 4 5 1 2
20 30 40 50 60 10

*/
