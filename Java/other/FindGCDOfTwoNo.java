import java.util.*;

/*
A program to find the gcd of two numbers
GCD= Greatest common divisor
*/

public class FindGCDOfTwoNo{

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        //taking the two numbers as input from the user
        System.out.println("Kindly enter the two numbers: ");
        int a = sc.nextInt();
        int b = sc.nextInt();

        int gcd = findgcd(a,b);

        System.out.println("The GCD of "+a+" and "+b+" = "+gcd);
    }

    //method to find the gcd of two numbers
    private static int findgcd(int a, int b) 
    {
        //the loop executes until the two numbers are equal to each other
        while(a!=b)   
        {  
            if(a>b)  
                a=a-b;  
            else  
                b=b-a;  
        }  
        return b;
    }
}

/*
Output:

Kindly enter the two numbers:
14
16
The GCD of 14 and 16 = 2

Kindly enter the two numbers:
18
1034
The GCD of 18 and 1034 = 2

Kindly enter the two numbers:
48
120
The GCD of 48 and 120 = 24

*/

