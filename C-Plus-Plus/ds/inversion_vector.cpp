/****************************************************************************
 Author: @Suvraneel Bhuin

 Create a singly linked list X of integers. A pair (xi,xj) is called an inversion of X if for i < j , xi > xj. The inversion vector of X is the sequence of integers d1, d2,.. dn such that dj is the number of elements greater than xj and to its left in the sequence, so 0 <= dj < j. Compute the inversion vector for a given permutation.
 Ex: Given link list X : 4-> 3-> 5-> 2-> 1->
 Inversion of X: 0, 1, 0, 3, 4
 ***************************************************************************/

#include <bits/stdc++.h>
using namespace std;

//node structure
typedef struct node
{
    int value;
    struct node *next;
}node;

//global nodes
node *newnode, *ptr, *inv;
node *first = NULL, *last = NULL;

//creation of new node
node* create_node(int val)
{
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        cout << endl << "Creation unsuccessful";
        return 0;
    }
    else
    {
        newnode->value = val;
        newnode->next = NULL;
        return newnode;
    }
}

//function to insert node at end
void insert_node()
{
    int val;
    cout << "Enter value of the Node:\t";
    cin >> val;
    newnode = create_node(val);
    if (first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = NULL;
    }
 cout << val << " inserted as node";
}

//Function to calculate inversion vector
void inversion()
{
    //Empty condition
    if (first == NULL)
    {
        cout << endl << "No nodes in the list";
    }
    else
    {   
        //for every x
        for (ptr = first; ptr != NULL; ptr = ptr->next)
        {
            //set new count to zero
            int inversion_count = 0;
            //traverse from beginning to end to find how many elements satisfy condition
            for (inv = first; inv != ptr->next ; inv = inv-> next)
            {   
                //inversion condition
                if (inv->value > ptr->value)
                    inversion_count++;
            }
            cout << "   " << inversion_count;
        }
    }
}

//function to display linked list
void display()
{
    if (first == NULL)
        cout << endl << "No nodes in the list";
    else
        for (ptr = first;ptr != NULL;ptr = ptr->next)
            cout << ptr->value << " -> ";
}

//main driver code
 int main()
 {
    int choice;
    cout << endl << "---------------------------------";
    cout << endl << "1-Insert node";
    cout << endl << "2-Display current list";
    cout << endl << "3-Compute Inversion vector";
    cout << endl << "4-Exit";
    cout << endl << "---------------------------------";
    while (1)
    {
        cout << endl << endl << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert_node();
            break;

        case 2:
            cout << endl << "Current List :\t";
            display();
            break;

        case 3:
            cout << endl << "Inversion vector :";
            inversion();
            break;

        case 4:
            cout << "Program was terminated";
            exit(0);

        default:
            cout << endl << "Invalid Choice";
            break;
        }
    }
    return 0;
 }
/*
Time Complexity of Inversion Vector = O(n^2)
Space Complexity = O(n)

Sample Run:
---------------------------------
1-Insert node
2-Display current list
3-Compute Inversion vector       
4-Exit
---------------------------------

Enter your choice : 1
Enter value of the Node:        4
4 inserted as node

Enter your choice : 1
Enter value of the Node:        3
3 inserted as node

Enter your choice : 1
Enter value of the Node:        5
5 inserted as node

Enter your choice : 1
Enter value of the Node:        2
2 inserted as node

Enter your choice : 1
Enter value of the Node:        1
1 inserted as node

Enter your choice : 2

Current List :  4 -> 3 -> 5 -> 2 -> 1 ->

Enter your choice : 3

Inversion vector :   0   1   0   3   4

Enter your choice : 4
Program was terminated
*/
