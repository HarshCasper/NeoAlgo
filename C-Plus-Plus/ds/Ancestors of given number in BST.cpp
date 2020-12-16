#include<iostream>
using namespace std;

struct BST
{
	int a,count = 0, level = 0; 
	BST *left = NULL;
	BST *right = NULL;
};

BST *start = NULL; //points to the root node
int l1,l2;

BST *arr_to_BST(int arr[20], int beg, int end) //function to convert array into Binary Search Tree with shortest height
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

void Display_BST(BST *ptr) //function to print Binary Search Tree
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

void level_assign(BST *ptr, int value=0) //function to assign level values to corresponding nodes
{
	ptr->level = value;
	if(ptr->left != NULL)
		level_assign(ptr->left,value+1);
	if(ptr->right != NULL)
		level_assign(ptr->right,value+1);
}

int find_number(BST *ptr,int n) //returns level of the number
{
	if(ptr->a == n)
		return ptr->level;
	else if(n < ptr->a)
		find_number(ptr->left,n);
	else
		find_number(ptr->right,n);
}

void Display(BST *ptr, int n1, int n2) //function to print the value of youngest member for given numbers
{
	if(n1 < ptr->a && n2 > ptr->a)
	{
		cout<<"\nyoungest:"<<ptr->a;
		return;
	}
	else if(ptr->level == (l1-1) || ptr->level == (l2-1))
	{
		cout<<"\nyoungest:"<<ptr->a;
		return;
	}
	if(ptr->left != NULL && (n1 < ptr->a || n2 < ptr->a))
		Display(ptr->left,n1,n2);
	else if(ptr->right != NULL && (n1 > ptr->a || n2 > ptr->a))
		Display(ptr->right, n1, n2);
}

int main()
{
	int n, arr[20], n1, n2, T;
	cout<<"\nEnter number of elements:"; 
	cin>>n;
	cout<<"\nEnter sorted array:";
	for(int i = 0 ; i < n ; i++)
	{
		cin>>arr[i];
	}
	start = arr_to_BST(arr, 0, n-1);	
	level_assign(start);
	cout<<"\nEnter number of test cases:";
	cin>>T;
	
	Display_BST(start);
	
	while(T--)
	{
		cout<<"\nEnter first number:";
		cin>>n1;
		cout<<"\nEnter second number:";
		cin>>n2;
		l1 = find_number(start,n1);
		l2 = find_number(start,n2);
		cout<<"\neldest:"<<start->a;	//print the eldest member of Binary Search Tree
		if(n1 > n2)
		{
			if(n2 < start->a && n1 > start->a)
				;
			else
				Display(start, n2, n1);
		}
		else
		{
			if(n1 < start->a && n2 > start->a)
				;
			else
				Display(start, n1, n2);
		}
	}
	return 0;
}
