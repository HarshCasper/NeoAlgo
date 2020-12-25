import java.util.Iterator;
import java.util.PriorityQueue;
import java.lang.*;

//Priority Queue data structure is a special queue in which the elements are present not as per FIFO order but as per the natural elements or any xyz comparator used during queue creation.

public class PriorityQueueEg {

    public static void main(String args[])
    {  

        PriorityQueue<String> cities_queue = new PriorityQueue<String>();  

        cities_queue.add("Sydney");  
        cities_queue.add("Venice");  
        cities_queue.add("New York");  
        cities_queue.add("California");  
        cities_queue.add("Melbourne");  

        //print the head of the PriorityQueue
        System.out.println("PriorityQueue Head:"+cities_queue.element());  
        //Define the iterator for PriorityQueue and print its elements 

        System.out.println("\nPriorityQueue contents:"); 
        
        Iterator iter=cities_queue.iterator();  
        while(iter.hasNext()){ 
            System.out.print(iter.next() + " ");  
        }  

    }

}
/*
Output:
PriorityQueue Head:California

PriorityQueue contents:
California Melbourne Sydney Venice New York 
*/
