/*
Description : 
            Given a doubly linked list, rotate the linked list counter-clockwise by N nodes. 
            Here N is a given positive integer and is smaller than the count of nodes in linked list.
*/

#include <bits/stdc++.h>
using namespace std;

// base data
struct Node
{
    char data;
    struct Node *prev;
    struct Node *next;
};
//function to rotate the dll from n point
void rotate_from_n(struct Node **head_ref, int N)
{
    if (N == 0)
        return;

    struct Node *current = *head_ref;

    int count = 1;
    while (count < N && current != NULL)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return;

    struct Node *NthNode = current;

    while (current->next != NULL)
        current = current->next;

    //changing the link
    current->next = *head_ref;
    (*head_ref)->prev = current;
    *head_ref = NthNode->next;
    (*head_ref)->prev = NULL;

    NthNode->next = NULL;
}
//adding new node to the dll
void push_data(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}
// printing the node in a pattern
void print_data(struct Node *node)
{
    while (node->next != NULL)
    {
        //adding the pattern
        cout << node->data << " "
             << "<=>"
             << " ";
        node = node->next;
    }
    cout << node->data;
}

int main(void)
{
    //size of the list
    int x;
    cout << "Enter the size : " << endl;
    cin >> x;

    struct Node *head = NULL;
    //N= the point of rotation
    int N;
    cout << "Enter the rotation point : " << endl;
    cin >> N;
    cout << "Enter the data in reverse order : " << endl;
    for (int i = 0; i < x; i++)
    {
        char z;
        cin >> z;
        push_data(&head, z);
        cout << endl;
    }

    cout << endl;
    cout << "Given linked list after arranging from front : \n";
    //printing the data in the right manner
    print_data(head);
    //rotating the dll
    rotate_from_n(&head, N);

    cout << "\nRotated Linked list from point " << N << " :" << endl;
    //printing the data
    print_data(head);

    return 0;
}
/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Case :
 Input :
 Enter the size : 
 5
 Enter the rotation point : 
 2
 Enter the data in reverse order : 
 e d c b a

 Output :
 Given linked list after arranging from front :
 a <=> b <=> c <=> d <=> e
 Rotated Linked list from point 2 :
 c <=> d <=> e <=> a <=> b
*/

