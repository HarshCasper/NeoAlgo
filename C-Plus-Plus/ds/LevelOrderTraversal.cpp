/*


This program is about Traversing elements of a binary Tree in a Level Order way.Here we will enter the values for
the nodes of the tree. 
It will simply print the elements of the tree level by level by simply storing the  
addresses of the nodes in a queue and printing the node whose address is on the front 
,and calling the same function for left and right subtree recursively and the process 
is iterated untill  queue doesn't gets emptied.


*/
#include <iostream>

#include<queue>

using namespace std;

//  Basic Definition of node in a Binary Tree

struct child {
    int data;
    child*LeftPtr;
    child*RightPtr;

    child(int value) {
        data = value;
        LeftPtr = NULL;
        RightPtr = NULL;
    }
};

//  Function to build tree Recursively 

child * buildTree() {
    int d;
    cin >> d;

    if (d == -1) {
        return NULL;
    }

    child*root = new child(d);

    root->LeftPtr = buildTree();

    root->RightPtr = buildTree();

    return root;
}

//  Function for implementing level order traversal using Queue

void levelOrder(child * root) {

    if (root == NULL)
        return;

    queue <child*> q;

    q.push(root);

    while (!q.empty()) {
        child*t = q.front();
        cout << t -> data << endl;

        if (t->LeftPtr)
            q.push(t->LeftPtr);
        if (t->RightPtr)
            q.push(t->RightPtr);

        q.pop();
    }

}

int main() {

    cout << "Enter the values of nodes of the tree: " << endl;

    child*root = buildTree();

    cout << "Level Order Traversal for the following Tree will be:" << endl;

    levelOrder(root);

    return 0;
}

/*  
Output:-
Enter the values of nodes of the tree:
3
4
6
-1
-1
7
-1
-1
5
-1
-1


Level Order Traversal for the following Tree will be:
3
4
5
6
7

Time Complexity:- O(n)
Space Complexity:- O(n) 

*/
