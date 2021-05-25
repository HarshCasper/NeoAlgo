/*
Is Symmetric Tree

For a given a Binary Tree,
your task is to check whether it is Symmetric or not,
i.e. whether that binary tree is a Mirror image of itself or not.
Like--
    5 
   / \
  2   2
 /     \
3       3
This is a symmetric tree.
*/

import java.util.LinkedList; 
import java.util.Queue; 
import java.io.*;
import java.util.*;

//defining a class for storing nodes of tree
class Node
{
    int value;
    Node left;
    Node right;
    Node(int value)
    {
        this.value = value;
        left=null;
        right=null;
    }
}

class Checksymmetric
{
    // function to return true/false accordingly if the tree is Symmetric or if not
    public static boolean isSymmetric(Node root)
    {
        // If the tree is empty then obviously it is symmtric
        if(root == null)
        {
            return true;
        }
        // Otherwise
        return util(root.left, root.right);
    }

    public static boolean util(Node n1,Node n2)
    {
        // If the trees are empty then they are symmetric
        if(n1 == null && n2 == null)
        {
            return true;
        }
        // If any one is empty then obviously is not equal to that tree
        // and hence not symmetric
        if(n1 == null || n2 == null)
        {
            return false;
        }
        // Otherwise
        return n1.value == n2.value && util(n1.left, n2.right) && util(n1.right, n2.left);
    }
}

//driver code
class Is_symmetric_tree
{
    // Function to build the tree
    static Node buildTree(String str)
    {    
        if(str.length() == 0 || str.charAt(0) == 'N')
        {
            return null;
        }

        String ip[] = str.split(" ");
        // Here we start creating the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Pushing the roots to the queue
        Queue<Node> Treequeue = new LinkedList<>(); 
        Treequeue.add(root);

        // Starting from the second element
        int i = 1;
        while(Treequeue.size() > 0 && i < ip.length)
        {    
            // Fetching and removing front of the queue
            Node currNode = Treequeue.peek();
            Treequeue.remove();
            // Getting current node value from the string
            String currVal = ip[i];
            // If the left child is not null then
            if(!currVal.equals("N"))
            {        
                // Creating left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // And then Pushing it to into the queue
                Treequeue.add(currNode.left);
            }
            i++;

            // For the right child
            if(i >= ip.length)
            {
                break;
            }
            currVal = ip[i];
            // If the right child is not null then
            if(!currVal.equals("N"))
            {
                // Creating right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));
                // And then Pushing it to into the queue
                Treequeue.add(currNode.right);
            }
            i++;
        }
        return root;
    }
    
	public static void main (String[] args) throws IOException
    {
        // Taking input
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the values of nodes for tree : ");
	    String str = br.readLine();
    	Node root = buildTree(str);	
        // For output        
        Checksymmetric g = new Checksymmetric();
        System.out.println("Check for a symmetric tree gives : ");
        if(g.isSymmetric(root) == true)
        {
            System.out.print("Symmetric");
        }
        else
        {
            System.out.print("Not Symmetric");
        }
        System.out.println(" ");
    }
}

/*
EXAMPLE:-
Input--
Enter the values of nodes for tree : 1 2 2 3 4 4 3
Output--
Check for a symmetric tree gives : Symmetric

TIME COMPLEXITY --> O(N)
SPACE COMPLEXITY --> O(N) ; where N is the total number of nodes in the tree
*/
