// This program is to check if a singly linked list is a palindrome or not.
// And, A singly linked list is a linked list that can be traversed in only one direction from head to the last node, i.e Unidirectional essentially.
// A string is said to be palindrome if it reads the same backward as forward. 
// eg. racecar, madam etc.

import java.util.*;

class Node
{
  int data;
  Node next;
  public Node (int data)
  {
    this.data = data;
    this.next = null;
  }
}

class Palindrome
{
  int n;
  //Represent the head and tail of the singly linked list  
  public Node head = null;
  public Node tail = null;

  //add() will add a new node to the list  
  public void add (int data)
  {
    //Create a new node  
    Node newNode = new Node (data);

    //Then, Check if the list is empty  
    if (head == null)
      {
	//If the list turns out to be empty, both head and tail will point to new node.  
	head = newNode;
	tail = newNode;
      }
    else
      {
	//newNode will be added after tail such that tail's next will point to newNode now.  
	tail.next = newNode;
	//newNode will become new tail of the list.  
	tail = newNode;
      }
    // n will count the number of nodes present in the list. 
    n++;
  }

  //reverseList() will reverse the singly linked list and return the head of the list  
  public Node reverseList (Node temp)
  {
    Node current = temp;
    Node prev = null, next = null;

    //Swapping the previous and next nodes of each node to reverse the direction of the list.  
    while (current != null)
      {
	next = current.next;
	current.next = prev;
	prev = current;
	current = next;
      }
    return prev;
  }

  //isPalindrome() will determine whether given list is palindrome or not.  
  public void isPalindrome ()
  {
    Node current = head;
    boolean flag = true;

    //Store the mid position of the list  
    int mid = (n % 2 == 0) ? (n / 2) : ((n + 1) / 2);

    //Find the middle node in the given singly linked list  
    for (int i = 1; i < mid; i++)
      {
	current = current.next;
      }

    //Reverse the list after middle node to end. 
    Node rev = reverseList (current.next);

    //Compare nodes of first half and second half of list  
    while (head != null && rev != null)
      {
	if (head.data != rev.data)
	  {
	    flag = false;
	    break;
	  }
	head = head.next;
	rev = rev.next;
      }

    if (flag)
      System.out.println ("Given linked list is a palindrome.");
    else
      System.out.println ("Given linked list is NOT a palindrome.");
  }

  //display() will display all the nodes present in the list. 
  public void display ()
  {
    //Node current will point to head.  
    Node current = head;

    if (head == null)
      {
	System.out.println ("List is empty.");
	return;
      }
    System.out.println ("Nodes of the linked list: ");
    while (current != null)
      {
	//Prints each node by incrementing pointer.  
	System.out.print ((char)current.data + " ");
	current = current.next;
      }
    System.out.println ();
  }
}

public class Main
{
  public static void main (String[]args)
  {

    Scanner sc = new Scanner (System.in);
    Palindrome list = new Palindrome();

    //Add nodes to the list.  
    System.out.println("Enter the string: ");
    String str=sc.nextLine().trim();

    for(int i=0;i<str.length();i++)
        list.add(str.charAt(i));

    list.display ();

    //Checks whether given list is palindrome or not.  
    list.isPalindrome ();
  }
}

// Time Complexity = O(n) //This represents the number of operations to be performed by an algorithm to complete its task.
// Space Complexity = O(1) //This represents the total space taken by the algorithm with respect to the input size.
/*
Output:
Enter the string:                                                                                                         
racecar                                                                                                                   
Nodes of the linked list:                                                                                                 
r a c e c a r                                                                                                             
Given linked list is a palindrome.                                                                                        
                                     
Enter the string:                                                                                                       
candy                                                                                                                   
Nodes of the linked list:                                                                                               
c a n d y                                                                                                               
Given linked list is NOT a palindrome. 

Enter the string:                                                                                                       
Anime                                                                                                                   
Nodes of the linked list:                                                                                               
A n i m e                                                                                                               
Given linked list is NOT a palindrome.   

Enter the string:                                                                                                       
malayalam                                                                                                               
Nodes of the linked list:                                                                                               
m a l a y a l a m                                                                                                       
Given linked list is a palindrome. 
*/
