/* 
AVL Trees: These are self-balancing trees where the difference between the heights
of left and right subtree(for any node) is not more than 1 and less than -1. This concept
came about so as to ensure that the opeations on BST doesn't become of the order of O(n)
as it becomes more and more skewed. In other words, AVL trees ensures that the balance of 
the tree is maintained, thus maintaining the order of the operations on it as O(log n).
properties of AVL:
 (1) It is a BST and (2) No duplicate nodes allowed 
 (3) |height of left subtree - height of right subtree| <=1
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* left;
    Node* right;
    int data;
    int bf;//balance factor of the node
    int height;
};

int find_height(Node* current_node){
    if(current_node==NULL) return(0);
    //cur_node is the pointer to the current Node
    Node* node=current_node;
    //The balance factor >0 means that left subtree has greater height
    //if it is <0 then, right subtree has greater height
    if(node->bf>=0){
        node = node->left;
    }
    else if(node->bf<0){
        node = node->right;
    }
    int height=0;
    while(node!=NULL){
        height++;
        if(node->bf<0){
            node = node->right;
        }
        else if(node->bf>=0){
            node = node->left;
        }
    }
    //one is added as the height of a single node is 1 and is added to
    //the height of the longest subtree.
    return(1+height);
}

//critical node is a node which has a balance factor either
// greater than  1 or less than -1.

int find_balance_factor(Node* node){
    return(find_height(node->left)-find_height(node->right));
}


/*
right rotation can be illustrated as follows:

   (critical_node)                                     (next_node)
    /                       (right rotation)           /          \
 (next_node)             ====================>        x        (critical_node)        
  /    \                                                        /                     
 x      y                                                      y

   Steps performed for above transformation:
    (i)   store the right node(i.e. y here) of the (next_node) to a temporary node (temp).
    (ii)  assign (critical_node) as (next_node)'s right child.
    (iii) assign node stored in temp as the left node of (critical_node).
    (iv)  update the height and balance factor of the next_node and critical_node.
*/
Node* right_rotate(Node* critical_node){
    Node* next = critical_node->left;
    Node* temp = next->right;
    next->right=critical_node;
    critical_node->left=temp;

    //updating height and balance factors for the rotated nodes
    next->height=find_height(next);
    next->bf = find_balance_factor(next);

    critical_node->height=find_height(critical_node);
    critical_node->bf = find_balance_factor(critical_node);
    return(next);
}

/*
Left rotation can be illustrated as follows:

   (critical_node)                                          (next_node)
                \               (left rotation)            /           \
              (next_node)    ====================>     (critical_node)  z      
                /    \                                             \           
               y      z                                             y          

   Steps performed for above transformation:
    (i)   store the left node(i.e. y here) of the (next_node) to a temporary node (temp).
    (ii)  assign (critical_node) as (next_node)'s left child.
    (iii) assign node stored in temp as the right node of (critical_node).
    (iv)  update the height and balance factor of the next_node and critical_node.
*/

Node* left_rotate(Node* critical_node){
    Node* next = critical_node->right;
    Node* temp = next->left;
    next->left = critical_node;
    critical_node->right = temp;

    //updating height and balance factors for the rotated nodes
    next->height=find_height(next);
    next->bf = find_height(next->left)-find_height(next->right);

    critical_node->height=find_height(critical_node);
    critical_node->bf = find_height(critical_node->left)-find_height(critical_node->right);
    return(next);
}

/*
finds the parent node of the given node. It keeps
traversing the tree until it reaches the given node.
It traverses as:
 -> if(root->data > node->data) then node is to be searched in the left subtree.
 -> if(root->data < node->data) then node is to be searched in the right subtree.
*/
Node* find_parent_node(Node* root, Node* node){
    Node* parent=NULL;
    while(root!=node){
        parent=root;
        if(root->data>node->data){
            root=root->left;
        }
        else if(root->data<node->data){
            root=root->right;
        }
    }
    return(parent);
}

