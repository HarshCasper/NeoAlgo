package Binary_Tree;

import java.util.Scanner;

public class Binary_Tree {
    private Node root;
    private int size;


    Scanner s=new Scanner(System.in);
    public Binary_Tree(){

        root=takeInput(null,false);
    }

    public Node takeInput(Node parent,Boolean  isleftorright){
        if(parent==null){
            System.out.println("Enter the value of root node");

=======
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



=======

        System.out.println("Do you have right child of "+node.value);
        choice=s.nextBoolean();
        if(choice){
            node.right=takeInput(node,false);
        }
        return node;
    }


=======

    public void preOrder() {

        preOrder(root);
    }

    private void preOrder(Node node) {
        if (node == null) {
            return;
        }
        System.out.print(node.value + ",");
        preOrder(node.left);
        preOrder(node.right);


    }










=======
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


=======
        }
    }

}
