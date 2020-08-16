package Binary_Tree;

import java.util.Scanner;

public class Binary_Tree {
    private Node root;
    private int size;
    Scanner s=new Scanner(System.in);
    
    public Binary_Tree(){
        root=takeInput(null,false);
    }

    public Node takeInput(Node parent,Boolean isleftorright){
        if(parent==null){
            System.out.println("Enter the value of root node");
        }
        else {
            if(isleftorright){
                System.out.println("enter the value of left child of "+parent.value);
            }
            else {
                System.out.println("enter the value of right child "+parent.value);
            }
        }
        int value=s.nextInt();
        Node node=new Node(value,null,null);
        boolean choice;
        System.out.println("Do you have left child of "+node.value);
        choice=s.nextBoolean();
        if(choice){
            node.left=takeInput(node,true);
        }

        System.out.println("Do you have right child of "+node.value);
        choice=s.nextBoolean();
        if(choice){
            node.right=takeInput(node,false);
        }
        System.out.println("Do you want tree traversal ");
        boolean chose = s.nextBoolean();
        if(chose){
            traversal();
        }
        return node;
    }
    public void traversal()
    {
        System.out.println("Enter 1 for preorder traversal or enter 2 for postorder traversal ");
        int option = s.nextInt();
        switch(option)
        {
            case 1:
            preOrder();
            break;

            case 2:
            postOrder();
            break;
        }

    }

    public void preOrder() {

        preOrder(root);
    }
    public void postOrder(){
        postOrder(root);
    }

    private void preOrder(Node node) {
        if (node == null) {
            return;
        }
        System.out.print(node.value + ",");
        preOrder(node.left);
        preOrder(node.right);
    }
    private void postOrder(Node node) {
        /* input tree 
              1  
            /   \
           2     3
         /  \
        4    5
        */
        if(node == null) {
            return;
        }
        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.value + ",");
        // post order travercal output will be 4 5 2 3 1
    }
    
    private class Node{
        private Node left;
        private Node right;
        private int value;

        private Node(int value, Node left, Node right){
            this.value=value;
            this.left=left;
            this.right=right;
        }
    }
}
