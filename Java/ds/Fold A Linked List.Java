// The function is expected to place last element after 1st element, 2nd last element after 2nd element and so on.
 /*Example 1
1->2->3->4->5
will fold as
1->5->2->4->3 */

/* Example 2
1->2->3->4->5->6
1->6->2->5->3->4 */
// Implement on singly Linked List , using Recurrsion.


import java.io.*;
import java.util.*;

public class Main {
  public static class Node {  // Creating Node for Singly Linked List
    int data;
    Node next;
  }

  public static class LinkedList {    // singly Linked List
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

    public int size() {       // size function
      return size;
    }

    public void display() {                // display function
      for (Node temp = head; temp != null; temp = temp.next) {
        System.out.print(temp.data + " ");
      }
      System.out.println();
    }



    static int c;                       // static variable for ending purpose
    static Node left;                   // static left pointer 

    private void foldHelper(Node node) {   // helper function


        if(node==null)                    // If reached null node simply return
        {
            return;
        }

        foldHelper(node.next);           // else call helper function for next node for placing right pointer at the tail
        if(c==1)                          // c works as flag to check if left pointer and right pointer has crosssed each other
        {
            return;
        }
        else if(left.next==node || left==node)  // if left.next = right node or left == right node 
        {
            node.next=null;                     // this node will be our tail node
            tail=node;
            c=1;                                // shows our work is complete now
            return;
        }

        else                                   // if work left pointer has not crossed right pointer
        { 
            Node nbr = left.next;              // storing the next of left since our new next will be right pointer       
            left.next=node;                    // storing right pointer in the next of left
            node.next=nbr;                     // this can we visualized as simple inserting right pointer between left pointer and its next
            left=nbr;                          // our new left will be its previous next
        }

    }

    public void fold() {             // Fold function
      c=0;
      left=head;                     // initially left pointer will be at head
      foldHelper(head);              // calling helper function for result


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

/*
Sample Input/Output:
Input:  6
        2 4 5 6 7 8 
Output: 2 8 4 7 5 6 
Time Complexity: O(n) 
Space Complexity: O(n) 
*/
