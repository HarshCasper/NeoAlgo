/*
in this problem we will have to merge two sorted linked list and will have to make a single list.
the list will be made by joining together the nodes of first two lists
*/
#include <iostream>
using namespace std;

//structure
class node{
    public:
        int data;
        node* next;

    //constructor
    node(int data){
        this->data = data;
        this->next = NULL;
    }    
};

// this function is for inserting nodes in each list
void insertAtTail(node* &head,int data)
{
    node* n = new node(data);
	if (head==NULL){
		head = n;
		return;
	}

	node* temp = head;
	while(temp->next != NULL) {
	    temp = temp->next;
	}
	temp->next = n;
}

// this function is the main function for merging two sorted linked list
node* merge(node* a, node* b)
{
    if(a == NULL){
        return b;
    }
    else if(b == NULL){
        return a;
    }
    node* c;
    //Compare a and b for smaller element
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }  
    else{
        c = b;
        c->next = merge(a, b->next);        
    }  
    return c;
}

// Print function
void print(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// driver code
int main() {
    
        node* head1 = NULL;
        node* head2 = NULL;
        long long int n1,n2;
        // size of first list
        cin>>n1;
        // input nodes of first list
        while(n1--){
            int no;
            cin>>no;
            insertAtTail(head1,no);
        }
        // size of second list
        cin>>n2;
        // input nodes of second list
        while(n2--){
            int no;
            cin>>no;
            insertAtTail(head2,no);
        }  

        // head of new list that will be created
        node* head3 = merge(head1,head2);

        //printing new list
        print(head3);      
    
}
/* 
input - 
3
1 2 4
3
1 2 3
output - 
1 1 2 2 3 4 

Time Complexity - O(n)
Space Complexity - O(1)
*/
