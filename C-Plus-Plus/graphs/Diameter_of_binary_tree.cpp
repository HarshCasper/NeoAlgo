/*
  Code Implementation of Diameter of Binary Tree(Recursive Approach)
  
  Definition:-The diameter of a binary tree (sometimes called the width) is the number of nodes
  on the longest path between two end nodes.

   Approach of solving:-Diameter of a tree can be calculated by utilizing the property that
   the diameter of a tree is nothing but maximum value of (left_height + right_height + 1) for each node.
   So we need to calculate this value (left_height + right_height + 1) for each node and update the result. 
   
*/

#include <bits/stdc++.h>
using namespace std;

//User-define Tree structure
struct  Tree {
    int data;
    Tree* left, *right;
};

struct Tree* CreateNode(int data)
{
    struct Tree* node = new Tree;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}

int height(struct Tree* node)
{
     //  case 1:- when Tree is empty
    if (node == NULL)
    {
         return 0;
    }
    //Case 2:- height would be 1+max(height of left tree,height of right tree)
    return 1 + max(height(node->left), height(node->right));
}

int Diameter(struct Tree* node)
{
    //  case 1:- when Tree is empty
    if (node == NULL)
    {
        return 0;  
    }      
    //  Finding the  diameter of left and right sub-trees
    int leftdiameter = Diameter(node->left);
    int rightdiameter = Diameter(node->right);
  
    // Finding the height of left and right sub-trees
    int leftheight = height(node->left);
    int rightheight = height(node->right);
    /* 
      Result is nothing but the maximum of diameter of left,right  subtrees and 
      height of left subtree + height of right subtree + 1;
    */
    return max(leftheight + rightdiameter + 1, max(leftdiameter, rightdiameter));
}

int main()
{  
    //Creating a random binary tree 
    struct Tree* root = CreateNode(1);
    root->left = CreateNode(4);
    root->right = CreateNode(9);
    root->left->left = CreateNode(3);
    root->left->right = CreateNode(6);
    root->left->right->left = CreateNode(10);    
    cout<<"Diameter of the above tree is:-"<<Diameter(root)<<"\n";   
    return 0;
}
/*

Complexity Analysis
Time _Complexity:O(n^2)
Space_Complexity:O(1)

Input Output Analysis:-
Input Tree:- 1
            / \
           4   9
          / \  
         3  6
           /
         10
  Output:-Diameter of the above tree is:-5

*/
