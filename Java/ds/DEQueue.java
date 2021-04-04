/**
 * Double Ended Queue is a linear data structure which follows both -
 * LIFO(Last In First Out) and FIFO(First In First Out).
 * 
 * Push Front  ---> O - O - O - O - O - O <---  Push Rear
 *                  |   |   |   |   |   |
 *   Pop Front <--- O - O - O - O - O - O ---> Pop Rear
 *              ^                   ^
 *            First                Last
 *           (Front)              (Rear)
 *            
 * The code has six methods:
 * void pushfront(int) - to insert a value at the front end of the queue
 * void pushrear(int) - to insert a value at the rear end of the queue
 * int popfront() - to delete a value from the front end of the queue
 * int poprear() - to delete a value from the rear end of the queue
 * void display() - to display the queue
 * void main() - driver code to execute all the methods
 * 
 * In addition to the methods, the code also has a default constructor DEQueue(int)
 * to initialize the global parameters:
 * integer array dequeue[] - to store the elements
 * integer variable elements - to keep a count of the number of elements in the queue
 * integer variable front - to point at the front end of the dequeue
 * integer variable rear - to point at the rear end of the dequeue
 * 
 * To take input from the user, Scanner class has been instantiated.
 * 
 */

import java.util.*;

public class DEQueue
{
    Scanner scanner = new Scanner(System.in);

    int dequeue[], elements, front, rear;

    DEQueue(int size)
    {
        dequeue = new int[size];
        elements=0;
        front=-1;
        rear=-1;
    }

    void pushfront(int value)
    {
        if(elements==dequeue.length)
        { 
            System.out.println("Overflow");
        }
        else
        {
            if(front==0)
            {
                System.out.println("Front full");
            }
            else
            {
                elements++;
                front--;
                dequeue[front]=value;
            }
        }
    }

    void pushrear(int value)
    {
        if(elements==dequeue.length)
        {
            System.out.println("Overflow");
        }
        else
        {
            elements++;
            rear++;
            if(front==-1)
            {
                front=0;
            }
            dequeue[rear]=value;
        }
    }

    int popfront()
    {
        int temp=0;
        if(elements==0)
        {
            System.out.println("Underflow");
        }
        else
        {
            temp=dequeue[front];
            front++;
            elements--;
            if(elements==0)
            {
                front=-1;
                rear=-1;
            }
        }
        return temp;
    }

    int poprear()
    {
        int temp=0;
        if(elements==0)
        {
            System.out.println("Underflow");
        }
        else
        {
            temp=dequeue[rear];
            rear--;
            elements--;
            if(elements==0)
            {
                front=-1;
                rear=-1;
            }
        }
        return temp;
    }

    void display()
    {
        if(elements==0)
        {
            System.out.println("Queue is empty!");
        }
        else
        {
            for(int pointer=front; pointer<=rear; pointer++)
            {
                System.out.print(dequeue[pointer]+" ");
            }
            System.out.println();
        }
    }

    void main()
    {
        // Driver code to call all the methods, until the user wishes

        System.out.println("Enter size of the dequeue: ");
        int size = scanner.nextInt(); 
        scanner.nextLine();

        DEQueue ob = new DEQueue(size);

        int flag=1,value;

        System.out.println("Which function would you like to implement?");
        System.out.println("1. Inserting element in the front of the dequeue");
        System.out.println("2. Inserting element in the rear of the dequeue");
        System.out.println("3. Deleting element from the front of the dequeue");
        System.out.println("4. Deleting element from the rear of the dequeue");
        System.out.println("5. Displaying the dequeue");

        while(flag!=0)
        {
            System.out.println("Enter your choice");
            int choice = scanner.nextInt(); 
            scanner.nextLine();
            
            switch(choice)
            {
                case 1:
                System.out.println("Enter element to be inserted: ");
                value = scanner.nextInt(); scanner.nextLine();
                    ob.pushfront(value);
                break;

                case 2:
                System.out.println("Enter element to be inserted: ");
                value = scanner.nextInt(); scanner.nextLine();
                    ob.pushrear(value);
                break;

                case 3:
                    ob.popfront();
                break;

                case 4:
                    ob.poprear();
                break;

                case 5:
                    ob.display();
                break;
            }
            System.out.println("Would you like to continue? Enter 1 for YES and 0 for NO:");
            flag = scanner.nextInt(); 
            scanner.nextLine();
        }
    }
}

/* Test Case-
Enter size of the dequeue: 
5
Which function would you like to implement?
1. Inserting element in the front of the dequeue
2. Inserting element in the rear of the dequeue
3. Deleting element from the front of the dequeue
4. Deleting element from the rear of the dequeue
5. Displaying the dequeue
Enter your choice
2
Enter element to be inserted: 
1
Would you like to continue? Enter 1 for YES and 0 for NO:
1
Enter your choice
2
Enter element to be inserted: 
2
Would you like to continue? Enter 1 for YES and 0 for NO:
1
Enter your choice
2
Enter element to be inserted: 
3
Would you like to continue? Enter 1 for YES and 0 for NO:
1
Enter your choice
5
1 2 3 
Would you like to continue? Enter 1 for YES and 0 for NO:
1
Enter your choice
3
Would you like to continue? Enter 1 for YES and 0 for NO:
1
Enter your choice
5
2 3 
Would you like to continue? Enter 1 for YES and 0 for NO:
1
Enter your choice
4
Would you like to continue? Enter 1 for YES and 0 for NO:
1
Enter your choice
5
2 
Would you like to continue? Enter 1 for YES and 0 for NO:
1
Enter your choice
4
Would you like to continue? Enter 1 for YES and 0 for NO:
1
Enter your choice
5
Queue is empty!
Would you like to continue? Enter 1 for YES and 0 for NO:
0
*/  
   
/* Time Complexity: O(1)
Space Complexity: O(size) */
 
