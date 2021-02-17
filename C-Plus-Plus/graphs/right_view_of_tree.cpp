/*
  This program will print Right view of tree by 
  using the concept of level order traversal  
  with some modification
    
*/
#include <bits/stdc++.h>

using namespace std;

struct node {
  node(int x): data(x), left_child(NULL),
    right_child(NULL) {}
  int data;
  node * left_child;
  node * right_child;
};

class bin_tree {
  node * root;
  int n = 0;
  public:
    // constructor of tree
    bin_tree() {
      root = NULL;
      n = 0;
    }
  void insert_data(int x) {
    //incrase number of element
    n++;
    //if tree is empty
    if (!root) {
      node * tnode = new node(x);
      root = tnode;
    }
    //if tree if not empty
    else {
      node * temp = root;
      while (1) {
        //if data to be inserted is less then the
        //data of current node
        if (x < temp -> data) {
          //if left child of current node is not 
          //present we simple add new node with 
          //the data to be inserted
          if (!temp -> left_child) {
            node * tnode = new node(x);
            temp -> left_child = tnode;
            break;
          }
          //else we change the current node 
          //pointer with pointer of left child 
          //node pointer
          else
            temp = temp -> left_child;
        }
        //if data to be inserted is grater then 
        //or equal to the data of current node
        else {
          //if right child of current node is not
          //present we simple add new node with 
          //the data to be inserted
          if (!temp -> right_child) {
            node * tnode = new node(x);
            temp -> right_child = tnode;
            break;
          }
          //else we change the current node 
          //pointer with pointer of left child 
          //node pointer
          else
            temp = temp -> right_child;
        }
      }
    }
  }
  int size() {
    return n;
  }

  void right_view_of_tree();
};

void bin_tree::right_view_of_tree() {
  int enterptr = 0, exitptr = 0;
  node * a[this -> size()];

  if (this -> root)
    a[enterptr++] = this -> root;

  while (enterptr != exitptr) {
    // number of nodes at current level 
    int cn = enterptr - exitptr;

    // Print the righ  most element at the level 
    cout << a[exitptr] -> data << " ";

    // Traverse all nodes of current level  
    for (int i = 1; i <= cn; i++) {
      // Add Rightchild node
      if (a[exitptr] -> right_child)
        a[enterptr++] = a[exitptr] -> right_child;

      // Add leftchild node
      if (a[exitptr] -> left_child)
        a[enterptr++] = a[exitptr] -> left_child;
      // Move to next node
      exitptr++;
    }
  }
}

int main() {
  bin_tree t;
  int n;
  cout << "Enter number of elements in tree: ";
  cin >> n;
  cout << "Enter elements to insert in  tree: ";
  while (n--) {
    int k;
    cin >> k;
    t.insert_data(k);
  }
  cout << "\nRight View of tree:";
  t.right_view_of_tree();
  return 0;
}

/* 
   
    Sample case 1
    Enter number of elements in tree: 8
    Enter elements to insert in  tree: 50 40 60 
    55 30 56 70 45
    Right View of tree : 50 60 70 56
         50                         
      /     \
     /       \
    40        60                    
   /   \     /   \
  /     \   /     \
30    45  55      70                
            \
             \
             56                    
             
.......................................................................
 Sample case 2
    Enter number of elements in tree: 10
    Enter elements to insert in  tree: 50 40 30 
    45 60 55 54 70 42 43
    Right View of tree : 50 60 70 54 43 
            50     
       /         \
      /           \
     /             \
    40             60                    
   /   \         /     \
  /     \       /       \
30    45       55       70                
     /        /        
    /        /          
   42        54        
     \
      \
       43
Time Complexity: O(n) 
Space Complexity: O(n)
        
*/
