//Implementation of nth fibonacci number using Dynamic Programming approach
import java.util.Scanner;
class Solution{
        
        public static void main(String[] args){
                int n;
                //Scanner class object to take user input
                Scanner sc = new Scanner(System.in);
                System.out.println("Insert a Number:");
                n = sc.nextInt();
                //DP array to store the previous results so that we can use it
                //for calculating further solution
                int[] fibo = new int[n];
                //Initialize dp[0] to 0 and dp[1] to 1
                //Initial values for fibonacci series
                fibo[0] = 0;
                fibo[1] = 1;
                //Loop array until we get nth fibonacci series
                //As we know next element in fibonacci series is sum of previous two numbers
                for(int i=2;i<n;i++){
                        fibo[i] = fibo[i-1]+ fibo[i-2];
                }
                //Print the last element as nth fibonacci number
                System.out.println(n+"th fibonacci number is "+fibo[n-1]);
                
                //If you want to print whole fibonacci series
                /*System.out.println("Fibonacci Series: ");
                for(int i=0;i<n;i++){
                        System.out.print(fibo[i] + " ");
                }
                */
        } 

}
