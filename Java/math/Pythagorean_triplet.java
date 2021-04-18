//A program to check that if a given set of numbers(a,b,c) is a valid pythagorean triplet.
//It will print The given set of numbers is a pythagorean triplet if they can form a pythagorean triplet and The given set of numbers is not a pythagorean triplet otherwise.
// A "Pythagorean Triple" is a set of positive integers, a, b and c that fits the rule: a^2 + b^2 = c^2

import java.util.*;

public class Pythagoreantriplet {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the three numbers:");
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();

        //taking out squares of the 3 numbers
        int asquare = a * a;
        int bsquare = b * b;
        int csquare = c * c;

        //comparing the combinations of number for pythagorean triplet
        //checks a^2+b^2=c^2
        if (asquare + bsquare == csquare)
        System.out.println("The given set of numbers is a pythagorean triplet");

        //checks b^2+c^2=a^2
        else if (bsquare + csquare == asquare)
        System.out.println("The given set of numbers is a pythagorean triplet");
        
        //checks a^2+c^2=b^2
        else if (asquare + csquare == bsquare)
            System.out.println("The given set of numbers is a pythagorean triplet");

        //if none of the condition is true then it is not a pythagoren triplet
        else
            System.out.println("The given set of numbers is not a pythagorean triplet");
    }
}

/*
Standard Input Output

 sample 1

 Enter the three numbers:
 5 
 3 
 4
 The given set of numbers is a pythagorean triplet

Sample 2

 Enter the three numbers:
 17 
 56
 24
 The given set of numbers is not a pythagorean triplet

 Time complexity: o(1)
 Space complexity:o(1)

*/
