import java.util.*;

class SubSequences {
    static void get_sequence(String str, String ans, int i) {
        // Base condition
        if (i == str.length()) {
            System.out.println("'"+ans+"'");
            return;
        }
        //Before character gets added to final
        get_sequence(str, ans, i + 1);
        //after character gets added to ans
        get_sequence(str, ans + str.charAt(i), i + 1);

    }

    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        String str;
        System.out.println("Enter the string");
        str = sc.nextLine();

        System.out.println("All possible subsequences are:");
        get_sequence(str, "", 0);
    }
}

/* output:
Enter the string
abcd
All possible subsequences are:
'' 'd' 'c' 'cd' 'b' 'bd' 'bc' 'bcd' 'a' 'ad' 'ac' 'acd' 'ab' 'abd' 'abc' 'abcd'

Time complexity : O(n^2)
space complexity : O(n)
*/
