/*
Sum up root to the leaf number

You are provided with the roots of the binary tree
that contains digits from 0 to 9 only.
Each root to leaf path in the tree represents a number.
For example :-
  1
 / \
2   3
has 12 and 13, as numbers forming from the tree.
Your task is to return the total sum of all root to leaf numbers. 
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

public class SumRootToLeaf
{
    //initializing a variable named result to store the final result
    int result;

    //function that sums up the root-to-leaf numbers 
    public int sumNumb(BTNode root)
    {
        //if the root is empty the result returned is  zero
        if(root == null)
        {
            return 0;
        }
        result = 0;
        findSum(root, 0);
        return result;
    }

    //function to find sum
    public void findSum(BTNode root, int value)
    {
        int currentval = value * 10 + root.value;
        //if both the sides of the tree are containing null then 
        //current number formed is added to the result and is simply 
        //returned 
        if(root.left == null && root.right == null)
        {
            result = result + currentval;
            return;
        }

        if(root.left != null)
        {
            findSum(root.left, currentval);
        }

        if(root.right != null)
        {
            findSum(root.right, currentval);
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
        System.out.println("Sum of the root-to-leaf path is : ");
        System.out.print(SumRootToLeaf(root));
        System.out.println(" ");
    }
}

/*
EXAMPLE:-
INPUT--
Enter the values of nodes for tree : 4 9 0 5 1
OUTPUT--
Sum of the root-to-leaf path is : 1026

    4
   / \
  9   0
 / \
5  1
has numbers formed by root-to-leaf iteration is 
495, 491, 40.
So, the sum comes out to be 495 + 491 + 40 = 1026.

TIME COMPLEXITY -- > O(N)
SPACE COMPLEXITY --> O(N) ; where n is no. of roots 
*/
