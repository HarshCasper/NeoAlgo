//given two linked lists. and we have to find intersection oint between these two linkedlist. So Here is the program for finding it.

import java.util.*;
class Intersection_of_two_linkedlists {
    static class Node 
    {
        int data;
        Node next; 
        Node(int x)
        {
            data = x;
            next = null;
        }
    }
 
    static Node head1;
    static Node head2;
     
    public void append1(int newdata) 
    { 
        Node newnode = new Node(newdata); 
        if (head1 == null) 
        { 
            head1 = new Node(newdata); 
            return; 
        } 
  
        newnode.next = null; 
 
        Node last = head1;  
        while (last.next != null) 
            last = last.next; 
  
        last.next = newnode; 
        return; 
    }
 
    public void append2(int data) 
    { 
        Node newnode = new Node(data); 
        if (head2 == null) 
        { 
            head2 = new Node(data); 
            return; 
        } 
  
        newnode.next = null; 
 
        Node last = head2;  
        while (last.next != null) 
            last = last.next; 
  
        last.next = newnode; 
        return; 
    }
    
    //function to get the intersection point of two linked lists
    int GetNode() 
    {
        int count1 = GetCount(head1);
        int count2 = GetCount(head2);
        int d;
 
        if (count1 > count2) {
            d = count1 - count2;
            return GetIntesectionNode(d, head1, head2);
        }
        else {
            d = count2 - count1;
            return GetIntesectionNode(d, head2, head1);
        }
    }
 
     // function to get the intersection point of two linked lists head1 and head2 
    int GetIntesectionNode(int d, Node node1, Node node2)   
    {
        //head1 has more nodes than head2
        Node curr1 = node1;
        Node curr2 = node2;
        for (int i = 0; i < d; i++)
        {
            if (curr1 == null) 
            {
                return -1;
            }
            curr1 = curr1.next;
        }
        while (curr1 != null && curr2 != null) 
        {
            if (curr1.data == curr2.data) 
            {
                return curr1.data;
            }
            curr1 = curr1.next;
            curr2 = curr2.next;
        }
 
        return -1;
    }
 
     // returns the count of nodes in the list
    int GetCount(Node node)          
    {
        Node curr = node;
        int count = 0;
 
        while (curr != null) 
        {
            count++;
            curr = curr.next;
        }
 
        return count;
    }
 
 
 // driver function
    public static void main(String[] args)            
    {
        Scanner sc = new Scanner(System.in); 
        Intersection_of_two_linkedlists list = new Intersection_of_two_linkedlists();
 
        System.out.print("enter total number of elements in list1: ");
        int n1=sc.nextInt();
        System.out.print("enter "+n1+" elemets(space separated) :");
        for(int i=0;i<n1;i++)
        {
            //inserting element in head1
              list.append1(sc.nextInt());           
        }
 
 
        System.out.print("enter total number of elements in list2: ");
        int n2=sc.nextInt();
        System.out.print("enter "+n2+" elemets(space separated) :");
        for(int i=0;i<n2;i++)
        {
            //inserting element in head2
              list.append2(sc.nextInt());          
        }
 
        System.out.println("The node of intersection is " + list.GetNode());
    }
}
