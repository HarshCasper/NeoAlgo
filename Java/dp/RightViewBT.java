/*
Description:

Implementation of Right side view of Binary Tree

The Right view contains all nodes that are last nodes in their levels. A simple solution 
is to do level order traversal and print the last node in every level.
*/

// Java Code -->

import java.util.*;

class Node
{
    int key;
    Node left = null, right = null;

    Node(int key) {
        this.key = key;
    }
}

public class Right_Side_View_Of_BinaryTree{

	public static Scanner sc=new Scanner(System.in);

	public static Node BuildTree(){

	//user inputs the values in preorder and enters -1 to denote a null node
	int d=sc.nextInt();

	if(d == -1)
		return null;

	//A new node created with value d
	Node root = new Node(d);

	//Recursive call to the left and right child of the root
	root.left = BuildTree();
	root.right = BuildTree();

	return root;
}

    public static void printRightView(Node root)
    {
        // return if the tree is empty
        if (root == null) {
            return;
        }

        // create an empty queue and enqueue the root node
        Queue<Node> queue = new ArrayDeque<>();
        queue.add(root);

        // to store the current node
        Node curr = null;

        // loop till queue is empty
        while (!queue.isEmpty())
        {
            // calculate the total number of nodes at the current level
            int size = queue.size();
            int i = 0;

            // process every node of the current level and enqueue their
            // non-empty right and right child
            while (i++ < size)
            {
                curr = queue.poll();

                // if this is the last node of the current level, print it
                if (i == size) {
                    System.out.print(curr.key + " ");
                }

                if (curr.left != null) {
                    queue.add(curr.left);
                }

                if (curr.right != null) {
                    queue.add(curr.right);
                }
            }
        }
    }

	public static void main(String[] args) {

		Node root = BuildTree();
		printRightView(root);

	}
}

/*
TEST CASES:

For Above test case example
    Output: 1 3 6 8
Note: -1 denote a Null Node for given Input.
1.
Input: 20 4 1 64 -1 -1 -1 8 -1 -1 7 34 -1 32 -1 -1 -1
Output: 20 7 34 32
Explanation: The tree will look like this
		    20		<----
		   /  \
		  4    7	<----
		 / \  / 
		1  8 34  	<----
	       /      \
	      64       32	<----
2.
Input: 10 7 8 -1 -1 9 -1 -1 15 18 -1 -1 19 -1 -1
Output: 10 15 19
Explanation: The tree will look like this
	        10			<----
		   /  \
		  7   15		<----
		 / \  /  \
		8   9 18  19	<----
The TIME COMPLEXITY of above solution is O(N) and
SPACE COMPLEXITY is also O(N) ,where N is the Number of nodes in the Tree.

*/