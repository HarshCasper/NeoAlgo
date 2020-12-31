import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Scanner;

/*Priority Queue data structure is a special queue in which the elements are present not as per FIFO order 
 *but as per the natural elements or any xyz comparator used during queue creation.
*/

public class PriorityQueueEg {
    
    private static Scanner sc = new Scanner(System.in);

    public static void printingthequeue(PriorityQueue<String> queue) {
        Iterator iterator = queue.iterator();  
        while(iterator.hasNext())
        { 
            System.out.print(iterator.next() + " ");  
        }  
    }

    public static void main(String args[])
    {  
        System.out.println("Kindly enter the number of strings in the queue: ");
        int n = sc.nextInt();

        PriorityQueue<String> queue = new PriorityQueue<String>();  
        
        //taking n strings as input from the user
        for(int i=0;i<n;i++)
        {
            System.out.println("Kindly enter the "+i+"'th element");
            queue.add(sc.next());
        }

        //print the head of the PriorityQueue
        System.out.println("PriorityQueue Head : "+ queue.element());  
        
        //Define the iterator for PriorityQueue and print its elements 
        System.out.println("\nPriorityQueue : "); 

        //to print the queue, using Iterator
        printingthequeue(queue);
    }

}

/*
Output:

Kindly enter the number of strings in the queue:                                                                                              
3                                                                                                                                             
Kindly enter the 0'th element                                                                                                                 
ram                                                                                                                                           
Kindly enter the 1'th element                                                                                                                 
seeta                                                                                                                                         
Kindly enter the 2'th element                                                                                                                 
geeta                                                                                                                                         
PriorityQueue Head : geeta                                                                                                                    
PriorityQueue :                                                                                                                               
geeta seeta ram   

*/