/*
This function finds the critical node in the AVL Tree
The idea here is that critical nodes closest to the
deleted or inserted node are more likely to be found
in the subtree which contains the "affected area" and within that subtree,
the longest subtree. So, traversal of the tree is done:
   (i) to the right  if the balance factor of the given node<-1
   (ii) to the left if balance factor>1
root of the affected subtree is given as the argument in this
function.
*/
Node* find_critical_node(Node* root){
    Node* critical_node=NULL;
    while(root!=NULL){
        root->bf=find_balance_factor(root);
        if(root->bf>1){
            critical_node=root;
            root=root->left;
        }
        else if(root->bf<-1){
            critical_node=root;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return(critical_node);
}

/*
This function finds the inorder predecessor of a node.
For a node, its predecessor can be found by finding the
rightmost element in the left subtree of the tree
whose root is the node whose predecessor is to be found.
*/
Node* find_predecessor(Node* root, Node* &parent){
    Node* node=root;
    parent=node;
    node=node->left;
    while(node->right!=NULL){
        parent=node;
        node=node->right;
    }
    return(node);
}

/*
this function balances our AVL tree(in case of deletion).
we have the following cases covered below:
 (1)if critical node has balance factor>1 and the node to
    its left has a balance factor either 0 or 1 then we apply right rotation.Example,
     y         y
    /         /
   x(0) or   z (1)
  / \       /
 w   z     x
 (2)if it has balance factor>1 and balance factor of its left node= -1, then,
     z                   z                    y
    / (left rotate)     /  (right rotate)    / \
    x    =======>      y      ========>     x   z
     \                /
      y              x

 (3)if node has balance factor<-1 and its right node has balance factor
    either 0 or -1 then apply left rotation. example of these cases,
    x                  w
     \                  \
      y(-1)      or      y(0)
       \                / \
        z              x   z

 (4)if it has balance factor<-1 and balance factor of its left node= 1, then,
    w(-2)                      w                          x
     \      (right rotate)      \      (left rotate)     / \
      y(1) ===============>      x    ===============>  w   y
     /                            \
    x                              y
*/
Node* balance_tree(Node* node){
    if(node->bf>1 && (node->left->bf==1 || node->left->bf==0)){
        node=right_rotate(node);
    }
    else if(node->bf>1 && node->left->bf==-1){
        node->left=left_rotate(node->left);
        node=right_rotate(node);
    }
    else if(node->bf<-1 && (node->right->bf==-1 || node->right->bf==0)){
        node=left_rotate(node);
    }
    else if(node->bf<-1 && node->right->bf==1){
        node->right=right_rotate(node->right);
        node=left_rotate(node);
    }
    return(node);
}

Node* delete_node(Node* node, int key ,int root_value){
    if(node==NULL){
        return(node);
    }
    if(node->data>key){
        node->left=delete_node(node->left,key,root_value);
    }
    else if(node->data<key){
        node->right=delete_node(node->right,key,root_value);
    }
    else{
        if(node->left==NULL && node->right==NULL){
            //for node having no child, just delete it.
            node=NULL;
        }
        else if(node->left!=NULL && node->right==NULL){
            //if node to be deleted only has left child
            node=node->left;
        }
        else if(node->left==NULL && node->right!=NULL){
            //if node to be deleted only has right child
            node=node->right;
        }
        else{
            /*
            if the node to be deleted has two child nodes, then we
            find its inorder predecessor and the parent node of that
            predecessor.
            we now have two cases:
             (i)if parent of predecessor = node to be deleted then the case
                would look like this:
                  (node to deleted)
                 /                 \
                (predecessor)     (right node)
                /
               (node)
               In this case, we just assign predecessor->right = (node_to_be_deleted)->right

             (ii)      (node_to_be_deleted)
                       /                  \
                      x                    z
                     / \
                    w   y
                    here, y is found to be the predecessor for the node to be deleted.
                    so we perform the following:
                     - y->left = node->left
                     - y->right= node->right
                     - x->right = NULL
                     - update the height and balance factor of predecessor and the parent of
                       predecessor.
                    x->right=NULL
            */
            Node* parent_of_pred=NULL;//parent of predecessor node
            Node* pred=find_predecessor(node,parent_of_pred);

            if(parent_of_pred==node){
                pred->right=node->right;
            }
            else{
                pred->left=node->left;
                pred->right=node->right;
                parent_of_pred->right=NULL;
                parent_of_pred->height=find_height(parent_of_pred);
                parent_of_pred->bf=find_balance_factor(parent_of_pred);
            }
            node=pred;
        }
        if(node!=NULL){
            //updating the height and balance factor of predecessor node
            //after inserting it in deleted node's position
            node->height=find_height(node);
            node->bf=find_balance_factor(node);
            if(node->bf>1 || node->bf<-1){
                node=balance_tree(node);
            }
        }
        if(key!=root_value){
            //if node deleted isn't root node
            return(node);
        }
        else if(node==NULL){
            //if only root node existed originally,
            //but now its deleted.
            return(node);
        }
    }
    if(key==root_value){
        /*
        if root node is deleted, then our recursive function won't be able to
        backtrack and check the balance of the tree after deletion.
        So, here we first find critical node and if any, then we find its
        parent as well. We then balance the tree using appropriate rotations and
        attach this new node to its parent node.
        Then we return the root node.
        */
        Node* critical=find_critical_node(node);

        if(critical!=NULL){
            Node* parent=find_parent_node(node,critical);

            critical=balance_tree(critical);

            if(parent->data>critical->data){
                parent->left=critical;
            }
            else{
                parent->right=critical;
            }
        }
        return(node);
    }
    /*
    if any other node is being deleted, then the function moves backwards
    from the position where the node is deleted from, and checks for the
    balance factor and updates it along with their height. If critical node
    is found then, the tree is balanced with appropriate rotations and that
    node is returned.
    */
    node->height=find_height(node);
    node->bf=find_balance_factor(node);
    node=balance_tree(node);
    return(node);
}

Node* create_node(int data){
    Node* node = new Node;
    node->bf=0;
    node->height=1;
    node->left=NULL;
    node->right=NULL;
    node->data=data;
    return(node);
}

Node* insert_node(Node* node,int data){
    if(node==NULL){
        node=create_node(data);
        return(node);
    }
    if(node->data>data){
        node->left=insert_node(node->left,data);
    }
    else if(node->data<data){
        node->right=insert_node(node->right,data);
    }
    else{
        //if the same data is added more than once then, it returns the existing node with that data
        return(node);
    }
    //Node->height=1+max(find_height(Node->left),find_height(Node->right));
    node->height=find_height(node);
    node->bf = find_balance_factor(node);

    if(node->bf>1 && node->left->bf==1){
        node=right_rotate(node);
    }
    else if(node->bf>1 && node->left->bf==-1){
        node->left=left_rotate(node->left);
        node=right_rotate(node);
    }
    else if(node->bf<-1 && node->right->bf==-1){
        node=left_rotate(node);
    }
    else if(node->bf<-1 && node->right->bf==1){
        node->right=right_rotate(node->right);
        node=left_rotate(node);
    }
    return(node);
}

/*
preorder traversal of AVL tree and for each node it also displays
their balance factor in brackets.
*/
void preorder_traversal(Node* node){
    if(node!=NULL){
        cout<<node->data<<"("<<node->bf<<") ";
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }
}

int main()
{
    Node* root=NULL;
    int n; //number of nodes in the tree
    cout<<"Enter the number of nodes to be inserted: ";
    cin>>n;
    cout<<"Enter the node values: ";
    vector<int>data(n);
    for(int i=0;i<data.size();i++){
        cin>>data[i];
        root=insert_node(root,data[i]);
    }
    cout<<"\npreorder traversal of the AVL tree:\n";
    preorder_traversal(root);
    cout<<"\n";

    int m;//number of elements to be deleted
    cout<<"\nEnter the number of nodes to be deleted: ";
    cin>>m;
    cout<<"Enter the node values to be deleted: ";
    vector<int>deletion_order(m);
    for(int i=0;i<deletion_order.size();i++){
        cin>>deletion_order[i];
        root=delete_node(root,deletion_order[i],root->data);
        cout<<"\nafter deleting node with key value = "<<deletion_order[i]<<"\n";
        preorder_traversal(root);
        cout<<"\n";
    }
    return 0;
}
/* 
Time Complexities:
 (1) insertion operation: O(log n)
 (2) deletion operation: O(log n)
 (3) finding critical node: O(log n)
 (4) finding parent node: O(log n)
 (5) finding height of the tree: O(log n)
*/

/*
Test Case 1:
  (insertion)

  Input:
  13
  14 17 11 7 53 4 13 12 8 60 19 16 20
  Output(preorder traversal):
  14(0) 11(0) 7(0) 4(0) 8(0) 12(-1) 13(0) 19(0) 17(1) 16(0) 53(0) 20(0) 60(0)

  (deletion)
  Input:
  5
  14 13 19 17 12
  Output:
  after deleting node with key value = 14
    13(0) 11(1) 7(0) 4(0) 8(0) 12(0) 19(0) 17(1) 16(0) 53(0) 20(0) 60(0)

  after deleting node with key value = 13
    12(0) 7(-1) 4(0) 11(1) 8(0) 19(0) 17(1) 16(0) 53(0) 20(0) 60(0)

  after deleting node with key value = 19
    12(0) 7(-1) 4(0) 11(1) 8(0) 17(-1) 16(0) 53(0) 20(0) 60(0)

  after deleting node with key value = 17
    12(0) 7(-1) 4(0) 11(1) 8(0) 53(1) 16(-1) 20(0) 60(0)

  after deleting node with key value = 12
    11(-1) 7(1) 4(0) 53(1) 16(-1) 20(0) 60(0)
*/

/*
The AVL Tree example used in this code:
                       14
                /            \
               11             19
              /   \         /    \
             7     12       17    53
            / \      \     /      / \
           4   8     13   16    20   60


after deleting 14 it should look like this:
                     13
                /            \
               11             19
              /   \         /    \
             7     12      17    53
            / \            /     / \
           4   8          16   20   60

after deleting 13 it should look like this:
                       12
                   /        \
                7             19
              /   \         /    \
            4      11      17    53
                   /       /     / \
                  8       16   20   60

after deleting 19 it should look like this:
                        12
                    /        \
                  7           17
                /   \        /  \
               4      11    16   53
                     /          /  \
                    8          20   60

after deleting 17 it should look like this:
                        12
                      /    \
                     7      53
                   /  \     / \
                  4   11   16  60
                     /       \
                    8         20

 */

//Other cases that you could try:
//vector<int>data={10,20,30,40,50,25};
//vector<int>data={33,13,53,9,21,61,8,11};
//vector<int>data={14,13};

