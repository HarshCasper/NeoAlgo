
// Java program to implement Queue using two stacks with costly enQueue()  
import java.util.*; 
  
class QueuetoStack  
{  
static class Queue  
{  
    static Stack<Integer> stk1 = new Stack<Integer>();  
    static Stack<Integer> stk2 = new Stack<Integer>();  
  
    static void enQueue(int x)  
    {  
        // Move all elements from stk1 to stk2  
        while (!stk1.isEmpty()) 
        {  
            stk2.push(stk1.pop());  
            //stk1.pop();  
        }  
  
        // Push item into stk1  
        stk1.push(x);  
  
        // Push everything back to stk1  
        while (!stk2.isEmpty())  
        {  
            stk1.push(stk2.pop());  
            //stk2.pop();  
        }  
    }  
  
    // Dequeue an item from the queue  
    static int deQueue()  
    {  
        // if first stack is empty  
        if (stk1.isEmpty())  
        {  
            System.out.println("Q is Empty");  
            System.exit(0);  
        }  
  
        // Return top of stk1  
        int s = stk1.peek();  
        stk1.pop();  
        return s;  
    }  
};  
  
// Main method 
public static void main(String[] args)  
{  
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter limit");
    int n = sc.nextInt();
    Queue qu = new Queue();
    for(int i = 1; i <= n; i++)
       qu.enQueue(i);  
    for(int i = 1; i <= n; i++)
       System.out.println(qu.deQueue());  
    
}  
}


/* Time Complexity:
  1) Push operation: O(N).
  2) Pop operation: O(1).

Space Complexity: O(N).

Input:
10

Output:
1
2
3
4
5
6
7
8
9
10
*/
