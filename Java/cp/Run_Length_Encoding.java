/*
Given an input string, write a code that returns the Run Length Encoded string for the input string.
For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6”
*/

public class Encoding 
{
    // for encoding
    public static void encodingString(String str)
    {
        // lenght of the string
        int len = str.length();
        // for traversing through the string
        for (int i = 0; i < len; i++) 
        {
 
            // counter occurrences of current character
            int counter = 1;
            while (i < len - 1 && str.charAt(i) == str.charAt(i + 1)) 
            {
                counter++;
                i++;
            }

            // printing the character and counter
            System.out.print(str.charAt(i));
            System.out.print(counter);
        }
    }
 
    public static void main(String[] args)
    {
        // taking input of the string 
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter a string: ");  
        String str= sc.nextLine();    
        System.out.println("Encoded string : ");
        encodingString(str);
    }
}

/**
Time complexity : O(N)
Space complexity : O(1)
 */

/**
Test case :
 Input :
    Enter the string to encode 
    tttyyss
 Output :
    Encoded string
    t3 y2 s2 

*/ 