#include<stdlib.h>
#include<stdio.h>
struct Node
{
    int data;
    struct Node *left,*right;
};
struct Node *getNode(int item)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}
void sort(struct Node *root,int arr[],int &i)
{
    if(root!=NULL)
    {
        sort(root->left,arr,i);
        arr[i++]=root->data;
        sort(root->right,arr,i);
    }
}
struct Node *insert(struct Node *node,int data)
{
    if(node==NULL)
        return getNode(data);
    if(data<node->data)
        node->left=insert(node->left,data);
    else if(data>node->data)
        node->right=insert(node->right,data);
        return node;
}
void treeSort(int arr[],int n)
{
    int i=0;
    struct Node *root=NULL;
    root=insert(root,arr[0]);
    for(int i=1;i<n;i++)
        root=insert(root,arr[i]);
    sort(root,arr,i);
}
int main()
{
    int arr[20],n,i;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    treeSort(arr,n);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
        return 0;
}
