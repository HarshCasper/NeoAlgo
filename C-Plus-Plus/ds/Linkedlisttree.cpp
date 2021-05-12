/*Given a binary tree as input, output it as the linkedlist in-place.
The "Linkedlist" should be in the same order as "Preorder Traversal" of the given binary tree.
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *node(int val)
{
    TreeNode *c = new TreeNode;
    c->val = val;
    c->left = c->right = NULL;
    return c;
}

/*Here,flatten is defined as the function to convert binary tree to linkedlist by altering the left node and making the right node point to null.*/

TreeNode *flatten(TreeNode *A)
{
     //if the tree is empty
    if (A == NULL)
    {
        return A;
    }
    //for the case of leaf node
    if (A->left == NULL && A->right == NULL) 
    {
        return A;
    }
    if (A->right != NULL && A->left == NULL)
    {
        A->right = flatten(A->right);
        return A;
    }
    else
    {
        TreeNode *j = A;
        TreeNode *p = j->right;
        TreeNode *q = j->left;
        while (q->right != NULL)
        {
            q = q->right;
        }
        q->right = p;
        j->right = flatten(j->left);
        j->left = NULL;
        return j;
    }
}
//function for output.
void inorder_output(TreeNode *root) 
{
    if (root == NULL)
    {
        return;
    }
    inorder_output(root->left);
    cout << root->val << " ";
    inorder_output(root->right);
}
 //code for inserting the required value to every node of tree to be formed.
TreeNode *insert_value(TreeNode *root, int val, queue<TreeNode *> &t)
{
    TreeNode *temp = node(val);
    if (val == -1)
    {
        temp = NULL;
    }
    if (root == NULL)
    {
        root = temp;
    }
    else if (t.front()->left == NULL)
        t.front()->left = temp;
    else
    {
        t.front()->right = temp;
        t.pop();
    }
    t.push(temp);
    return root;
}
//code for creating tree
TreeNode *form_tree(vector<int> v) 
{
    TreeNode *root = NULL;
    queue<TreeNode *> t;
    for (int i = 0; i < v.size(); i++)
    {
        root = insert_value(root, v[i], t);
    }
    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int u;
        cin >> u;
        v.push_back(u);
    }
    TreeNode *A = form_tree(v);
    inorder_output(flatten(A));
}

/*
sample input:
13 
6 4 8 2 -1 5 9 -1 -1 -1 -1 -1 -1

given input tree is:-
              6
             / \
            4   8
           /   / \
          2   5   9

sample output:
6 4 2 8 5 9

output flattened tree should be like a linkedlist in-place as shown below :-      
              6
               \
                4
                 \
                  2
                   \
                    8
                     \
                      5
                       \
                        9


CODE COMPLEXITY FOR THE CODE OF FLATTEN FUNCTION :
1.TIME COMPLEXITY- O(N) 
2.SPACE COMPLEXITY- O(1)
*/
