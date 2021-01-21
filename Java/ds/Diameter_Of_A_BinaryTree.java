import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/* The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
 * This path may or may not pass through the root.
 * Time Complexity - O(N) Space Complexity - O(H) 
   where, N is the number of nodes in input binary tree and H is the height of nodes in input binary tree
*/
/* Wrapping up height and a diameter of a binary tree within a single box */
class Pair<T1, T2> {
	public T1 height;
	public T2 diameter;
}

/* Class containing left and right child of current node and key value */
class BinaryTreeNode<T> {
	public int data;
	public BinaryTreeNode<T> left;
	public BinaryTreeNode<T> right;

	BinaryTreeNode(int data) {
		this.data = data;
	}
}

public class Diameter_Of_A_BinaryTree {
	/* Function to find height and diameter of a tree */
	public static Pair<Integer, Integer> heightDiameter(BinaryTreeNode<Integer> root) {

		/* If root is null then height and diameter of a tree is zero */
		if (root == null) {
			Pair<Integer, Integer> output = new Pair<>();
			output.height = 0;
			output.diameter = 0;
			return output;
		}
		/* Getting height and diameter of left Subtree */
		Pair<Integer, Integer> leftSubtree = heightDiameter(root.left);

		/* Getting height and diameter of right Subtree */
		Pair<Integer, Integer> rightSubtree = heightDiameter(root.right);

		/* Overall height of binary tree */
		int height = 1 + Math.max(leftSubtree.height, rightSubtree.height);

		/*
		 * Diameter have 3 options - 1) height of leftSubtree + height of rightSubtree
		 */
		int option1 = leftSubtree.height + rightSubtree.height;

		/* 2) Diameter of leftSubtree */
		int option2 = leftSubtree.diameter;

		/* 3) Diameter of rightSubtree */
		int option3 = rightSubtree.diameter;

		/* Overall diameter of binary tree */
		int diameter = Math.max(option1, Math.max(option2, option3));

		Pair<Integer, Integer> output = new Pair<>();
		output.height = height;
		output.diameter = diameter;
		return output;
	}

	/* Take Input Levelwise */
	public static BinaryTreeNode<Integer> takeInput() {
		Scanner s = new Scanner(System.in);
		/* Use queue to store levelwise input of binary tree (first in first out) */
		Queue<BinaryTreeNode<Integer>> pendingNodes = new LinkedList<>();
		System.out.print("Enter root data: ");
		int rootdata = s.nextInt();
		if (rootdata == -1) {
			s.close();
			return null;
		}
		/* Create a root of binary tree */
		BinaryTreeNode<Integer> root = new BinaryTreeNode<>(rootdata);
		/* Insert root into queue */
		pendingNodes.add(root);
		while (!pendingNodes.isEmpty()) {
			/* Remove first element from the queue */
			BinaryTreeNode<Integer> frontNode = pendingNodes.poll();
			System.out.print("Enter left  child of " + frontNode.data +" : ");
			int leftChild = s.nextInt();
			/* if leftChild is not null */
			if (leftChild != -1) {
				/* Create leftChild */
				BinaryTreeNode<Integer> child = new BinaryTreeNode<>(leftChild);
				pendingNodes.add(child);
				/* Create leftChildNode of a frontNode */
				frontNode.left = child;
			}
			System.out.print("Enter right child of " + frontNode.data +" : ");
			int rightChild = s.nextInt();
			/* if rightChild is not null */
			if (rightChild != -1) {
				/* Create rightChild */
				BinaryTreeNode<Integer> child = new BinaryTreeNode<>(rightChild);
				pendingNodes.add(child);
				/* Create rightChildNode of a frontNode */
				frontNode.right = child;
			}
		}
		s.close();
		return root;
	}
        public static void main(String[] args) {
		BinaryTreeNode<Integer> root = takeInput();
		System.out.println("Diameter of a Binary Tree is " + heightDiameter(root).diameter);
	}
}
/*
  Binary Tree represented as 1 2 3 4 5 -1 -1 6 7 -1 -1 -1 -1 -1 -1 
  Sample Input 1: 
  Enter root data: 1
  Enter left  child of 1 : 2
  Enter right child of 1 : 3
  Enter left  child of 2 : 4
  Enter right child of 2 : 5
  Enter left  child of 3 : -1
  Enter right child of 3 : -1
  Enter left  child of 4 : 6
  Enter right child of 4 : 7
  Enter left  child of 5 : -1
  Enter right child of 5 : -1
  Enter left  child of 6 : -1
  Enter right child of 6 : -1
  Enter left  child of 7 : -1
  Enter right child of 7 : -1
  Sample Output 1: 
  Diameter of a Binary Tree is 4
  
  Binary Tree represented as  1 2 3 4 5 -1 -1 8 -1 -1 6 9 -1 -1 7 -1 -1 -1 -1
  Sample Input 2:  
  Enter root data: 1
  Enter left  child of 1 : 2
  Enter right child of 1 : 3
  Enter left  child of 2 : 4
  Enter right child of 2 : 5
  Enter left  child of 3 : -1
  Enter right child of 3 : -1
  Enter left  child of 4 : 8
  Enter right child of 4 : -1
  Enter left  child of 5 : -1
  Enter right child of 5 : 6
  Enter left  child of 8 : 9
  Enter right child of 8 : -1
  Enter left  child of 6 : -1
  Enter right child of 6 : 7
  Enter left  child of 9 : -1
  Enter right child of 9 : -1
  Enter left  child of 7 : -1
  Enter right child of 7 : -1
  Diameter of a Binary Tree is 6
 */
