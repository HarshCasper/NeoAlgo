/*
Description : 
            Given a pointer/ reference to the node which is 
            to be deleted from the linked list of N number nodes.
            The task is to delete the node. Pointer/ reference to head node is not given.     
*/

#include <bitset/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
} * head;

// function used to search the data which is given by user
Node *search_node(Node *head, int search_for_data)
{
    Node *current = head;
    while (current != NULL)
    {
        // if data found then break
        if (current->data == search_for_data)
        {
            break;
        }
        current = current->next;
    }
    return current;
}

//function used for the inserting the data into the tree.
void insert_node()
{
    // n= number of nodes in tree
    int n, i, value;
    Node *temp;
    cout << "Enter the number of nodes : " << endl;
    scanf("%d", &n);
    cout << "Enter the data : " << endl;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (i == 0)
        {
            head = new Node(value);
            temp = head;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

// function used for the printing the data of the tree
void print_tree(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// another class
class Solution
{
public:
    // function used to delete the data given by user
    // head pointer is not given
    // reference given of the node to be deleted
    void to_delete_node(Node *del)
    {
        if (del->next == NULL)
        {
            return;
        }
        Node *temp_1 = del->next;
        del->data = temp_1->data;
        del->next = del->next->next;
        delete (temp_1);
    }
};

int main()
{
    // k = storing data to be deleted
    int k;
    insert_node();
    cout << "Enter data to delete : " << endl;
    scanf("%d", &k);
    Node *del = search_node(head, k);
    Solution obj;

    //deleting the given data by user
    if (del != NULL && del->next != NULL)
    {
        obj.to_delete_node(del);
    }
    cout << "Tree after deleting " << k << " : " << endl;
    print_tree(head);

    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Case :
    Input :
    Enter the number of nodes :
    4
    Enter the data :
    1 2 3 4
    Enter data to delete :
    3

    Output :
    Tree after deleting 3 :
    1 2 4
*/

