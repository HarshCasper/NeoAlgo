/* 
    Progam to find the Least Common Ancestor in a Binary Search Tree
    1. We are given a partially written BST class.
    2. We are required to complete the body of lca function. "lca" function is expected to find the lowest commong ancestor of d1 and d2.
*/
import java.io.*;
import java.util.*;
import java.util.Scanner;

//This class can be used as a reference to create a new Node in a Binary Tree
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

// this class contains functions that will help find out the Least Common Ancestor in a Binary Search Tree
class LCAofaBST {
    // function to find out the Least Common Ancestor in a Binary Search Tree
    public static Node lca(Node root, int d1, int d2) {
        // Write your code here.
        if (d1 > root.data && d2 > root.data) {
            return lca(root.right, d1, d2);
        } else if (d1 < root.data && d2 < root.data) {
            return lca(root.left, d1, d2);
        } else {
            return root;
        }
    }
    // function to insert nodes in a binary search tree , does navigation also along the way
    public static Node insertNode(Node root, int data) {
        if (root == null) {
            return new Node(data);
        } else {
            Node curr;
            if (data <= root.data) {
                curr = insertNode(root.left, data);
                root.left = curr;
            } else {
                curr = insertNode(root.right, data);
                root.right = curr;
            }
            return root;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        Node root = null;
        while (t-- > 0) {
            int data = sc.nextInt();
            root = insertNode(root, data);
        }
        int target1 = sc.nextInt();
        int target2 = sc.nextInt();
        sc.close();
        Node ans = lca(root, target1, target2);
        System.out.println(ans.data);
    }
}

/*
    Time Complexity : O(n)
    Space Complexity : O(1)


    Sample Test Cases :

    I/P :
    6
    60 50 70 30 52 65
    30 70
    O/P :
    60

    I/P :
    6
    50 40 70 30 41 69 75
    30 41
    O/P :
    50

*/
