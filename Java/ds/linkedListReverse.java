import java.util.Scanner;

public class linkedListReverse {
static Node head;
class Node{
	public int data;
	public Node next;
	Node(int data){
		this.data=data;
	}
}

void add(int data)
{   Node ctr=head;
	Node ptr = new Node(data);
	if(ctr==null)
	{
		head=ptr;
		ptr.next=null;
	}
	else 
	{
		
		while(ctr.next!=null)
			ctr=ctr.next;
		ctr.next=ptr;
		ptr.next=null;
	}
}

public void print() {
	Node ctr=head;
	

	
	while(ctr!=null)
	{
		System.out.print(ctr.data+" ");
		ctr=ctr.next;
	}
	
	
	
}

public static void main(String[] args)
{
	Scanner sc=new Scanner(System.in);
	linkedListReverse ll = new linkedListReverse();
	String choice;int data; 
	
	System.out.println("Enter y to add a data to Linked List");
	
	choice = sc.nextLine();
		while(!choice.isEmpty() && choice.charAt(0)=='y') {
			
		
		System.out.println("Enter data to enter into the linked list");
		data=sc.nextInt();
		ll.add(data);
		ll.print();
		System.out.println();
System.out.println("Enter y to add a data to Linked List");
		sc.nextLine();
		choice = sc.nextLine();
	}
	Node ctr=head;Node ptr,temp;
	if(ctr==null)
		System.out.println("Linked List is empty");
	else {
	ptr=null;
	temp=ctr.next;
	while(ctr.next!=null)
	{
		ctr.next=ptr;
		ptr=ctr;
		ctr=temp;
		temp=temp.next;
		
		
	}
	ctr.next=ptr;
head=ctr;
ll.print();
}
}
}
