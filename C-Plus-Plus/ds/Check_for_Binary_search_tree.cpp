/*
Validating BST: This program check if the given tree is BST or not.
BST: A tree with following conditions:
1. At max 2 childern.
2. Value stored in left child < Value of Parent node < Value of right child. (Must be valid for every node)

Author: @Mohim-Singla
*/

#include <bits/stdc++.h>

using namespace std;

//initializing structure
struct node{
int data;
node* lchild;
node* rchild;
};
//Function to create tree
node* create_node (int data)
{
    node* temp = new node;
    temp -> data = data;
    temp -> lchild = temp -> rchild = NULL;
    return temp;
}

node* create (node* root, int data)
{
    if(root == NULL)
    {
        root = create_node (data);
        return root;
    }
    else
    {
        if (data < root->data)
        {
            root -> lchild = create (root -> lchild, data);
        }
        else
        {
            root -> rchild = create (root -> rchild, data);
        }
        return root;
    }
}
//BST Check Function
bool check (node* root, int minv, int maxv)
{
    if (root == NULL)
    {
        return true;
    }
    else if (root -> data > minv && root -> data < maxv && check (root -> lchild, minv, root -> data) && check (root -> rchild, root -> data, maxv))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Displaying output
void check_output (node* root, int minv, int maxv)
{
    bool ans = check (root, INT_MIN, INT_MAX);
    if (ans)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}

int main ()
{
    //creating a BST
    node* root = NULL;
    int counts;
    cout << "Enter number of nodes: " ;
    cin >> counts;
    for (int i = 0; i < counts; i++)
    {
        int datas;
        cin >> datas;
        root = create (root, datas);
    }

    check_output (root, INT_MIN, INT_MAX);

    //converting bst to binary tree
    root -> lchild -> data = 18;
    check_output (root, INT_MIN, INT_MAX);
    return 0;
}

/*

---------------------------
Test case:
Input:
10
1 2 34 4 5 56 7 18 9 23
A non-BST

Output:
True
False
---------------------------

Time complexity: O(nlogn)
Space complexity: O(n)

*/
