// check whether a number is Prime or not with recursion

import java.util.Scanner;
class PrimeRecursion
{
    public static int prime(int n,int div)
    {
        if(div<n)
        { if(n%div!=0)
            prime(n,div+1);
            else
            return 0;
        }
        return 1;
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a number : ");
        int n=(int)Math.abs(sc.nextInt());
        int c=prime(n,2);
        System.out.println(n+((c!=0)?" is a Prime Number." :" is not a Prime Number."));
    }
}

// Contributed By ErzaTitani-2001

/*
Sample Input and Output :
Input :
Enter a number : 13
Output :
13 is a Prime Number.
Space Complexity : O(n)
Time Complexity : O(n)
*/
