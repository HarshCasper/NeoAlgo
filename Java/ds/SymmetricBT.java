import java.util.*;

public class SymmetricBT{
    
    public static class Node{ // Node of binary tree
        int data;
        Node left;
        Node right;
    }
    
    public static class Pair{ //Use while constructing binary tree
        Node node;
        int state;
    }
    
    //constructing binary tree through array -> -1 means null value
    public static Node construct(int[] arr){ 
        Stack<Pair> st = new Stack<>();
        
        Pair temp = new Pair();
        Node root = new Node();
        root.data = arr[0];
        temp.node = root;
        temp.state = 1;
        st.push(temp);
        for(int i=1;i<arr.length;i++){
            Pair p = st.peek();
            if(p.state == 1){
                if(arr[i] != -1){
                    Node templeft = new Node();
                    templeft.data = arr[i];
                    p.node.left = templeft;
                    
                    Pair pairleft = new Pair();
                    pairleft.node = templeft;
                    pairleft.state = 1;
                    st.push(pairleft);
                }else{
                    p.node.left = null;
                }
                p.state++;
            }else if(p.state == 2){
                if(arr[i] != -1){
                    Node tempright = new Node();
                    tempright.data = arr[i];
                    p.node.right = tempright;
                    
                    Pair pairright = new Pair();
                    pairright.node = tempright;
                    pairright.state = 1;
                    st.push(pairright);
                }else{
                    p.node.right = null;
                }
                p.state++;
            }else{
                st.pop();
                i--;
            }
        }
        return root;
    }
    
    public static boolean areMirror(Node a, Node b)  //checking Mirror Image of a tree
    { 
        if (a == null && b == null) 
            return true; 
  
        if (a == null || b == null)  
            return false; 

        return a.data == b.data && areMirror(a.left, b.right) && areMirror(a.right, b.left); 
    }

    public static boolean isSymmetric(Node node){ 
        return areMirror(node,node); //Symmetric means mirror image of itself so passing same node two times of same tree 
                                     // to check if binary tree is symmetric or not
    }

    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int []arr = new int[n];
        for(int i=0;i<arr.length;i++){
            arr[i] = scn.nextInt();
        }
        Node node = construct(arr);
        System.out.println(isSymmetric(node));
    }
    
}