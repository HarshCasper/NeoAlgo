/*
Transforms given BST into greater sum tree (GST) where each node contains sum of all nodes greater than that node.
*/

#include<iostream>
using namespace std;

struct BST
{
	int a,count = 0; 
	BST *left = NULL;
	BST *right = NULL;
};

//points to the root node
BST *start = NULL; 

//function to convert array into Binary Search Tree with shortest height
BST *arr_to_BST(int arr[20], int beg, int end) 
{
	BST *ptr;
	
	if(beg <= end)
	{
		ptr = new BST;
		ptr->left = NULL;
		ptr->right = NULL;
		ptr->a = arr[(beg+end)/2];
		int mid = (beg+end)/2;
		ptr->left = arr_to_BST(arr,beg,mid-1);
		ptr->right = arr_to_BST(arr,mid+1,end);	
		return ptr;
	}
	else
		return NULL;
}

//function to print Binary Search Tree
void Display_BST(BST *ptr) 
{
	cout<<"\na:"<<ptr->a;
	
	if(ptr->left != NULL)
		cout<<"\tleft:"<<ptr->left->a;
	
	if(ptr->right != NULL)
		cout<<"\tright:"<<ptr->right->a;
	
	if(ptr->left != NULL)
		Display_BST(ptr->left);
	
	if(ptr->right != NULL)
		Display_BST(ptr->right);
}

//function to convert BST to Greater Sum Tree
int BST_to_GST(BST *ptr=start, int sum = 0)
{
	int temp = 0;
	if(ptr != NULL)
	{
		sum = BST_to_GST(ptr->right,sum);
		temp = ptr->a;
		ptr->a = sum;
		sum = BST_to_GST(ptr->left,sum+temp);
	}
	else
		return sum;	
}

int main()
{
	int n, arr[20];
	cout<<"\nEnter number of elements:"; 
	cin>>n;
	cout<<"\nEnter sorted array:";
	for(int i = 0 ; i < n ; i++)
	{
		cin>>arr[i];
	}
	start = arr_to_BST(arr, 0, n-1);	
	cout<<"\nBinary Search Tree before conversion";
	Display_BST(start);

	BST_to_GST(start);

	cout<<"\nBinary Search Tree after conversion";
	Display_BST(start);

  return 0;
}

/*
Sample I/O:
Enter number of elements:6

Enter sorted array:1 2 3 4 5 6

Binary Search Tree before conversion
a:3     left:1  right:5
a:1     right:2
a:2
a:5     left:4  right:6
a:4
a:6
Binary Search Tree after conversion
a:15    left:20 right:6
a:20    right:18
a:18
a:6     left:11 right:0
a:11
a:0
*/
