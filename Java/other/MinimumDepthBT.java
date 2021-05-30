/*
Minimum Depth Binary Tree

You are provided a binary tree, your task is
to find the minimum depth of tree, which is the 
number of nodes along the shortest path from the
root node down to the nearest leaf node.
Note that the path must end on a leaf node.
*/

import java.io.*;
import java.until.*;
 
//defining a class for storing nodes of tree
class BTNode 
{
    int value;
    BTNode left;
    BTNode right;
    BTNode() 
    {}
    BTNode(int value) 
    {
        this.value = value; 
    }
    BTNode(int value, BTNode left, BTNode right) 
    {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class MinimumDepthBT
{
    //function that calculates the minimum depth
    int minDepth(BTNode root)
    {
        //for no root obviously the depth is zero 
        //because no root
        if(root == null){
            return 0;
        }

        //for just leaf node, the depth will be obviously 1,
        //because just one node is present which is the leaf node
        if(root.left == null && root.right)
        {
            return 1;
        }

        //if left node is not null, recursively call minDepth to 
        // get leftDepth, else set leftDepth to MAX_VALUE
        int leftDepth = root.left != null ? minDepth(root.left) : Integers.MAX_VALUE;
        
        //if left node is not null, recursively call minDepth to 
        // get leftDepth, else set rightDepth to MAX_VALUE
        int rightDepth = root.right != null ? minDepth(root.right) : Integers.MAX_VALUE;

        return 1 + Math.min(leftDepth, rightDepth);
    }

    //drivers code.
    public static void main (String[] args) throws IOException
    {
        // Taking input
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the values of nodes for tree : ");
	    String str = br.readLine();

        String ip[] = str.split(" ");
        // Here we start creating the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Pushing the roots to the queue
        Queue<Node> Treequeue = new LinkedList<>(); 
        Treequeue.add(root);

        //for output
        System.out.println("Minimum height obtained is : ");
        System.out.print(minDepth(root));
        System.out.println(" ");
    }
} 

/*
EXAMPLE:--
INPUT--
Enter the values of nodes for tree : 3 9 20 null null 15 7
OUTPUT--
Minimum height obtained is : 2

    3
   / \
  9   20
     /  \
    15   7  

TIME COMPLEXITY -- > O(N)

SPACE COMPLEXITY -- > O(N), where N is the number of nodes
*/
