#include <stdio.h>
#include <stdlib.h>

struct node{
	int info;
	struct node* left;
	struct node* right;
};

struct stack_node{
	struct node* node;
	struct stack_node* next;
};

//This function creates a new stack to keep a track of the nodes visited
struct node* create_new_node(int info){

	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->info = info;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

//push, pop and is_empty functions of stack
void push(struct stack_node** top, struct node *node){ 

  	struct stack_node* new_node = (struct stack_node*) malloc(sizeof(struct stack_node));              
  	new_node->node  = node; 
  	new_node->next = (*top);    
  	(*top) = new_node; 

} 
struct node *pop(struct stack_node** TOP) {

  	struct node *res; 
  	struct stack_node *top; 
  	top = *TOP; 
    res = top->node; 
    *TOP = top->next; 
    return res; 

} 
int is_empty(struct stack_node *top) { 

  	if (top == NULL)
  		return 1;
  	return 0;
}

//This function displays the inorder traversal of the binary tree
void inorder_traversal(struct node* head) { 

  	struct node* curr_node = head; 
  	struct stack_node *stk_node = NULL;
  
  	while (true){ 
    if(curr_node !=  NULL){ 
      	push(&stk_node, curr_node);                                                
      	curr_node = curr_node->left;   
    } 
    else{ 
      if (!is_empty(stk_node)){ 
        curr_node = pop(&stk_node); 
        printf("%d, ", curr_node->info); 
        curr_node = curr_node->right; 
      } 
      else
      	//traversal is complete
        return;  
    } 
  }  
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

//Time complexity of the above program : O(n) 
//Space complexity of the above program : O(n)
//(where n is the number of nodes in the tree)

//Sample input : If the nodes from the root till the last leaf node are as follows : [40, 30, 60, 10, 30, 50, 70]
//Sample output : [10, 20, 30, 40, 40, 60, 70]
