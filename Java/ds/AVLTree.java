class Node { 
    int key, height; 
    Node l, r; 
  
    Node(int d) { 
        key = d; 
        height = 1; 
    } 
} 
  
class AVLTree { 
  
    Node root; 
  
    //A function to get height of tree
    int height(Node N) { 
        if (N == null) 
            return 0; 
  
        return N.height; 
    } 
  
// A function to get max of two numbers
    int max(int a, int b) { 
        return (a > b) ? a : b; 
    } 
 
    Node rightRotate(Node y) { 
        Node x = y.l; 
        Node T2 = x.r; 
  
        x.r = y; 
        y.l = T2; 
  
        //height update
        y.height = max(height(y.l), height(y.r)) + 1; 
        x.height = max(height(x.l), height(x.r)) + 1; 
  
        //new root 
        return x; 
    } 

    Node leftRotate(Node x) { 
        Node y = x.r; 
        Node T2 = y.l; 
  
        y.l = x; 
        x.r = T2; 
  
        //height upate
        x.height = max(height(x.l), height(x.r)) + 1; 
        y.height = max(height(y.l), height(y.r)) + 1; 
  
        //new root 
        return y; 
    } 
    int getBalance(Node N) { 
        if (N == null) 
            return 0; 
  
        return height(N.l) - height(N.r); 
    } 
  
    Node insert(Node node, int key) { 
	    
        if (node == null) 
            return (new Node(key)); 
  
        if (key < node.key) 
            node.l = insert(node.l, key); 
        else if (key > node.key) 
            node.r = insert(node.r, key); 
        else
            return node; 
 
        node.height = 1 + max(height(node.l), 
                              height(node.r)); 

        int balance = getBalance(node); 
  
        if (balance > 1 && key < node.l.key) 
            return rightRotate(node); 

        if (balance < -1 && key > node.r.key) 
            return leftRotate(node); 
  
  
        if (balance > 1 && key > node.l.key) { 
            node.l = leftRotate(node.l); 
            return rightRotate(node); 
        } 
  
    
        if (balance < -1 && key < node.r.key) { 
            node.r = rightRotate(node.r); 
            return leftRotate(node); 
        } 
        return node; 
    } 

    Node deleteNode(Node root, int key)  
    {  
  
        if (root == null)  
            return root;  

        if (key < root.key)  
            root.l = deleteNode(root.l, key);  
  
        else if (key > root.key)  
            root.r = deleteNode(root.r, key);  

        else
        {  
            // node with only 1 or no child
            if ((root.l == null) || (root.r == null))  
            {  
                Node temp = null;  
                if (temp == root.l)  
                    temp = root.r;  
                else
                    temp = root.l;  
   
                if (temp == null)  
                {  
                    temp = root;  
                    root = null;  
                }  
                else 
                    root = temp; 
            }  
            else
            {  
    
                Node temp = minValueNode(root.r);  

                root.key = temp.key;  
  
                root.r = deleteNode(root.r, temp.key);  
            }  
        }  
  
        //if the tree has 1 node then return
        if (root == null)  
            return root;  
 
        root.height = max(height(root.l), height(root.r)) + 1;  
  

        int balance = getBalance(root);  

        if (balance > 1 && getBalance(root.l) >= 0)  
            return rightRotate(root);  

        if (balance > 1 && getBalance(root.l) < 0)  
        {  
            root.l = leftRotate(root.l);  
            return rightRotate(root);  
        }  

        if (balance < -1 && getBalance(root.r) <= 0)  
            return leftRotate(root);  
 
        if (balance < -1 && getBalance(root.r) > 0)  
        {  
            root.r = rightRotate(root.r);  
            return leftRotate(root);  
        }  
  
        return root;  
    }  
  
  
    // A  function to print preorder traversal 
    // of the tree. 
    void preOrder(Node node) { 
        if (node != null) { 
            System.out.print(node.key + " "); 
            preOrder(node.l); 
            preOrder(node.r); 
        } 
    } 
  
    public static void main(String[] args) { 
        
        AVLTree tree = new AVLTree();
        //insertion

        tree.root = tree.insert(tree.root, 10); 
        tree.root = tree.insert(tree.root, 20); 
        tree.root = tree.insert(tree.root, 30); 
        tree.root = tree.insert(tree.root, 40); 
        tree.root = tree.insert(tree.root, 50); 
        tree.root = tree.insert(tree.root, 25); 
	    
        System.out.println("Preorder traversal of constructed tree is : "); 
        tree.preOrder(tree.root); 

        //deletion

        tree.root = tree.deleteNode(tree.root, 10);  
        System.out.println("");  
        System.out.println("Preorder traversal after deletion of 10 :");  
        tree.preOrder(tree.root);  

    } 
} 
