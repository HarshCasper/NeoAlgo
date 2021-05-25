/*

Given n elements Linked List
This code will implement insertion sort on Linked List
Example
n=5
Linkedlist : 1 43 3 7 97
Answer: 1 3 7 43 97
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
void push(Node **root, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = (*root);
    *root = temp;
}
void print(Node *root)
{
    if (root == NULL)
        return;
    while (root)
    {
        cout << root->data << "->";
        root = root->next;
    }
}
void sortlist(Node **answer, Node *current)
{
    if (*answer == NULL || current->data <= (*answer)->data)
    {
        current->next = *answer;
        *answer = current;
    }
    else
    {
        Node *q = *answer;
        while (q->next != NULL && q->next->data < current->data)
        {
            q = q->next;
        }
        current->next = q->next;
        q->next = current;
    }
}
void insertionsort(Node **root)
{
    Node *answer = NULL;
    Node *current = *root;
    while (current)
    {
        Node *next = current->next;
        sortlist(&answer, current);
        current = next;
    }
    *root = answer;
}
int main()
{
    int n;
    cout << "Enter Number of Elements:";
    cin >> n;
    Node *root = NULL;
    cout << "Enter Elements:";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        push(&root, a);
    }
    cout << "\nOriginal Unsorted Linked List:";
    print(root);
    cout << "\nSorted Linked List:";
    insertionsort(&root);
    print(root);
}
/*

Sample Input/Output:
Input:
Enter Number of Elements:5
Enter Elements:10 32 44 13 7

Output:
Original Unsorted Linked List:7->13->44->32->10->
Sorted Linked List:7->10->13->32->44->

Time-Complexity: O(n^2)
Space-complexity: O(n)

*/
