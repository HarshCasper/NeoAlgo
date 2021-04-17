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
    public int size() {
      return size;
    }

    public void print() {
      for (Node temp = head; temp != null; temp = temp.next) {
        System.out.print(temp.data + " ");
      }
      System.out.println();
    }
  }
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
