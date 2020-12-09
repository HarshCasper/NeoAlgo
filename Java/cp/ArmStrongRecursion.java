// Checking Armstrong number with Recursion

import java.util.Scanner;
class ArmStrongRecursion
{
    static int p;
    public static int armstrong(int i)
    { if(i<10) //base class
        return (int)(Math.pow(i,p));
        else
        return((int)Math.pow(i%10,p)+armstrong(i/10));
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("N = ");
        int n=sc.nextInt();
        p=Integer.toString(n).length(); //calculating the number of digits in the number by converting it into String

        if(n==armstrong(n))
        System.out.println(n+" is an Armstrong number");
        else
        System.out.println(n+" is not an Armstrong number");
    }
}

/*
Sample Input and Output :
N = 153
153 is an Armstrong number
Space Complexity: O(1)
Time Complexity : O(p)
*/
