/*Find pair of nodes in the BST which sum to S. BST and an integer(sum) will be given as inputby the user.*/

#include <iostream>
#include <bits/stdc++.h>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}
bool pairHelper(BinaryTreeNode<int> *root, int sum, unordered_set<int> &s)
{
	if(!root)
		return false;

	if(pairHelper(root->left, sum, s))
		return true;

	if(s.find(sum - root->data) != s.end())
	{
		cout << sum - root->data << " " << root->data << "\n";
		
	}
	else
		s.insert(root->data);

	return pairHelper(root->right, sum, s);

}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    
    unordered_set<int> sett;
    if(pairHelper(root, s, sett))
        cout << -1 << endl;

}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}

/*
INPUT:

8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12

OUTPUT:

2 10
5 7

TIME COMPLEXITY: O(N)

*/
