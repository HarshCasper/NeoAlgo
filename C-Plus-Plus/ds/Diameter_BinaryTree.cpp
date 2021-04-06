/*C++ program to find Diameter of a Binary Tree.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree.*/

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> v;

    istringstream iss(str);
    for (string str; iss >> str;)
        v.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(v[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < v.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = v[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= v.size())
            break;
        currVal = v[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int height(Node *n, int *dia)
{
    if (!n)
        return 0;

    // Height of left subtree
    int l = height(n->left, dia);
    // Height of right subtree
    int r = height(n->right, dia);

    // l+r+1 is a possible max dia
    if (l + r + 1 > *dia)
        *dia = l + r + 1;

    // Returning height of subtree
    return 1 + max(l, r);
}

/* Function to get diameter of a binary tree */
int diameter(Node *root)
{
    int dia = 0;
    height(root, &dia);
    return dia;
}

int main()
{
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    // Diameter
    cout << diameter(root) << endl;

    return 0;
}

/* Test Cases:

Input: 1 2 3 N N 4 6 N 5 N N 7 N
Output: 6

Input: 1 2 3
Output: 3

Time Complexity: O(N) where N is the total number of nodes in the tree.
Space Complexity: O(h) where h is the height of the tree.

*/