/*
PROBLEM STATEMENT:
Given a binary tree, the task is to print its top view. Top view of a binary tree is defined 
as the nodes which will be visible if the tree is viewed from the top.
The input for the binary tree is in the form of preorder and entering '-1' denotes a null node.
For example:
Input: 3 4 -1 6 -1 -1 5 1 -1 -1 -1
The above input will have the following structure:
    3
   / \
  4   5
  \   /
   6  1
Output: The top view is: 4 3 5, as these are the nodes that will be visible from the top.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

// A class to create a node
class Node{
	// hor represents the horizonatal distance, root node has 0 hor
	int data, hor;
	Node left, right;
	public Node(int d){
		data = d;
		hor = 0;
		left = null;
		right = null;
	}
}

class BinaryTree {

    Scanner sc = new Scanner(System.in);  
    public BinaryTree(){ 
    	Node root = null; 
    }
    // A function that creates the binary tree and return its root
    public Node BuildTree(){
		int d = sc.nextInt();
		if(d == -1)
			return null;
		Node root = new Node(d);
		root.left = BuildTree();
		root.right = BuildTree();
		return root;
	}
 	// A function to print the top view of the binary tree
    private void TopView(Node root)
    {
        int hor = 0;
        Queue<Node> q = new LinkedList<Node>();
        Map<Integer, Integer> mp = new TreeMap<Integer, Integer>();
 
        if (root == null) {
            return;
        }
        else {
        	root.hor = hor;
            q.add(root);
        }
 
        while (!q.isEmpty()) {
            hor = root.hor;
            if (!mp.containsKey(root.hor)) {
                mp.put(hor, root.data);
            }
 			// On moving left, horizontal distance decrements
            if (root.left != null) {
            	root.left.hor = hor - 1;
                q.add(root.left);
                                  
            }
            // On moving right, horizontal distance increments
            if (root.right != null) {
            	root.right.hor = hor + 1;
                q.add(root.right);
            }
            root = q.poll();
        }
		
        // Printing the top view
        for (Map.Entry<Integer, Integer>entry : mp.entrySet()) {
            System.out.print(entry.getValue() + " ");
        }
    }

    // Driver function
	public static void main (String[] args) throws java.lang.Exception{
		BinaryTree tree = new BinaryTree();
		System.out.println("Enter values in a binary tree:");
		Node root = tree.BuildTree();
		System.out.println("The top view of the given binary tree is:");
		tree.TopView(root);
	}
}

/*
TEST CASE:
1.
Input:
Enter values in a binary tree:
2 4 7 8 -1 -1 -1 5 -1 -1 3 9 -1 6 -1 1 -1 -1 -1
Output:
The top view of the given binary tree is:
8 7 4 2 3 1
Explanation:
The structure of the tree is:
	    2
	  /   \
	 4     3
	/ \   /
       7   5 9
      /       \
     8         6
		\
		 1
Therefore, the nodes visible from the top are: 8 7 4 2 3 1

TIME COMPLEXITY: O(n), due to the traversal of the whole tree, where 'n' denotes the number of nodes in the tree.
SPACE COMPLEXITY: O(n), space due to queue, where 'n' denotes the size of the queue.
*/
