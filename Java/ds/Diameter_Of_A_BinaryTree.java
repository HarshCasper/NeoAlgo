/* The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
 * This path may or may not pass through the root.
   Time Complexity - O(n) 
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
		
		
		/* Overall height of binary tree  */
		int height = 1 + Math.max(leftSubtree.height, rightSubtree.height);
		
		
		/* Diameter have 3 options - 1) height of leftSubtree + height of rightSubtree */
		int option1 = leftSubtree.height + rightSubtree.height;
		
		/* 2) Diameter of leftSubtree */
		int option2 = leftSubtree.diameter;
		
		/* 3) Diameter of rightSubtree */
		int option3 = rightSubtree.diameter;
		
		/* Overall diameter of binary tree   */
		int diameter = Math.max(option1, Math.max(option2, option3));
		
		Pair<Integer, Integer> output = new Pair<>();
		output.height = height;
		output.diameter = diameter;
		return output;
	}

	public static void main(String[] args) {
		BinaryTreeNode<Integer> root = new BinaryTreeNode<>(1);
		root.left = new BinaryTreeNode<>(2);
		root.right = new BinaryTreeNode<>(3);
		root.left.left = new BinaryTreeNode<>(4);
		root.left.right = new BinaryTreeNode<>(5);
		root.left.left.left = new BinaryTreeNode<>(6);
		root.left.left.right = new BinaryTreeNode<>(7);
		
		System.out.println( heightDiameter(root).diameter);
	}

	
}
