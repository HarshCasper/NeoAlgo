// C++ program for different tree traversals using stack
//Time Complexity of the Program : O(n)
#include <iostream> 
using namespace std; 
  
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 
  
/* Given a binary tree, print its nodes according to the 
 postorder traversal. */
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 
  
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->data << " "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 
  
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right); 
}  
  
/* Code for  testing of above functions*/
int main() 
{ 
    struct Node *root    = new Node(10); 
    root->left           = new Node(20); 
    root->right          = new Node(30); 
    root->left->left     = new Node(40); 
    root->left->right    = new Node(50);  
    root->right->left    = new Node(60);
    root->right->right   = new Node(70);
  
    cout << "\nPreorder traversal of binary tree is \n"; 
    printPreorder(root); 
  
    cout << "\nInorder traversal of binary tree is \n"; 
    printInorder(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    printPostorder(root); 
  
    return 0; 
}
/* Input is: 10 20 30 40 50 60 70
  output is:
  Preorder traversal of binary tree is
  10 20 40 50 30 60 70
  Inorder traversal of binary tree is
  40 20 50 10 60 30 70
  Postorder traversal of binary tree is
  40 50 20 60 70 30 10 8 */ 
