/**
 * Ciruclar Queue is a Data Structure which operates on the FIFO (First In First Out) Principle.
 * The pointers to the first and last element are dynamic. 
 *                               
 *          First element -> O - O                   Last element -> O - O <- First element
 *                          /     \                                 /     \
 *          Last element -> O     O      may also be                O     O
 *                          \     /                                 \     /
 *                           O - O                                   O - O 
 * 
 * 
 *       O - O - O - O - O - O           may also be         O - O - O - O - O - O
 *       ^                   ^                               ^   ^
 *      first               last                           last first
 * 
 * In a normal Queue, we can insert elements until queue becomes full. But once queue becomes full, 
 * we can not insert the next element even if there is a space in front of queue. This is possible
 * in Circular Queues and hence is a optimizes space consumption.
 */

import java.util.*;
public class CircularQueue
{
    int cq[];
    int first, last;

    CircularQueue(int size)
    { 
        //This is a default constructor to declare Circular Queue and global parameters first and last.
        cq = new int[size];
        first =-1;
        last = -1;
    }

    public void insert(int value)
    {
        /**
         * This function is used to insert an element into the circular queue. 
         * In a circular queue, the new element is always inserted at last position. 
         * Steps:
         * 1. Check if Circular Queue cq is full (first==0 && last==cq.length-1 || first==last+1).
         * 2. If it is full then display "Overflow" and return to main function. If Circular Queue is not full then go to Step 3. 
         * 3. Check if (first==-1).
         *    If it is, then set first=last=0.
         *    Else check if (last==cq.length-1).
         *    If it is, then set last=0.
         *    Else increment last by 1.
         * 4. Insert value at position last.
         */
        if(first==0 && last==cq.length-1 || first==last+1)
        { 
            System.out.println("Overflow"); return;
        }
        else if(first==-1)
        {
            first=last=0;
        }
        else if(last==cq.length-1)
        {
            last=0;
        }
        else
        {
            last++;
        }
        cq[last]=value;
    }

    public int delete()
    {
        /**
         * This function is used to delete an element from the Circular Queue. 
         * In a circular queue, the element is always deleted from first position. 
         * Steps:
         * 1. Check if the Circular Queue cq is empty (first==-1).
         * 2. If it is empty then display "Underflow" and return 0. If the Circular Queue is not empty then go to Step 3.
         * 3. Check if (first==last).
         *    If it is, then call reset function [first=last=-1].
         *    Else check if (first==cq.length-1).
         *    If it is, then set first=0.
         *    Else increment first by 1.
         * 4. Return the element at position first.
         */

        if(first==-1)
        {
            System.out.println("Underflow"); return 0; 
        }
        else
        {
            int temp = cq[first];
            if(first==last)
            { 
                reset(); 
            }
            else if(first==cq.length-1)
            {
                first=0;
            }
            else
            {
                first++;
            }
            return temp;
        }
    }

    private void display()
    {
        /**
         * This function is used to display a Circular Queue.
         * Steps:
         * 1. Check if Circular Queue is empty (first==-1)
         * 2. If it is empty then display "Circular Queue is Empty". If the Circular Queue is not empty then go to Step 3.
         * 3. Start for loop from the position pointed by variable first, incrementing i by 1.
         *    Check if i points to end of Circular Queue.
         *    If it does, then initialize first as 0.
         * 4. Print the element at i.
         * 5. Check if i points to last (i==last)
         *    If it does, then all the elements are printed. Break.
         *    
         */
        if(first==-1)
        {
            System.out.print("Circular Queue is Empty");
            return;
        }
        
        for(int i = first; ; i++)
        {
            if(i==cq.length)
            {
                i=0;
            }

            System.out.print(cq[i]+" ");

            if(i==last)
            {
                break;
            }
        }
        System.out.println();
    }

    void reset()
    {
        /**
         * This function is used to reset first and last to original values -1.
         */
        first=last=-1;
    }

    void main()
    {
        /** 
         * This function serves as a driver code.
         * It follows a menu driven approach and gives user the options to 
         * or delete an element from the Circular Queue or display its elements
         * and calls the appropriate functions to do so.
         * It contniues until the user enter 0 (no).
         */
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number of elements: ");
        int size = scanner.nextInt(); scanner.nextLine();

        CircularQueue ob = new CircularQueue(size);

        int flag=1;

        while(flag==1)
        {
            System.out.println("Choose from following: ");
            System.out.println("1. Insert an element");
            System.out.println("2. Delete an element");
            System.out.println("3. Display the elements: ");
            System.out.println("Enter choice: ");
            int choice = scanner.nextInt(); scanner.nextLine();

            switch(choice)
            {
                case 1:
                System.out.println("Enter element: ");
                int value = scanner.nextInt(); scanner.nextLine();
                ob.insert(value);
                break;

                case 2:
                if(ob.delete()!=0)
                { 
                    System.out.println("Deleted element: "+ob.delete());
                }
                break;

                case 3:
                System.out.println("Displaying the queue");
                ob.display();
                break;
            }

            System.out.println("Do you wish to continue? Enter 1 for YES or 0 for NO: ");
            flag = scanner.nextInt(); scanner.nextLine();
        }
    }
}

/**
    Test Case:
    
    Enter number of elements: 
    5
    -> Inserting an element
    Enter element: 
    14
    -> Inserting an element
    Enter element: 
    50
    -> Inserting an element
    Enter element: 
    -10
    -> Inserting an element
    Enter element: 
    -78
    -> Inserting an element
    Enter element: 
    45
    -- Displaying the queue
    14 50 -10 -78 45 
    -> Inserting an element
    Enter element: 
    60
    Overflow
    <- Deleting an element
    Deleted element: 14
    -- Displaying the queue
    50 -10 -78 45 
    -> Inserting an element
    Enter element: 
    60
    -- Displaying the queue
    50 -10 -78 45 60 
    <- Deleting an element
    Deleted element: 50
    <- Deleting an element
    Deleted element: -10
    <- Deleting an element
    Deleted element: -78
    <- Deleting an element
    Deleted element: 45
    <- Deleting an element
    Deleted element: 60
    <- Deleting an element
    Underflow
    -- Displaying the queue
    Circular Queue is Empty
*/
   
 /**
  * Time Complexity:
  * insert - O(1)
  * delete - O(1)
  * display - O(n)
  * 
  * Space Complexity:
  * O(n)
  * 
  * where n is number of elements
 */
