/*
Check Alphabet, Digit, Special Character

For a given character from the user, 
your task is to check if that character is an 
alpabet, or a digit, or a special charter, and print it accordingly.
For example if the character is a digit print "Digit".
*/

import java.io.*;
import java.util.Scanner;

class Alpha_Digit_Spechar
{
    static void inputCheck(char c)
    {
    //Checking for alphabet
    if((c>=65 && c<=90) || (c>=97 && c<=122))
        System.out.println(" Alphabet ");
        
    //checking for digits
    else if(c>=48 && c<=57)
        System.out.println(" Digit ");

    // otherwise special Character
    else
        System.out.println(" Special Charcter ");

    }

    //driver code    
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of test cases: ");
        int t = sc.nextInt();
        while(t!=0){
            System.out.println("Enter any character: ");
            char c = sc.next().charAt(0);
            inputCheck(c);
            t--;
        }
    }
}

/*
EXAMPLE 1:-
Input--
Enter the number of test cases: 4
Enter any character: a
Enter any character: A
Enter any character: 2
Enter any character: @
Output--
Alphabet
Alphabet
Digit
Special Charcter 
*/
