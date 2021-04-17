/*Given the head pointer to a linked list of length n and an integer k, we have to reverse every alternate k nodes in the linked list.

Approach:
1.Reverse the first k nodes
2.Link the next of head of the modified list to the (k+1)th node 
3.Traverse the next k nodes to skip their reversal
4.Since 2k nodes are already processed,recursively call the function for the rest n-2k nodes
5.Return the new head of the list

*/

import java.util.*;
public class Reverse_alternate_k_Nodes {

    //creating the head of the list
    static Node head;

    //class which defines the structure of each node in the list
    class Node {
        int data;
        Node next;

        // Constructor to initialize the data and next pointer
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    //Function to create the linked list with the elements given as input
    public void createList(int newData) {

        Node new_Node = new Node(newData);
        Node temp = head;
        if (head == null) {
            head = new_Node;
        } else {
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = new_Node;
        }
    }

    //Function to display the linked list
    public void displayList(Node A) {

        Node temp = A;

        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    //Function which returns the head node of the result list
    public Node reverseAlternately(Node A, int k) {
        if (A == null || A.next == null)
            return A;
        Node head = null;
        Node current = A;
        Node forward = null;
        Node backward = null;

        //Reversing first k nodes of the current list
        for (int i = 0; i < k; i++) {
            forward = current.next;
            current.next = backward;
            backward = current;
            current = forward;
        }
        //Setting the head pointer to the result list after reversing k nodes
        head = backward;

        if (A != null)
            A.next = current;

        if (current == null)
            return head;

        //Next k nodes should not be reversed hence we skip them
        for (int i = 0; i < k - 1; i++) {
            current = current.next;
        }
        //Recursive call by making the rest of the list as next of current node
        current.next = reverseAlternately(current.next, k);
        return head;
    }

    public static void main(String[] args) {
        Reverse_alternate_k_Nodes list = new Reverse_alternate_k_Nodes();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements you want to insert in the list: ");
        int n = sc.nextInt();
        System.out.println("Enter the elements of the list: ");
        for (int i = 0; i < n; i++) {
            list.createList(sc.nextInt());
        }
        System.out.println("Enter the number of elements to be reversed alternately");
        int k = sc.nextInt();

        System.out.println("The original list is");
        list.displayList(head);

        head = list.reverseAlternately(head, k);
        System.out.println();

        System.out.println("The list after reversal is");
        list.displayList(head);
        sc.close();
    }
}
/*
Sample Input:
Enter the number of elements you want to insert in the list: 
6
Enter the elements of the list: 
1
4
6
6
4
10
Enter the number of elements to be reversed alternately
2

Sample Output:
The original list is
1 4 6 6 4 10 
The list after reversal is
4 1 6 6 10 4 

Time Complexity : O(n)
Space Complexity : O(n),since there is a recursive function
*/
