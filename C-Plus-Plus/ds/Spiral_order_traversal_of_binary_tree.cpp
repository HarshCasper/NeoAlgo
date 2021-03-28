/*
We need to traverse the binary tree in spiral order. First row will be traversed from right to left,second from left to right and so on. 
nullptr is pushed into the queue after every level. If we reach nullptr we will print the entire vector(arr) in reverse if flag==0 and forward if flag==1.
After printing we will make the flag reverse and resize the vector to 0. We will keep on doing this process and at the end when the queue becomes empty
we will get the spiral traversal printed.  
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    // constructor
    Node(int x){                
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* Insert(Node* root, int data){

    // make new Node
    if(root == nullptr){                
        root = new Node(data);
        return root;
    }

    else if(data < root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }

    return root;
}

void spiral_level_order(Node * root) {
    if (root == nullptr) return;

    queue < Node * > q;
    vector < int > arr;
    int flag = 0;

    q.push(root);
    q.push(nullptr);

    while (q.empty() == false) {
        Node * temp = q.front();
        q.pop();

        //Printing level when nullptr arrived
        if (temp == nullptr) {

            //Printing in the reverse order
            if (flag == 0) {
                for (auto it = arr.end() - 1; it >= arr.begin(); it--) {
                    cout << * it << " ";
                }
                flag = 1;
            } 
            //Printing in the forward order 
            else {
                for (auto e: arr) {
                    cout << e << " ";
                }
                flag = 0;
            }

            arr.resize(0);

            //To check we have covered entire tree or not
            if (q.size() != 0) q.push(nullptr);
            continue;
        }

        arr.push_back(temp -> data);
        if (temp -> left != nullptr) q.push(temp -> left);
        if (temp -> right != nullptr) q.push(temp -> right);
    }
}

int main() {

    int data;               
    cin >> data;

    Node* root = new Node(data);

    while(true){ 
        cin >> data;
        if(data==-1)break;
        root = Insert(root, data);
    }

    spiral_level_order(root);

    return 0;
}

/*
Input:
      1         <-
       \  
        7       ->
       / \
      9   4     <-
Output:
1 7 4 9
Input:
      1         <-
     / \
    5   7       ->
       / \
      6   4     <-
         / \
        2   3   ->
Output:
1 5 7 4 6 2 3
Time Complexity: O(Nodes)
Space Complexity: O(Nodes)
*/