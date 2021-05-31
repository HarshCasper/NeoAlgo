/*
A Queue is a linear structure which follows a particular order in which the operations are performed.
The order is First In First Out. The below program reverses a queue using stack data structure.
Here stack and queue are implemented using linked list.
*/

import java.util.Scanner;

class Stack
{
    int data;
    Stack next;
}
class Queue
{
    int data;
    Queue next;
}

class Code{
    static Stack top = null;
    static Queue front = null;
    static Queue rear = null;
    static void push(int n)
    {
        Stack New = new Stack();
        if (top == null)
        {
            top = New;
            top.data = n;
            top.next = null;
        }
        else
        {
            New.next = top;
            top = New;
            top.data = n;
        }
    }
    static int pop()
    {
        if (top != null)
        {
            Stack ptr = top;
            top = top.next;
            return ptr.data;
        }
        return 0;
    }
    static boolean isStackEmpty()
    {
        if (top == null)
        {
            return true;
        }
        return false;
    }
    static boolean isQueueEmpty()
    {
        if (front == null)
        {
            return true;
        }
        return false;
    }
    static void enqueue(int n)
    {
        Queue New = new Queue();
        if (front == null)
        {
            front = New;
            rear = front;
            front.data = n;
            rear.next = null;
        }
        else
        {
            rear.next = New;
            New.data = n;
            rear = New;
            rear.next = null;
        }
    }
    static int dequeue()
    {
        if (front != null)
        {
            Queue ptr = front;
            front = front.next;
            return ptr.data;
        }
        return 0;
    }
    static void printQueue()
    {
        Queue ptr = front;
        while (ptr != null)
        {
            System.out.println(ptr.data);
            ptr = ptr.next;
        }
    }
    static void reverseQueue()
    {
        while (!isQueueEmpty())
        {
            push(dequeue());
        }
        while (!isStackEmpty())
        {
            enqueue(pop());
        }
    }
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements to insert into queue");
        n = sc.nextInt();
        int temp;
        System.out.println("Enter the elements");
        for (int i = 0; i < n; i++)
        {
            temp = sc.nextInt();
            enqueue(temp);
        }
        System.out.println("Elements in the queue");
        printQueue();
        System.out.println("Elements in queue after reversing using stack");
        reverseQueue();
        printQueue();   
    }
}
/*
Sample I/O:

Enter the number of elements to insert into queue
5
Enter the elements
2 4 3 1 5
Elements in the queue
2
4
3
1
5
Elements in queue after reversing using stack
5
1
3
4
2

Time complexity : O(n)
Space complexity : O(n)
*/