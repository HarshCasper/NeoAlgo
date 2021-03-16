
/*
Problem:
Solving Quadratic equations in Java-
A program that prints all real solutions to quadratic equation ax^2+bx+c=0, if discriminant is negative displays a message "roots are imaginary". 
*/
import java.util.*;
import java.io.*;

public class Quadratic_Equation {

  public static void main(String[] args) {

    // value a, b, and c
    double a, b, c;
    double x, y;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter coefficients of the equation:");
    System.out.print("Enter a: ");
    a = sc.nextDouble();
    System.out.println();
    System.out.print("Enter b: ");
    b = sc.nextDouble();
    System.out.println();
    System.out.print("Enter c: ");
    c = sc.nextDouble();
    System.out.println();
    // If a is 0, then equation is not quadratic, but
    // linear
    if (a == 0) {
      System.out.println("Its a linear equation,Not a quadratic equation!");
      return;
    }
    // calculate the discriminant (b^2 - 4ac)
    double discriminant = b * b - 4 * a * c;

    // check if discriminant is greater than 0
    if (discriminant > 0) {

      // two real and distinct roots
      x = (-b + Math.sqrt(discriminant)) / (2 * a);
      y = (-b - Math.sqrt(discriminant)) / (2 * a);
      System.out.println("Roots are real and distinct");
      System.out.format("root1 = %.2f and root2 = %.2f", x, y);
    }

    // check if determinant is equal to 0
    else if (discriminant == 0) {

      // two real and equal roots
      // discriminant is equal to 0

      x = y = -b / (2 * a);
      System.out.println("Equal roots");
      System.out.format("root1 = root2 = %.2f;", x);
    }

    // if discriminant is less than zero
    else {

      // roots are complex number
      double real = -b / (2 * a);
      double imaginary = Math.sqrt(-discriminant) / (2 * a);
      System.out.println("Imaginary roots!");
      System.out.format("root1 = %.2f+%.2fi", real, imaginary);
      System.out.format("\nroot2 = %.2f-%.2fi", real, imaginary);
    }

  }
}

/*
Sample Test Cases:

Test case 1:
Enter coefficients of the equation:
Enter a: 1

Enter b: -4

Enter c: 0

Roots are real and distinct
root1 = 4.00 and root2 = 0.00

Test case 2:
Enter coefficients of the equation:
Enter a: 7.2

Enter b: 5

Enter c: 9

Imaginary roots!
root1 = -0.35+1.06i
root2 = -0.35-1.06i

Test case 3:
Enter coefficients of the equation:
Enter a: 1

Enter b: -2

Enter c: 1

Equal roots
root1 = root2 = 1.00;

*/