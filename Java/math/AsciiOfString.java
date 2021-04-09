/*
AIM :: Take a string form the user.
	   Consider each individual character and print the corresponding ASCII code of that character.
*/
import java.util.Scanner;

public class AsciiOfString {

    public static void main(String[] args) {

        //taking user input of string
        System.out.print("Enter the string :: ");
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();

        // printing all the characters with their ASCII code
        for (int i = 0; i < str.length(); i++)
            System.out.println(str.charAt(i) + " = " + (int) str.charAt(i));
    }
}

/*
TEST CASE

Enter the string :: ANAND
A = 65
N = 78
A = 65
N = 78
D = 68

TIME COMPLEXITY  :: O(n)
SPACE COMPLEXITY :: O(1)

 */

