/*Solution to check if a binary tree is a Binary Search tree.
This solution works for duplicate input values of nodes as well.

Constraints:
0<= NodeValue <= 10^4
  
Incorrect Approach:
It is not enough to check if the left and right node of current node are smaller and larger than it respectively.
This approach would't work for the following example which is actually not a Binary Search Tree --
     15
    /   \
  12     28
 /  \
9    24 


Correct Approach:
It is a property of Binary Search Tree that its inorder traversal produces a sorted list in ascending order. By inorder traversal of the tree we store the elements in a list and then check if the list is sorted.
Time Complexity : O(n)
Space Complexity : O(n)
 */



import java.util.*;

//Class which defines the structure of each node in the binary tree
class Node {
    int data;
    Node left, right;
    Node(int data) {
        this.data = data;
    }
}
public class CheckBST {
    //Create a binary tree by taking input level wise
    public static Node createBinaryTree() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter root node value or -1 to exit: ");
        int rootData = sc.nextInt();
        Node root = null;
        if (rootData != -1) {
            root = new Node(rootData);
        } else {
            sc.close();
            return root;
        }
        Queue < Node > tree = new LinkedList < > ();
        tree.add(root);
        while (!tree.isEmpty()) {
            Node temp = tree.remove();
            System.out.print("Enter left  child of " + temp.data + " or -1 if there is no left child: ");
            int leftChild = sc.nextInt();
            // if leftChild is not null create and add left child node
            if (leftChild != -1) {
                Node child = new Node(leftChild);
                tree.add(child);
                temp.left = child;
            }
            System.out.print("Enter right child of " + temp.data + " or -1 if there is no right child: ");
            int rightChild = sc.nextInt();
            //if rightChild is not null create and add right child node
            if (rightChild != -1) {
                Node child = new Node(rightChild);
                tree.add(child);
                temp.right = child;
            }
        }
        sc.close();
        return root;
    }

    static ArrayList < Integer > arr = new ArrayList < Integer > ();
    //Function to produce a list by inorder traversal of tree
    public static void inorder(Node root) {
        if (root == null)
            return;
        inorder(root.left);
        arr.add(root.data);
        inorder(root.right);
    }
    //Function to check if a Binary Tree is a Binary Search Tree
    public static boolean checkBST(Node root) {
        if (root == null)
            return true;
        boolean check = true;
        inorder(root);
        for (int i = 1; i < arr.size(); i++) {
            if (arr.get(i - 1) >= arr.get(i)) {
                check = false;
                break;
            }
        }
        return check;
    }
    // The checkBST method Takes Space to Store in order traversal
    // we can optimize the checkBST function by doing the check in inOrderTraversal itself and modifying the lower and upper bounds of values in each recursive call
    // The below method has time Complexity of O(N) and Space Complexity of O(logN) where N are number of nodes
    public static boolean checkBSTOptimized(Node root,int min,int max){
        if(root==null)return true;

        if(root.data <min || root.data>max)return false;

        boolean left=checkBSTOptimized(root.left,min, root.data);
        boolean right=checkBSTOptimized(root.right,root.data,max);

        return left && right;
    }

    public static void main(String[] args) {
        Node root = createBinaryTree();
        boolean check;
//        check = checkBST(root);
          check= checkBSTOptimized(root,Integer.MIN_VALUE,Integer.MAX_VALUE);
        if (check == true)
            System.out.println("It is a Binary Search Tree");
        else
            System.out.println("It is not a Binary Search Tree");
    }
}
/* Sample Input :
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

Sample Output :
It is not a Binary Search Tree

Time Complexity : O(n)
Space Complexity : O(n)
Space Complexity of Optimized method O(logN)
*/
