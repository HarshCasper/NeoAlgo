/*
   We will create a LinkedList first and display its elements.
   After that we will delete some elements from the LinkedList
   * Delete from beginning - In this case we will simply move the head pointer
      to the next node. In case if we have only one element in the LL then we 
      will assign null to head which is the pointer to the first and only node in the LL. 
   * Delete from end - In this case we will take a pointer and initialize 
      it to the head pointer and we will move this pointer till end-1 so 
      that we can access the last node.    
   * Delete from any position - In this case we will take a pointer variable
      and initialize it to the head pointer and we will move this pointer till 
      position-1 so that we can access the desired position node.
*/

import java.util.Scanner;

public class DeleteElementLL {
     
	//creating the Node class having one data part and one pointer to the next node
	class Node{
		 int data;      
		 Node next;
		 
		 // Constructor to initialize the data and next pointer
		 Node(int data){
			 this.data = data;      
			 this.next = null;  
		 }
	}
	  
	  // creating the head of the list
	  Node head = null; 
	  
	  public void createList(int newData) {
		  
		/* creating a new node with data value.
		   If list is empty head points to the newly
		   created node and if list is not empty, we create
		   temp variable and traverse the list till end
		   and insert the node at the end */
             
		  Node new_Node = new Node(newData); 
		  Node temp = head;
		  if(head==null) {
			  head = new_Node;
		  }
		  else {
		     	while(temp.next!=null) {
		     		temp = temp.next;
		     	}
		     	temp.next = new_Node;
		  }
	  } 
	
	  public void displayList() {
		  /* creating a temp variable 
		     traversing and printing the list*/
		  
		  Node temp = head;  
		 
		  while(temp != null) {
			  System.out.print(temp.data + " ");
			  temp = temp.next;
		  }
		  System.out.println();
	  }
	  
	  public void deleteFromBeg() {
		  /* if list is empty nothing to delete
		    else head points to the second element in the list */
		   
		  if(head==null){
			  System.out.println("List is Empty.");
			  return;
		  }
		  else {
			  head = head.next; 
		  } 
	  }
	  
	  public void deleteFromEnd() {
		  /* if only one element is present in the list
		     delete it otherwise create a temp variable
		     and traverse the list till the second
		     last element and at last temp should
		     point null to remove last node */
		   
		   
		  Node temp = head;
		
		  if(head.next == null) {
			  head = null;
		  }
		  
		  else{
			   while(temp.next.next != null) {
				   temp = temp.next;
			   }
			   temp.next = null;
		  }
	  }
	  
	  public void deleteFromAnyPosition(int pos) {
		  /* create a temp variable and initialize it to head.
		     Then traverse the list till position-1 and at 
		     last link the previous node of the node to-be-deleted
		     to the node after it. */
		  
		  Node temp = head;
		  int i=1;
		  while(i<pos-1) {
			  temp = temp.next;
			  i++;
		  }
		  
		  Node next = temp.next.next; 
	      temp.next = next;
		  
	  }
	  
	public static void main(String[] args) {
		 
		   DeleteElementLL list = new DeleteElementLL();
		   
		    Scanner input = new Scanner(System.in);
		   System.out.println("Enter the number of elements you want to insert in the List: ");
		   int n = input.nextInt();
		   System.out.println("Enter the elements of the List: ");
		   for(int i=0; i<n; i++) {
			   list.createList(input.nextInt());
		   }
		   
		   System.out.print("Initial List: ");
		   list.displayList();
		   
		   list.deleteFromBeg();
		   System.out.print("List after deletion from the Beginning: ");
		   list.displayList();
		   
		   list.deleteFromEnd();
		   System.out.print("List after deletion from the End: ");
		   list.displayList();
		 
		   System.out.println("Enter the position of the element you want to delete: ");
		   int position = input.nextInt(); 
		   input.close();
		   
		   list.deleteFromAnyPosition(position);
		   System.out.print("List after deletion from the desired position: " );
		   list.displayList();
		
	}

}

/*
  Enter the number of elements you want to insert in the List: 
  9
  Enter the elements of the List: 
  3 5 8 2 10 7 21 6 1
  Initial List: 3 5 8 2 10 7 21 6 1 
  List after deletion from the Beginning: 5 8 2 10 7 21 6 1 
  List after deletion from the End: 5 8 2 10 7 21 6 
  Enter the position of the element you want to delete:
  3
  List after deletion from the desired position: 5 8 10 7 21 6 


  Time Complexity - O(n) Worst case
                    O(1) Best case
                    
 */
