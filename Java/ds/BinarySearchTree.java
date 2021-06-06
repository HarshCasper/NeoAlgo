
public class BinarySearchTree {
	
	
	
	class Node{
		int data;
		Node left, right;
		
		Node(int data){
			this.data = data;
			this.left = null;
			this.right = null;
		}
		
		
	}
	
	/*
	 * Inserting a new node to BST with recursion 
	 * @param Node (root node to tree)
	 * @param value to insert
	 */
	public Node insert(Node root, int value) {
		
		if(root==null)
			root = new Node(value);
		
		else {
			
				if(root.data >= value)
					root.left = insert(root.left, value);
				else
					root.right = insert(root.right, value);
			
		}
		
		return root;	
	}
	
	/*
	 * To findPath for given key recursively 
	 * @param Node root node
	 * @param key to find
	 * return String path to node
	 */
	public String findPath(Node root, int key) {
		
		
		if(root!=null) {
			
			String seq = String.valueOf(root.data);
			
			if(key == root.data)
				return seq;
			
			else if(key< root.data) {
				String returnValue = findPath(root.left, key);
				return returnValue.equals("NF")? returnValue : seq+"-->"+returnValue;
			}
			
			else {
				String returnValue = findPath(root.right, key);
				return returnValue.equals("NF")? returnValue : seq+"-->"+returnValue;			}
		}
		
		/*
		 * Return NF if not found
		 */
		return "NF";
	}
	
	
	/*
	 * Find Node with key
	 * @param Node root node
	 * @param key to find
	 * return Node which contains key
	 */
	public Node findNode(Node root, int key) {
		
		if(root!=null) {
			
			//String seq = String.valueOf(root.data);
			
			if(key == root.data)
				return root;
			
			else if(key< root.data) {
				return findNode(root.left,key);
			}
			
			else {
				return findNode(root.right,key);
			}
		}
		
		
		return null;
	}
	
	
	/*
	 * Delete given value from BST
	 * @param Node root node
	 * @param key to delete
	 */
	public Node delete(Node root, int value) {
		
			
		if(root!=null) {
			
			//if key found
			if(root.data == value){
				
				
				if(root.left == null && root.right==null)
					//delete leaf node
					return null;
				
				
				else if(root.left != null && root.right!=null) {
					
					/*
					 * Delete node with 2 child with below steps
					 * find inorder successor of node
					 * replace value in inorder successor to current node
					 * delete inorder successor and assign it's child to right of curr node
					 */
					Integer inorderSuc = minInSubtree(root.right);
					root.data = inorderSuc;
					root.right = delete(root.right, inorderSuc);
					
				}
				else {
					//delete node with one child	
					if(root.left == null)
						return root.right;
					
					else
						return root.left;
					
				}
				
				
			}
			
			//search in left subtree
			else if(root.data > value)
				root.left = delete(root.left, value);
			//search in right subtree
			else
				root.right = delete(root.right, value);
			
			
		}
			
			
		return root;
	}
	
	
	/*
	 * Get min value of given sub tree
	 * @param Node root node of subtree
	 * return integer (min value in sub tree
	 */
	public Integer minInSubtree(Node currNode) {
		
		if(currNode.left == null)
			return currNode.data;
		else
			return minInSubtree(currNode.left);
		
		
	}
	
	
	/*
	 * Print data of current node, data in left node and right node
	 */
	public void printNodeLeftRight(Node node) {
		
		System.out.println("Node->data:- "+node.data);
		if(node.left == null)
			System.out.println("Node->left:- "+ null);
		else
			System.out.println("Node->left:- "+ node.left.data);
		
		if(node.right == null)
			System.out.println("Node->right:- "+ null);
		else
			System.out.println("Node->right:- "+ node.right.data);
		
		
	}
	
	
	/*
	 * Print in order traversal of given tree
	 */
	public void inorderTraversal(Node root) {
		
		
		if(root!=null) {
			
			inorderTraversal(root.left);
			System.out.print(root.data+"\t");
			inorderTraversal(root.right);
		}
		
		
		
	}
	
	public static void main(String[] args) {
		
		
		BinarySearchTree bst = new BinarySearchTree();
		
		Node root = null;
		
		root = bst.insert(root, 10);
		root = bst.insert(root, 20);
		root = bst.insert(root, 5);
		root = bst.insert(root, 1);
		root = bst.insert(root, 9);
		
		System.out.println("##################### PATH FOR EACH ####################");
		
		String seq;
		seq = bst.findPath(root, 10);
		System.out.println("seq for "+10+" is "+seq);
		seq = bst.findPath(root, 20);
		System.out.println("seq for "+20+" is "+seq);
		seq = bst.findPath(root, 5);
		System.out.println("seq for "+5+" is "+seq);
		seq = bst.findPath(root, 1);
		System.out.println("seq for "+1+" is "+seq);
		seq = bst.findPath(root, 9);
		System.out.println("seq for "+9+" is "+seq);

		
		bst.inorderTraversal(root);
		System.out.println("\n");
		System.out.println("\n##################### INORDER FOR AFTER EACH DELETION ####################");
		
		System.out.println("deleting :- 9");
		root = bst.delete(root, 9);
		bst.inorderTraversal(root);
		System.out.println("\n");
		
		System.out.println("deleting :- 5");
		root = bst.delete(root, 5);
		bst.inorderTraversal(root);
		System.out.println("\n");
		
		System.out.println("deleting :- 10");
		root = bst.delete(root, 10);
		bst.inorderTraversal(root);
		System.out.println("\n");
		
		
		
		System.out.println("\n##################### PATH FOR  EACH AFTER DELETION ####################");
		seq = bst.findPath(root, 10);
		System.out.println("seq for "+10+" is "+seq);
		seq = bst.findPath(root, 20);
		System.out.println("seq for "+20+" is "+seq);
		seq = bst.findPath(root, 5);
		System.out.println("seq for "+5+" is "+seq);
		seq = bst.findPath(root, 1);
		System.out.println("seq for "+1+" is "+seq);
		seq = bst.findPath(root, 9);
		System.out.println("seq for "+9+" is "+seq);
		
	
	}

}
