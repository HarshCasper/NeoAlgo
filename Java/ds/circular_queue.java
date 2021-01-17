import java.util.*;
import java.lang.*;

public class Main
{
    public  static int front;
    public static int rear;
    public static int arr[];
    public static int size;
    
    Main(int n) //Constructor
    {
        front =-1;
        rear=-1;
        size=n;
        arr=new int[n];
    }
    ///////////////////////////////////////////////////////////////
    public void getFront()
    {
        if(front ==-1)
             System.out.println("Queue is Empty.");
        else
            System.out.println("Front : "+arr[front]);
    }
    ///////////////////////////////////////////////////////////////
    public void getRear()
    {
        
        if(rear ==-1)
             System.out.println("Queue is Empty.");
        else
            System.out.println("Rear : "+arr[rear]);
    }
    //////////////////////////////////////////////////////////////
    public void Enqueue(int value)
    {
           
           if(front==-1)
           {
               front = 0;
               rear = 0;
               arr[rear]=value;
           }
           else if(rear == size-1 && front !=0)
           {
               rear=0;
               arr[rear]=value;
           }
           else{
                rear++;
                arr[rear]=value;
           }
    }
    //////////////////////////////////////////////////////////////
    public static void Dequeue()
    {
        int data=arr[front];
        arr[front]=-1;
        if(front ==rear)
        {
            front=-1; rear=-1;
        }
        else if(front ==size-1)
        {
            front =0;
        }
        else{
            front++;
        }
        System.out.print("Deleted : "+ data);
        
    }
    //////////////////////////////////////////////////////////////
    public static void main(String []args)  //main function
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the size of queue : ");
        int size = sc.nextInt();
        Main m = new Main(size);
        do
        {
                System.out.println("\n1. Enqueue");
                System.out.println("2. Dequeue");
                System.out.println("3. Front");
                System.out.println("4. Rear");
                System.out.println("5. Exit");
                
                System.out.println("Enter your choice (1 - 5)");
                int ch=sc.nextInt();
                
                switch(ch)
                {
                    case 1:
                        {
                            // checking for full condition
                            if(front ==0 && rear ==size-1 || (rear ==(front-1)%(size-1)))
                                 System.out.println("Queue is Full.");
                            else  
                            {
                                 System.out.print("Enter the value to insert :");
                                 int value=sc.nextInt();
                                 m.Enqueue(value);
                            }
                                
                        }
                        break;
                    case 2:
                        {
                            // checking if empty
                            if(front==-1)
                                System.out.println("Queue is Empty.");
                            else
                                Dequeue();
                        }
                        break;
                    case 3:
                        {
                            m.getFront();
                        }
                        break;
                    case 4:
                        {
                            m.getRear();
                        }
                        break;
                    case 5:
                        {
                            System.exit(0);
                        }
                        break;
                    default:
                        System.out.println("Invalid Choice ! Try again.");
                        break;
                }
                
        }while(true);   
         
    }

}