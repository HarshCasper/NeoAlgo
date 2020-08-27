#include <stdio.h>
#include <stdlib.h>

struct node{
	int info;
	struct node* left;
	struct node* right;
};

//This function creates a new node and alocates memory to it
struct node* create_new_node(int info){

	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->info = info;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

//This function is for displaying the inorder traversal of the binary tree
void inorder_traversal(struct node* head){

	if (head==NULL)
		return;

	inorder_traversal(head->left);

	printf ("%d, ", head->info);

	inorder_traversal(head->right);

}

//driver program
int main(){
	
	struct node* head = create_new_node(40);
	head->left = create_new_node(20);
	head->right = create_new_node(60);
	head->left->left = create_new_node(10);
	head->left->right = create_new_node(30);
	head->right->left = create_new_node(50);
	head->right->right = create_new_node(70);
	inorder_traversal(head);
	return 0;
}

//Time complexity of the above code : O(n) 
//Space complexity of the above code : O(n)
//(where n is the number of nodes in the tree)

//Sample input : If the nodes from the root till the last leaf node are as follows : [40, 30, 60, 10, 30, 50, 70]
//Sample output : [10, 20, 30, 40, 40, 60, 70]

