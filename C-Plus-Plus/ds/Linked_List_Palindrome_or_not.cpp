/*

Given N, Linked List
Your task is to check wheather Given Linked List is Palindrome or Not
Example:
N=4
Linked List : 1 2 2 1
Answer : Yes

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
void inorder(vector<int> &v, Node *head)
{
    Node *curr = head;
    if (curr == NULL)
        return;
    v.push_back(curr->data);
    inorder(v, curr->next);
}
bool isPalindrome(Node *head)
{
    vector<int> v;
    inorder(v, head);
    int i = 0, j = v.size() - 1;
    while (i <= j)
    {
        if (v[i++] != v[j--])
        {
            return false;
        }
    }
    return true;
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
    if (isPalindrome(head) == true)
    {
        cout << "\nYes Given Linked List is Palindrome";
    }
    else
    {
        cout << "\nNo Given Linked List is not Palindrome";
    }
}

/*

Sample Input/Output:

Input:
Enter Numbers of Element N:5
Enter elements:1 2 3 2 1

Output:
Linked List:1->2->3->2->1->
Yes Given Linked List is Palindrome

Time-Complexity: O(n)
Space-Complexity: O(n)

*/
