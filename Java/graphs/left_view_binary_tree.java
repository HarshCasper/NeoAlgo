/*
Left view of binary tree

Given a binary tree, print the nodes in top to bottom manner as visible from left of the tree.
Input is given in order of root, left child then right child(Inorder traversal). 
For e.g. 1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
Tree looks like 
              1
          /      \
      2           3
    /     \       /
  4       5     6
   
nodes '3', '5' and '6' will be overlapped by '2' and '4' as seen from left side, 
so when viewed from the left , we would see the nodes 1, 2 and 4 only.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

// A class to create a node with left and right as childs and val as the key value of that node
class node {
    int val;
    node left;
    node right;

    public node(int d) {
        val = d;
        left = null;
        right = null;
    }
};

class BinaryTree {
    // "maxlev" is used so that we can differentiate if the left node is of next level or of same level
    static int maxlev = -1;
    Scanner sc = new Scanner(System.in);

    public BinaryTree() {
        node root = null;
    }

    // A function which creates the binary tree and input the respective nodes using queue
    public node maketree() {
        Queue<node> q = new LinkedList<node>();
        int d = sc.nextInt();
        node root = new node(d);
        q.add(root);
        while (!q.isEmpty()) {
            node temp = q.peek();
            q.poll();
            int l = sc.nextInt();
            int r = sc.nextInt();
            if (l != -1) {
                temp.left = new node(l);
                q.add(temp.left);
            }
            if (r != -1) {
                temp.right = new node(r);
                q.add(temp.right);
            }
        }
        return root;
    }

    public void leftview(node root) {
        printleft(root, 0);
    }

    // A function to print the left view of the binary tree
    static void printleft(node root, int lev) {
        if (root == null)
            return;
        // if the left child node is of new level then print the node and update the maxlev
        if (maxlev < lev) {
            System.out.print(root.val + " ");
            maxlev = lev;
        }

        printleft(root.left, lev + 1);
        printleft(root.right, lev + 1);
        return;
    }

    // Driver function
    public static void main(String[] args) throws java.lang.Exception {
        BinaryTree tree = new BinaryTree();
        System.out.println("Enter values of binary tree: ");
        node root = tree.maketree();
        System.out.println("The left view of the binary tree is: ");
        tree.leftview(root);

    }
}

/*
Sample Input:
Enter values of binary tree: 
1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1

Sample Output:
The left view of the binary tree is: 
1 2 4

Time Complexity:  O(n), for traversing the nodes

Space Complexity: O(n), since queue has been used for n nodes
*/
