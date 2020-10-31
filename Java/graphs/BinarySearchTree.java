package com.company;

public class BinarySearchTree {

    public static void main(String[] args) {
        Tree tree= new Tree();
        tree.insert(34);
        tree.insert(67);
         tree.insert(23);
         tree.insert(98);
         tree.insert(36);
         tree.insert(78);
         tree.transverseInorder();
        System.out.println();
        System.out.println(tree.get(36));
        System.out.println(tree.get(78));
        System.out.println(tree.max());
        System.out.println(tree.min());

    }
}

class TreeNode{
    private final int data;
    private TreeNode leftchild;
    private TreeNode rightchild;

    public TreeNode(int data){
        this.data=data;

    }

public void insert(int value) {
    if (value == data) {
        return;
    }
    if (value < data) {
        if (leftchild == null) {
            leftchild = new TreeNode(value);

        } else {
            leftchild.insert(value);
        }
    } else {
        if (rightchild == null) {
            rightchild = new TreeNode(value);

        } else {
            rightchild.insert(value);

        }
    }
}

//transversal using transcerseInorder

    public void transverseInorder(){
            if (leftchild!=null){
                leftchild.transverseInorder();
            }
        System.out.println("Data =" + data + "," );
            if (rightchild!=null){
                rightchild.transverseInorder();
            }
    }

    // finding minimum value in tree

    public int min(){
        if (leftchild== null){
            return data;
        }
        else
        {
            return leftchild.min();

        }
    }

    //finding max value in tree
    public int max(){
        if (rightchild== null){
            return data;
        }
        else
        {
            return rightchild.max();
        }
    }
    public TreeNode get(int value) {
        if (value == data) {
            return this;

        }
        if (value < data) {
            {
                assert leftchild != null;
                return leftchild.get(value);

            }
        } else {
            if (rightchild != null) {
                return rightchild.get(value);

            }
        }
        return null;
    }

}
class Tree{

    private TreeNode root;
    public void insert(int value){
        if (root== null){
            root=new TreeNode(value);
        }
        else
        {
            root.insert(value);
        }
    }
    public void transverseInorder(){
        if (root!=null){
            root.transverseInorder();
        }
    }
    public TreeNode get(int value){
        if (root!=null){
            return root.get(value);

        }
        return null;

    }
    public int min(){
        if (root==null){
                  return  Integer.MIN_VALUE;
        }
        else {
           return root.min();

        }
    }
    public int max(){
        if (root==null){
            return Integer.MAX_VALUE;
        }
        else {
            return root.max();

        }
    }
}