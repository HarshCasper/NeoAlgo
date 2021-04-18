/*
A program which find the value of the equation F(x)=Σn.(-1)^n,where n lies between 1 to x.
x is any given integer.
The program works for t number of testcases
*/

import java.util.*;
class equation
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        /*Input the number of testcases for which the program will work*/
        System.out.println("Enter the number of testcases");
        int t=sc.nextInt();
        while(t--!=0)
        {
            int s=0;
            /*Taking x as input*/
            System.out.println("Enter the last value of range");
            int x=sc.nextInt();
            for(int i=1;i<=x;i++)
            {
                /*Calcualting the value of s for odd numbers*/
                if(i%2!=0)
                s=s-i;
                /*Calculating the value of s for even numbers*/
                else
                s=s+i;
            }
            /*Printing the value of equation for each x*/       
            System.out.println("The value of equation is "+s);
        }
        }
    }

/*
Time Complexity:O(x)
Space Complexity:O(1)

Input/Output:
Enter the number of testcases
2
Enter the last value of range
5
The value of equation is -3
Enter the last value of range
8
The value of equation is 4
*/
