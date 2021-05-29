
/**
 * Implementing Stacks Using Arrays.
 * 
 * A stack is a linear Data Structure while follows LIFO (Last In First Out).
 * An element in a stack is always pushed (inserted) or popped (deleted) from the top.
 * 
 * Visualizing:
 * 
 *            O - O
 *            |   | <- top
 *            O - O
 *            |   |
 *            O - O
 *            |   |
 *            O - O
 *            
 * This code has four methods:
 * void push (int) - to insert an element in the stack
 * void pop() - to delete an element from the stack
 * void display() - to dispaly the stack
 * void main() - driver code to execute all the methods
 * 
 * In addition to the methods, the code also has a default constructor 
 * StackUsingArrays(int) to initialize the global parameters:
 * integer array stack[] - to store the elements
 * integer variable top - to point at the top of the stack
 * 
 * To take input from the user, Scanner class has been instantiated.
 * 
 */

import java.util.*;

public class StackUsingArrays
{
    int stack[];
    int top;

    StackUsingArrays(int size)
    {
        stack = new int[size];
        top = -1;
    }

    public void push(int value)
    {
        /* Algorithm:
         * 1. Check if the queue is full (top == stack.length-1).
         *      If true, queue is full, print "Overflow" and exit.
         *      If false, queue is not full, go to Step 2.
         * 2. Increment the top by 1.
         * 3. Assign the memory space pointed by top the value received as formal parameter.
         */
        if(top == stack.length-1)
        {
            System.out.println("Overflow");
        }
        else
        {
            top++;
            stack[top] = value;
        }
    }

    public void pop()
    {
        /* Algorithm:
         * 1. Check if the queue is empty (top == -1).
         *      If true, queue is full, print "Underflow" and exit.
         *      If false, queue is not full, go to Step 2.
         * 2. Initialize temporary variable the value pointed by top
         * 3. Decrement the top by 1.
         * 4. Display the temp variable is popped.
         */
        if(top == -1)
        {
            System.out.println("Underflow");
        }
        else
        {
            int temp = stack[top];
            top--;
            System.out.println(temp+" is popped");
        }
    }

    public void display()
    {
        System.out.println("Displaying the stack");
        for(int pointer = top; pointer>=0; pointer--)
        {
            System.out.println(stack[pointer]);
        }
    }

    public static void main()
    {
        // Driver code to call all the methods, until the user wishes
        
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter size of stack: ");
        int size = scanner.nextInt();
        scanner.nextLine();

        StackUsingArrays ob = new StackUsingArrays(size);

        System.out.println("Choose from the following: ");
        System.out.println("1. Insert an element");
        System.out.println("2. Delete an element");
        System.out.println("3. Displaying the stack");

        int flag=1;

        while(flag!=0)
        {
            System.out.println("Please enter your choice:");
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch(choice)
            {
                case 1:
                        System.out.println("Enter value: ");
                        int value = scanner.nextInt();
                        scanner.nextLine();
                        ob.push(value);
                        break;

                case 2:
                        ob.pop();
                        break;

                case 3:
                        ob.display();
                        break;
            }
            
            System.out.println("Do you wish to continue? Enter 1 for YES and 0 for NO:");
            flag = scanner.nextInt();
            scanner.nextLine();
        }
    }
}

/*
 * Test Case-
 * 
Enter size of stack: 
3
Choose from the following: 
1. Insert an element
2. Delete an element
3. Displaying the stack
Please enter your choice:
1
Enter value: 
1
Do you wish to continue? Enter 1 for YES and 0 for NO:
1
Please enter your choice:
1
Enter value: 
2
Do you wish to continue? Enter 1 for YES and 0 for NO:
1
Please enter your choice:
1
Enter value: 
3
Do you wish to continue? Enter 1 for YES and 0 for NO:
1
Please enter your choice:
3
Displaying the stack
3
2
1
Do you wish to continue? Enter 1 for YES and 0 for NO:
1
Please enter your choice:
2
3 is popped
Do you wish to continue? Enter 1 for YES and 0 for NO:
1
Please enter your choice:
3
Displaying the stack
2
1
Do you wish to continue? Enter 1 for YES and 0 for NO:
0
*/

/*
 * Time Complexity: O(1)
 * Space Complexity: O(size)
 */
    
        
