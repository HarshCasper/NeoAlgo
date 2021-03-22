import java.util.ArrayList;

public class NodetoRootPath {

    public static class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            left = null;
            right = null;
        }
    }

    // to check if the data is present in the tree or not
    public static boolean find(Node node, int data) {
        // write your code here
        if (node == null)
            return false;

        boolean res = node.data == data;
        return res || find(node.left, data) || find(node.right, data);
    }

    static ArrayList<Integer> path = new ArrayList<>();

    public static boolean Helper(Node node, int data) {

        if (node == null)
            return false;

        boolean res = (node.data == data) || Helper(node.left, data) || Helper(node.right, data);
        if (res) {
            path.add(node.data);
        }

        return res;
    }

    public static ArrayList<Integer> node2RootPath(Node node, int data) {
        // write your code here
        path = new ArrayList<>(); // reinitialisation of the arraylist
        Helper(node, data);

        return path;

    }

    public static void main(String[] args) throws Exception {
        Node root = new Node(60);
        root.left = new Node(50);
        root.right = new Node(70);
        root.left.left = new Node(30);
        root.left.right = new Node(52);
        root.right.left = new Node(65);
        root.right.right = new Node(75);
        root.right.left.left = new Node(62);
        root.right.left.right = new Node(68);

        int data = 62;

        boolean found = find(root, data);
        System.out.println(found);
        ArrayList<Integer> path = node2RootPath(root, data);
        System.out.println(path);
    }

}

// O/P:
// true
// [62, 65, 70, 60]

// Time Complexity : O(n) in Worst Case
// Space Complexity : O(1)
