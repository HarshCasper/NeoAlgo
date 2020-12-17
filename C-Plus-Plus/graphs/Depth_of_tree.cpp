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
    t.insert_data(50);
    t.insert_data(40);
    t.insert_data(60);
    t.insert_data(30);
    t.insert_data(45);
    t.insert_data(55);
    t.insert_data(70);
    /*

         50                         level 1
      /     \
     /       \
    40        60                    level 2
   /   \     /   \
  /     \   /     \
30    45  55      70                level 3



    */
    cout<<t.depth_of_tree()<<endl;
    //so output will be 3

    t.insert_data(56);

    /*

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
    cout<<t.depth_of_tree()<<endl;
    //so output will be 4
	return 0;
}
