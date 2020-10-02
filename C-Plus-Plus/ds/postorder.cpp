#include<iostream>
using namespace std;

//creating structure for node
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

// Insert Function
Node* Insert(Node *root, char data) {
    //if root have no value
    //then create a node and insert values
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    //check if data is less than root value
    //then insert into left subtree
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    //check if data is less than root value
    //then insert into right subtree
    else
        root->right = Insert(root->right, data);
    return root;
}

//Postorder Function
void Postorder(Node *root) {

    if (root == NULL) return;
    // if tree is empty then return
    //visit left and right subtree
    Postorder(root->left);
    Postorder(root->right);
    //otherwise print data
    printf("%c ", root->data);
}

//Main Function began
int main() {
    Node* root = NULL;
    //input values
    root = Insert(root, 'M');
    root = Insert(root, 'B');
    root = Insert(root, 'Q');
    root = Insert(root, 'Z');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
    //Print Nodes in Preorder.
    cout << "\tOUTPUT\n";
    cout << "Postorder traversal : ";
    Postorder(root);
    cout << "\n";
}
//Main Ends

/*
Sample Input Output:

Input -> M B Q Z A C

OUTPUT:
Postorder traversal : A C B Z Q M

Time Complexity: O(n)
*/
