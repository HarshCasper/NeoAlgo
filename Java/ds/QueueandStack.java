//Qs class for implementing queue using two stack with costly dequeue() 
import java.util.Scanner;
class QueueUsingStack {
	int s1[];			//First stack
	int s2[];			//Second stack
	int size;			//size of queue
	int topS1;			//To maintain top of stack 1
	int topS2;			//To maintain top of stack 2
	int count;  		//To count number of items in queue
	public QueueUsingStack(int s)
	{
		topS1 = 0;
		topS2 = 0;
		count = 0;
		size = s;
		s1 = new int[size];
		s2 = new int[size];
	}
	public void pushS1(int d)	  //Function to push an item of stack 1
	{
		s1[topS1] = d;
		topS1++;
	}
	public int popS1()	         //Function to pop an item of stack 1
	{
		topS1--;
		int temp = s1[topS1];
		return temp;
	}
	public void pushS2(int d)	 //Function to push an item of stack 2
	{
		s2[topS2] = d;
		topS2++;
	}
	public int popS2()			//Function to pop an item of stack 1
	{
		topS2--;
		int temp = s2[topS2];
		return temp;
	}
	public boolean isFull(int c) 	//Function to check whether queue is full or not
	{
		return (c == size);
	}
	public boolean isEmpty(int c)	//Function to check whether queue is empty or not
	{
		return (c == 0);
	}
	
	public void enqueue(int d)		// Function to enqueue an item to the queue
	{
		if(isFull(count))
		{
			System.out.println("Queue is full");
			System.exit(0);
		}
		else {
			pushS1(d);
			count++;
		}
	}
	public int dequeue()		//Function to deQueue an item from queue
	{
		int temp,i,dq;
		if(isEmpty(count))
		{
			System.out.println("Queue is empty");
			System.exit(0);
		}

		//push all the items in stack 2
		for(i=0;i<count;i++)
		{
			temp = popS1();
			pushS2(temp);
		}
		dq = popS2();
		count--;

		//After poping push all the items of stack 2 back into stack 1
		for(i=0;i<count;i++)
		{
			temp = popS2();
			pushS1(temp);
		}
		return dq;
	}
	public void display()
	{
		int i;
		for(i=0;i<count;i++)
		{
			System.out.print(s1[i]+" ");
		}
	}
}

//Sq class to implement a stack using two queue with costly push()
class StackUsingQueue {
	int q1[];		//First queue
	int q2[];		//Second queue
	int front1;		//To maintain front of queue 1
	int front2;		//To maintain front of queue 2
	int rear1;		//To maintain rear of queue 1
	int rear2;		////To maintain rear of queue 2
	int size;		//size of stack
	int count;		//to count number of items in stack
	public StackUsingQueue(int s)
	{
		size = s;
		q1 = new int[size];
		q2 = new int[size];
	}
	public void enqueue1(int d)			//Function to enqueue an item from queue 1
	{
		q1[rear1] = d;
		rear1 = (rear1+1)%size;
	}
	public int dequeue1()				//Function to dequeue an item from queue 1
	{
		int temp = q1[front1];
		front1 = (front1+1)%size;
		return temp;
	}
	public void enqueue2(int d)			//Function to enqueue an item from queue 2
	{
		q2[rear2] = d;
		rear2 = (rear2+1)%size;
	}
	public int dequeue2()				//Function to dequeue an item from queue 2
	{
		int temp = q2[front2];
		front2 = (front2+1)%size;
		return temp;
	}
	public boolean isFull(int c)		//Function to check whether stack is full or not
	{
		return (c == size);
	}
	public boolean isEmpty(int c)		//Function to check whether stack is empty or not
	{
		return (c == 0);
	}
	public void push(int d)				//Function to push an item into a stack
	{
		int i,temp;
		if(isFull(count))
		{
			System.out.println("Stack is full");
			System.exit(0);
		}
		enqueue2(d);
		for(i=0;i<count;i++)
		{
			temp = dequeue1();
			enqueue2(temp);
		}
		count++;

		//Swap the name of two queues
		int q[] = new int[q1.length];
		q = q1;
		q1 = q2;
		q2 = q;
	}
	public int pop()					//Function to pop an item from a stack
	{
		int temp;
		if(isEmpty(count))
		{
			System.out.println("Stack is empty");
			System.exit(0);
		}
		temp = dequeue1();
		count--;
		return temp;
	}
	public void display(int k)
	{
		int i;
		for(i=k;i<count+k;i++)
		{
			System.out.print(q1[i]+" ");
		}
	}
}

//QueueandStack class with main function to operate Qs and Sq class
public class QueueandStack {
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter 1 for implementing Queue using Stack");
		System.out.println("Enter 2 for implementing Stack using Queue");
		int n = sc.nextInt(); 
		if(n == 1)  	//For implementing queue using stack
		{
			System.out.println("Enter the size of Queue");
			int s = sc.nextInt();
			QueueUsingStack obq = new QueueUsingStack(s);
			System.out.println("Enter 1 for Enqueue");
			System.out.println("Enter 2 for Dequeue");
			System.out.println("Enter 3 to display Queue");
			System.out.println("Enter 4 to exit");
			while(true)
			{
				int ch = sc.nextInt();
				switch(ch) 
				{
					case 1:
						System.out.println("Enter the number to enqueue");
						int d = sc.nextInt();
						obq.enqueue(d);
						System.out.println("Number enqueued successfully");
						break;
					case 2:
						int temp = obq.dequeue();
						System.out.println(temp+" is dequeued");
						break;
					case 3:
						obq.display();
						break;
					case 4:
						System.exit(0);
				}
			}
		}
		else			//For implementing stack using queue
		{
			int k = 0;
			System.out.println("Enter the size of Stack");
			int s = sc.nextInt();
			StackUsingQueue obs = new StackUsingQueue(s);
			System.out.println("Enter 1 for Push");
			System.out.println("Enter 2 for Pop");
			System.out.println("Enter 3 to display Stack");
			System.out.println("Enter 4 to exit");
			while(true)
			{
				int ch = sc.nextInt();
				switch(ch) 
				{
					case 1:
						System.out.println("Enter the number to Push");
						int d = sc.nextInt();
						obs.push(d);
						System.out.println("Number pushed successfully");
						break;
					case 2:
						int temp = obs.pop();
						k++;
						System.out.println(temp+" is poped");
						break;
					case 3:
						obs.display(k);
						break;
					case 4:
						System.exit(0);
				}
			}
		}
	}
}



/*Output:

--------------------------------------------
Output of implementing Queue using Stack
--------------------------------------------

Enter 1 for implementing Queue using Stack
Enter 2 for implementing Stack using Queue
1
Enter the size of Queue
3
Enter 1 for Enqueue
Enter 2 for Dequeue
Enter 3 to display Queue
Enter 4 to exit
1
Enter the number to enqueue
1
Number enqueued successfully
1
Enter the number to enqueue
2
Number enqueued successfully
1
Enter the number to enqueue
3
Number enqueued successfully
2
1 is dequeued
3
2 3 

--------------------------------------------
Output of implementing Stack using Queue
--------------------------------------------

Enter 1 for implementing Queue using Stack
Enter 2 for implementing Stack using Queue
2
Enter the size of Stack
3
Enter 1 for Push
Enter 2 for Pop
Enter 3 to display Stack
Enter 4 to exit
1
Enter the number to Push
1
Number pushed successfully
1
Enter the number to Push
2
Number pushed successfully
1
Enter the number to Push
3
Number pushed successfully
2
3 is poped
3
2 1 
 */
