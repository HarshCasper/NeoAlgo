//Java Program to Remove Duplicates from a Unsorted Linked List 
//Without using any Extra Space i.e while finding Duplicates we can't
//use any Data Structure to store values.
//Then we can use two pointers approach :current and runner ,current iterates through the linked list
//and runner check all subsequent nodes for every current and try to find duplicates in the list.

import java.util.*;
//class structure for Linked List
public class RemDupInLLWithoutExtraSpace {
  static Node head;
  class Node {
    public int data;
    public Node next;
    Node(int data) {
      this.data = data;
    }
  }
  
  //insert new node at the beginning
  public void insert_At_beginning(int data) {
    Node ptr = new Node(data);
    if (head != null) {
      ptr.next = head;
      head = ptr;
    } else {
      ptr.next = null;
      head = ptr;
    }
  }

  //check whether a Linked List is empty or not
  public boolean isEmpty() {
    if (head == null)
      return true;
    return false;
  }

  public void display() {
    Node ctr = head;
    if (!isEmpty()) {
      while (ctr != null) {
        System.out.print(ctr.data + " ");
        ctr = ctr.next;
      }
      System.out.println();
    } else {
      System.out.println("List is empty");
    }
  }

  /*
  Two pointers current and runner is used
  current will iterate through the linked list and runner will
  check all the subsequent nodes for duplicates
  */
  public void delete_Duplicates() {
    Node current = head;
    while (current != null) {
      //Remove all future nodes that have the same value
      Node runner = current;
      while (runner.next != null) {
        if (runner.next.data == current.data) {
          runner.next = runner.next.next;
        } else {
          runner = runner.next;
        }
      }
      current = current.next;
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    RemDupInLLWithoutExtraSpace ll = new RemDupInLLWithoutExtraSpace();

    System.out.print("Enter the size of Linked List: ");
    int size = sc.nextInt();

    System.out.println("Enter the values of the Linked List: ");
    for (int i = 0; i < size; i++) {
      ll.insert_At_beginning(sc.nextInt());
    }

    System.out.println("List with duplicates values:");
    ll.display();

    //deleting the duplicates from the Linked List if it has any 
    ll.delete_Duplicates();
    System.out.println("List after deleting duplicates:");
    ll.display();

  }
}
/**
Sample input/output:
 
Enter the size of Linked List: 5
Enter the values of the Linked List:
-2
7
1
7
5
List with duplicates values:
5 7 1 7 -2
List after deleting duplicates:
5 7 1 -2
  
Time complexity: O(n^2) for finding duplicates
Space complexity: O(n)

 */