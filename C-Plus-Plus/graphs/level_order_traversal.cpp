// level order traversal in c++

/*

Author - Jeet Patel 

*/
/* Question : you are provided with a tree.you have to traverse in level order .
        level order :
        1         level 1
       /  \
      2    3       level 2
     / \  / \
    4  5  7  8     level 3
         /
        6         level 4

        level order is: [level1,level2,level3,level4] = 1,2,3,4,5,7,8,6.
 */


#include<bits/stdc++.h>
using namespace std;
 
 struct node
 {
     int val;        // value of node 
     node *left;
     node *right; // left child and right child.
   
 };
 
 node * root; // to create nodes.
 node * create(int value){
     node * newnode =new node();
     newnode->left=NULL;
     newnode->right=NULL;
     newnode->val=value;
     
     return newnode;
 }
 
 

// function input : pointer to the root.
// function output : a 1d vector/ or array of level order traversal.

// approach : BFS by Queue,as we need to print it level wise. 

vector<int> level(node * root)
{
    vector<int> ans;  // ans is where level order will be stored.
    queue<node *>q;
    q.push(root);
    while(!q.empty())
    {
        node * first=q.front();
        q.pop();
        ans.push_back(first->val);
        if(first->left!=NULL) q.push(first->left); // checking if left nodes exists or not 
        if(first->right!=NULL) q.push(first->right); // checking if right node exisits or not.

    }

    return ans; // it will return the node values in level order.
}
// driver code......
// to create a treee as per above example.
int main()
{
    vector<int>anss;
 node * root =create(1); // level 1
 
 root->left=create(2);
 root->right=create(3); // level 2
 
  root->left->left=create(4);
 root->left->right=create(5);
  root->right->left=create(7);
 root->right->right=create(8); // level 3
 
 root->right->left->left=create(6); //level 4;

 // this is the same example as above mentioned.
 
 anss=level(root);
 for(auto i : anss) cout<<i<<" ";
}