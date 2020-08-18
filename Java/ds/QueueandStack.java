//Qs class for implementing queue using two stack with costly dequeue() 
class Qs {
	int s1[];			//First stack
	int s2[];			//Second stack
	int size;			//size of queue
	int topS1;			//To maintain top of stack 1
	int topS2;			//To maintain top of stack 2
	int count;  		//To count number of items in queue
	public Qs(int s)
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
}

//Sq class to implement a stack using two queue with costly push()
class Sq {
	int q1[];		//First queue
	int q2[];		//Second queue
	int front1;		//To maintain front of queue 1
	int front2;		//To maintain front of queue 2
	int rear1;		//To maintain rear of queue 1
	int rear2;		////To maintain rear of queue 2
	int size;		//size of stack
	int count;		//to count number of items in stack
	public Sq(int s)
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
}

//QueueandStack class with main function to operate Qs and Sq class
public class QueueandStack {
	public static void main(String args[])
	{
		Sq obs = new Sq(5);		//Creating an object of Sq class
		Qs obq = new Qs(5);		//Creating an object of Qs class
		
		//Calling enqueue function from Qs class to enqueue an item into queue
		obq.enqueue(1);
		obq.enqueue(2);
		obq.enqueue(3);
		obq.enqueue(4);
		obq.enqueue(5);
		
		System.out.println("Implementation of queue using stack");
		
		//Printing dequeue items from dequeue function from Qs class
		System.out.print(obq.dequeue()+" ");
		System.out.print(obq.dequeue()+" ");
		System.out.print(obq.dequeue()+" ");
		System.out.print(obq.dequeue()+" ");
		System.out.println(obq.dequeue()+" ");
		
		//Calling push function from Sq class to push an item into a stack
		obs.push(1);
		obs.push(2);
		obs.push(3);
		obs.push(4);
		obs.push(5);
		
		System.out.println("Implementation of stack using queue");
		
		//Printing poped items from pop function from Sq class
		System.out.print(obs.pop()+" ");
		System.out.print(obs.pop()+" ");
		System.out.print(obs.pop()+" ");
		System.out.print(obs.pop()+" ");
		System.out.println(obs.pop()+" ");
	}
}



/*Output:

Implementation of queue using stack
1 2 3 4 5 
Implementation of stack using queue
5 4 3 2 1  */