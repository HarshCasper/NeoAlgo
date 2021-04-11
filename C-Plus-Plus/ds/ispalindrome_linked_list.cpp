/* Approach
A simple solution is to use a stack of list nodes. 
This mainly involves three steps.
Traverse the given list from head to tail and push every visited node to stack.
Traverse the list again. For every visited node, pop a node from stack and compare data of popped node with currently visited node.
If all nodes matched, then return true, else false.*/

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

// To check whether linked list is palindrome or not
bool isPalindrome(Node* head) {
        stack<int> st;
        Node* temp = head;
        while(temp!=NULL) {
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(!st.empty()) {
            
            if(st.top() != temp->data )
                return false;
            st.pop();
            temp = temp->next;
        }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        Node* head = buildList(n);
        if(isPalindrome(head)) {
            cout<< "True\n ";
        }
        else {
            cout<< "False\n ";
        }
    }
return 0;
}


/*Input 
a)
1    
5    
10 20 30 20 10  
Output
True

b)
1    
3    
10 15 20  
Output 
False

Time Complexity: O(n)

*/