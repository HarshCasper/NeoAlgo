// Iterative Queue based Java program to do level order traversal 
// of Binary Tree 

package practice;

/* importing the inbuilt java classes required for the program */
import java.util.LinkedList;
import java.util.Queue;

/* Class to represent Tree node */
public class Node 
{	
	 int data;
	 Node right,left;
	 
	 public Node(int item) 
	 {
		 data=item;
		 right=left=null;
	 }
}

/* Class to print Level Order Traversal */
public class LevelOrderTraversalInQueue 
{	
	Node root;
	
	/* Given a binary tree. Print its nodes in level order 
    using array for implementing queue  */
	public void printLevelOrder()
	{  Queue<Node> q=new LinkedList<Node>();
	   q.add(root);
       while(!q.isEmpty())
       {
    	  /* poll() removes the present head.*/ 
    	  Node temp=q.poll();
		  System.out.print(temp.data+" ");
		  
		  /*Enqueue left child */
		  if (!((temp.left)==null))
		     q.add(temp.left);
		  
		  /*Enqueue right child */
		  if (!((temp.right)==null))
		     q.add(temp.right);
	   }
	}
    
	public static void main(String args[])  
    { 
        /* creating a binary tree and entering  
         the nodes */
        LevelOrderTraversalInQueue tree_level = new LevelOrderTraversalInQueue(); 
        tree_level.root = new Node(1); 
        tree_level.root.left = new Node(2); 
        tree_level.root.right = new Node(3); 
        tree_level.root.left.left = new Node(4); 
        tree_level.root.left.right = new Node(5); 
  
        System.out.println("Level order traversal of binary tree is - "); 
        tree_level.printLevelOrder(); 
    } 
} 

/*Output is
  Level order traversal of binary tree is - 
  1 2 3 4 5 
*/