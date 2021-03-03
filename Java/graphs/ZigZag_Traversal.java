import java.util.*;
 
// Binary Tree node
class Node
{
int data;
Node leftChild;
Node rightChild;
Node(int data)
 {
    this.data = data; 
 }
}
 
class BinaryTree {
Node rootNode;
 
// function to print the
// zigzag traversal
void printZigZagTraversal() {
     
    // if null then return
    if (rootNode == null) {
    return;
    }
 
    // declare two stacks
    Stack<Node> currentLevel = new Stack<>();
    Stack<Node> nextLevel = new Stack<>();
 
    // push the root
    currentLevel.push(rootNode);
    boolean leftToRight = true;
 
    // check if stack is empty
    while (!currentLevel.isEmpty()) {
 
    // pop out of stack
    Node node = currentLevel.pop();
     
    // print the data in it
    System.out.print(node.data + " ");
 
    // store data according to current
    // order.
    if (leftToRight) {
        if (node.leftChild != null) {
        nextLevel.push(node.leftChild);
        }
         
        if (node.rightChild != null) {
        nextLevel.push(node.rightChild);
        }
    }
    else {
        if (node.rightChild != null) {
        nextLevel.push(node.rightChild);
        }
         
        if (node.leftChild != null) {
        nextLevel.push(node.leftChild);
        }
    }
 
    if (currentLevel.isEmpty()) {
        leftToRight = !leftToRight;
        Stack<Node> temp = currentLevel;
        currentLevel = nextLevel;
        nextLevel = temp;
    }
    }
   }
}

public class ZigZag_Traversal {
    public static void main(String[] args) 
   {
    BinaryTree tree = new BinaryTree();
    tree.rootNode = new Node(1);
    tree.rootNode.leftChild = new Node(2);
    tree.rootNode.rightChild = new Node(9);
    tree.rootNode.leftChild.leftChild = new Node(7);
    tree.rootNode.leftChild.rightChild = new Node(6);
    tree.rootNode.rightChild.leftChild = new Node(3);
    tree.rootNode.rightChild.rightChild = new Node(4);
 
    System.out.println("ZigZag Order traversal of binary tree is: ");
    tree.printZigZagTraversal();
  }
}

/*
ZigZag Order traversal of binary tree is:
1 9 2 7 6 3 4 
*/
