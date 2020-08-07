#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

/// Creating a class for Linked List object

/*
      next (Node pointer)
        |
 -----------
 | 1  |    |
 -----------
   |
  data

*/

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this -> data = data;
        this -> next = nullptr;
    }
};


/* 
The helper class for the basic utility 
functions used in Linked List algorithms

1 - length - to return length of the Linked List
2 - print_ll - print the linked list to the output console
3 - take_input - take input from the user, terminated by -1

*/
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
        Node* temp = head;
        while(temp != nullptr)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }
    Node* take_input()
    {
        int data;
        cin >> data;
        Node* head = nullptr;
        Node* tail = nullptr;
        while(data != -1)
        {
            Node* n = new Node(data);
            if(head==nullptr)
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

};

/// The main algorithmic solution class
class solution
{
public:
    
     /// Recursive approach
     Node* reverse_linked_recursive(Node* head)
     {
         /// if head or it's next pointer are null
         if(head == nullptr || head -> next == nullptr)
         {
             return head;
         }
         
         /// getting small output using recursion
         Node* small_head = reverse_linked_recursive(head -> next);
         head -> next = nullptr;
         
         /// Traversing to the end node
         Node* temp = small_head;
         while(temp -> next != nullptr)
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
         if(head == nullptr || head -> next == nullptr)
         {
             return head;
         }
         
         /*
          getting three pointers,
          
          prev = to store the previous pointer
          temp = auxiliary storage (Node pointer)
          curr = current pointer
         
         */
         Node* prev = nullptr, *temp, *curr = head;
         while(curr)
         {
             temp = curr -> next;
             curr -> next = prev;
             prev = curr;
             curr = temp;
         }
         return prev;
     }
};


int main()
{
    helper help_object;
    solution sol;
    Node* head = help_object.take_input();
    Node* head2 = sol.reverse_linked_recursive(head);
    Node* head3 = sol.reverse_linked_iterative(head);
    help_object.print_ll(head2);
    help_object.print_ll(head3);
    return 0;
}
