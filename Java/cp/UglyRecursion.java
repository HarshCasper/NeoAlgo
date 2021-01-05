//finding nth ugly number using recursion
import java.util.Scanner;
class UglyRecursion
{
   
       public static int ugly(int n) 
    { 
        
        if (n == 1)  //base cases
            return 1; 
        if (n <= 0) 
            return 0; 
        if (n % 2 == 0)  
            return (ugly(n / 2)); 
        
        if (n % 3 == 0) 
            return (ugly(n / 3)); 
        
        if (n % 5 == 0)  
            return (ugly(n / 5)); 
        
        return 0; 
    } 
  
       
    
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("N= ");
        int n=sc.nextInt();
        int i=1;
        while(n>0)
        { if(ugly(i)==1)
            n-=1;
            i++;
        }
        System.out.println(i--); //to avoid the last increment,we decrement by one
    }
}


/* Sample Input
   Input:
N = 10
Output: 12
Time Complexity : O(n)
Space Complexity : O(1)*/