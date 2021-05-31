/*

Given N, Linked List and K,
Reverse the Node of Linked List in Groups of K and return
example:
N=5
Linked list: 1 2 3 4 5
K=2

Answer 2 1 4 3 5
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
Node *reverseK(Node *head, int k)
{
    int flag = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        flag++;
        if (flag == k)
            break;
    }
    if (flag < k)
        return head;
    int count = 0;
    Node *curr = head;
    Node *prev = NULL, *next = NULL;
    while (curr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reverseK(next, k);
    }
    return prev;
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
    int k;
    cout << "Enter K:";
    cin >> k;
    cout << "\nOriginal Linked List:\n";
    printLL(head);
    head = reverseK(head, k);
    cout << "\nNew Linked List:\n";
    printLL(head);
}
/*

Sample Input/Output:
Input:
Enter Numbers of Element N:5
Enter elements:1 2 3 4 5
Enter K:2

Output:
Original Linked List:
5->4->3->2->1->
New Linked List:
4->5->2->3->1->

Time-Complexity: O(n)
Space-Complexity: O(1)

*/
