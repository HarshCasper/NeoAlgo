import java.util.*;
import java.io.*;
import java.lang.*;
//nodes of Linked list
class Node
{
    int data;
    Node next;
    Node(int x)
    {
        data = x;
        next = null;
    }
}
class DetectLoopLL
{
    public static void makeLoop(Node head, Node tail, int x){
        if (x == 0) return;
        Node curr = head;
        for(int i=1; i<x; i++)
            curr = curr.next;
        tail.next = curr;
    }
    // } Driver Code Start
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        //size of linked list
        System.out.println("\Enter the size of Linked List:");
        int n = sc.nextInt();
         System.out.println("\Enter the data of Linked List:");
        //Input for the Linked list
        int num = sc.nextInt();
        Node head = new Node(num);
        Node tail = head;
        //Linked List created
        for(int i=0; i<n-1; i++)
        {
            num = sc.nextInt();
            tail.next = new Node(num);
            tail = tail.next;
        }
        //Position to check loop exists or not
         System.out.println("\Enter the Position to check:");
        int pos = sc.nextInt();
        makeLoop(head, tail, pos);
        //Object of Solution class
        Solution x = new Solution();
        //True if loop exits otherwise False
        System.out.println("\tOUTPUT");
        System.out.println("-----------------");
        if( x.detectLoop(head) )
            System.out.println("TRUE");
        else
            System.out.println("FALSE");
    }
}
//  Driver Code Ends
//Solution class to check detect the loop
class Solution {
    public static boolean detectLoop(Node head){
        if(head==null||head.next==null)
            return false;
        Node slow = head;
        Node fast = head;
        while(fast != null && fast.next != null) {
            
            slow = slow.next;
            fast = fast.next.next;
            //there exists a loop if and only if 
            //both fast and slow pointer 
            //point to a same one during traversal
            if(slow==fast)
                return true;
        }
        //otherwise return false
        return false;
    }
}
//Sample Input OUTPUT
/*Enter the size of Linked List:
4
Enter the data of Linked List:
1 8 3 4
Enter the Position to check:
0
    OUTPUT
-----------------
FALSE

Time complexity: O(n).
Auxiliary Space:O(1).
*/
