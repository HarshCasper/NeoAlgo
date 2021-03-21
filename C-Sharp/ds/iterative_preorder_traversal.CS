// C# program to implement iterative
// preorder traversal
using System;
using System.Collections.Generic;

// A binary tree node
public class Node {
	public int data;
	public Node left, right;

	public Node(int item)
	{
		data = item;
		left = right = null;
	}
}

class mine {
	public Node root;

	public virtual void iterativePreorder()
	{
		iterativePreorder(root);
	}

	// An iterative process to print preorder
	// traversal of Binary tree
	public virtual void iterativePreorder(Node node)
	{

		// Base Case
		if (node == null) {
			return;
		}

		// Create an empty stack and push root to it
		Stack<Node> nodeStack = new Stack<Node>();
		nodeStack.Push(root);

		/* Pop all items one by one. Do following
	for every popped item 
	a) print it 
	b) push its right child 
	c) push its left child 
	Note that right child is pushed first so 
	that left is processed first */
		while (nodeStack.Count > 0) {

			// Pop the top item from stack and print it
			Node mynode = nodeStack.Peek();
			Console.Write(mynode.data + " ");
			nodeStack.Pop();

			// Push right and left children of
			// the popped node to stack
			if (mynode.right != null) {
				nodeStack.Push(mynode.right);
			}
			if (mynode.left != null) {
				nodeStack.Push(mynode.left);
			}
		}
	}

	// Driver Code
	public static void Main(string[] args)
	{
		mine tree = new mine();
		tree.root = new Node(10);
		tree.root.left = new Node(8);
		tree.root.right = new Node(2);
		tree.root.left.left = new Node(3);
		tree.root.left.right = new Node(5);
		tree.root.right.left = new Node(2);
		tree.iterativePreorder();
	}
}


