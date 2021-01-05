import java.util.*;

/*
A program to check whether a string is palindrome or not.
A plaindrome string is a string which is same to its reverse.
eg. 1234321, radar etc.
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
        //creating an empty string to store the reverse of string_1
        String string_2 = "";

        //we iterate starting from the end of the string_1
        //storing the reverse in string_2

        /*
        string.length() returns the length of the string
        eg. length() of strinf = radar, equals 5
        But since the index starts from 0, we subtract 1 from the length while initializing.
        */
        for(int i=string_1.length()-1;i>=0;i--)
        {
            string_2 = string_2 + string_1.charAt(i);
        }

        //comparing both the string to see if they are equal
        if(string_1.equals(string_2))
            return true;
        else 
            return false;
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

