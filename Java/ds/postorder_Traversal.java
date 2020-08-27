
import java.util.*;
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
    postorder_Trevarsal()
    {
        root = null;
    }
    postorder_Trevarsal(int item)
    {
        root = new node(item);
    }
    //postorder traversal iterative
    //static Stack<node> stack1, stack2;
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
    public static void main(String args[])
    {
        postorder_Traversal binaryTree = new postorder_Traversal();
        // forming the binary tree
        binaryTree.root = new node(1);
        binaryTree.root.left = new node(2);
        binaryTree.root.right = new node(3);
        binaryTree.root.left.left = new node(4);
        binaryTree.root.left.right = new node(5);
        binaryTree.root.right.left = new node(6);
        binaryTree.root.right.right = new node(7);
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