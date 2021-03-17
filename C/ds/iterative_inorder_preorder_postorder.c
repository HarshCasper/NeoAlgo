/*
The traversal operation is a frequently used operation on a binary tree. This operation is used to visit each node in the tree exactly once
A full traversal on a binary tree gives a linear ordering of data in the tree . These are the iterative tree traversal algorithms
(preorder , inorder , postorder)
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
//iterative preorder traversal
void preorder(TreeNode *root)
{
    TreeNode *ptr = root;
    Stack *s = NULL;
    push(&s, root);
    while (!isEmpty(&s))
    {
        ptr = pop(&s);
        if (ptr != NULL)
        {
            printf("%c ", ptr->data);
            push(&s, ptr->right);
            push(&s, ptr->left);
        }
    }
}
//iterative postorder traversal
void postorder(TreeNode *root)
{
    Stack *s1 = NULL;
    Stack *s2 = NULL;
    TreeNode *ptr = root;
    push(&s1, root);
    while (!isEmpty(&s1))
    {
        ptr = pop(&s1);
        if (ptr != NULL)
        {
            push(&s2, ptr);
        }
        if (ptr->left)
        {
            push(&s1, ptr->left);
        }
        if (ptr->right)
        {
            push(&s1, ptr->right);
        }
    }
    while (!isEmpty(&s2))
    {
        printf("%c ", pop(&s2)->data);
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
//search function returns the parent of the node containing the value key , it is used in the deletion operation
TreeNode *search(TreeNode *root, char key, TreeNode *prev)
{
    TreeNode *ptr = root;
    if (ptr == NULL)
    {
        return NULL;
    }
    if (ptr->data == key)
    {
        return prev;
    }
    else
    {
        search(ptr->left, key, ptr);
        search(ptr->right, key, ptr);
    }
}
//Deletion from a binary tree
void deleteNode(TreeNode *root, char key)
{
    if (root == NULL)
    {
        printf("Deletion not possible");
        return;
    }
    TreeNode *ptr = search(root, key, NULL);
    if (ptr != NULL)
    {
        if (ptr->left != NULL)
        {
            if (ptr->left->data == key)
            {
                if (ptr->left->left == NULL && ptr->left->right == NULL)
                {
                    ptr->left = NULL;
                }
                else
                {
                    printf("Node is not a leaf node,No deletion\n");
                }
            }
        }
        if (ptr->right != NULL)
        {
            if (ptr->right->data == key)
            {
                if (ptr->right->left == NULL && ptr->right->right == NULL)
                {
                    ptr->right = NULL;
                }
                else
                {
                    printf("Node is not a leaf node,No deletion\n");
                }
            }
        }
    }
    else
    {
        printf("No Deletion\n");
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
    do
    {
        char d;
        int c;
        printf("Enter your choice\n");
        printf("1) Deletion \n2) Inorder Traversal \n3) PreOrder Traversal \n4) PostOrder Traversal\n5) Exit\n");
        scanf(" %d", &c);
        switch (c)
        {
        case 1:
            printf("Enter The Node to Be Deleted \n");
            scanf(" %c", &d);
            deleteNode(root, d);
            printf("\n");
            break;
        case 2:
            printf("Inorder Traversal of the Tree \n");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("PreOrder Traversal of the Tree \n");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("PostOrder Traversal of the Tree \n");
            postorder(root);
            printf("\n");
            break;
        case 5:
            return 0;
        }
    } while (1);
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
Enter your choice
1) Deletion
2) Inorder Traversal
3) PreOrder Traversal
4) PostOrder Traversal
5) Exit
2
Inorder Traversal of the Tree
B A C
Enter your choice
1) Deletion
2) Inorder Traversal
3) PreOrder Traversal
4) PostOrder Traversal
5) Exit
3
PreOrder Traversal of the Tree
A B C
Enter your choice
1) Deletion
2) Inorder Traversal
3) PreOrder Traversal
4) PostOrder Traversal
5) Exit
4
PostOrder Traversal of the Tree
B C A
Enter your choice
1) Deletion
2) Inorder Traversal
3) PreOrder Traversal
4) PostOrder Traversal
5) Exit

Time Complexity = O( n )
Space Complexity = O( n )
*/