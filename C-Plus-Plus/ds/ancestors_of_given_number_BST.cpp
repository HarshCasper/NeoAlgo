/*
Given a Binary Search Tree, the program finds the Youngest and Oldest 
member of given two numbers.
Youngest member is the Parent of the given 2 nodes only if they are siblings.
Oldest member is the root node of the BST.
*/

#include<iostream>
using namespace std;

struct BST
{
	int a,count = 0, level = 0; 
	BST *left = NULL;
	BST *right = NULL;
};

//points to the root node
BST *start = NULL; 
int l1,l2;

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

//function to assign level values to corresponding nodes
void level_assign(BST *ptr, int value=0) 
{
	ptr->level = value;
	if(ptr->left != NULL)
		level_assign(ptr->left,value+1);
	if(ptr->right != NULL)
		level_assign(ptr->right,value+1);
}

//returns level of the number
int find_number(BST *ptr,int n) 
{
	if(ptr->a == n)
		return ptr->level;
	else if(n < ptr->a)
		find_number(ptr->left,n);
	else
		find_number(ptr->right,n);
}

//function to print the value of youngest member for given numbers
void Display(BST *ptr, int n1, int n2) 
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
//print the eldest member of Binary Search Tree
		cout<<"\neldest:"<<start->a;	
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

/*
For example:
The sample output screen will be:

Enter number of elements:7

Enter sorted array:
12 34 45 56 67 78 89

a:56    left:34 right:78
a:34    left:12 right:45
a:12
a:45
a:78    left:67 right:89
a:67
a:89

//the program runs for n test cases
Enter number of test cases:3

Enter first number:78

Enter second number:89

eldest:56
youngest:56
Enter first number:12

Enter second number:45

eldest:56
youngest:34

Enter first number:34

Enter second number:78

eldest:56
*/
