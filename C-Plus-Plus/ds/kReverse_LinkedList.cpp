/* We reverse the list taking k elements at a time i.e. we reverse the list in groups of k elements.
If size of linkedlist n = 9 and k=3
I/P  9 4 1 7 8 3 2 6 5
O/P  1 4 9 3 8 7 5 6 2
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

node* kReverse(node* head,int k){
    node* current = head;
    node* previous = NULL;
    node* n = NULL;
    int count = 0;
    while(count<k and current!=NULL){
        n = current->next;
        current->next = previous;
        previous = current;
        current = n;
        count++;
    }
    if(n != NULL){
        head->next = kReverse(n,k);
    }
    return previous;
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
	int n,k;
	cout<<"Enter the size of LinkedList: ";
	cin>>n;
	cout<<"Enter the no. of elements to be taken at a time: ";
	cin>>k;
	cout<<"Enter the elements of the LinkedList: ";

	//To take input from user
	node* head  = takeInput(n);

	//To reverse the elements in groups of k
	node* newHead = kReverse(head,k);

	cout<<"The final list after kReverse is:     ";
	print(newHead);
	return 0;
}

/* Sample I/O
Enter the size of LinkedList: 9
Enter the no. of elements to be taken at a time: 3
Enter the elements of the LinkedList: 9 4 1 7 8 3 2 6 5
The final list after kReverse is:     1 4 9 3 8 7 5 6 2

Time Complexity:   O(n)
Space Complexity : O(1)
*/