/*
Problem Statement:

Given a binary tree, we need to find the Level Order Traversal of it.
This is also called as Breadth first search of the binary tree.

BFS - Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. 
It starts at the tree root and explores the neighbor nodes first, before moving to the next level neighbors left to right.

Input:

1. number of nodes in the binary tree
2. nodes of the binary tree

Output:

Level order traversal of all nodes of the binary tree.
*/

import java.util.*;
import java.io.*;
import java.lang.*;

class Node
{
	int key;
	Node left = null, right = null;

	Node(int key) {
		this.key = key;
	}
}

class Main
{
	// Function to print all nodes of a given level from left to right
	public static boolean printLevel(Node root, int level)
	{
		// base case
		if (root == null) {
			return false;
		}

		if (level == 1)
		{
			System.out.print(root.key + " ");

			// return true if at least one node is present at a given level
			return true;
		}

		boolean left = printLevel(root.left, level - 1);
		boolean right = printLevel(root.right, level - 1);

		return left || right;
	}

	// Function to print level order traversal of a given binary tree
	public static void levelOrderTraversal(Node root)
	{
		// start from level 1 — till the height of the tree
		int level = 1;

		// run till `printLevel()` returns false
		while (printLevel(root, level)) {
			level++;
		}
	}
    
    public static Node insert(Node root, int data) {
         if(root == null) {
             return new Node(data);
         } else {
             Node curr;
             if(data <= root.key) {
                 curr = insert(root.left, data);
                 root.left = curr;
             } else {
                 curr = insert(root.right, data);
                 root.right = curr;
            }
             return root;
         }
     }

	public static void main(String[] args)
	{
        Scanner sc = new Scanner(System.in);
         System.out.println("Enter number of nodes:");
         int t = sc.nextInt();
         System.out.println("Enter nodes:");
         Node root = null;
         while(t-- > 0) {
             int data = sc.nextInt();
             root = insert(root, data);
         }
         System.out.println("The level order Traversal (BFS) of binary tree is: ");
         levelOrderTraversal(root);
         sc.close();
     }	
}

/*

 Sample Input                  Input:      
      4                        Enter no of nodes : 5             
     / \                       Enter nodes : 4 8 6 2 7
    2   8  
       /                      Output:
      6                       The level order Traversal (BFS) of binary tree is: 
       \                      4 2 8 6 7 
        7                
      
 Sample Output
 4 2 8 6 7
 
*/
