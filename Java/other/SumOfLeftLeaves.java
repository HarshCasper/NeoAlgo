/*
Sum up left leaves of the tree 

You are given root of the binary tree,
your task is to find the sum of all the leaves
present on the left.
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

public class SumOfLeftLeaves
{
    //function to find the sum of left leaves
    public int sumLeftLeaves(BTNode root)
    {
        //if the root is null then simply return 0
        if(root == null)
        {
            return 0;
        }
        //else if the left node does not have any 
        //child then we add that node to the sum 
        //derived from right side
        else if(root.left != null && root.left.left == null && root.left.right == null)
        {
            return root.left.val + sumLeftLeaves(root.right);
        }
        //else we recursivily call the function for both the sides
        else
        {
            return sumLeftLeaves(root.left) + sumLeftLeaves(root.right);
        }
    }

    //driver code
    public static void main()
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
        System.out.println("Sum of left leaves is : ");
        System.out.print(sumLeftLeaves(root));
        System.out.println(" ");
    }
}

/*
EXAMPLE -- 
INPUT-- 
Enter the values of nodes for tree : 3 9 20 null null 15 7
OUTPUT--
Sum of left leaves is : 24

    3
   / \
  9   20
      / \
    15   7
    SUM = 9 + 15 = 24

TIME COMPLEXITY --> O(log N)
SPACE COMPLEXITY --> O(N) , where N is the number of nodes.
*/
