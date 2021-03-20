/*
The traversal operation is a frequently used operation on a binary tree. This operation is used to visit each node in the tree exactly once
A full traversal on a binary tree gives a linear ordering of data in the tree .  This is the iterative inorder tree traversal algorithms
*/
#include <stdio.h>
#include <stdlib.h>
//structure for the binary tree node
typedef struct Tree
{
    char data;
    struct Tree *left;
    struct Tree *right;
} TreeNode;
//structure for stack which is used for the iterative traversal algorithms
//stack is implemented using linked list
typedef struct Stack
{
    TreeNode *node;
    struct Stack *next;
} Stack;
//push operation for the stack
void push(Stack **s, TreeNode *node)
{
    Stack *New = (Stack *)malloc(sizeof(Stack));
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
            printf("%c ", ptr->data);
            ptr = ptr->right;
        }
    }
}
//Search_Link returns the pointer to the node which contains the value key , it is used in the insertion operation
TreeNode *Search_Link(TreeNode *root, char key)
{
    TreeNode *ptr = root;
    if (ptr->data != key)
    {
        if (ptr->left != NULL)
        {
            Search_Link(ptr->left, key);
        }
        if (ptr->right != NULL)
        {
            Search_Link(ptr->right, key);
        }
        if (ptr->right == NULL && ptr->left == NULL)
        {
            return NULL;
        }
    }
    else
    {
        return ptr;
    }
}
// Insertion operation of the binary tree
void insert(TreeNode *root, char key, char c)
{
    TreeNode *ptr = Search_Link(root, key);
    if (ptr == NULL)
    {
        printf("Search Unsuccessfull No Insertion \n");
        return;
    }
    char option;
    if (ptr->left == NULL || ptr->right == NULL)
    {
        printf("Enter Where to insert left or right (L/R)\n");
        scanf(" %c", &option);
        if (option == 'L' || option == 'l')
        {
            if (ptr->left == NULL)
            {
                TreeNode *New = (TreeNode *)malloc(sizeof(TreeNode));
                ptr->left = New;
                New->data = c;
                printf("Inserting %c as the left\n", c);
                New->left = NULL;
                New->right = NULL;
            }
            else
            {
                printf("Insertion not Possible as Left child \n");
            }
        }
        else
        {
            if (ptr->right == NULL)
            {
                TreeNode *New = (TreeNode *)malloc(sizeof(TreeNode));
                ptr->right = New;
                New->data = c;
                printf("Inserting %c as the right\n", c);
                New->left = NULL;
                New->right = NULL;
            }
            else
            {
                printf("Insertion not possible as the right child \n");
            }
        }
    }
    else
    {
        printf("The Node Already has child");
    }
}

int main()
{
    printf("Enter the value for root node\n");
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    char c;
    scanf("%c", &c);
    root->data = c;
    root->right = NULL;
    root->left = NULL;
    char choice = 'y';
    char data;
    do
    {
        printf("Enter the Node to be Inserted \n");
        scanf(" %c", &data);
        printf("Enter the Parent node of the node to be inserted\n");
        scanf(" %c", &c);
        insert(root, c, data);
        printf("Do you want to continue (y/n)\n");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("Inorder Traversal of the Tree \n");
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
