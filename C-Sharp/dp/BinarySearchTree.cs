/* Binary search tree(BST) is a rooted binary tree whose internal nodes each store a key greater than all 
the keys in the node's left subtree and less than those in its right subtree. */

using System;

namespace Binary_Search_Tree
{
    public class Node
    {
        public int data;
        public Node left;
        public Node right;
        public Node(int data)
        {
            this.data = data;
            left = null;
            right = null;
        }
    }
    public class BinarySearchTree
    {
        Node root;
        BinarySearchTree()
        {
            root = null;
        }
        public void Insert(int data)
        {
            root = Insert(root, data);
        }
        //Insert New Node in Binary search tree
        public Node Insert(Node root, int data)
        {
            if (root is null)
            {
                Node newNode = new Node(data);
                root = newNode;
                return root;
            }
            if (data < root.data)
            {
                root.left = Insert(root.left, data);
            }
            else if (data > root.data)
            {
                root.right = Insert(root.right, data);
            }
            return root;
        }
        //To limit parameters
        public void Inorder()
        {
            Inorder(root);
        }

        // to perform inorder traversal of BST
        public void Inorder(Node root)
        {
            if (root != null)
            {
                Inorder(root.left);
                Console.WriteLine(root.data);
                Inorder(root.right);
            }
        }
        //To limit parameters
        public void Postorder()
        {
            Postorder(root);
        }

        // to perform postorder traversal of BST
        public void Postorder(Node root)
        {
            if (root != null)
            {
                Postorder(root.left);
                Postorder(root.right);
                Console.WriteLine(root.data);
            }
        }
        //To limit parameters
        public void Preorder()
        {
            Preorder(root);
        }

        // to perform preorder traversal of BST
        public void Preorder(Node root)
        {
            if (root != null)
            {
                Console.WriteLine(root.data);
                Preorder(root.left);
                Preorder(root.right);
            }
        }
        //To limit parameters
        public int FindMin()
        {
            return FindMin(root);
        }
        //To find the min value in BST
        public int FindMin(Node root)
        {
            if(root.left is null)
            {
                return root.data;
            }
            return FindMin(root.left);
        }
        //To limit parameters
        public int FindMax()
        {
            return FindMax(root);
        }
        //To find the max value in BST
        public int FindMax(Node root)
        {
            if (root.right is null)
            {
                return root.data;
            }
            return FindMax(root.right);
        }
        //To search for a specific node in BST
        public Node Find(int data)
        {
            Node current = root;
            while (data != current.data)
            {
                if (data < current.data)
                {
                    current = current.left;
                }
                else
                {
                    current = current.right;
                }
                if (current is null)
                {
                    Console.WriteLine("Node is not found.");
                    return null;
                }
            }
            return current;
        }
        //To limit number of parameters
        public void Delete(int data)
        {
            root = Delete(root, data);
        }
        //To Delete a specific node
        public Node Delete(Node root, int data)
        {
            if (root == null)
                return root;
            //search for the node with the needed value
            if (data < root.data)
                root.left = Delete(root.left, data);
            else if (data > root.data)
                root.right = Delete(root.right, data);
            else
            {
                //for nodes with one or none child
                if (root.left == null)
                    return root.right;
                else if (root.right == null)
                    return root.left;
                //for nodes with two childs get min value in right
                root.data = FindMin(root.right);
                root.right = Delete(root.right, root.data);
            }
            return root;
        }
        public static void Main(String[] args)
        {
            BinarySearchTree BST = new BinarySearchTree();
            BST.Insert(50);
            BST.Insert(30);
            BST.Insert(20);
            BST.Insert(40);
            BST.Insert(70);
            BST.Insert(60);
            BST.Insert(80);

            Console.WriteLine("Inorder traversal");
            BST.Inorder();

            Console.WriteLine("Delete 20");
            BST.Delete(20);
            Console.WriteLine("Inorder traversal");
            BST.Inorder();
            Console.WriteLine("Preorder traversal");
            BST.Preorder();
            Console.WriteLine("Postorder traversal");
            BST.Postorder();
            Console.WriteLine("Min Value:");
            Console.WriteLine(BST.FindMin());
            Console.WriteLine("Max Value:");
            Console.WriteLine(BST.FindMax());



        }
    }
}
/*
Sample Input: 50 30 20 4070 60 80

inorder traversal: 20 30 40 50 60 70 80
Delete Node with data = 20
Inorder traversal: 30 40 50 60 70 80

Preorder traversal
50
30
40
70
60
80
Postorder traversal
40
30
60
80
70
50
Min Value:
30
Max Value:
80

Insersion Time Complexity: O(n)
Insersion Space Complexity: O(n)
Deletion Time Complexity: O(n)
Deletion Space Complexity: O(n)
Searching Time Complexity: O(n)
Searching Space Complexity: O(n)

*/
