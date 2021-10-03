/*
Convert Sorted Array to Binary Search Tree

You are given an array of integers arr[], where 
the elements of the array are sorted in ascending order, 
your task is to convert it to a height balenced binary 
search tree which is a binary tree in which the depth of 
the two subtrees of every node never differs by more than one.
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

public class SortedArrayToBST
{
    //function to convert the sorted array to BST
    public BTNode sortedArrtoBST(int[] arr)
    {
        //if the array is empty then simply return zero
        if(arr == null || arr.length == 0)
        {
            return null;
        }

        //otherwise recursively call the array and then construct the BST
        return constructBST(arr, 0, arr.length - 1);
    }

    //function to construct the BST
    public BTNode constructBST(int[] arr, int left, int right)
    {
        int lftprt = left;
        int rtprt = right;
        //if the left pointer is greater than right pointer 
        //then then simply return
        //this is a kind of check for sorted array
        if(lftprt > rtprt)
        {
            return null;
        }

        //otherwise we go for recursive call
        int mid = lftprt + (rtprt - lftprt) / 2;
        BTNode curr = new BTNode(arr[mid]);
        curr.lftprt = constructBST(arr, lftprt, mid - 1);
        curr.rtprt = constructBST(arr, mid + 1, rtprt);

        //returning the node generated
        return curr;
    }

    //drivers code 
    public static void main (String[] args) throws IOException
    {
        // Taking input
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter the number of elements in array : ");
        int n = br.nextInt();

        int []arr = new int[n];
        System.out.println("Enter the array element in sorted order : ");
        for(int i = 0; i < n; i++)
        {
            arr[i] = br.nextInt();
        }

        //for output
        System.out.println("Binary search tree formed is : ");
        sortedArrtoBST(arr);

        //printing the tree order thus generated
        for(int i = 0; i < n; i++)
        {
           System.out.print(arr[i]);
        }

        System.out.println(" ");
    }
}

/*
EXAMPLES:-

INPUT--
Enter the number of elements in array : 5
Enter the array element in sorted order : -10 -3 0 5 9
OUTPUT--
Binary search tree formed is : 0 -3 9 -10 null 5
     0
    / \
   -3  9
   /   /
 -10   5
It can also be 0 -10 5 null -3 null 9
     0
    / \
  -10  5
    \   \
    -3   9

TIME COMPLEXITY -- > O(N), where N is the number of nodes
SPACE COMPLEXITY --> O(1)
*/     
