/*
Given two linked lists: list1 and list2 of sizes l1 and l2 respectively.
We need to remove list1's nodes from the ath node to the bth node, and put list2 in their place.

SAMPLE INPUT:
list1 = [0,1,2,3,4,5,6]
a = 3, b = 4
list2 = [100,101,102]

SAMPLE OUTPUT:
[0,1,2,100,101,102,5]

Here [3,4,5] in list1 is removed and list2 is inserted in place of that.

*/

import java.util.*;
import java.io.*;
class LinkedList
{

static ListNode list1,list2;

public static class ListNode {
   int data;
   ListNode next;
   ListNode() {}
   ListNode(int data) { this.data = data; }
   ListNode(int data, ListNode next) { this.data= data; this.next = next; }
 }
  
  
  public static void insertNode(ListNode list, int data)
  {
  	ListNode n=new ListNode(data,null);//new node
    ListNode head=list;
  	if(head==null)
  		head=n;
    else
    {
    	ListNode ptr=list;
    	while(ptr.next!=null)//traverse till last existing node
    		ptr=ptr.next;

    	ptr.next=n;
    }
  }

  public static ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode temp=list1;
        ListNode a1=null;
        ListNode b1=null;
        int c=0;
        while(temp!=null)
        {
            if(c==a-1)
                a1=temp;//node right before ath position
            if(c==b+1)
                b1=temp;//node right after bth position
            temp=temp.next;
            c++;//stores the total number of nodes in list1
        }
        temp=list1;
        a1.next=list2;//list2 is connected to node right before ath position in list1
        while(list2.next!=null)//traversing to end of list2
        {
            list2=list2.next;
        }
        list2.next=b1;//last node of list2 is connected to the node right after bth position in list1
        
        return list1;
    }

    public static void printLinkedList(ListNode head)
    {
    	ListNode ptr=head;
    	while(ptr.next!=null)
    		{
          System.out.print(ptr.data+"->");
          ptr=ptr.next;
        }
    	System.out.println(ptr.data);
    }

    public static void main(String args[])
    {
    	
    	Scanner in=new Scanner(System.in);
    	//list 1
    	System.out.println("ENTER NODES IN LIST1");
    	int l1=in.nextInt();
        System.out.println("INSERT NODE DATA FOR LIST1");
         list1=new ListNode(in.nextInt());
    	for(int i=1;i<l1;i++)
         {
         	int data=in.nextInt();
         	insertNode(list1,data);
         }

        //list 2
        System.out.println("ENTER NODES IN LIST2");
        int l2=in.nextInt();
        System.out.println("INSERT NODE DATA FOR LIST2:");

        ListNode list2=new ListNode(in.nextInt());
        for(int i=1;i<l2;i++)
         {
         	int data=in.nextInt();
         	insertNode(list2,data);
         }
        
        //list1 index range to be removed
        System.out.println("INSERT LIST1 INDEX RANGE THAT NEEDS TO BE REPLACED:");
    	  int a=in.nextInt();
    	  int b=in.nextInt();

        System.out.println("LIST1: ");
        printLinkedList(list1);
        System.out.println("LIST2: ");
        printLinkedList(list2);

        ListNode ans=mergeInBetween(list1,a,b,list2);
        System.out.println("MODIFIED LIST: ");
        printLinkedList(ans);

    }

}
/*
ENTER NODES IN LIST1
5
INSERT NODE DATA FOR LIST1
1 2 3 4 5
ENTER NODES IN LIST2
3
INSERT NODE DATA FOR LIST2:
100 101 102
INSERT LIST1 INDEX RANGE THAT NEEDS TO BE REPLACED:
1 3
LIST1:
1->2->3->4->5
LIST2:
100->101->102
MODIFIED LIST:
1->100->101->102->5
*/
