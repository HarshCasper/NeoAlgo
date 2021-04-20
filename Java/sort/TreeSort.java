/*Tree sort is a sorting algorithm that is based on Binary Search Tree data structure.
 It first creates a binary search tree from the elements of the input list
 or array and then performs an in-order traversal on the created binary search
 tree to get the elements in sorted order.
 */

import java.util.*;
import java.lang.*;

class Node{

    int data;
    Node left, right;

    public Node(int data){
        this.data = data;
        left = right = null; //Initially assigning left and right node as null
    }
}

//Tree_Sort Algorithm
class Tree_Sort {
    Node root;

    //Constructor
    Tree_Sort(int value){
        root = new Node(value);
    }

    //Inserting values in a tree
    public Node insert(int value, Node root){

        /*Initially assigning first value
          from the array as root
         */
        if(root == null){
            return new Node(value);
        }

        if(root.data > value){
            //checking if preceding node to left of root is empty
            if(root.left == null){
                root.left = new Node(value);
            }
            insert(value, root.left);
            //Recursive Call for inserting values in left subtree
        }

        if(root.data < value){
            //checking if preceding node to right of root is empty
            if(root.right == null){
                root.right = new Node(value);
            }
            insert(value, root.right);
            //Recursive Call for inserting values in right subtree
        }

        return root;
    }

    //Inorder Traversal of Tree
    public void inOrder(Node root){
        if(root != null){
            inOrder(root.left);
            System.out.print(root.data + " ");
            inOrder(root.right);
        }
    }
}

public class TreeSort {
    public static void main(String[] args) {
        
     int n;
        Scanner sc=new Scanner(System.in);
        System.out.println();

        //Taking Array size from the user
        System.out.print("Enter the size of array: ");
        n=sc.nextInt();

        int[] arr = new int[n];
        System.out.println();

        //taking array input from the user using loop
        System.out.println("Enter the elements of the array: ");
        for(int i=0; i<n; i++)
        {
            arr[i]=sc.nextInt();
        }

        //printing out the array elements using for loop
        System.out.print("\nArray elements (before sorting): ");

        for (int i=0; i<n; i++)
        {
            System.out.print(arr[i] + " ");
        }

        //passing root value for creating Binary tree
        Tree_Sort tree = new Tree_Sort(arr[0]);

        //inserting values in tree
        for(int num : arr){
            tree.insert(num, tree.root);
        }

        //printing sorted array
        System.out.print("Array elements (after sorting): ");
        tree.inOrder(tree.root);
        System.out.println();

    }
}

/*
Sample I/O:

Enter the size of array: 5

Enter the elements of the array: 
12
45
13
2
5

Array elements (before sorting): 12 45 13 2 5 
Array elements (after sorting): 2 5 12 13 45 


Best Case Time complexity - O(NlogN)

Worst Case Time complexity - O(N^2)

Space complexity - O(N)

(here N is the input number)
 */
