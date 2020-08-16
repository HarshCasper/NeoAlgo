import java.util.*;
public class Main 
{
    static Node head;
    class Node{
    	public int data;
    	public Node next;
    	Node(int data){
    		this.data=data;
    	}
    }
    
    public void insert_At_beginning(int data) {
    	Node ptr = new Node(data);
    	if(head!=null)
          {
    		ptr.next=head;
    		head=ptr;
          }
    	else 
    	  {     
		ptr.next=null;
    	        head=ptr;
       	  }
    }
    public bool isEmpty()
    {
      if(head==null)
       return true;
      return false;
    }
    public void print() {
    	Node ctr=head;	
    	while(ctr!=null)
    	{
    		System.out.print(ctr.data);
    		ctr=ctr.next;
    	}
    	System.out.println();
    }  
    public void insert_At_End(int data)
    {    Node ctr=head;
    	 Node ptr = new Node(data);
    	 if(ctr==null)
    	 { head=ptr;
    	   ptr.next=null;
    	   return ;
    	 }
    	 else {
    	   while(ctr.next!=null)
    		 ctr=ctr.next;
    	   ctr.next=ptr;
           ptr.next=null;
    	 }
    } 
    public void delete_From_Beginning()
    {   if(head!=null)
    	  head = head.next;
        else 
    	System.out.println("Linked list is empty");
    }
    public void delete_From_End()
    {   
    	Node ctr=head;
    	if(ctr!=null && ctr.next!=null)
	   {
    	     while(ctr.next.next!=null)
    		ctr=ctr.next;
    	     ctr.next=null;
    	  }
    	else if( ctr!=null && ctr.next==null)
    	   head = null;
    	else
    	  System.out.println("Linked list is empty");  
    }
    public void delete_At_Position(int c)
    {   
    	int i=1;Node ctr=head,ptr;
    	if(ctr!=null ) 
	{
    	   while(i<c-1 && ctr.next!=null)
    		ctr=ctr.next;
    	   ptr=ctr.next;
    	   ctr.next=ptr.next;
        }
       else
    	 System.out.println("Linked list is empty"); 
       return ;
   }
   public void insert_At_Position(int c,int data)
    {
    	int i=1;Node ctr=head;
    	if(ctr!=null)
	{
    	  while(i<c-1 && ctr.next!=null)
    	  {
    	      ctr=ctr.next;
    	      i++;
    	  }
    	  Node ptr = new Node(data);
    	  ptr.next=ctr.next;
    	  ctr.next=ptr;
    	}
    	else
    	{
    		Node ptr = new Node(data);
    		ptr.next=null;
		head=ptr;
        }
    }
  public void count()
    {
    	Node ptr = head;int count = 0;
        while (ptr!=null)
    		{
    			count++;
    			ptr=ptr.next;
    		}
    	System.out.println(count);
    }
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    Main ll = new Main();
    System.out.println("Enter 1 to insert at beginning, 2 to insert at end, 3 to insert at position, 4 to delete from beginning, 5 to delete from end, 6 to delete at position and 7 to find the length of Linked List");
    System.out.println("Enter choice from 1-7");
    boolean f=true;int choice;
    while(f)
    {
    	 choice = sc.nextInt();
         switch(choice)
	 {
           case 1: {
                    int data=sc.nextInt();
                    ll.insert_At_beginning(data);ll.print();
                     break;
                   }
           case 2:{
    	            int data=sc.nextInt();
    	            ll.insert_At_End(data);ll.print();break;
                  }
           case 3:{
    	           int data=sc.nextInt();
                   int c=sc.nextInt();
    	           ll.insert_At_Position(c, data);ll.print();break;
                  }
           case 4:{
    	          ll.delete_From_Beginning();ll.print();break;
                  }
           case 5:{
    	          ll.delete_From_End();ll.print();break;
                  }
           case 6:{
    	          int c=sc.nextInt();
    	          ll.delete_At_Position(c);ll.print();break;
                  }
           case 7:{
   	          ll.count();
   	          break;
                  }
           default:f=false;
        }
       System.out.println("Enter choice from 1-7");
     }
   }
}
