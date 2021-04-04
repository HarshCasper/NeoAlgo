/*
Depth of tree :- we can define depth of tree as total number of levels present in whole tree  tree.

Time Complexity: O(n)

Space Complexity: if tree is perfectly balanced tree O(log n)
		  if it is not perfectly balanced tree O(n)

*/
#include <bits/stdc++.h>
using namespace std;

struct node {
    node(int x): data(x), left_child(NULL), right_child(NULL) {}
    int data;
    node *left_child;
    node *right_child;
};

class bin_tree{
    node *root;
public:
   // constructor of tree
    bin_tree()
    {
        root = NULL;
    }
    void insert_data(int x){
        //if tree is empty
        if(!root)
        {
            node *tnode = new node(x);
            root = tnode;
        }
        //if tree if not empty
        else
        {
            node *temp =root;
            while(1)
            {
                //if data to be inserted is less then the data of current node
                if(x < temp->data )
                {
                    //if left child of current node is node present we simple add new node with the data to be inserted
                    if(!temp->left_child)
                        {
                            node *tnode = new node(x);
                            temp->left_child = tnode;
                            break;
                        }
                    //else we change the current node pointer with pointer of left child node pointer
                    else
                        temp = temp->left_child;
                }
                //if data to be inserted is grater then or equal to the data of current node
                else
                {
                    //if right child of current node is node present we simple add new node with the data to be inserted
                    if(!temp->right_child)
                        {
                            node *tnode = new node(x);
                            temp->right_child = tnode;
                            break;
                        }
                    //else we change the current node pointer with pointer of left child node pointer
                    else
                     temp = temp->right_child;
                }
            }
        }
    }

    int depth(node *level)
    {
        if(level == NULL)
        {
            return 0;
        }
        //depth of left subtree
        int left_depth = depth(level->left_child);
        //depth of right subtree
        int rigth_depth = depth(level->right_child);
        // depth of tree will max of depth of left subtree and depth of right subtree adding current node;
        return  max(left_depth,rigth_depth)+1;
    }
	
    //depth of whole tree
    int depth_of_tree()
    {
        return(depth(root));
    }
};
int main() {
    bin_tree t;
    int n;
    cout<<"Enter number of elements in tree: ";
    cin>>n;
    cout<< "Enter elements to insert in  tree: ";
    while(n--)
    {	
        int k; cin>>k;
        t.insert_data(k);
    }
    cout<<"\nDepth of tree:"<<t.depth_of_tree()<<endl;
    return 0;	
    /* 
    Sample case 1
    Enter number of elements in tree: 7
    Enter elements to insert in  tree: 50 60 40 55 30 70 45 
    Depth of tree : 3

         50                         level 1
      /     \
     /       \
    40        60                    level 2
   /   \     /   \
  /     \   /     \
30    45  55      70                level 3

......................................................................................................
    Sample case 2
    Enter number of elements in tree: 8
    Enter elements to insert in  tree: 50 40 60 55 30 56 70 45
    Depth of tree : 4

         50                         level 1
      /     \
     /       \
    40        60                    level 2
   /   \     /   \
  /     \   /     \
30    45  55      70                level 3
            \
             \
             56                     level 4
*/   
	
}
