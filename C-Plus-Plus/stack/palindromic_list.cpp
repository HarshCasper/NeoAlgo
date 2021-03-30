/* Code to check if a linked list is palindromic or not using stacks
OBJECTIVE:
1. Push the data of each node into the stack(LIFO)
2. Pop each element of the stack and compare with the linked list element
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void push(Node **head, int new_data)
{
    Node *temp = new Node();
    temp->data = new_data;
    temp->next = *head;
    *head = temp;
}
int checkPalin(Node *head)
{
    stack<int> s;
    Node *temp = head;
    while (temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    Node *ref = new Node();
    ref = head;
    while (ref != NULL)
    {
        int i = s.top();
        s.pop();
        if (i != ref->data)
        {
            return -1;
        }
        ref = ref->next;
    }
    return 1;
}
int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;
    push(&head, 2);
    push(&head, 1);
    cout << checkPalin(head) << "\n";
}
/*
Time Complexity:O(n)
INPUT: 
When linked list is 1->2->1
OUTPUT:
1
*/
