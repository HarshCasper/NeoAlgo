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

//Creating a function to get the node to be deleted
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
    cout << "Insertion in circular linkedlist" << endl;
    int arr[100], arr2[100];
    int n, n2;
    cout << "enter the number of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter element number " << i << "-" << endl;
        cin >> arr[i];
        insert(head, arr[i]);
    }
    cout << "Elements inserted" << endl;
    print(head);

    cout << "enter the number of elements you want to delete" << endl;
    cin >> n2;
    for (int j = n2 - 1 + 1; j > 0; j--)
    {
        cout << "enter position of number " << endl;
        cin >> arr2[j];
        del(head, arr[j + 1]);
    }

    print(head);

    return 0;
}

/*
OUTPUT
Insertion in circular linkedlist
enter the number of elements
6
enter element number 0-
1
enter element number 1-
2
enter element number 2-
3
enter element number 3-
4
enter element number 4-
5
enter element number 5-
6
Elements inserted
6 -> 5 -> 4 -> 3 -> 2 -> 1
enter the number of elements you want to delete
2
enter position of number 
2
enter position of number 
3
6 -> 5 -> 2 -> 1
*/
