// post-order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h> 
#include <stdlib.h> 

// Defining maximum stack size 
#define MAX_SIZE 100 

// Creating a tree node using struct  
struct Node {
	int data;
	struct Node* leftNode, * rightNode;
};

// Stack type 
struct Stack {
	int size;
	int top;
	struct Node** array;
};

// Function to create a new tree node 
struct Node* newNode(int data){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->leftNode = node->rightNode = NULL;
	return node;
}

// Function to create a stack of given size 
struct Stack* createStack(int size){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->size = size;
	stack->top = -1;
	stack->array = (struct Node**)malloc(stack->size * sizeof(struct Node*));
	return stack;
}

// Basic stack operations
int isFull(struct Stack* stack){
	return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack* stack){
	return stack->top == -1;
}

void push(struct Stack* stack, struct Node* node){
	if (isFull(stack))
		return;
	stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack){
	if (isEmpty(stack))
		return NULL;
	return stack->array[stack->top--];
}

// Iterative post order traversal for a binary tree 
void postOrderIterative(struct Node* root){
	if (root == NULL)
		return;

	// Creating  two stacks. The second stack i.e. s2 will hold the final output. 
	struct Stack* stack1 = createStack(MAX_SIZE);
	struct Stack* stack2 = createStack(MAX_SIZE);

	// Function to push root to first stack 
	push(stack1, root);
	struct Node* node;

	// Iterative approach to run the while loop as long as the first stack is not empty 
	while (!isEmpty(stack1)) {
		// Pop an item from s1 and push it to s2 
		node = pop(stack1);
		push(stack2, node);

		// Pushing the left and right children of removed item to s1 
		if (node->leftNode)
			push(stack1, node->leftNode);
		if (node->rightNode)
			push(stack1, node->rightNode);
	}

	// Printing all elements of second stack (The final output of the program) 
	while (!isEmpty(stack2)) {
		node = pop(stack2);
		printf("%d ", node->data);
	}
}

// Main function implementing the above functions to get the final output 
int main(){ 
	struct Node* root = NULL;
	root = newNode(1);
	root->leftNode = newNode(2);
	root->rightNode = newNode(3);
	root->leftNode->leftNode = newNode(4);
	root->leftNode->rightNode = newNode(5);
	root->rightNode->leftNode = newNode(6);
	root->rightNode->rightNode = newNode(7);

	postOrderIterative(root);

	return 0;
}
