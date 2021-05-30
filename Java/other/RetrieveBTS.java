/*
Retrieve Binary Search Tree

You are provided with the roots of the binary search tree
where it has been conditionaaly mentioned that
any two of the nodes of the tree are swapped by mistake.
Your task is to recover the original tree without 
changing any any of its configuration.
You have been asked to find a solution without the use of 
extra space i.e. constant space.
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

public class RetrieveBST
{
    //function of to recover the changed binary 
    //search tree
    public void retrieveTree(BTNode root){
        if(root == null) 
        {
            return;
        }

        BTNode previous = null;
        BTNode first = null, second = null;

        while(root != null)
        {
            //for no node present at the left side of the tree
            if(root.left == null)
            {
                //we print root
                if(previous != null && previous.value > root.value)
                {
                    if(first == null)
                    {
                        first = previous;
                    }
                    second = root;
                }
                previous = root;

                root = root.right;
            }
            else
            {
                BTNode temp = root.left;
                while(temp.right != null && temp.right != root)
                {
                    temp = temp.right;
                }

                if(temp.right == null)
                {
                    //then we move to extreme left
                    temp.right = root;
                    //moving to left
                    root = root.left;
                }
                else
                {
                    temp.right = null;
                    //we print root
                    if(previous != null && previous.value > root.value)
                    {
                        if(first == null)
                        {
                            first = previous;
                        }
                        second = root;
                    }
                    previous = root;

                    root = root.right;
                }
            }
        }
        int temp = first.value;
        first.value = second.value;
        second.value = temp;
    }

    void printNode(BTNode node)
    {
        if(node == null)
        {
            return;
        }
        printNode(node.left);
        System.out.print(" "+node.value);
        printNode(node.right);
    }

    //driver code
    public static void main (String[] args) throws IOException
    {
        // Taking input
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the values of nodes for tree : ");
	    String str = br.readLine();
    	Node root = buildTree(str);

        //for output
        if(str.length() == 0 || str.charAt(0) == 'N')
        {
            return(System.out.println("Null"));
        }

        String ip[] = str.split(" ");
        // Here we start creating the root of the tree
        BTNode root = new BTNode(Integer.parseInt(ip[0]));
        
        retrieveTree(root);
        System.out.println("Retrieved tree is : ");
        printNode(root);
    }   
}

/*
EXAMPLE:--
INPUT--
Enter the values of nodes for tree : 1 3 N N 2
OUTPUT--
Retrieved tree is : 3 1 N N 2

  1              3
 /              /
3        -->   1
 \              \
  2              2

TIME COMPLEXITY -- > O(N), where N is the number of nodes
SPACE COMPLEXITY -- > O(1)
*/
