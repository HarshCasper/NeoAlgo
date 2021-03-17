//Given an array of integers which represents the preorder traversal of a Binary Search Tree 
//Construct the BST and return its root.

#include <iostream>
#include <stack>
using namespace std;

//Structure for node contains data, pointer to the left child and pointer to the right child
struct Node{
    int data;
    Node *left;
    Node *right;
};

//Function to create a new node with desired value and return its address
Node* CreateNode (int val){
    Node* new_node = new Node;
    new_node->data = val;
    new_node->left = new_node->right = NULL;
    return new_node;
}

//Function to generate BST from preorder traversal 
//Iterative solution using stack which runs in O(n) time
Node* BstFromPreorder (int pre[], int size){
    stack <Node*> stk;
    //First element of preorder traversal is always the root
    Node *root = CreateNode (pre[0]);     
    Node *p = root;
    //count maintains number of nodes in tree                      
    int count = 1;                        
    //Iterate through the rest of pre[] array
    while (count < size){
        if (pre[count] < p->data)  
        //If the element is less than the element pointed by p 
        {
            Node *temp = CreateNode ( pre[count++] );
            p->left = temp;
            stk.push (p);
            p = temp;
        }
        else 
        {
            //If the element is greater than the element pointed by p and is smaller than the element at top of stack 
            if ((pre[count] > p->data) && ((stk.size()==0) || (pre[count] < stk.top()->data))){
                Node *temp = CreateNode ( pre[count++] );
                p->right = temp;
                p = temp;
            }
            //If the element is greater than element pointed by p and at the top of stack
            else{
                p = stk.top();
                stk.pop();
            }
        }
    }
    return root;  
}

//Function to print inorder traversal of tree
void Inorder (Node* node)  
{  
    if (node == NULL)
    {
        return; 
    }   
    Inorder (node->left);  
    cout << node->data<<" ";  
    Inorder (node->right);  
} 

int main ()  
{  
    int size,pre[30];
    cout << "Enter the number of nodes in tree: ";
    cin >> size;   
    cout << "Enter a valid preorder traversal :";
    for (int i=0 ; i<size ; i++) 
    {
        cin >> pre[i];
    }
    Node *root = BstFromPreorder(pre, size);  
    cout<<"Inorder traversal of the constructed tree: \n"; 
    Inorder(root);  
    return 0;  
}

/*
Time Complexity : O(n)
Space Complexity : O(n)

Sample Input:
Enter the number of nodes in tree:8
Enter a valid preorder traversal :30 20 10 15 25 40 50 45

Sample Output:
Inorder traversal of the constructed tree:
10 15 20 25 30 40 45 50
*/