/*Problem Statement: 
You are given a tree with cycle present in it. Your task is to remove the cycle and make it into 
a Linked List */

#include <bits/stdc++.h>
using namespace std;

int cycle = 0;
class Node
{
    public:
        int data;
    Node * next;

    Node(int num)
    {
        data = num;
        next = NULL;
    }
};

void addToTail(Node* &head, Node *nodeToAdd)
{
    int flag = 0;
    Node * save;
    if (head == NULL)
    {
        head = nodeToAdd;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == nodeToAdd->data)
        {
            flag = 1;
            save = temp;
        }

        temp = temp->next;
    }

    if (flag == 0)
    {
        temp->next = nodeToAdd;
    }
    else
    {
        temp->next = save;
        cycle = 1;
    }
}

void print(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << "-->";
        tmp = tmp->next;
    }

    cout << endl;
}

Node* createTree()
{
    int num;
    Node *head = NULL;

    while (cin >> num && num != -1)
    {
        if (cycle == 1)
        {
            break;
        }

        Node *newNode = new Node(num);
        addToTail(head, newNode);
    }

    return head;
}

Node* detectcycle(Node *head)
{
    Node *temp = head;
    Node *temp1 = head;
    while (temp != NULL)
    {
        temp = temp->next;
        temp1 = temp1->next->next;
        /*If temp1 pointer meets the temp pointer before reaching NULL, 
         then cycle is present */
        if (temp == temp1)
        {
            break;
        }
    }

    return temp1;
}

void breakcycle(Node *head, Node *node1)
{
    if (node1 == head)
    {
        Node *kk = head->next;
        /*While the next node of the current node doesn't reach the head node,
        because that will be the cycle point */
        while (kk->next != head)
        {
            kk = kk->next;
        }
        //Making the next node of that node that again lands itself to the head as NULL
        kk->next = NULL;
        return;

    }

    Node *prev = node1;
    Node *temp = head;
    /*While the next node of the current node doesn't reach the node already visited,
    because that will be the cycle point */
    while (temp != node1)
    {
        temp = temp->next;
        prev = node1;
        node1 = node1->next;
    }
    //Making the next node of the node that again lands itself to the visited node as NULL
    prev->next = NULL;
}

int main()
{
    cout << "Enter nodes of the tree: " << endl;
    Node *head = createTree();
    breakcycle(head, detectcycle(head));
    cout << "After breaking the cycle the linked list is: " << endl;
    print(head);
    return 0;
}
/*
Example:-

Input:-
Enter nodes of the tree: 
1 2 3 4 5 2 3 -1

Output:-
After breaking the cycle the linked list is: 
1-->2-->3-->4-->5-->

Time Complexity: O(n)
Space Complexity: O(n)
*/

