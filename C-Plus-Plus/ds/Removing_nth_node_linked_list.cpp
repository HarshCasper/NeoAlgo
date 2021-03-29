/*Given a linked list. The task is to remove the Nth node from the end of the linked list. (issue #4495)*/

#include <bits/stdc++.h>
using namespace std;
  
struct Node {
    int data;
    struct Node* next;
};
  
// Function to insert node in a linked list
struct Node* create(struct Node* head, int x)
{
    struct Node *temp, *ptr = head;
    temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}
  
// Function to remove nth node from last
Node* removeNthFromEnd(Node* head, int B)
{
    // To store length of the linked list
    int len = 0;
    Node* tmp = head;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next; 
    }
      
    // B > length, then we can't remove node
    if (B > len) 
    {
        cout << "Length of the linked list is " << len;
        cout  << " we can't remove "<< B << "th node from the";
        cout << " linked list\n";
        return head; 
    }
      
    // We need to remove head node
    else if (B == len) {
          
        // Return head->next
        return head->next; 
          
    }
    else 
    {
        // Remove len - B th node from starting
        int diff = len - B;          
        Node* prev= NULL;       
        Node* curr = head;         
        for(int i = 0;i < diff;i++){
            prev = curr;            
            curr = curr->next;      
        }
        prev->next = curr->next;
        return head;
    }
      
}
  
// This function prints contents of linked 
// list starting from the given node 
void dispaly(struct Node* head)
{
  
    struct Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
  
// Driver code
int main()
{
    struct Node* head = NULL;
      
      
    head = create(head, 1);
    head = create(head, 2);
    head = create(head, 3);
    head = create(head, 4);
    head = create(head, 5);
      
    int n = 2;
      
    cout << "Linked list before modification: \n";
    dispaly(head);
  
    head = removeNthFromEnd(head, 2);
    cout << "Linked list after modification: \n";
    dispaly(head);
  
    return 0;
}