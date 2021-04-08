/* We append the last K elements of a linked list to the front. In this we take k number of elements from
the end of the linkedlist and append them as it is without changing sequence to the front of the linkedlist.
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

node* kAppend(node* head,int k,int n1){
    node* temp = head;
    int count = 1;
    node* n = NULL;
    while(temp->next!=NULL){
        if(count == n1-k){
            n  = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = head;
    head = n->next;
    n->next = NULL;
    return head;
}

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

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    int n;
	cout<<"Enter the size of LinkedList: ";
	cin>>n;

	cout<<"Enter the elements of the LinkedList: ";
	node* head = takeInput(n);

    int k;
	cout<<"Enter the no. of elements you want to append to the front: ";
	cin>>k;

	if(k == n){
	    print(head);
	    return 0;
	}
	if(k>n){
	    k = k%n;
	}
	node * newHead = kAppend(head,k,n);
	cout<<"The resultant LinkedList afer appending "<<k<<"elements to the front is: ";
	print(newHead);

	return 0;
}

/* Sample I/O
Enter the size of LinkedList: 7
Enter the elements of the LinkedList: 1 2 2 1 8 5 6
Enter the no. of elements you want to append to the front: 3
The resultant LinkedList afer appending 3elements to the front is: 8 5 6 1 2 2 1*

Time Complexity:   O(n)
Space Complexity : O(1)
*/
cout<<endl;
