#include<iostream>        
#include<queue>
#include <vector>
using namespace std;      

/*
    DESCRIPTION:
        Tree operations:
        1. Build Tree function implementation - level wise
        2. Height of tree
        3. Count total nodes present in tree
        4. preorder, postorder and levelorder traversal
*/

//Implement Tree Data Structure Node
class TreeNode{
	public:
	int data;                       // data present in TreeNode
	vector<TreeNode*> children;     // vector containing all the children of a TreeNode

	TreeNode(int data) {
		this->data = data;
	}

};

//Build Tree function implementation - level wise
TreeNode* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode* root = new TreeNode(rootData);

	queue<TreeNode*> remainingNodes;
	
	remainingNodes.push(root);
	while (remainingNodes.size() != 0) {
		TreeNode* front = remainingNodes.front();
		remainingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode* child = new TreeNode(childData);
			front->children.push_back(child);
			remainingNodes.push(child);
		}
	}
	return root;
}

// Height of tree
int height(TreeNode* root) {
    int max=0;
    for(int i=0;i<root->children.size();i++){
        int childheight=height(root->children[i]);
        if(childheight>max)
            max=childheight;
    }
    return max+1;
}

// counts total nodes present in tree
int countNodes(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int ans = 1;
	for (int i = 0; i < root->children.size(); i++) {
		ans += countNodes(root->children[i]);
	}
	return ans;
}

// preorder traversal
void preOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	for (int i = 0; i < root->children.size(); i++) {
		preOrder(root->children[i]);
	}
}

// post order traversal
void postOrder(TreeNode* root) {

    if(root==NULL)
        return;
    
    for(int i=0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}

// level order traversal
void printTree(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}
//Driver Funtion
int main(){
    cout<<"INPUT\n";
	TreeNode* root = takeInputLevelWise();
    cout<<"Level order traversal with detailed info on children\n";
	printTree(root);
    cout<<"Height of tree is "<<height(root)<<"\n";
    cout<<"Total number of nodes present is "<<countNodes(root)<<"\n";
    cout<<"Preorder traversal is:\n";
    preOrder(root);
    cout<<"\n";
    cout<<"Postorder traversal is:\n";
    postOrder(root);
    cout<<"\n";
}