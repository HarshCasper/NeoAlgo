/* 
The function is expected to place last element after 1st element, 2nd last element after 2nd element and so on.

Example 1
1->2->3->4->5
will fold as
1->5->2->4->3 

Implement on singly Linked List , using Recurrsion.
 */


import java.io.*;
import java.util.*;

public class Main {
  
  // Creating Node for Singly Linked List
  public static class Node {  
    int data;
    Node next;
  }
  // singly Linked List
  public static class LinkedList {    
    Node head;
    Node tail;
    int size;

    void addLast(int val) {
      Node temp = new Node();
      temp.data = val;
      temp.next = null;

      if (size == 0) {
        head = tail = temp;
      } else {
        tail.next = temp;
        tail = temp;
      }

      size++;
    }
    // size function
    public int size() {       
      return size;
    }
    // display function
    public void display() {                
      for (Node temp = head; temp != null; temp = temp.next) {
        System.out.print(temp.data + " ");
      }
      System.out.println();
    }


    // static variable for ending purpose
    static int c;     
    // static left pointer 
    static Node left;                   

    // helper function
    private void foldHelper(Node node) {   

        // If reached null node simply return
        if(node==null)                    
        {
            return;
        }
        // else call helper function for next node for placing right pointer at the tail
        foldHelper(node.next);
        
        // c works as flag to check if left pointer and right pointer has crosssed each other
        if(c==1)                          
        {
            return;
        }
      
        // if left.next = right node or left == right node
        else if(left.next==node || left==node)   
        {   
            // this node will be our tail node
            node.next=null;                     
            tail=node;
            // shows our work is complete now
            c=1;                                
            return;
        }

        // if work left pointer has not crossed right pointer
        else                                   
        { 
            // storing the next of left since our new next will be right pointer
            Node nbr = left.next;      
            // storing right pointer in the next of left
            left.next=node;    
            // this can we visualized as simple inserting right pointer between left pointer and its next
            node.next=nbr;
            // our new left will be its previous next
            left=nbr;                          
        }

    }

    // Fold function
    public void fold() {             
      c=0;
      // initially left pointer will be at head
      left=head;  
      // calling helper function for result
      foldHelper(head);              


    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n1 = Integer.parseInt(br.readLine());
    LinkedList l1 = new LinkedList();
    String[] values1 = br.readLine().split(" ");
    for (int i = 0; i < n1; i++) {
      int d = Integer.parseInt(values1[i]);
      l1.addLast(d);
    }

    int a = Integer.parseInt(br.readLine());
    int b = Integer.parseInt(br.readLine());

    l1.display();
    l1.fold();
    l1.display();

  }
}

/*
Sample Input/Output:
Input:  5
        1 2 3 4 5
Output: 1 5 2 4 3 
Time Complexity: O(n) 
Space Complexity: O(n) 
*/
