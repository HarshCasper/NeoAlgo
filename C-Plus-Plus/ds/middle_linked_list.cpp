/* Approach
Traverse linked list using two pointers. Move one pointer by one and the other pointers by
two. When the fast pointer reaches the end slow pointer
will reach the middle of the linked list.
*/

#include<bits/stdc++.h>
using namespace std;

//Creation of Node class for Linked List
class Node{
public:
	int data;
	Node*next;
	Node(int d){
		data = d;
		next = NULL;
	}
};

// Inserted At the end of linked list function 
Node* buildList(int size){
    int val;
    cin>> val;
    Node* head = new Node(val);
    Node* tail = head;
    for(int i=0; i<size-1; i++){
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}
// Displaying the list function
void printList(Node* n){
    while(n) {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}
// To find the length of linked list
int length(Node* head) {
        int c =0;
        Node* t = head;
        while(t!=NULL){
            c++; 
            t = t->next;
        }
        return c;
}
// To find the middle node of linked list
Node* middleNode(Node* head) {
 	if(head==NULL || head->next==NULL){
	    return head;
	    }
    Node* fast = head->next;
    Node* slow = head;
	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
        if(length(head)%2 == 0)
	        return slow->next;
        else 
            return slow;
    }

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        Node* head = buildList(n);
        Node* res = middleNode(head);
        cout<<(res->data);
    }
return 0;
}

/*Input 
a)
1    
5    
10 20 30 40 50  
Output 
30

b)
1    
6    
5 10 15 20 25 30  
Output 
40

Time Complexity: O(n) 
Space Complexity: O(n)

*/