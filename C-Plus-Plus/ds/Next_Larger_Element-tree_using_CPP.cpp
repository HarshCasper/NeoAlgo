/*Given a generic tree and an integer n. Find and return the node with the next larger element in the tree
i.e. find a node with a value just greater than n.
Note: Return NULL if no node is present with a value greater than n.
*/

#include<bits/stdc++.h>
using namespace std;

// TreeNode

template < typename T >
  class TreeNode {
    public:
      T data;
    vector < TreeNode < T > * > children;

    TreeNode(T data) {
        this -> data = data;
      }

      ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
          delete children[i];
        }
      }
  };

// take input of tree level wise
// The order is: data for root node, number of children to root node, data of each of child nodes and 
// so on and so forth for each node. The data of the nodes of the tree is separated by space.  
//uncomment cout lines if you want the program to ask again and again about the data that is being given.

TreeNode < int > * takeInputLevelWise() {
  int rootData;
//   cout<<"enter root data"<<endl;
  cin >> rootData;
  TreeNode < int > * root = new TreeNode < int > (rootData);

  queue < TreeNode < int > * > pendingNodes;

  pendingNodes.push(root);
  while (pendingNodes.size() != 0) {
    TreeNode < int > * front = pendingNodes.front();
    pendingNodes.pop();
    int numChild;
//     cout<<"enter number of children of "<<front<<endl;       
    cin >> numChild;
    for (int i = 0; i < numChild; i++) {
      int childData;
//       cout<<"enter "<< i <<" th childdata"<<endl;
      cin >> childData;
      TreeNode < int > * child = new TreeNode < int > (childData);
      front -> children.push_back(child);
      pendingNodes.push(child);
    }
  }

  return root;
}

// function for finding out nextlargest element

TreeNode < int > * getNextLargerElement(TreeNode < int > * root, int x) {

  int min = 0;
  TreeNode < int > * nextnode = NULL;
  if (root == NULL) {
    return root;
  }
  if (root -> data > x) {
    min = root -> data;
    nextnode = root;

  }
  for (int i = 0; i < root -> children.size(); i++) {
    TreeNode < int > * small = getNextLargerElement(root -> children[i], x);
    if (small != NULL) {
      if (nextnode == NULL) {
        nextnode = small;
        min = small -> data;
      } else if (small -> data < min) {
        min = small -> data;
        nextnode = small;
      }
    }
  }

  return nextnode;
}

int main() {
  TreeNode < int > * root = takeInputLevelWise();
  int x;
  cout<<"enter the digit"<<endl;
  cin >> x;
  cout<<"the largest data after" <<x <<"is" <<endl;
  TreeNode < int > * ans = getNextLargerElement(root, x);

  if (ans != NULL) {
    cout << ans -> data;
  }
}

/*

Time Complexity- O(n)
Space Complexity - O(h)
where n is the number of nodes in the tree and h is the height or depth of the tree

Sample Input - 
10 3 20 30 40 2 40 50 0 0 0 0
enter the digit
18

Sample Output-
the largest data after 18 is
20
*/
