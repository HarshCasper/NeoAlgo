#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

/* 
The helper class for the basic utility 
functions used in Linked List algorithms

1 - length - to return length of the Linked List
2 - print_ll - print the linked list to the output console
3 - take_input - take input from the user, terminated by -1
4 - Copy function is used to make a clone of head pointer.
*/
//Node* copy=NULL;

class helper
{
public:
    int length(Node* head)
    {
        Node* temp = head;
        int count = 0;
        while(temp != NULL)
        {
            temp = temp -> next;
            count++;
        }
        return count;
    }
    void print_ll(Node* head)
    {
        Node *temp=head;
        while(temp != NULL)
        {
            cout << temp -> data <<"--> ";
            temp= temp -> next;
        }
        cout<<"NULL"<<endl;
    }
    Node* take_input()
    {
        cout<<"Enter data to enter into the linked list and add -1 at the end of link list : ";
        int data;
        cin >> data;
        Node* head = NULL;
        Node* tail = NULL;
        if(data==-1)
            cout<<"Link List is Empty please try again.";
        while(data != -1)
        {
            Node* n = new Node(data);
            if(head==NULL)
            {
                head = n;
                tail = n;
             
            }
            else
            {
                tail -> next = n;
                tail = tail -> next;
            }
            cin >> data;
        }
        return head;
    }
    Node *copy(Node *ref)
    {
        if(ref==NULL) return ref;
        Node *temp=(Node *)malloc(sizeof(Node));
        temp->data=ref->data;
        temp->next=copy(ref->next);
        return temp;
    }
    

};

/// The main algorithmic solution class
class solution
{
public:
    
     /// Recursive approach
     Node* reverse_linked_recursive(Node* head)
     {
         /// if head or it's next pointer are null
         if(head == NULL || head -> next == NULL)
         {
             return head;
         }
         
         /// getting small output using recursion
         Node* small_head = reverse_linked_recursive(head -> next);
         head -> next = NULL;
         
         /// Traversing to the end node
         Node* temp = small_head;
         while(temp -> next != NULL)
         {
            temp = temp -> next;
         }
         
         /// Putting the head pointer at the next of end node
         temp -> next = head;
         head = small_head;
         return head;
     }

     /// The iterative approach
     Node* reverse_linked_iterative(Node* head)
     {
         /// if head or it's next pointer are null
         if(head == NULL || head -> next == NULL)
         {
             return head;
         }
         
         /*
          getting three pointers,
          
          prev = to store the previous pointer
          temp = auxiliary storage (Node pointer)
          curr = current pointer
         
         */
         
         Node* prev = NULL;
         Node *temp;
         Node  *curr = head;
         while(curr)
         {
             temp = curr -> next;
             curr -> next = prev;
             prev = curr;
             curr = temp;
         }
         head=prev;
         return head;
     }
     
};



int main()
{
    helper help_object;
    solution sol;
    Node* head = help_object.take_input();
    Node *copy=help_object.copy(head);
    Node* head2 = sol.reverse_linked_recursive(head);
    Node* head3 = sol.reverse_linked_iterative(copy);
    help_object.print_ll(head2);
    help_object.print_ll(head3);
    return 0;
}

