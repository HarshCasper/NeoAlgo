
/* Java Program to implement a stack using two queue */
import java.util.*; 
  
class Stack_using_Queue { 
  
    static class Stack { 
        // Two inbuilt queues 
        static Queue<Integer> q1 = new LinkedList<Integer>(); 
        static Queue<Integer> q2 = new LinkedList<Integer>(); 
  
        // To maintain current number of elements 
        static int size; 
  
        Stack() 
        { 
            size = 0; 
        } 
  
        static void push(int x) 
        { 
           size++; 
  
            // Push x first in empty q2 
            q2.add(x); 
  
            // Push all the remaining 
            // elements in q1 to q2. 
            while (!q1.isEmpty()) { 
                q2.add(q1.peek()); 
                q1.remove(); 
            } 
  
            // swap the names of two queues 
            Queue<Integer> q = q1; 
            q1 = q2; 
            q2 = q; 
        } 
  
        static void pop() 
        { 
  
            // if no elements are there in q1 
            if (q1.isEmpty()) 
                return; 
            q1.remove(); 
            size--; 
        } 
  
        static int top() 
        { 
            if (q1.isEmpty()) 
                return -1; 
            return q1.peek(); 
        } 
  
        static int size() 
        { 
            return size; 
        } 
    } 
  
    // driver code 
    public static void main(String[] args) 
    { 
        Scanner sc = new Scanner(System.in);
        Stack s = new Stack(); 

        System.out.println("Enter the limit");
        int n = sc.nextInt();
        for(int i = 1; i <= n; i++)  //accepting input from user
          s.push(i); 
        
        for(int i = 1; i <= n; i++){
           System.out.println(s.top()); //printing the output
           s.pop(); 
    }
  
    } 
} 

/* Time Complexity : O(n)
   Space Complexity : O(n)

   Input
   5

   Output
    5
    4
    3
    2
    1
*/
