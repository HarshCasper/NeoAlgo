/*Below is the code which is used to find whether a cycle is present in a linked list.
It uses 2 pointer slow and fast(which travels at speed twice that of slow).
If they meet at any position while traversing the linked list then a cycle is
present otherwise cycle is not present */
#include <bits/stdc++.h>
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

void insertAtHead(node* &head,int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = head;
    head = n;
    return;
}

void insertAtTail(node* &head,int d){
    if(head==NULL){
        insertAtHead(head,d);
        return;
    }
    node* tail = head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next = new node(d);
    return;
}

void makeCycle(node* &head,int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next != NULL){
         if(count == pos){
             startNode = temp;
         }
         temp = temp->next;
         count++;
    }
    temp->next = startNode;
}

bool detectCycle(node* head){
    node* slow = head;
    node* fast = head;
    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

int main()
{
    node* head = NULL;
    int n;
    cout<<"Enter the number of nodes:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
       int x;
       cin>>x;
       insertAtTail(head,x);
    }
    int pos;
    cout<<"Enter the position where you want to make a cycle:"<<endl;
    cin>>pos;

    //cycle is created at position pos
    makeCycle(head,pos);

    //detect a cycle
    if(detectCycle(head)){
       cout<<"Cycle is present"<<endl;
    }
    else{
       cout<<"Cycle is not present"<<endl;
    }
    return 0;
}

/*
SAMPLE INPUT
7
1 2 3 4 5 6 7
3
SAMPLE OUTPUT
Enter the number of nodes:
Enter the position where you want to make a cycle:
Cycle is present

Time Complexity  O(N)
Space Complexity O(1)
*/

