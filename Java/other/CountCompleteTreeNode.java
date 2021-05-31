/*
Count Complete Tree Nodes

You are provided the roots of
the complete binary tree, Your task is to 
find out the total numbers of nodes of the complete 
tree and return it.
A complete tree has every level, except the last one, 
completely filled and all nodes in the last level 
are as far left as possible. The total number of nodes, 
lies between 1 to 2^h nodes, inclusive at the last 
level h.
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

public class CountCompleteTreeNode
{
    //fuction to count the nodes of the 
    //complete tree
    public int compTreeNodes(BTNode root)
    {
        //if the root is empty then simply return 0
        if(root == null)
        {
            return 0;
        }

        BTNode left = root, right = root;
        //Initializing two pointers for incrementing level for
        //each side left and right 
        int heightLeft = 0, heightRight =0;

        //for counting nodes on left side
        while(left != null)
        {
            heightLeft++;
            left = left.left;
        }

        //for counting nodes of right side
        while(right != null)
        {
            heightRight++;
            right = right.right;
        }

        //if the pointers are at same level then 
        if(heightLeft == heightRight)
        {
            return (1 << heightLeft) - 1;
        }

        //otherwise we recursively call function 
        //for left and right roots and increment the result 
        //by 1, and return it
        return 1 + compTreeNodes(root.left) + compTreeNodes(root.right);
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
        System.out.println("Total number of nodes in complete tree : ");
        System.out.print(compTreeNodes(root));
        System.out.println(" ");
    }
}

/*
EXAMPLE--
INPUT--
Enter the values of nodes for tree : 1 2 3 4 5 6
OUTPUT--
Total number of nodes in complete tree : 6

    1
   / \
  2   3
 / \  /
4   5 6

TIME COMPLEXITY --> O(logN)
SPACE COMPLEXITY --> O(N), where N is the number of roots.
*/
