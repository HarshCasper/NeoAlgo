package neoAlgo;

/*This is the solution to create a Binary Tree from user inputs taken level wise and to check if that binary tree is a Binary Search tree.This solution works for duplicate input values of nodes as well.

Constraints:
0<= NodeValue <= 10^4
  
Incorrect Approach:
It is not enough to check if the left node of current node is smaller than it and the right node of current node is larger than it respectively.
This approach would't work for the following example which is actually not a Binary Search Tree --
     15
    /   \
  12     28
 /  \
9    24 

Correct Approach:
1. For each node we have to check, if maximum value in its left sub tree is smaller than the respective node value and the minimum value in its right sub tree is larger than the respective node value. 
Time Complexity: O(n^2)
Space Complexity: O(1)
	
2. It is a property of Binary Search Tree that its inorder traversal produces a sorted list in ascending order. By inorder traversal of the tree we store the elements in a list and then check if the list is sorted.
Time Complexity : O(n)
Space Complexity : O(n)
 */



import java.util.*;

//Class which defines the structure of each node in the binary tree
class Node{
	int data;
	Node left,right;
	Node(int data){
		this.data = data;
	}
}

public class CheckBST {

	//Create a binary tree by taking input level wise
	public static Node createBinaryTree() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter root node value or -1 to exit: ");
		int rootData = sc.nextInt();
		Node root=null;
		if(rootData!=-1) {
			
			root = new Node(rootData);
		}
		else {
			sc.close();
			return root;
		}
		Queue<Node> tree = new LinkedList<>();
		tree.add(root);
		while(!tree.isEmpty()) {
			Node temp = tree.remove();
			System.out.print("Enter left  child of " + temp.data +" or -1 if there is no left child: ");
			int leftChild = sc.nextInt();
			// if leftChild is not null 
			if (leftChild != -1) {
				//Create leftChild Node
				Node child = new Node(leftChild);
				tree.add(child);
				/* Create leftChildNode of a frontNode */
				temp.left = child;
			}
			System.out.print("Enter right child of " + temp.data +" or -1 if there is no right child: ");
			int rightChild = sc.nextInt();
			//if rightChild is not null 
			if (rightChild != -1) {
				/* Create rightChild */
				Node child = new Node(rightChild);
				tree.add(child);
				/* Create rightChildNode of a frontNode */
				temp.right = child;
			}
		}
		sc.close();
		return root;
	}
	
	
	//Approach 1:
	//Function to find the maximum element in the Left Sub Tree of any node : Rightmost node with no child
	public static Node maxLST(Node root) {
		if(root==null)
			return root;
		else if(root.right==null)
			return root;
		else
			return maxLST(root.right);
	}
	//Function to find the minimum element in the Right Sub Tree of any node : Leftmost Node with no child
	public static Node minRST(Node root) {
		if(root==null)
			return root;
		else if(root.left==null)
			return root;
		else
			return minRST(root.left);
	}
	//Function to check if a tree is a Binary Search Tree by Approach 1
	public static boolean checkBST1(Node root){
		if(root==null)
			return true;
		//Return false if max element in LST is greater than root
		else if((root.left!=null)&&(maxLST(root.left).data >= root.data))
			return false;
		//Return false if min element in RST is smaller than root
		else if((root.right!=null)&&(minRST(root.right).data <= root.data))
			return false;
		//The subtrees of root should be BSTs as well
		else if((!checkBST1(root.left))||(!checkBST1(root.right)))
			return false;
		else
			return true;
	}
	
	
	//Approach 2:
	static ArrayList<Integer> arr = new ArrayList<Integer>();
	//Function to produce a list by inorder traversal of tree 
	public static void inorder(Node root) {
		if(root==null)
			return;
		inorder(root.left);
		arr.add(root.data);
		inorder(root.right);
	}
	//Function to check if a Binary Tree is a Binary Search Tree by Approach 2
	public static boolean checkBST2(Node root) {
        if(root==null)
            return true;
        boolean check = true;
        inorder(root);
        for(int i=1;i<arr.size();i++){
            if(arr.get(i-1)>=arr.get(i)){
                check = false;
                break;
            }
        }
        return check;
    }
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Node root = createBinaryTree();
		boolean check;
		System.out.println("Checking by Approach 1:");
		check = checkBST1(root);
		if(check==true)
			System.out.println("It is a Binary Search Tree");
		else
			System.out.println("It is not a Binary Search Tree");
		
		
		System.out.println("Checking by Approach 2:");
		check = checkBST2(root);
		if(check==true)
			System.out.println("It is a Binary Search Tree");
		else
			System.out.println("It is not a Binary Search Tree");
	}

	/* Sample Input 1:
	 Enter root node value or -1 to exit: 56
	Enter left  child of 56 or -1 if there is no left child: 26
	Enter right child of 56 or -1 if there is no right child: 200
	Enter left  child of 26 or -1 if there is no left child: 18
	Enter right child of 26 or -1 if there is no right child: 28
	Enter left  child of 200 or -1 if there is no left child: 190
	Enter right child of 200 or -1 if there is no right child: 213
	Enter left  child of 18 or -1 if there is no left child: 12
	Enter right child of 18 or -1 if there is no right child: 24
	Enter left  child of 28 or -1 if there is no left child: 27
	Enter right child of 28 or -1 if there is no right child: -1
	Enter left  child of 190 or -1 if there is no left child: -1
	Enter right child of 190 or -1 if there is no right child: -1
	Enter left  child of 213 or -1 if there is no left child: -1
	Enter right child of 213 or -1 if there is no right child: -1
	Enter left  child of 12 or -1 if there is no left child: -1
	Enter right child of 12 or -1 if there is no right child: -1
	Enter left  child of 24 or -1 if there is no left child: -1
	Enter right child of 24 or -1 if there is no right child: -1
	Enter left  child of 27 or -1 if there is no left child: -1
	Enter right child of 27 or -1 if there is no right child: -1

	Sample Output 1:
	Checking by Approach 1:
	It is a Binary Search Tree
	Checking by Approach 2:
	It is a Binary Search Tree
	 
	 */
	
	/* Sample Input 2: 
	 Enter root node value or -1 to exit: 15
	Enter left  child of 15 or -1 if there is no left child: 12
	Enter right child of 15 or -1 if there is no right child: 28
	Enter left  child of 12 or -1 if there is no left child: 9
	Enter right child of 12 or -1 if there is no right child: 24
	Enter left  child of 28 or -1 if there is no left child: -1
	Enter right child of 28 or -1 if there is no right child: -1
	Enter left  child of 9 or -1 if there is no left child: -1
	Enter right child of 9 or -1 if there is no right child: -1
	Enter left  child of 24 or -1 if there is no left child: -1
	Enter right child of 24 or -1 if there is no right child: -1
	
	Sample Output 2:
	Checking by Approach 1:
	It is not a Binary Search Tree
	Checking by Approach 2:
	It is not a Binary Search Tree
	 
	 */
	
}




 