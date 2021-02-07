
/*
A page replacement algorithm looks at the limited information about accesses to the pages provided by hardware and tries to guess which pages should be replaced.
The simplest page-replacement algorithm is a FIFO algorithm. The first-in, first-out (FIFO) page replacement algorithm is a low-overhead algorithm that requires little bookkeeping on the part of the operating system.
In the Least Recently Used (LRU) page replacement policy, the page that is used least recently will be replaced.
Optimal Page Replacement algorithm is the best page replacement algorithm as it gives the least number of page faults.

*/
import java.util.*;

class node
{
	int d;
	node next;

	node() //constructor of node class
	{
		d = 0;
		next = null;
	}
}
class queue
{
	node front;
	node rear;

	queue()//default constructor
	{
		front = null;
		rear = null;
	}

	public int isEmpty()//returns 1 if queue is empty
	{
		if(front == null)
		{
			return 1;
		}
		else return 0;
	}

	public void enq(node temp) //adds an element of type node in queue
	{
		if(front == null) //if queue is empty
		{
			rear = temp;
			front = temp;
		}
		else 
		{
			rear.next = temp;
			rear = temp;
		}
	}

	public node deq() //deletes an element of type node from the queue
	{
		node x = new node();
		if(isEmpty() == 0)
		{
			if(front == rear)
			{
				x = front;
				front = null;
				rear = null;
			}
			else
			{
				x = front;
				front = front.next;
			}
		}
		else
		{
			System.out.println("Queue is empty.");
		}
		return x;
	}
}

class page
{
	int arr[];
	int pf;
	int ph;
	int pno;
	page()
	{
		arr = new int[5];
		pf = 0;
		ph = 0;
		pno = 0;
	}
}

class pagerep
{
	page p[];
	String input;
	queue q;
	int frame;
	int number;
	int arrlru[];
	int arropt[];

	pagerep()
	{
		input = "";
		q = new queue();
		frame = 0;
		number = 0;
	}

	public void accept()
	{
		Scanner Sc = new Scanner(System.in);
		System.out.println("ENTER THE REFERENCE STRING");
		input = Sc.nextLine();
		String ref[] = input.split(" ");
		number = ref.length;

		System.out.println("ENTER THE NUMBER OF FRAMES ");
		frame = Sc.nextInt();

		p = new page[number];
		for(int i = 0 ; i < number ; i++)
		{
			p[i] = new page();
			p[i].pno = Integer.parseInt(ref[i]);
		}
	}

	public void display_ref()
	{
		System.out.println("REFERENCE STRING IS  " + input);
		System.out.println();
	}

	public void fcfsalgo()
	{
		int i = 0,j = 0;
		node ptr;
		int pfc = 0,phc = 0;

		for(i = 0 ; i < frame ; i++)
		{
			node temp = new node();
			temp.d = p[i].pno;
			q.enq(temp);
			for(ptr = q.front , j = 0 ; j < frame ; j++)
			{
				if(ptr != null)
				{
					p[i].arr[j] = ptr.d;
					ptr = ptr.next;
				}
				else
				{
					p[i].arr[j] = -1;
				}
			}
			pfc++;
			p[i].pf = pfc;
			p[i].ph = phc;
		}

		while( i < number )
		{
			int flag = 0;
			for( int k = 0 ; k < frame ; k++)
			{
				p[i].arr[k] = p[i-1].arr[k];
			}
			for( j = 0 ; j < frame ; j++)
			{
				if(p[i-1].arr[j] == p[i].pno)
				{
					flag = 1;
					p[i].pf = pfc;
					phc++;
					p[i].ph = phc;
				}
			}
			if(flag == 0)
			{
				node temp = q.deq();
				for(j = 0 ; j < frame ; j++)
				{
					if(p[i].arr[j] == temp.d)
					{
						p[i].arr[j] = p[i].pno;
						pfc++;
						p[i].pf = pfc;
						p[i].ph = phc;
						break;
					}
				}
				temp.d = p[i].pno;
				temp.next = null;
				q.enq(temp);
			}
			i++;
		}
	}

	public void lru1()
	{
		int i = 0;
		int j = 0;
		int pfcnt = 0;
		int phcnt = 0;
		arrlru = new int[frame];
		for(i = 0 ; i < frame ; i++)
		{
			arrlru[i] = i;
			for( j = 0 ; j <= i ; j++)
			{
				p[i].arr[j] = p[arrlru[j]].pno;
			}
			while(j < frame)
			{
				p[i].arr[j] = -1;
				j++;
			}
			pfcnt++;
			p[i].pf = pfcnt;
			p[i].ph = phcnt;
		}

		while( i < number)
		{
			
			int flag = 0;
			for( int k = 0 ; k < frame ; k++)
			{
				p[i].arr[k] = p[i-1].arr[k];
			}
			for( j = 0 ; j < frame ; j++)
			{
				if(p[i-1].arr[j] == p[i].pno)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				for(j = 0; j < frame ; j++)
				{
					if(p[arrlru[j]].pno == p[i].pno)
					{
						arrlru[j] = i;
					}
				}
				p[i].pf = pfcnt;
				phcnt++;
				p[i].ph = phcnt;
			}
			else
			{
				int min = 999;
				int pos = 0;
				for(j = 0 ; j < frame ; j++)
				{
					if(arrlru[j] < min)
					{
						min = arrlru[j];
						pos = j;
					}
				}
				for( j = 0 ; j < frame ; j++)
				{
					if(p[min].pno == p[i].arr[j])
					{
						p[i].arr[j] = p[i].pno;
						break;
					}
				}
				arrlru[pos] = i; 
				pfcnt++;
				p[i].pf = pfcnt;
				p[i].ph = phcnt;
			}
			i++;
		}
	}

