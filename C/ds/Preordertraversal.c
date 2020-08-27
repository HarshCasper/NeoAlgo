#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct BST{
 int data;
 struct BST *left;
 struct BST *right;
};

struct BST* create();
void insert(struct BST*, struct BST*);
void preorderRecursive(struct BST*);
void preorderIterative(struct BST*);

int main(){
 char ch;
 struct BST *root=NULL, *temp;
 do{
    temp=create();
    if(root==NULL){
        root=temp;
        }
    else  
        insert(root,temp);
    printf("Do you want to enter more data? (y/n) ");
    getchar();
    scanf("%c", &ch);
 }while(ch=='y' || ch== 'Y');
 printf("\nPreorder traversal using recursion\n");
 preorderRecursive(root);
 printf("\nPreorder traversal using iteration\n");
 preorderIterative(root);
 getch();
 return 0;
}

struct BST *create(){
 struct BST *temp;
 printf("Enter data: ");
 temp=(struct BST*)malloc(sizeof(struct BST*));
 scanf("%d", &temp->data);
 temp->left=NULL;
 temp->right=NULL;
 return temp;
}

void insert(struct BST *root, struct BST *temp){
 if(temp->data<root->data){
   if(root->left==NULL){
    root->left=temp;
   }
   else{
    root=root->left;
    insert(root, temp);
   }
 }
 else if(temp->data>root->data){
   if(root->right==NULL){
    root->right=temp;
   }
   else{
    root=root->right;
    insert(root, temp);
   }
 }
}

void preorderRecursive(struct BST *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorderIterative(root->left);
        preorderIterative(root->right);
    }
}

void preorderIterative(struct BST* root)
{
    while(root){
        if(root->left!=NULL){
            struct BST* node = root->left;
			while(node->right && node->right != root){
			    node=node->right;
			}
			if(node->right==root){
				node->right=NULL;
				root=root->right;
			}
			else{
		        printf("%d ", root->data);
				node->right=root;
				root=root->left;
			}
        }
        else{
		    printf("%d ", root->data);
			root=root->right;
        }
    }
}