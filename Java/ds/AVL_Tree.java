/*
AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot
be more than one for all nodes and if at any time they differ by more than one, rebalancing is done to restore this property.
Each node maintains extra information called a balance factor whose value is either -1, 0 or +1 where balance factor of node
in an AVL tree is the difference between the height of the left subtree and that of the right subtree of that node.
*/

import java.util.*;

public class AVL_Tree {

    private Node root;

    private class Node {
        int data;
        Node left;
        Node right;
        int height;

        public Node(int data) {
            this.data = data;
            this.height = 1;
            left = null;
            right = null;
        }
    }

    // Inserting node in a tree
    public void insert(int num) {
        this.root = insert(this.root, num);
    }

    // Inorder Traversal
    public void inOrder(Node node) {
        if (node != null) {
            inOrder(node.left);
            System.out.print(node.data + " ");
            inOrder(node.right);
        }
    }

    // Preorder traversal
    public void preOrder(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    // Postorder traversal
    public void postOrder(Node node) {
        if (node != null) {
            postOrder(node.left);
            postOrder(node.right);
            System.out.print(node.data + " ");
        }
    }

    private Node insert(Node node, int num) {

        if (node == null) {
            Node node_new = new Node(num);
            return node_new;
        }

        if (num > node.data) {
            node.right = insert(node.right, num);
        } else if (num < node.data) {
            node.left = insert(node.left, num);
        }

        node.height = Math.max(height(node.left), height(node.right)) + 1;

        int balancefactor = balancefactor(node);

        // L-L Case
        if (balancefactor > 1 && num < node.left.data) {
            return rightRotate(node);
        }

        // R-R Case
        if (balancefactor < -1 && num > node.right.data) {
            return leftRotate(node);
        }

        // L-R Case
        if (balancefactor > 1 && num > node.left.data) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        // R-L Case
        if (balancefactor < -1 && num < node.right.data) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }
        return node;
    }

    // Finding height of the node
    private int height(Node node) {
        if (node == null) {
            return 0;
        }
        return node.height;
    }

    // Balance Factor (difference between the height of the left subtree and that of the right subtree of the node)
    private int balancefactor(Node node) {
        if (node == null) {
            return 0;
        }

        return height(node.left) - height(node.right);
    }

    //Right rotation
    private Node rightRotate(Node node) {

        Node node1 = node.left;
        Node node2 = node.left.right;

        node1.right = node;
        node.left = node2;

        node.height = Math.max(height(node.left), height(node.right)) + 1;
        node1.height = Math.max(height(node1.left), height(node1.right)) + 1;

        return node1;
    }

    //Left rotation
    private Node leftRotate(Node node) {

        Node node1 = node.right;
        Node node2 = node1.left;

        node1.left = node;
        node.right = node2;

        node.height = Math.max(height(node.left), height(node.right)) + 1;
        node1.height = Math.max(height(node1.left), height(node1.right)) + 1;

        return node1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        AVL_Tree tree = new AVL_Tree();
        System.out.println("Enter the number of nodes: ");
        int num = sc.nextInt();

        System.out.println("Enter the value of nodes: ");
        for (int i = 0; i < num; i++) {
            int value = sc.nextInt();
            tree.insert(value);
        }

        System.out.println("Preorder display: ");
        tree.preOrder(tree.root);
        System.out.println("\n\nInorder display: ");
        tree.inOrder(tree.root);
        System.out.println("\n\nPostorder display: ");
        tree.postOrder(tree.root);

    }
}

/*

Enter the number of nodes: 
10
Enter the value of nodes: 
10
20
40
30
80
60
50
44
22
18
Preorder display: 
40 20 10 18 30 22 60 50 44 80

Inorder display:
10 18 20 22 30 40 44 50 60 80

Postorder display:
18 10 22 30 20 44 50 80 60 40

--------------------------------
Space Complexity :
 O(n) in all the cases

Time Complexity :
 O(log n) in all the cases

*/
