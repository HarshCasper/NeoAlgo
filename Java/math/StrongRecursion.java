//checking for a strong number using indirect recursion
import java.util.*;
class StrongRecursion
{
    public static int sofd(int n) //recursive function for sum of factorial of digits

    {
        if(n==0)
            return n;
        else
            return (factorial(n%10)+sofd(n/10));

    }

    public static int factorial(int n) //factorial of n
    {    
        if (n == 0)    
            return 1;    
        else    
            return(n * factorial(n-1));    
    }    

    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.print(" N = ");
        int num=sc.nextInt();
        if(num==sofd(num)) 
            System.out.println(" It is a Strong Number");
        else
            System.out.println(" It is not a Strong Number");
    }
}

/* Sample Input And Output ; 
 * N = 145
 * It is a Strong Number
 * N = 534
 *  It is not a Strong Number
 *  
 *  
 *  Time Complexity : O(n)
 *  Space Complexity : 1
 *  
 * 
 */
 