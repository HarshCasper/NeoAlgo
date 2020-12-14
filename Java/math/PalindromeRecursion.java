// Checking Palindrome number with Recursion

import java.util.Scanner;
class PalindromeRecursion
{
    static long revNum=0; //stored reversed number
    public static long palindrome(long i)
    { if(i>0) //base class
        { revNum=(revNum*10)+(i%10);
            palindrome(i/10);
        }
        else
        return revNum;
        return revNum;
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("N = ");
        long n=sc.nextLong();
        if(n==palindrome(n))
        System.out.println(n+" is a Palindrome number");
        else
        System.out.println(n+" is not a Palindrome number");
    }
}

/*
Sample Input and Output :
 N = 153
153 is not a Palindrome number
Space Complexity: O(1)
Time Complexity : O(i) i=Number of digits in n
*/
