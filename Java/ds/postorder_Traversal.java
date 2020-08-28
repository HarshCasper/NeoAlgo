
import java.util.*;
// import java.util.LinkedList; 
// import java.util.Queue; 
class node{
    int value;
    node left;
    node right;

    node(int key)
    {
        value = key;
        left = null;
        right = null;
    }
    node(int key, node left, node right )
    {
        this.value = key;
        this.left = left;
        this.right = right;

    }

}
class stack
{
    node[] array = new node[10000];
    private int top;
    stack()
    {
        top = 0;
    }
    void push(node item)
    {
        array[++top] = item;
    }
    node pop()
    {
        
        int temp  = top;
        --top;
        return array[temp];
    }
    boolean isEmpty()
    {
        if(top == 0)
         return true;
         else
         return false;
    }
}
public class postorder_Traversal {
    node root;
    void postorder_traversal_Iterative()
    {
        stack stack1 = new stack();
        stack stack2 = new stack();
        if(root == null)
        return;
        stack1.push(root);
        while(!stack1.isEmpty())
        {
            node item = stack1.pop();
            stack2.push(item);
            if(item.left!=null)
            {
                stack1.push(item.left);
            }
            if(item.right!=null)
            {
                stack1.push(item.right);
            }
        }
        while(!stack2.isEmpty())
        {
            node item = stack2.pop();
            System.out.print(item.value+" ");
        }
        System.out.print("\n");
    }
    public void postorderRecursive(node root)
    {
        if(root == null)
        return;
        postorderRecursive(root.left);
        postorderRecursive(root.right);
        System.out.print(root.value + " ");
        
    }
    void postorder_traversal_recursive()
    {
        postorderRecursive(root);
    }
    public postorder_Traversal(){
        root=takeInput(null,false);
    }
      node takeInput(node parent,Boolean isleftorright){
          Scanner s = new Scanner(System.in);
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
        node node=new node(value,null,null);
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
        return node;
    }
    
    public static void main(String args[])
    {
    
        postorder_Traversal binaryTree = new postorder_Traversal();
       // tree formed is 
       /*
                 1
               /   \
              2     3 
            /   \  /  \ 
           4     5 6   7
          /      \ /    \
         null null null null
        */
      // this will print postorder traversal of above binary tree iteratively using defined stack class
      binaryTree.postorder_traversal_Iterative();
      // this will print postorder traversal of above binary tree recursively
      binaryTree.postorder_traversal_recursive();
      //post orde traversal of above tree is 
      //    4 5 2 6 7 3 1

        


    }
}