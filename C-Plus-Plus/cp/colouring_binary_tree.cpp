/*Problem Statement:
A binary tree is given, there are two players. We are given the root of this binary tree,
and the number of nodes n in the tree. n is odd, and each node has distinct values.
Initially, player1 has a color x and player 2 has a color y. 
Player1 colors the node with value x in red and player2 colors the node with value y in blue.
Then the players take turns, in each turn the player choses a node of their color and colors
the uncolored neighbour of the chosen node.
If a player cannot choose such a node this way, they must pass their turn. 
If both players pass their turn, the game ends and the winner with more colored nodes wins.
If you are a player. If it is possible to choose such a y to ensure you win the game, print 1
else print 0 */

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node*left;
    Node*right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }

};

Node* buildTree(Node*root){
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    root = new Node(d);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

void preorder(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

Node* findNode(Node* root,int first_node)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==first_node)
    {
        return root;
    }
    Node* left=findNode(root->left,first_node);
    Node* right=findNode(root->right,first_node);

    return (left==NULL?right:left);
}

int countNodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int Left_nodes=countNodes(root->left);
    int Right_nodes=countNodes(root->right);

    return 1+Left_nodes+Right_nodes;
}

int color(Node* root,int first_node,int actual_nodes)
{
    Node* t=findNode(root,first_node);
    int left=countNodes(t->left);
    int right=countNodes(t->right);
    int remaining=actual_nodes-(left+right)-1;
    if(left>right+remaining)
    {
        return 1;
    }
    if(right>left+remaining)
    {
        return 1;
    }
    if(remaining>left+right)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int total,actual_nodes,first_node;
    cout<<"Enter the total number of nodes,the actual nodes and the node marked by first person: "<<endl;
    cin>>total>>actual_nodes>>first_node;
    cout<<"Enter nodes: "<<endl;
    Node* root=buildTree(root);
    cout<<"Possibility: "<<color(root,first_node,actual_nodes)<<endl;
    return 0;
}
/*
Example:-

Input:-
Enter the total number of nodes,the actual nodes and the node marked by first person:
7 3 1
Enter nodes:
1 2 -1 -1 3 -1 -1

Output:-
Possibility: 0

Time Complexity: O(n)
Space Complexity: O(n)
*/

