/*Introduction:
Any binary tree can be represented using multiple traversal techniques.One of them is level order traversal.
In this traversal, we print the nodes of a tree,level by level,one after another.
This could be implemented using recursion or queue data structure.
Here,this code is based on the queue data structure.
The binary tree will be traversed from left to right and thus the entries would be kept in a FIFO data structure(Queue).
One by One,the entries of the queue will get printed.
This method is more efficient than the one that is based on recursion.
*/
import java.util.*;
import java.util.Queue;
import java.util.LinkedList;
class Node
{
    int data;
    Node left;
    Node right;
    public Node(int item)
    {
        data = item;
        left = right = null;
    }
}
class BinaryTree
{
    Node root;
    public BinaryTree()
	{
		root = null;
	}
    public Node insert(Node root, int data) 
    {
        if(root == null) 
            return new Node(data);
        else 
        {
            Node curr;
            if(data <= root.data) 
            {
                curr = insert(root.left, data);
                root.left = curr;
            } else 
            {
                curr = insert(root.right, data);
                root.right = curr;
            }
            return root;
        }
    }
}
public class LevelOrderTraversalQueue 
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        BinaryTree b = new BinaryTree();
        System.out.println("Enter the number of nodes of the tree: ");
        int n=sc.nextInt();
        Node root=null;
        System.out.println("Enter the values:");
        for(int i=0;i<n;i++)
        {
            int data = sc.nextInt();
            root = b.insert(root, data);
        }
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);//Adding root in the queue
        System.out.println("Level order traversal is: ");
        while(!q.isEmpty())
        {
            Node t = q.poll();//taking out the present head
            System.out.print(t.data + " ");

            if (t.left != null)//Adding the left child in the queue
            q.add(t.left);

            if (t.right != null)//Adding the right child in the queue 
            q.add(t.right);
        }
}
}
/*
input:
Enter number of nodes:
5
Enter nodes:
8 67 6 90 2

output:
Level order traversal is:
8 6 67 2 90
       8
      / \
     6   67
    /     \
   2       90

Time Complexity: O(n) in worst case.
Space Complexity: O(n) in worst case. 
(where n is number of nodes in the binary tree)
*/

