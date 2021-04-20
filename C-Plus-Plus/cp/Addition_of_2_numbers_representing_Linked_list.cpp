/*
Given two Linked list, both of n size. The linked list is representing
positive integer. As they are being pushed to linked list they are 
given in reverse order. 
Your task is two add the numbers represented as Linked List and return 
the sum answer in the form of Linked List.

For example: Linked List1: ->1->2->3 
             Linked List2: ->3->7->1
             Answer:       ->4->9->4    
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
void push(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}
void printLinkedlist(Node *temp)
{
    while (temp != NULL)
    {
        cout << "->" << temp->data;
        temp = temp->next;
    }
}
Node *addtwonumbers(Node *l1, Node *l2)
{
    Node *temp = new Node();
    Node *head = temp;
    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        push(&temp->next, sum % 10);
        temp = temp->next;
    }
    if (carry != 0)
    {
        push(&temp->next, carry);
    }
    return head->next;
}
int main()
{
    int n;
    cout << "Enter length of Linked List:";
    cin >> n;
    cout << "Enter Linked List 1:";
    Node *head1 = NULL;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        push(&head1, a);
    }
    cout << "Enter Linked list 2:";
    Node *head2 = NULL;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        push(&head2, a);
    }
    Node *head = NULL;
    head = addtwonumbers(head1, head2);
    cout << "\nLinked List 1:\n";
    printLinkedlist(head1);
    cout << "\nLinked List 2:\n";
    printLinkedlist(head2);
    cout << "\nNew Linked List:\n";
    printLinkedlist(head);
}

/*

Sample Input:
Enter length of Linked List:3
Enter Linked List 1:1 2 3
Enter Linked list 2:2 3 4

Sample Output:
Linked List 1:
->3->2->1
Linked List 2:
->4->3->2
New Linked List:
->7->5->3

Time-Complexity: O(n)
Space-Complexity: O(1)

*/
