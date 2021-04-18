/* 
Java Program for Floyd Cycle Detection.
It is a pointer algorithm that uses only two pointers, moving through the sequence at different speeds to detect if a 
cycle is present.
*/

class Node {
    int data;
    Node next;
 
    Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }
}

public class FloydCycleDetection {
	public static boolean detectCycle(Node head)
    {
		// pointers used: slow and fast
        Node slow = head, fast = head;
 
        while (fast != null && fast.next != null)
        {
        	// slow moves one step
            slow = slow.next;

            // fast moves two steps
            fast = fast.next.next;
 
            // if they meet any node, the linked list contains a cycle
            if (slow == fast) {
                return true;
            }
        }
 
        // cycle not found case
        return false;
    }
	
	public static void main(String[] args) {
			int arr[] = { 1, 2, 3};
		    
	        Node head = null;
	        for (int i = arr.length - 1; i >= 0; i--) {
	            head = new Node(arr[i], head);
	        }
	 
	        // cycle created
	        head.next.next.next = head.next.next;
	 
	        if (detectCycle(head)) {
	            System.out.println("Cycle Found");
	        }
	        else {
	            System.out.println("No Cycle Found");
	        }
	}
}

/*
Time complexity: O(N)
Space complexity: O(1)

Output:
Cycle Found
*/