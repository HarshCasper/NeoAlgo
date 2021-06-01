/*Convert the BST into a Min Heap with the condition that all the values in the left subtree of a 
node should be less than all the values in the right subtree of the node. */

#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node *left, *right;
};
 
/*  Function to allocate a new node with the given data and NULL left and right pointers. */
struct Node* getNode(int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 

void preorderTraversal(Node*);
 
void inorderTraversal(Node *root, vector<int>& arr)
{
    if (root == NULL)
        return;
 
    inorderTraversal(root->left, arr);
 
    arr.push_back(root->data);
 
    inorderTraversal(root->right, arr);
}
 
void BSTToMinHeap(Node *root, vector<int> arr, int *i)
{
    if (root == NULL)
        return;
 
    root->data = arr[++*i];
    
 //for left subtree
    BSTToMinHeap(root->left, arr, i);
 
 //for right subtree
    BSTToMinHeap(root->right, arr, i);
}
 
// To convert the given BST to MIN HEAP
void convertToMinHeapUtil(Node *root)
{
    // vector to store the data of all the
    // nodes of the BST
    vector<int> arr;
    int i = -1;
 
    // inorder traversal
    inorderTraversal(root, arr);
 
    // BST to MIN HEAP conversion
    BSTToMinHeap(root, arr, &i);
}
 
//  preorder traversal 
void preorderTraversal(Node *root)
{
    if (!root)
        return;
 
    // print the root's data first
    cout << root->data << " ";
 
    // recur on left subtree
    preorderTraversal(root->left);
 
    // recur on right subtree
    preorderTraversal(root->right);
}
void convert(int keys[], int low, int high, Node* &root)
{
    // base case
    if (low > high) {
        return;
    }
 
    // finding the middle element of the current range
    int mid = (low + high) / 2;
 
    // constructing a new node from the middle element and assign it to the root
    root = getNode(keys[mid]);
 
    convert(keys, low, mid - 1, root->left);
 
    convert(keys, mid + 1, high, root->right);
}

Node* convert(int keys[], int n)
{

    sort(keys, keys + n);
 
    Node* root = nullptr;
    convert(keys, 0, n - 1, root);
    
    return root;
}
 

int main()
{
    // BST formation
    int n;
    cout<<"Total no. of nodes:";
    cin>>n;
    int keys[n];
    cout<<"Enter the elements of Tree";
    for(int i=0;i<n;i++){
        cin>>keys[i];
    }
    Node* root = convert(keys, n);
    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
 
    return 0;
}

/* 
OUTPUT:
Total no. of nodes:8

Enter the elements of Tree9 8 7 6 5 4 10 12

Preorder Traversal:

4 5 6 7 8 9 10 12 

---------------------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(n) [n here is number of nodes in the tree]
Space Complexity: O(n) 
