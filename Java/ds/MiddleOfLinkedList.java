//Java program to find middle of LinkedList

/*Possible Approaches: 
i) Traverse List: Traverse list to find it's length, then scan list to locate n/2 node from the beginning.
ii) Two - Pointer Approach: It is the efficient approach (only one scan). Use 2 pointers. Move one at twice the speed of second. 
When first pointer reaches the end of list, second pointer will point the middle node of the LinkedList.

Using the 2 pointer approach to find the middle element with Time Complexity: O(n) Space Complexity: O(1)					   		
**/
public class MiddleOfLinkedList {
	Node head;
	 
    static class Node {
    	int data;
        Node next;
     
        // constructor
        Node(int data) {
            this.data = data;
            
        }
    }
 
    public void addToTheLast(Node node) {
 
        if (head == null) {
            head = node;
        } else {
            Node temp = head;
            while (temp.next != null)
                temp = temp.next;
 
            temp.next = node;
        }
    }
 
    public void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.format("%d ", temp.data);
            temp = temp.next;
        }
        System.out.println();
    }
 
    // This function will find middle element in linkedlist
    public Node findMiddleNode(Node head)
    {
    	Node pointer1, pointer2;       //2 pointers 
    	pointer1 = pointer2 = head;	   // Both pointers start from head node

    	int i = 0;

    	// loop until pointer reaches the tail, i.e., next will be NULL

    	while(pointer1.next != null){
    		if(i == 0){
    			pointer1 = pointer1.next;  //Increment only the first Pointer
    			i=1;
    		}

    		else if(i == 1){
    			pointer1 = pointer1.next;  //Increment both the pointers
    			pointer2 = pointer2.next;
    			i=0;
    		}
    	}	
    	
    	return pointer2;  //Return pointer2 which now points to the middle node
 
    }
    	
    //Main Method
    public static void main(String[] args) {
        MiddleOfLinkedList list = new MiddleOfLinkedList();
        
        // Creating a linked list
        Scanner sc = new Scanner(System.in);
        
        //size of linked list
        System.out.println("Enter the size of Linked List:");
        int n = sc.nextInt();
        System.out.println("Enter the data of Linked List:");
        //Input for the Linked list
        int num = sc.nextInt();
        Node head = new Node(num);
        list.addToTheLast(head);
        Node tail = head;
        //Linked List created
        for(int i=0; i<n-1; i++)
        {
            num = sc.nextInt();
            tail.next = new Node(num);
            tail = tail.next;
        }
 
        list.printList();  //prints list
        
        // finding the middle element of the LinkedList
        Node middle = list.findMiddleNode(head);
        
        System.out.println("Middle node is: "+ middle.data); //Prints middle element
 
    }
}

/*OUTPUT
  Enter the size of Linked List:
  5
  Enter the data of Linked List:
  1 2 3 4 5
  1 2 3 4 5 
  Middle node is: 3
  
  Time Complexity: O(n) Space Complexity: O(1)
 */