	public void optimal1()
	{
		int i = 0;
		int j = 0;
		int pfcnt = 0;
		int phcnt = 0;
		int flag = 0;
		node ptr;
		arropt = new int[frame];
		queue oq = new queue();

		for(i = 0 ; i < frame ; i++)
		{
			int t = p[i].pno;
			for(j = i+1 ; j < number ; j++)
			{
				if(p[j].pno == t)
				{
					flag = 1;
					arropt[i] = j;
					break;
				}
			}
			if(flag == 0)
			{
				node temp = new node();
				temp.d = t;
				oq.enq(temp);
				arropt[i] = 999;
			}
			ptr = q.front;
			for( j = 0 ; j <= i ; j++)
			{
				if(arropt[j] != 999)
				{
					p[i].arr[j] = p[arropt[j]].pno;
				}
				else
				{
					p[i].arr[j] = ptr.d;
					ptr = ptr.next;
				}
			}
			while(j < frame)
			{
				p[i].arr[j] = -1;
				j++;
			}
			pfcnt++;
			p[i].pf = pfcnt;
			p[i].ph = phcnt;
		}

		while( i < number)
		{
			//System.out.println("i = " + i );
			flag = 0;
			for( int k = 0 ; k < frame ; k++)
			{
				p[i].arr[k] = p[i-1].arr[k];
			}
			for( j = 0 ; j < frame ; j++)
			{
				if(arropt[j] == i)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				flag = 0;
				for(int k = i+1 ; k < number ; k++)
				{
					if(p[k].pno == p[i].pno)
					{
						flag = 1;
						arropt[j] = k;
						break;
					}
				}
				if(flag == 0)
				{
					node temp = new node();
					temp.d = p[i].pno;
					oq.enq(temp);
					arropt[j] = 999;
				}
				p[i].pf = pfcnt;
				phcnt++;
				p[i].ph = phcnt;
			}
			else
			{
				int max = 0;
				int pos = 0;
				for(j = 0 ; j < frame ; j++)
				{
					if(arropt[j] > max)
					{
						max = arropt[j];
						pos = j;
					}
				}
				if(max != 999)
				{
					for( j = 0 ; j < frame ; j++)
					{
						if(p[max].pno == p[i].arr[j])
						{
							p[i].arr[j] = p[i].pno;
							break;
						}
					}
				}
				else
				{
					node temp = oq.deq();
					for( j = 0 ; j < frame ; j++)
					{
						if(temp.d == p[i].arr[j])
						{
							p[i].arr[j] = p[i].pno;
							break;
						}
					}
				}
				flag = 0;
				for(int k = i+1 ; k < number ; k++)
				{
					if(p[k].pno == p[i].pno)
					{
						flag = 1;
						arropt[pos] = k;
						break;
					}
				}
				if(flag == 0)
				{
					node temp = new node();
					temp.d = p[i].pno;
					oq.enq(temp);
					arropt[pos] = 999;
				}
				pfcnt++;
				p[i].pf = pfcnt;
				p[i].ph = phcnt;
			}
			i++;
		}

	}

	void dis()//DISPLAY THE MATRIX
	{
		System.out.println("\t\t ");
		System.out.println();
		System.out.print("RF\t  ");
		for(int i = 0 ; i < number ; i++)
		{
			System.out.print(p[i].pno + "\t");
		}
		System.out.println();
		System.out.println();
		for(int i = 0 ; i < frame ; i++)
		{
			System.out.print("Frame" + i + " \t");
			for(int j = 0 ; j < number ; j++)
			{
				System.out.print(p[j].arr[i] + "\t");
			}
			System.out.println();
		}
		System.out.println();
		System.out.print("PF\t  ");
		for(int j = 0 ; j < number ; j++)
		{
			System.out.print(p[j].pf + "\t");
		}
		System.out.println();
		System.out.println("\t\t ");
		System.out.println("THE NUMBER PAGE FAULT IS/ARE  " + p[number-1].pf);
		System.out.println("THE NUMBER PAGE HIT IS/ ARE " + p[number-1].ph);
		System.out.println(" ");
	}
}


public class allocate {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner Sc = new Scanner(System.in);

		pagerep sh = new pagerep();

