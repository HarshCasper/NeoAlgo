import java.util.*;
public class Stack
{
  static Node top;
  class Node
  {
	public int data;
	public Node next;
	Node(int data)
	{
		this.data=data;
	}
  }
  void push(int data)
  {
	Node ptr = new Node(data);
	if(top==null)
	{
		top=ptr;
		ptr.next=null;
	}
	else 
	{
		Node ctr=top;
		ptr.next=ctr;
		top = ptr;
	}
  }
  boolean isEmpty()
  {
	if(top==null) 
		return true;
	return false;
  }
  void peek()
  {     if(!isEmpty())
	  System.out.println(top.data);
        else 
          System.out.println("Stack is empty");
  }
  void pop()
  {
	Node ctr=top;
	if(ctr==null)
	{
		System.out.println("Stack is empty");
		return ;
	}
	else if(ctr!=null && ctr.next==null)
		top = null;
	else 
		top = top.next;	
  }
  void print()
  {
	Node ctr=top;
	while(ctr!=null)
	{
		System.out.print(ctr.data+" ");
		ctr=ctr.next;
	}
	System.out.println();
  }
  public static void main(String[] args)
  {
	Stack st=new Stack();
	Scanner sc=new Scanner(System.in);
	System.out.println("Stack");
	int choice; boolean f=true;
	while(f) 
	{
		System.out.println("Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack and 4 to exit");
		choice=sc.nextInt();
		switch(choice) 
		{
		 case 1: System.out.println("Enter data to enter into stack");
		         int data = sc.nextInt();
		         st.push(data);
		         st.print();
		         System.out.println("Success");
		         break;
		 case 2: st.pop();
		         st.print();
		         System.out.println("Success");
			 break;
		 case 3: st.peek();
			  System.out.println("Success");	
		         break;
		case 4:  f=false;
	                 break;
	     default: System.out.println("Enter Valid Input");
	            break;
		}
	}
  }

}

/*
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack and 4 to exit
1
Enter data to enter into stack
2
2 
Success
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack and 4 to exit
1
Enter data to enter into stack
3
3 2 
Success
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack and 4 to exit
2
2 
Success
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack and 4 to exit
3
2
Success
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack and 4 to exit
1
Enter data to enter into stack
4
4 2 
Success
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack and 4 to exit
4
*/
