/*
 This code helps in printing a LinkedList by using addLast function after taking input from the user
*/
import java.io.*;
import java.util.*;

public class printLinkedList {
  
  public static class Node {
    int data;
    Node next;
  }

  public static class LinkedList {
    Node head;
    Node tail;
    int size;

    // Using add last function, the elements will be added to the end of the LinkedList

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

    // Size function returns the size of the LinkedList provided

    public int size() {
      return size;
    }
  //  print function prints the LinkedList

    public void print() {
      for (Node temp = head; temp != null; temp = temp.next) {
        System.out.print(temp.data + " ");
      }
      System.out.println();
    }
  }

  // Here main function is taking suitable input from the user and is printing the LinkedList
  
    public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    LinkedList ll = new LinkedList();
    System.out.println("Enter the no of the elements:");
    int n = sc.nextInt();
    System.out.println("Enter the nos:");
    for(int i=0;i<n;i++){
        int val = sc.nextInt();
       ll.addLast(val);
    }
    ll.print();
    }
}


/*

Sample Input/Output:

Input:
5
10
13
14
15
16

Output:
10 13 14 15 16

Time Complexity: O(n)
Space Complexity:O(1)

*/