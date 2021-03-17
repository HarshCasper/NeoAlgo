/*
CHILDERN SUM PROPERTY
---------------------------------
Children Sum Property is a property in which the sum of values 
of the left child and right child should be equal to the value 
of their node if both children are present else if only one child 
is present then the value of the child should be equal to its node value.
*/
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}
/* Return 1 if all the nodes in the tree satisfy 
the given property else return 0 */
int isSumProperty(Node *root)
{
    if(root == NULL){
        return true;
    }
    if(!root->right && !root->left){
        return true;
    }
    int s = 0;
    if(root->left){
        s = s+root->left->data;
    }
    if(root->right){
        s += root->right->data;
    }
    if(s!=root->data){
        return false;
    }
return isSumProperty(root->left) && isSumProperty(root->right);
}
//Driver's Code
int main() {
    string str;
    getline(cin, str);
    Node *root = buildTree(str);
    cout << isSumProperty(root) << "\n";
    return 0;
}
/*
Time Complexity : O(n) 

TestCases : 
-------------------
Input :-
str : 10 4 6 2 2 3 3
Output : 1
-------------------
Input :-
str : 9 8 4 4 4 2 2
Output : 0
*/

