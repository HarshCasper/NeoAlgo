import java.util.Scanner;

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

class LCAofaBST {
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

// Time Complexity : O(n)
// Space Complexity : O(1)

// Sample Test Cases :

// I/P :
// 6
// 60 50 70 30 52 65
// 30 70
// O/P :
// 60

// I/P :
// 6
// 50 40 70 30 41 69 75
// 30 41
// O/P :
// 50
