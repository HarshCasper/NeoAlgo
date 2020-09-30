import java.util.Scanner;

public class RecursionCount {

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter first string:");
        String str1 = scanner.nextLine();
        System.out.println("Enter second string:");
        String str2 = scanner.nextLine();
        scanner.close();

        System.out.println("Number of occurrences of \"" + str2 + "\" in \"" + str1 + "\":" + countSubstring(str1, str2));
    }

    static int countSubstring(String str1, String str2) {
        // recursive function
        if(str1.contains(str2)) {
            return 1 + countSubstring(str1.replaceFirst(str2, ""), str2);
        } else {
            return 0;
        }
    }
}
/*
* Sample input/output:
* Enter first string:
* abcdabc
* Enter second string:
* abc
* Number of occurrences of "abc" in "abcdabc":2
*
* Time complexity: O(n)
*/
