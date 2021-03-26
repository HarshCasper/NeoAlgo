//AIM :: to print the ASCII CODE of each character of entered string

import java.util.Scanner;

public class ASCII_code_of_each_character_of_string {

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
TEST CASE 1

Enter the string :: ANAND
A = 65
N = 78
A = 65
N = 78
D = 68

TEST CASE 2

Enter the string :: anand
a = 97
n = 110
a = 97
n = 110
d = 100

 */
