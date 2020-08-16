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
                System.out.println(data+" is successfully added to the stack");
	}
	else 
	{
		Node ctr=top;
		ptr.next=ctr;
		top = ptr;
		System.out.println(data+" is successfully added to the stack");
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
  void count()
  {
	  int count = 0;
	  Node ptr = top;
	  while(ptr!=null)
	  {
		  count++;
		  ptr = ptr.next;
	  }
	  System.out.println("The stack has "+count+" elements"); 
  }
  void pop()
  {
	Node ctr=top;int data;
	if(ctr==null)
	{
		System.out.println("Stack is empty");
		return ;
	}
	else if(ctr!=null && ctr.next==null)
	{       data = top.data;
		top = null;
	}
	else 	
	{       data = top.data;
		top = top.next;
	}
	  System.out.println(data+" is successfully removed from the stack");
  }
  void display()
  {   if (isEmpty())
        {
	    System.out.println("The stack is empty");
        }
      else 
      { System.out.println("The stack is ");
	Node ctr=top;
	while(ctr!=null)
	{
		System.out.print(ctr.data+" ");
		ctr=ctr.next;
	}
	System.out.println();
  }
  }
  public static void main(String[] args)
  {
	Stack st=new Stack();
	Scanner sc=new Scanner(System.in);
	System.out.println("Stack");
	int choice; boolean f=true;
	while(f) 
	{
		System.out.println("Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack,4 to count the number of elements in the stack, 5 to display all elements in the stack and 6 to exit");
		choice=sc.nextInt();
		switch(choice) 
		{
		 case 1: System.out.println("Enter data to enter into stack");
		         int data = sc.nextInt();
		         st.push(data);
		         break;
		 case 2: st.pop();
			 break;
		 case 3: st.peek();	
		         break;
		 case 4: st.count();
			 break;
		 case 5: st.display();
			 break;
		 case 6: f=false;
	                 break;
	        default: System.out.println("Enter Valid Input");
	                 break;
		}
	}
  }

}

/*
Stack
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack,4 to count the number of elements in the stack, 5 to display all elements in the stack and 6 to exit
1
Enter data to enter into stack
2
2 is successfully added to the stack
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack,4 to count the number of elements in the stack, 5 to display all elements in the stack and 6 to exit
2
2 is successfully removed from the stack
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack,4 to count the number of elements in the stack, 5 to display all elements in the stack and 6 to exit
1
Enter data to enter into stack
3
3 is successfully added to the stack
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack,4 to count the number of elements in the stack, 5 to display all elements in the stack and 6 to exit
3
3
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack,4 to count the number of elements in the stack, 5 to display all elements in the stack and 6 to exit
4
The stack has 1 elements
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack,4 to count the number of elements in the stack, 5 to display all elements in the stack and 6 to exit
5
The stack is 
3 
Enter 1 to input data, 2 to delete data from stack, 3 to peek data from stack,4 to count the number of elements in the stack, 5 to display all elements in the stack and 6 to exit
6
*/
