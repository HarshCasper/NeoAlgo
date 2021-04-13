/*
 ----------------THIS IS THE PROGRAM TO FIND THE WIDTH OF THE BINARY TREE----------------

 APPROACH - 1. Level order traversal of the binary tree with the help of a queue.
            2. In the queue, store the nodes of the tree as (node, index)
                where the root of the node is at the index = 0;
            3. When pushing the left and the right child of the node, keep in mind to change the index to 
               (2 * i + 1) and (2 * i + 2);
            4. Get the size of the queue in every iteration and get the index of the front and back element in the 
               queue
            5. Subtract the index values to get the width at each level, maintain a variable to store the maximum width

  eg.      1
         /   \
        3     2       width of this tree is 4 (5, 3, null, 9)
       / \     \  
      5   3     9
 
 
 */

#include <bits/stdc++.h>
using namespace std;

// class to define the internal structure of the tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
// ---------------------------FUNCTION TO TAKE THE INPUT OF THE TREE----------------------
BinaryTreeNode<int> *TakeinputLevelWise()
{
    int data;
    cout << "enter the root data :" << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *> nodes;
    nodes.push(root);
    while (nodes.size() != 0)
    {
        BinaryTreeNode<int> *front = nodes.front();
        nodes.pop();
        int leftchild;
        int rightchild;
        cout << "Enter the left child of " << front->data << ":" << endl;
        cin >> leftchild;
        if (leftchild != -1)
        {
            BinaryTreeNode<int> *LChild = new BinaryTreeNode<int>(leftchild);
            front->left = LChild;
            nodes.push(LChild);
        }
        cout << " Enter the right Child of " << front->data << ":" << endl;
        cin >> rightchild;
        if (rightchild != -1)
        {
            BinaryTreeNode<int> *RChild = new BinaryTreeNode<int>(rightchild);
            front->right = RChild;
            nodes.push(RChild);
        }
    }
    return root;
}
// ---------------------------FUNCTION TO PRINT THE TREE--------------------------
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> nodes;
    nodes.push(root);
    while (nodes.size() != 0)
    {
        BinaryTreeNode<int> *front = nodes.front();
        cout << front->data << ":";
        nodes.pop();
        if (front->left)
        {
            nodes.push(front->left);
            cout << "L:" << front->left->data;
        }
        if (front->right)
        {
            nodes.push(front->right);
            cout << "R:" << front->right->data;
        }
        cout << endl;
    }
}

// -----------------------FUNCTION TO FIND THE WIDTH OF THE TREE-------------------------
int widthOfBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    // make a queue with pair of node and the index value
    queue<pair<BinaryTreeNode<int> *, int>> q;
    int width = 1;
    q.push({root, 0});
    while (!q.empty())
    {
        int Qsize = q.size();
        int start = q.front().second; // get the start index of the element in the queue at a particular level
        int end = q.back().second;    // get the end index of the element in the queue at a particular level
        width = max(width, (end - start + 1));

        for (int i = 0; i < Qsize; i++)
        {
            pair<BinaryTreeNode<int> *, int> top = q.front();
            BinaryTreeNode<int> *node = top.first;
            // This is an improvisation in the algoritm as the index cound would have been gone beyond the 32 bit
            // so we are subtracting the start index from index of every node
            int idx = top.second - start;
            q.pop();
            if (node->left)
                q.push({node->left, (2 * idx + 1)});
            if (node->right)
                q.push({node->right, (2 * idx + 2)});
        }
    }
    return width;
}

int main()
{
    BinaryTreeNode<int> *root = TakeinputLevelWise();
    printLevelWise(root);
    cout << widthOfBinaryTree(root);
}

/*  
    INPUT - 1 3 2 5 3 6 9 -1 8 -1 -1 -1 -1 -1 5 7
    
           1
        /     \
       3       2
      / \     / \  
     5   3   6   9 
      \        /  \
       8      5   7

    OUTPUT - 7 
    EXPLANATION - (8, NULL, NULL, NULL, NULL, 5, 7)
    

    COMPLEXITY ANALYSIS-
    The code uses level order traversal to find the width of the binary tree and a queue to store the node
    Time complexity - O(n) each node is visisted once
    Space complexity - o(n); 
    
*/