/*
The traversal operation is a frequently used operation on a binary tree. This operation is used to visit each node in the tree exactly once
A full traversal on a binary tree gives a linear ordering of data in the tree .  This is the iterative inorder tree traversal algorithms
*/
#include <bits/stdc++.h>

using namespace std;
//structure for the binary tree node
class TreeNode
{
public:
    char data;
    TreeNode *left;
    TreeNode *right;
};
//structure for stack which is used for the iterative traversal algorithms
//stack is implemented using linked list
class Stack
{
public:
    TreeNode *node;
    Stack *next;
};
//push operation for the stack
void push(Stack **s, TreeNode *node)
{
    Stack *New = new Stack();
    New->node = node;
    New->next = (*s);
    (*s) = New;
}
// pop operation for the stack
TreeNode *pop(Stack **s)
{
    if ((*s) != NULL)
    {
        TreeNode *ptr = (*s)->node;
        (*s) = (*s)->next;
        return ptr;
    }
}
//checks whether the stack is empty or not
int isEmpty(Stack **s)
{
    if ((*s) == NULL)
    {
        return 1;
    }
    return 0;
}
//iterative inorder traversal
void inorder(TreeNode *root)
{
    TreeNode *ptr = root;
    Stack *s = NULL;
    while (!isEmpty(&s) || ptr != NULL)
    {
        if (ptr != NULL)
        {
            push(&s, ptr);
            ptr = ptr->left;
        }
        else
        {
            ptr = pop(&s);
            cout << ptr->data << " ";
            ptr = ptr->right;
        }
    }
}
//search function returns the pointer to the node which contains the value key , it is used in the insertion operation
TreeNode *search(TreeNode *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == k)
    {
        return root;
    }
    else
    {
        TreeNode *x = search(root->left, k);
        if (x)
            return x; //if we find in left subtree, return result
        return search(root->right, k);
    }
}
// Insertion operation of the binary tree
void insert(TreeNode *root, char key, char c)
{
    TreeNode *ptr = search(root, key);
    if (ptr == NULL)
    {
        cout << "Search Unsuccessfull No Insertion \n";
        return;
    }
    char option;
    if (ptr->left == NULL || ptr->right == NULL)
    {
        cout << "Enter Where to insert left or right (L/R)\n";
        cin >> option;
        if (option == 'L' || option == 'l')
        {
            if (ptr->left == NULL)
            {
                TreeNode *New = new TreeNode();
                ptr->left = New;
                New->data = c;
                cout << "Inserting " << c << " as the left" << endl;
                New->left = NULL;
                New->right = NULL;
            }
            else
            {
                cout << "Insertion not Possible as Left child " << endl;
            }
        }
        else
        {
            if (ptr->right == NULL)
            {
                TreeNode *New = new TreeNode();
                ptr->right = New;
                New->data = c;
                cout << "Inserting " << c << " as the right" << endl;
                New->left = NULL;
                New->right = NULL;
            }
            else
            {
                cout << "Insertion not possible as the right child" << endl;
            }
        }
    }
    else
    {
        cout << "The Node Already has child" << endl;
    }
}

int main()
{
    cout << "Enter the value for root node" << endl;
    TreeNode *root = new TreeNode();
    char c;
    scanf("%c", &c);
    root->data = c;
    root->right = NULL;
    root->left = NULL;
    char choice = 'y';
    char data;
    do
    {
        cout << "Enter the Node to be Inserted" << endl;
        cin >> data;
        cout << "Enter the Parent node of the node to be inserted" << endl;
        cin >> c;
        insert(root, c, data);
        cout << "Do you want to continue (y/n)" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Inorder Traversal of the Tree" << endl;
    inorder(root);
    return 0;
}
/*
Sample I/O:
Enter the value for root node
A
Enter the Node to be Inserted
B
Enter the Parent node of the node to be inserted
A
Enter Where to insert left or right (L/R)
L
Inserting B as the left
Do you want to continue (y/n)
y
Enter the Node to be Inserted
C
Enter the Parent node of the node to be inserted
A
Enter Where to insert left or right (L/R)
R
Inserting C as the right
Do you want to continue (y/n)
n
Inorder Traversal of the Tree
B A C
Time Complexity = O( n )
Space Complexity = O( n )
*/
