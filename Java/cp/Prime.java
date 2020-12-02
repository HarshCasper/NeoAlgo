// check whether a number is Prime or not without recursion

import java.util.Scanner;
class Prime
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a number : ");
        int n=(int)Math.abs(sc.nextInt());
        int c=0;
        for(int i=2;i<n;i++)
        if (n%i==0)
        c++;
        System.out.println(n+((c==0)?" is a Prime Number." :" is not a Prime Number."));
    }
}

// Contributed By ErzaTitani-2001

/*
Sample Input and Output :
Input :
Enter a number : 13
Output :
13 is a Prime Number.
Space  Complexity : O(1)
Time Complexity : O(n)
*/
