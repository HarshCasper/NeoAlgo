/*
Trimming Binary Tree

You are given root of the binary search tree 
and the low and high points, your task is to trim the tree
so that all its elements lies in low to high range only.
Trimmimg the tree should not change the relative structure 
of the elements which will remain in the treeYou need to 
return the root of the trimmed binary search tree. 
Note that the root may change depending on the given bounds.
*/

import java.io.*;
import java.util.Scanner;
import java.util.*;

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

public class Trimming_binary_tree
{
    //function to trim the binary tree
    public BTNode trimBinaryTree(BTNode root, int low, int high)
    {
        //we use recursive approach 
        
        //if the root is empty then the root itself is returned
        if (root == null) 
        {
            return root;
        }

        //when BTNode.value will be greater than high 
        //then we know that the trimmed binary tree 
        //would occur to the eft of the node.
        if (root.value > high) 
        {
            return trimBinaryTree(root.left, low, high);
        }

        //similarly, when BTNode.value will be less than 
        //low value, then the trimmed binary tree occurs
        //on the right of the node.
        if (root.value < low) 
        {
            return trimBinaryTree(root.right, low, high);
        }

        //otherwise, we trim both the sides of the 
        //tree
        root.left = trimBinaryTree(root.left, low, high);
        root.right = trimBinaryTree(root.right, low, high);

        //returning the trimmed root
        return root;
    }

    //driver code
    public static void main (String[] args) throws IOException
    {
        // Taking input
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the values of nodes for tree : ");
	    String str = br.readLine();
    	Node root = buildTree(str);
        System.out.println("Enter the value of lower range : ");
        int low = br.nextInt();
        System.out.println("Enter the value of high range : ");
        int high = br.nextInt();

        //for output
        System.out.println("Root of the trimmed binary tree is : ");
        System.out.print(trimBinaryTree(root, low, high));
        System.out.println(" ");
    }
}

/*
EXAMPLE:-
Input--
Enter the values of nodes for tree : 3 0 4 null 2 null null 1
Enter the value of lower range : 1
Enter the value of high range : 3
Output--
Root of the trimmed binary tree is : 3 2 null 1

Input--
Enter the values of nodes for tree : 1
Enter the value of lower range : 1
Enter the value of high range : 2
Output--
Root of the trimmed binary tree is : 1

TIME COMPLEXITY --> O(N)
SPACE COMPLEXITY --> O(N) ; where N is the total number of nodes in the tree
*/
