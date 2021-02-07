// Java solution for longest palindrome in a substring
import java.util.*;
 
class GFG{
 
// Function to print longest subString
static void printSubStr(String str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        System.out.print(str.charAt(i));
}

static int longestPallindromeSubstr(String str)
{
    // get length of input String
    int n = str.length();

    int maxLength = 1, start = 0;
 
    // Nested loop to mark start and end index
    for (int i = 0; i < str.length(); i++) {
        for (int j = i; j < str.length(); j++) {
            int f = 1;
 
            // Check palindrome
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str.charAt(i + k) != str.charAt(j - k))
                    f = 0;
            if (f!=0 && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }
 
    System.out.print("Longest palindrome subString is: ");
    printSubStr(str, start, start + maxLength - 1);

    return maxLength;
}
 
public static void main(String[] args)
{
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter word");
    String str = sc.nextLine();
    System.out.print("\nLength of longest pallindrome substring is: "
         + longestPallindromeSubstr(str));
}
}