/*
    Given a binary tree with unique values, a target node in the binary tree, and an integer value k, print all the nodes
    that are at a distance k from the given target node.

    Sample input : 
        Enter the size of preorder and inorder arrays   :  8
        Enter the elements of preorder traversal array  :  1 2 3 4 8 5 6 7
        Enter the elements of inorder traversal array   :  3 2 8 4 1 6 7 5
        Enter the target node in the binary tree        :  2
        Enter the value of distance K                   :  1

    Sample output : 
        Nodes at a distance K are                       :  3 4 1 

    @author : shankhanil007
    @created : 16-08-2020

*/


#include <iostream>
using namespace std;

// Basic definition of a node in binary tree
class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};


node* buildTree(int *preorder, int *inorder, int start, int end)
{
	static int i = 0;

	//Base Case
	if(start >  end){
		return NULL;
	}

	//Recursive Case
	node* newnode = new node(preorder[i]);

	int index = -1;

	for(int j = start; start <= end; j++)
	{
		if(preorder[i] == inorder[j])
		{
			index = j;
			break;
		}
	}

	i++;

	newnode->left = buildTree(preorder, inorder, start, index-1);
	newnode->right = buildTree(preorder, inorder, index+1, end);

	return newnode;

}



// Function to print the Kth level of the tree starting from a given node
void printKthLevel(node* root, int k)
{
    if(root == NULL)
        return;

    if(k == 0)
    {
        cout<<root->data<<" ";
        return;
    }

    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);

    return;
}


// Function to find the nodes at a distance K from a given node
int printAtDistanceK(node* root, int target, int k)
{
    // base case
    if(root == NULL){
        return -1;
    }

    //reach the target node
    if(root->data == target){
        printKthLevel(root , k);
        return 0;
    }

    // next step - ancestor
    int dl = printAtDistanceK(root->left, target, k);

    if(dl != -1){

        // Again there are 2 cases
        // Ancestor itself or you need to go to the right ancestor
        if(dl+1 == k){
            cout<<root->data<<" ";
        }
        else{
            printKthLevel(root->right, k-2-dl);
        }

        return dl+1;
    }

    // next step - ancestor
    int dr = printAtDistanceK(root->right, target, k);

    if(dr != -1){

        // Again there are 2 cases
        // Ancestor itself or You need to go to the left ancestor
        if(dr+1 == k){
            cout<<root->data<<" ";
        }
        else{
            printKthLevel(root->left, k-2-dr);
        }

        return dr+1;
    }

    //node was not present in left and right subtree
    return -1;
}


int main()
{

	cout<<"Enter the size of preorder and inorder arrays"<<endl;
	int n; cin>>n;
	int preorder[n];

	cout<<"Enter the elements of preorder traversal array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>preorder[i];
	}

	int inorder[n];

	cout<<"Enter the elements of inorder traversal array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>inorder[i];
	}

    int target, k;

    cout<<"Enter the target node in the binary tree"<<endl;
    cin>>target;

    cout<<"Enter the value of distance K"<<endl;
    cin>>k;

    node* root = buildTree(preorder, inorder, 0, n-1);

    cout<<"Nodes at a distance K are : "<<endl;
        printAtDistanceK(root, target, k);

    return 0;
}



