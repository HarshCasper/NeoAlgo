/* We arrange elements in a Linked List such that all even numbers are placed after odd numbers.
I/P: 5
     1 2 2 2 1
O/P: 1 1 2 2 2
*/
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtTail(node* &head,int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* tail = head;
    while(tail->next!=NULL){
        tail  = tail->next;
    }
    node* n = new node(d);
    tail->next = n;
}

node* takeInput(int n){
    node* head = NULL;
    while(n!=0){
        int d;
        cin>>d;
        insertAtTail(head,d);
        n--;
    }
    return head;
}


node* evenAfterOdd(node* head){
    node* h1 = NULL;
    node* h2 = NULL;
    node* temp = head;
    while(temp!=NULL){
        if(temp->data%2 != 0){
            insertAtTail(h1,temp->data);
        }
        else{
            insertAtTail(h2,temp->data);
        }
        temp = temp->next;
    }
    node* n = h1;
    node* n1 = h1;
    while(n1->next != NULL){
        n1 = n1->next;
    }
    n1->next = h2;
    return n;
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    cout<<"Enter the size of LinkedList: ";
    int n;
	cin>>n;
	cout<<"Enter the elements of the LinkedList: ";
	node* head = takeInput(n);
	cout<<"The resulatant LinkedList is: ";
	node* newHead = evenAfterOdd(head);
	print(newHead);
	return 0;
}

/* Sample I/O
Enter the size of LinkedList: 5
Enter the elements of the LinkedList: 1 2 2 2 1
The resulatant LinkedList is: 1 1 2 2 2

Time Complexity:   O(n)
Space Complexity : O(1)

*/