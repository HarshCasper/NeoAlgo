#include<iostream>        //Header file
using namespace std;      //For cin and cout

/*
    The height of a binary tree is the number of edges between the tree's root node and its furthest leaf node.
    Recursivley compute heights of left subtree and right subtree. Height upto the current node will be maximum of these two + 1(itself). 

    Sample Preorder Input : 
    8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 -1 -1 
    Sample Output: 
    4

    @author Aditya Saxena
    @since 28-7-2020
*/

//Implement Binary Tree Data Structure Node
class Node{
public:
    int data;
    Node* left;
    Node* right;

    //Constructor
    Node( int data ){
        this->data= data;
        left= NULL;
        right= NULL;
    }
};

//Build Tree function implementation - Recursively builds tree (preorder build) 
Node* buildTree (){

    //Input data
    int d;
    cin>>d;

    //If d is -1 then return NULL
    if( d == -1 ){
        return NULL;
    }

    //Place data at current node
    Node* root= new Node( d );

    //Recursively build left and right subtrees
    root->left= buildTree();
    root->right= buildTree();

    return root;
}

//Implement function to compute height of the tree
int height( Node* root ){

    //Check if NULL, height is zero
    if( root == NULL ){
        return 0;
    }

    //Recursivley compute heights of left and right subtrees
    int h1= height( root->left );
    int h2= height( root->right );

    return (max( h1, h2 ) + 1);

}

//Driver Funtion
int main(){

    //Build the tree
    cout<<"Enter the binary tree elements preorder wise: ";
    Node* root= buildTree();

    //Find height of tree
    cout<<endl<<"The height of the binary tree: "<<height(root); 

    return 0;
}
