/*
  Here is a recursive algorithm In-Order Traversal of a tree. 
*/

import java.util.*;

class Node{
   
   String data;
   Node   left;
   Node   right;
      
   Node(String data){ 
      this.data = data; 
      left      = null; 
      right     = null;
   }

}

class BinaryTree{
   
  Node root = null;
  static void inOrder(Node node){ 
    
     if (node == null){
        return;
     } 
    
     else{
    
        inOrder(node.left);
        System.out.printf("%s ",node.data);
        inOrder(node.right);
     }
   }
}
 
public class InOrderTraversal{
    public static void main(String[] args){
      
         BinaryTree tree              = new BinaryTree();
         Node root                    = new Node("1");
             
            tree.root                 = root;
            tree.root.left            = new Node("2"); 
            tree.root.left.left       = new Node("3"); 
            tree.root.left.left.left  = new Node("4");
            tree.root.left.right      = new Node("5");
            tree.root.right           = new Node("6");
            tree.root.right.right     = new Node("7"); 
            tree.root.left.right.left = new Node("8"); 
            tree.root.right.left      = new Node("9");

         BinaryTree.inOrder(root);
    }
}

/*
    Here is the sample Tree in which we are going to print the data members corresponding to their respective 
    nodes in In-Order Traversal in a recursive manner.
                   1
                   /\  
                  /  \
                 /    \
                /      \    
               2        6            In-Order traversal : 4 3 2 8 5 1 9 6 7
             /   \     / \
            /     \   /   \
           3       5 9     7
          / \     / \
         4  null 8 null

*/
    

