//  The function is expected to return the number of edges between two nodes which are farthest from each other in terms of edges


import java.io.*;
import java.util.*;

public class Main {
  public static class Node {          // Node Class
    int data;
    Node left;
    Node right;

    Node(int data, Node left, Node right) {
      this.data = data;
      this.left = left;
      this.right = right;
    }
  }

  public static class Pair {
    Node node;
    int state;

    Pair(Node node, int state) {
      this.node = node;
      this.state = state;
    }
  }

  public static Node construct(Integer[] arr) {       // Function for Conteruction of Binary Tree
    Node root = new Node(arr[0], null, null);
    Pair rtp = new Pair(root, 1);

    Stack<Pair> st = new Stack<>();
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0) {
      Pair top = st.peek();
      if (top.state == 1) {
        idx++;
        if (arr[idx] != null) {
          top.node.left = new Node(arr[idx], null, null);
          Pair lp = new Pair(top.node.left, 1);
          st.push(lp);
        } else {
          top.node.left = null;
        }

        top.state++;
      } else if (top.state == 2) {
        idx++;
        if (arr[idx] != null) {
          top.node.right = new Node(arr[idx], null, null);
          Pair rp = new Pair(top.node.right, 1);
          st.push(rp);
        } else {
          top.node.right = null;
        }

        top.state++;
      } else {
        st.pop();
      }
    }

    return root;
  }

  public static void display(Node node) {
    if (node == null) {
      return;
    }

    String str = "";
    str += node.left == null ? "." : node.left.data + "";
    str += " <- " + node.data + " -> ";
    str += node.right == null ? "." : node.right.data + "";
    System.out.println(str);

    display(node.left);
    display(node.right);
  }

  
  public static class DiaSolver   // Class to help us return the height and diameter of tree to ease Calculation
  {
      int h;
      int dia;
      DiaSolver(int h,int dia)
      {
          this.h=h;
          this.dia=dia;
      }
      
  }

  public static DiaSolver diameter1(Node node) {                  //   Function to calculate Diameter
    if(node==null)
    {
        return new DiaSolver(-1,0);  // if node is null then its height is -1 and diameter is 0
    }
    
    DiaSolver l = diameter1(node.left);   // fuction calling left part
    
    DiaSolver r = diameter1(node.right);  // function calling right part
    
    int d = l.h + r.h + 2;                    // the current diameter is left height + right height + 2
    
    int cdia = Math.max(d,Math.max(l.dia,r.dia)); // calculating current maximum diameter
    
    int ch=Math.max(l.h,r.h)+1;                   // calculating height
    
    return new DiaSolver(ch,cdia);               // return ans in form of DiaSolver 
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    Integer[] arr = new Integer[n];
    String[] values = br.readLine().split(" ");
    for (int i = 0; i < n; i++) {
      if (values[i].equals("n") == false) {
        arr[i] = Integer.parseInt(values[i]);
      } else {
        arr[i] = null;
      }
    }

    Node root = construct(arr);

    int diameter = 0;
    DiaSolver  res = diameter1(root); // function calling
    System.out.println(res.dia);     // prining maximum diameter 
  }

}

/*
Sample Input/Output:
Input: 19
       50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
Output: 6
Time Complexity: O(n) 
*/

/*
Sample Input/Output:
Input: 11
       1 2 4 n n 5 n n 3 n n
Output: 3
Time Complexity: O(n) 
*/
