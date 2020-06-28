#include<stdio.h>
#include<stdlib.h>
 
typedef struct BST
{
  int data;
  struct BST *left;
  struct BST *right;
}node;
 
node *create();
void insert(node *,node *);
void preorder(node *);
 
int main()
{
  char ch;
  node *root=NULL,*temp;
  
  do
  {
    temp=create();
    if(root==NULL)
      root=temp;
    else  
      insert(root,temp);
      
    printf("Do you want to enter more(y/n)?");
    getchar();
    scanf("%c",&ch);
  }while(ch=='y'|ch=='Y');
  
  printf("Preorder Traversal: ");
  preorder(root);
  return 0;
}
 
node *create()
{
  node *temp;
  printf("Enter data:");
  temp=(node*)malloc(sizeof(node));
  scanf("%d",&temp->data);
  temp->left=temp->right=NULL;
  return temp;
}
 
void insert(node *root,node *temp)
{
  if(temp->data<root->data)
  {
    if(root->left!=NULL)
      insert(root->left,temp);
    else
      root->left=temp;
  }
  
  if(temp->data>root->data)
  {
    if(root->right!=NULL)
      insert(root->right,temp);
    else
      root->right=temp;
  }
}
 
void preorder(node *root)
{
  if(root!=NULL)
  {
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
