import java.util.*;


class Node
{
    int data;
    Node next;
    Node(int d) {
        data = d;
        next = null;
    }
}

 class LinkedList_Intersection
{
    Node head = null;
	Node tail = null;

public void addToTheLast(Node node)
{

  if (head == null) {
   head = node;
   tail = head;
  } else {
   //Node temp = head;
   //while (temp.next != null)
    //temp = temp.next;

   //temp.next = node;
   tail.next=node;
   tail = node;
  }
}

  /* Function to print linked list */
    void printList()
    {
        Node temp = head;
        while (temp != null)
        {
           System.out.print(temp.data+" ");
           temp = temp.next;
        }
        System.out.println();
    }



     /* Driver program to test above functions */
    public static void main(String args[])
    {


        /* Constructed Linked List is 1->2->3->4->5->6->
           7->8->8->9->null */
         Scanner sc = new Scanner(System.in);
		 int t=sc.nextInt();

		 while(t>0)
         {
			int n1 = sc.nextInt();
			int n2 = sc.nextInt();
			int n3 = sc.nextInt();
			LinkedList_Intersection llist1 = new LinkedList_Intersection();
		    LinkedList_Intersection llist2 = new LinkedList_Intersection();
			LinkedList_Intersection llist3 = new LinkedList_Intersection();

				int a1=sc.nextInt();
				Node head1= new Node(a1);
				Node tail1= head1;

				for (int i = 1; i < n1; i++)
				{
					int a = sc.nextInt();
					tail1.next = (new Node(a));
					tail1= tail1.next;
				}


				int b1=sc.nextInt();
				Node head2 = new Node(b1);
				Node tail2 = head2;
				for (int i = 1; i < n2; i++)
				{
					int b = sc.nextInt();
					tail2.next = (new Node(b));
					tail2= tail2.next;
				}

				int c1=sc.nextInt();
				Node head3= new Node(c1);
				tail1.next = head3;
				tail2.next = head3;
				Node tail3=head3;
				for (int i = 1; i < n3; i++)
				{
					int c = sc.nextInt();
					tail3.next = (new Node(c));
					tail3= tail3.next;
				}

				Intersect obj = new Intersect();
				System.out.println(obj.intersectPoint(head1, head2));
			t--;
         }
    }
}
// } Driver Code Ends


/* Node of a linked list
 class Node {
   int data;
    Node next;
    Node(int d)  { data = d;  next = null; }
}
 Linked List class
class LinkedList
{
    Node head;  // head of list
}
This is method only submission.  You only need to complete the method. */
class Intersect
{
	int intersectPoint(Node headA, Node headB)
	{
        Node n1 = headA;
        Node n2 = headB;
        HashSet <Node> hs=new HashSet<>();
        int i=0;

        while(n1!=null){
            hs.add(n1);
            n1=n1.next;

        }
        while(n2!=null){
            if(hs.contains(n2)){
                i=n2.data;
                break;
            }else{
                n2=n2.next;

            }


        }
           return i;

	}
}
