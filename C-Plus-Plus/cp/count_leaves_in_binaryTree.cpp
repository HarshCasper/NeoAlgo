/*
Description : Given a Binary Tree and we have to count leaves in it.
*/

#include <bits/stdc++.h>
using namespace std;

// adding base variables
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *new_node(int val)
{
    //initializing NULL to left and right node data
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

//for making a tree like structure
Node *tree_struct(string str)
{
    if (str.length() == 0)
    {
        return NULL;
    }
    //for storing the input
    vector<string> ip;
    // for adding space
    istringstream iss(str);
    for (string str; iss >> str;)
    {
        ip.push_back(str);
    }
    //making the root of tree
    Node *root = new_node(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    //starting from second data
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        //if left child is not null
        if (currVal != "N")
        {
            //pushing it to queue
            currNode->left = new_node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        //for right child
        if (i >= ip.size())
        {
            break;
        }
        currVal = ip[i];

        //checking if it is null or not
        if (currVal != "N")
        {
            currNode->right = new_node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

//function for counting the leaves
//root reference given
int sum_leaves(struct Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    //sum of leaves
    else
    {
        return sum_leaves(root->left) + sum_leaves(root->right);
    }
}

int main()
{
    // taking input as a string
    string input;
    cout << "Enter the data : " << endl;
    //taking input
    getline(cin, input);
    Node *root = tree_struct(input);

    cout << "Number of leaves in the tree : " << endl;
    cout << sum_leaves(root) << endl;

    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Cases :
 Test Case 1: 
    Input :
    Enter the data : 
    10 20 30

    Output :
    Number of leaves in the tree : 
    2
Test Case 2 :
    Input :
    Enter the data : 
    1 10 39 5

    Output :
    Number of leaves in the tree : 
    2
*/

