#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    //constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

//Function to insert in circular LinkedList
void insert(node *&head, int data) //pass by referance
{
    node *n = new node(data);
    n->next = head; //creating a new node
    node *temp = head;
    if (temp != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    //self loop for single node
    else
    {
        n->next = n;
    }
    head = n;
}

//Creating a function the get the node to be deleted
node *getnode(node *head, int data) //pass ny value
{
    node *temp = head;
    while (temp->next != head)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    if (temp->data == data)
    {
        return temp;
    }
    return NULL;
}

//Creating the delete function
void del(node *head, int data)
{
    node *del = getnode(head, data);

    if (del == NULL)
    {
        return;
    }

    if (head == del)
    {
        head = head->next;
    }

    node *temp = head;

    while (temp->next != del)
    {
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
}

//function to print circular linkedlist
void print(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << endl; //for last node
}

int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    print(head);

    del(head, 4);
    del(head, 5);
    print(head);

    return 0;
}

/*
OUTPUT
6 -> 5 -> 4 -> 3 -> 2 -> 1
6 -> 3 -> 2 -> 1
*/
