// circular linkedlist is a linkedlist in which the first element points to the last element and the
// last element points to the first element.

#include <bits/stdc++.h> 
  
using namespace std; 
  

class Node { 
    public:
    int data; 
    Node* next; 
}; 
  

Node* newNode(int data) 
{ 
    //allocation of memory
    Node* newcopy = new Node; 
    newcopy->data = data; 
    newcopy->next = NULL; 
    return newcopy; 
} 
  
//  to reverse the circular linked list 
void reverse(Node** k) 
{ 
    
    if (*k == NULL) 
        return; 
    Node* prev = NULL; 
    Node* curr = *k; 
    Node* next; 
   do
     { 
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    } while (curr != (*k)); 
  
    
    (*k)->next = prev; 
    *k = prev; 
} 
  
// printing circular linked list 
void dispaly(Node* head) 
{ 
    if(head==NULL)
    cout<<"nothing to display";
    else
    {
       Node * temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<temp->data;
    }
}   
  

int main() 
{ 
    
    Node* head = newNode(5); 
    head->next = newNode(6); 
    head->next->next = newNode(7); 
    head->next->next->next = newNode(8); 
    head->next->next->next->next = head; 
  
    cout << "circular linked list: "; 
    dispaly(head); 
    cout<<endl;
    reverse(&head); 
    cout << "Reversed circular linked list: "; 
    dispaly(head); 
  
    return 0; 
} 

/* OUTPUT
circular linked list: 1234

Reversed circular linked list: 4321

*/
