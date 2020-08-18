#include <stdio.h>
#include <stdlib.h>

// Maximum stack size
#define MAX_SIZE 100

// A tree node
struct Node {
	int data;
	struct Node *left, *right;
};

// Stack type
struct Stack {
	int size;
	int top;
	struct Node** array;
};

// A utility function to create a new tree node
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// A utility function to create a stack of given size
struct Stack* createStack(int size)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->size = size;
	stack->top = -1;
	stack->array = (struct Node**)malloc(stack->size * sizeof(struct Node*));
	return stack;
}

// BASIC OPERATIONS OF STACK
int isFull(struct Stack* stack)
{
	return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, struct Node* node)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return NULL;
	return stack->array[stack->top--];
}

// An iterative function to do post order traversal of a given binary tree
void postOrderIterative(struct Node* root)
{
	if (root == NULL)
		return;

	// Create two stacks
	struct Stack* s1 = createStack(MAX_SIZE);
	struct Stack* s2 = createStack(MAX_SIZE);

	// push root to first stack
	push(s1, root);
	struct Node* node;

	// Run while first stack is not empty
	while (!isEmpty(s1)) {
		// Pop an item from s1 and push it to s2
		node = pop(s1);
		push(s2, node);

		// Push left and right children of removed item to s1
		if (node->left)
			push(s1, node->left);
		if (node->right)
			push(s1, node->right);
	}

	// Print all elements of second stack
	while (!isEmpty(s2)) {
		node = pop(s2);
		printf("%d ", node->data);
	}
}

// Driver program to test above functions
int main()
{
	// Let us construct the tree shown in above figure
	struct Node* root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	postOrderIterative(root);

	return 0;
}

