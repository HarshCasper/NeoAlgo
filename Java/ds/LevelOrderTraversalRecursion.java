/*
Introduction 
Any binary tree can be represented using multiple traversal techniques.One of them is level order traversal.
In this traversal, we print the nodes of a tree,level by level,one after another.
This could be implemented using recursion or queue data structure.
Here,this code is based on recursion.
There are basically two functions in this code.One prints all nodes at a given level and the other
prints level order traversal considering the subtrees individually.
At the end,it prints the level order traversal of the given binary tree.
*/
import java.util.*;
class Node
{
    int data;
    Node left;
    Node right;
    public Node(int item)
    {
        data = item;
        left = right = null;
    }
}
class BinaryTree
{
    Node root;
    public BinaryTree()
	{
		root = null;
	}
    int height(Node root)
	{
		if (root == null)
		return 0;
		else
		{
			/* calculate height of each subtree individually */
			int lh = height(root.left);
			int rh = height(root.right);
			
			/* the height is the maximum path,theefore,return the larger one */
			if (lh > rh) return(lh+1);
			else return(rh+1);
		}
	}
    void printLevel (Node root ,int level)
	{
        /* if root is null,then the root is the last node,therefore,we end here */
		if (root == null)
			return;

        /* if it is the first level,then print the data */
		if (level == 1)
			System.out.print(root.data + " ");

        /* if the level is not 1, print the left and right subtree individually */
		else if (level > 1)
		{
			printLevel(root.left, level-1);
			printLevel(root.right, level-1);
		}

	}
    void LevelOrderTraversal(Node root)
	{
        /* calculate the height of the tree */
		int h = height(root);
		int i;

        /* traverse till the height */
		for (i=1; i<=h; i++)
			printLevel(root, i);
	}
    public Node insert(Node root, int data) 
    {
        if(root == null) {
            return new Node(data);
        } else {
            Node curr;
            if(data <= root.data) {
                curr = insert(root.left, data);
                root.left = curr;
            } else {
                curr = insert(root.right, data);
                root.right = curr;
           }
            return root;
        }
    }
}
public class LevelOrderTraversalRecursion
{
    public static void main (String[] args)
     {
        BinaryTree b=new BinaryTree();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of nodes:");
        int t = sc.nextInt();
        System.out.println("Enter nodes:");
        Node root = null;
        while(t-- > 0)
        {
            int data = sc.nextInt();
            root = b.insert(root, data);
        }
        System.out.println("Level order traversal is:");
        b.LevelOrderTraversal(root);
    }

}
/*
input:
Enter number of nodes:
5
Enter nodes:
8 67 6 90 2

output:
Level order traversal is:
8 6 67 2 90
       8
      / \
     6   67
    /     \
   2       90

Time Complexity: O(n^2) in worst case.
 
Space Complexity: O(n) in worst case. 
*/

