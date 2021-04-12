/*
Stack data structure is used to construct the binary tree.
This is an iterative process for constructing the binary tree .
  
  -->state variable is providing this functionality for making the process iterative rather than using recursion.
        3 states are used-
        1. state==1 then add left child
        2. state==2 then add right child
        3. state==3 then pop the node from stack as both left and rigth child are added for this node.
*/

#include <iostream>
using namespace std;
#include <vector>
#include <stack>
class Tree
{
public:
    int val;
    int state;
    Tree *left;
    Tree *right;
    Tree()
    {
        val = 0;
        state = 0;
        left = NULL;
        right = NULL;
    }

    Tree(int x, int s)
    {
        val = x;
        state = s;
        left = NULL;
        right = NULL;
    }
    Tree(int val, int state, Tree *left, Tree *right)
    {
        this->val = val;
        this->state = state;
        this->left = left;
        this->right = right;
    }

    // Function to display tree (preorder traversal)
    void display(Tree *root)
    {
        if (root == NULL)
            return;

        cout << root->val << " ";
        display(root->left);
        display(root->right);
    }
};

int main()
{
    int n;
    cout << "Enter size of the array:";
    cin >> n;
    cout << "\nEnter the elements :";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\n";
    Tree t;
    stack<Tree *> st;
    //initially root is at state =1
    Tree *root = new Tree(arr[0], 1);
    st.push(root);
    int i = 1;
    while (st.size() > 0)
    {
        if (st.top()->state == 1)
        {
            if (arr[i] != -1)
            {
                Tree *node = new Tree(arr[i], 1);
                //state increased as left child added
                st.top()->state++;
                st.top()->left = node;
                st.push(node);
            }
            //if arr[i]==-1 then NULL is added
            else
            {
                st.top()->left = NULL;
                st.top()->state++;
            }
        }
        else if (st.top()->state == 2)
        {
            if (arr[i] != -1)
            {
                Tree *node = new Tree(arr[i], 1);
                //state increased as right child added
                st.top()->state++;
                st.top()->right = node;
                if (st.top()->state == 3)
                    st.pop();
                st.push(node);
            }
            else
            {
                st.top()->right = NULL;
                st.top()->state++;
            }
        }

        if (st.top()->state == 3)
        { //node popped from stack as both left and right child added
            st.pop();
        }

        i++;
    }
    //preorder traversal of tree
    t.display(root);
    cout << "\n";
}

/* Sample input.
50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1

                      50
                    /   \
                25        75
               /  \      /  \
            12     37   62  87
                  /      \
                30         70


Output: (preorder traversal)
50 25 12 37 30 75 62 70 87  

*/
