import java.util.*;

/*
A program to check whether a string is palindrome or not.
A plaindrome string is a string which is same to its reverse.
eg. 1234321, radar etc.
Time Complexity = O(n/2) //represents the number of operations to be performed by an algorithm to complete its task
Space Complexity = O(n) //represents the total space needed by the algorithm
*/

public class Palindrome {

    private static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {

        //the string entered by the user is stored in string_1
        System.out.println("Kindly enter the string: ");
        String string_1 = sc.nextLine();

        //to check if the string is palindrome or not
        Boolean check = ispalindrome(string_1);

        if(check==true)
            System.out.println(string_1+" is a palindrome.");
        else
            System.out.println(string_1+" is not a palindrome.");
    }

    //method to check if the string is a palindrome or not
    //method returns true if the string is a palindrome else it returns false
    private static boolean ispalindrome(String string_1) 
    {
        //storing the last index of the string in n
        int n =string_1.length() - 1;
        //comparing the characters of the string
        //first to the end and so on
        for (int i = 0; i < (n) / 2; i++) 
        {
           if (string_1.charAt(i) != string_1.charAt(n-i)) 
               return false;
        }
        return true; 
    }
}

/*
Output:

Kindly enter the string: 
1234321
1234321 is a palindrome.

Kindly enter the string: 
radar
radar is a palindrome.

Kindly enter the string: 
lol
lol is a palindrome.

Kindly enter the string: 
good
good is not a palindrome.

*/

