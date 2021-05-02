/*

Given N, Linked List 
Your task is to print the middle element(Data) of Given Linked List 
Example:
N=5
1 2 3 4 5
Answer should be 3

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
    (new_node)->next = (*head);
    (*head) = new_node;
}
void printLL(Node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
int middleinLL(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int main()
{
    Node *head = NULL;
    int n;
    cout << "Enter Numbers of Element N:";
    cin >> n;
    cout << "Enter elements:";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        push(&head, a);
    }
    cout << "Linked List:";
    printLL(head);
    cout << "\nMiddle Element of the Linked List:" << middleinLL(head);
}

/*

Sample Input/Output:

Input:
Enter Numbers of Element N:7
Enter elements:4 1 6 2 4 9 1

Output:
Linked List:1->9->4->2->6->1->4->
Middle Element of the Linked List:2

Time-Complexity: O(n)
Space-Complexity: O(1)

*/