		int choice = 0;
		do
		{	
			   System.out.println("---------------------------------------------------------------------------------------------------");
			    System.out.println("  ");
				System.out.println("PRESS 0 TO EXIT");
				System.out.println("PRESS 1 TO ACCEPT STRING");
				System.out.println("PRESS 2 TO DISPLAY STRING");
				System.out.println("PRESS 3 FOR FCFS");
				System.out.println("PRESS 4 FOR LRU");
				System.out.println("PRESS 5 FOR OPTIMAL");
				System.out.println("PLEASE ENTER YOUR CHOICE ");
				choice = Sc.nextInt();
				 System.out.println("--------------------------------------------------------------------------------------------------");
			switch(choice)
			{
			case 1:
				sh.accept();//accepting the reference string
				break;

			case 2:
				sh.display_ref();//display of reference string
				break;

			case 3:
				sh.fcfsalgo();//first come first serve algorithm
				sh.dis();
				break;

			case 4:
				sh.lru1();//least recently used algorithm
				sh.dis();
				break;

			case 5:
				sh.optimal1();//optimal algorithm
				sh.dis();
				break;

			}
		}while(choice != 0);
	}

}


/*
---------------------------------------------------------------------------------------------------
PRESS 0 TO EXIT
PRESS 1 TO ACCEPT STRING
PRESS 2 TO DISPLAY STRING
PRESS 3 FOR FCFS
PRESS 4 FOR LRU
PRESS 5 FOR OPTIMAL
PLEASE ENTER YOUR CHOICE 
1
--------------------------------------------------------------------------------------------------
ENTER THE REFERENCE STRING
1 2 3 4 5 1 2 5 3 2 1 5
ENTER THE NUMBER OF FRAMES 
3
---------------------------------------------------------------------------------------------------
  
PRESS 0 TO EXIT
PRESS 1 TO ACCEPT STRING
PRESS 2 TO DISPLAY STRING
PRESS 3 FOR FCFS
PRESS 4 FOR LRU
PRESS 5 FOR OPTIMAL
PLEASE ENTER YOUR CHOICE 
2
--------------------------------------------------------------------------------------------------
REFERENCE STRING IS  1 2 3 4 5 1 2 5 3 2 1 5
---------------------------------------------------------------------------------------------------
  
PRESS 0 TO EXIT
PRESS 1 TO ACCEPT STRING
PRESS 2 TO DISPLAY STRING
PRESS 3 FOR FCFS
PRESS 4 FOR LRU
PRESS 5 FOR OPTIMAL
PLEASE ENTER YOUR CHOICE 
3
--------------------------------------------------------------------------------------------------
		 
RF	  1	2	3	4	5	1	2	5	3	2	1	5	
Frame0 	1	1	1	4	4	4	2	2	2	2	2	2	
Frame1 	-1	2	2	2	5	5	5	5	3	3	3	3	
Frame2 	-1	-1	3	3	3	1	1	1	1	1	1	5	
PF	  1	2	3	4	5	6	7	7	8	8	8	9	
		 
THE NUMBER PAGE FAULT IS/ARE  9
THE NUMBER PAGE HIT IS/ ARE 3
 
---------------------------------------------------------------------------------------------------
  
PRESS 0 TO EXIT
PRESS 1 TO ACCEPT STRING
PRESS 2 TO DISPLAY STRING
PRESS 3 FOR FCFS
PRESS 4 FOR LRU
PRESS 5 FOR OPTIMAL
PLEASE ENTER YOUR CHOICE 
4
--------------------------------------------------------------------------------------------------
		 
RF	  1	2	3	4	5	1	2	5	3	2	1	5	
Frame0 	1	1	1	4	4	4	2	2	2	2	2	2	
Frame1 	-1	2	2	2	5	5	5	5	5	5	1	1	
Frame2 	-1	-1	3	3	3	1	1	1	3	3	3	5	
PF	  1	2	3	4	5	6	7	7	8	8	9	10	
		 
THE NUMBER PAGE FAULT IS/ARE  10
THE NUMBER PAGE HIT IS/ ARE 2
 
---------------------------------------------------------------------------------------------------
  
PRESS 0 TO EXIT
PRESS 1 TO ACCEPT STRING
PRESS 2 TO DISPLAY STRING
PRESS 3 FOR FCFS
PRESS 4 FOR LRU
PRESS 5 FOR OPTIMAL
PLEASE ENTER YOUR CHOICE 
5
--------------------------------------------------------------------------------------------------
		 
RF	  1	2	3	4	5	1	2	5	3	2	1	5	
Frame0 	1	1	1	1	1	1	1	1	1	1	1	1	
Frame1 	-1	2	2	2	2	2	2	2	2	2	2	2	
Frame2 	-1	-1	3	4	5	5	5	5	3	3	3	5	
PF	  1	2	3	4	5	5	5	5	6	6	6	7	
		 
THE NUMBER PAGE FAULT IS/ARE  7
THE NUMBER PAGE HIT IS/ ARE 5
 
---------------------------------------------------------------------------------------------------
  
PRESS 0 TO EXIT
PRESS 1 TO ACCEPT STRING
PRESS 2 TO DISPLAY STRING
PRESS 3 FOR FCFS
PRESS 4 FOR LRU
PRESS 5 FOR OPTIMAL
PLEASE ENTER YOUR CHOICE 
*/
© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
