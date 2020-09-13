import java.util.*;
import java.util.Stack;
 class Node {
     Node left;
     Node right;
     int data;

     Node(int data) {
         this.data = data;
         left = null;
         right = null;
     }
 }
 class demo{
                //recursive
     public static void preOrderRec(Node root){
         if(root == null)
         return;
         else{
             System.out.print(root.data+" ");
             preOrderRec(root.left);
             preOrderRec(root.right);
         }
     }
                //iterative
   public static void preOrderIte(Node root) {
         if (root == null) { 
             return; 
         } 
         Stack<Node> stack = new Stack<>();
         stack.push(root);
         while (!stack.empty()) {
             Node node = stack.pop();
             if (node != null) {
                 System.out.print(node.data + " ");
                 stack.push(node.right);
                 stack.push(node.left);
             }
         }
    }
 	public static Node insert(Node root, int data) {
         if(root == null) {
             return new Node(data);
         } else {
             Node curr;
             if(data <= root.data) {
                 curr = insert(root.left, data);
                 root.left = curr;
             } else {
                 curr = insert(root.right, data);
                 root.right = curr;
            }
             return root;
         }
     }
     public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         System.out.println("Enter number of nodes:");
         int t = sc.nextInt();
         System.out.println("Enter nodes:");
         Node root = null;
         while(t-- > 0) {
             int data = sc.nextInt();
             root = insert(root, data);
         }
         System.out.print("Recursive approach: ");
         preOrderRec(root);
         System.out.println();
         System.out.print("Iterative approach: ");
         preOrderIte(root);
         sc.close();
     }	
 }
 /*                         
 sample Input                  Input:      
      1                        Enter no of nodes : 6             
       \                       Enter nodes : 1 2 5 3 6 4
        2  
         \                     output:
          5                    1 2 5 3 4 6 
         / \                   
        3   6
         \
          4  
 Sample Output
 1 2 5 3 4 6 
 */ 