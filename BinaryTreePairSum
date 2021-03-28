#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void createVector(BinaryTreeNode<int>* root,vector<int>& v){
    if(root==NULL){
        return;
    }
v.push_back(root->data);
createVector(root->left,v);
createVector(root->right,v);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(root==NULL){
        return;
    }
    vector<int>v;
    createVector(root,v);
    sort(v.begin(),v.end());
    int i=0,j=v.size()-1;
    while(i<j){
        if(v[i]+v[j]==sum){
            cout<<v[i]<<" "<<v[j]<<endl;
            i++;
            j--;
        }
        else if(v[i]+v[j]<sum){
            i++;
        }
        else{
            j--;
        }
    }
