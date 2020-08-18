// Recursive Post-order traversal in C

#include <stdio.h> 
#include <stdlib.h> 

//Creating a structure for a binary tree node containing data, pointer to left and pointer to right
struct node
{
	int data;
	struct node* leftNode;
	struct node* rightNode;
};
// Function to allocate data to a new node and NULL left and right ponters 
struct node* newNode(int data)
{
	struct node* node = (struct node*)  malloc(sizeof(struct node));
	node->data = data;
	node->leftNode = NULL;
	node->rightNode = NULL;

	return(node);
}
//Printing the nodes of a binary tree according to BOTTOM-UP post traversal
void printPostorder(struct node* node)
{
	if (node == NULL)
		return;

	// first recursive call will be on the left subtree 
	printPostorder(node->leftNode);

	// then we will recursively call the right subtree 
	printPostorder(node->rightNode);

	// Then printing the node
	printf("%d ", node->data);
}



//Main function implementing the above functions
int main()
{
	struct node* root = newNode(1);
	root->leftNode = newNode(2);
	root->rightNode = newNode(3);
	root->leftNode->leftNode = newNode(4);
	root->leftNode->rightNode = newNode(5);

	printf("\nPostorder traversal of binary tree is \n");
	printPostorder(root);

	getchar();
	return 0;
}
