/*
 * A generalised Cullen Number is defined as a number in the form:
 * 
 *             (k x b^k) + 1   with   k + 2 > b
 *             where b is the base
 * 
 * This program gives the user the first n cullen numbers of base b.
 */

import java.util.*;

public class cullen_number
{
    void main()
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter base b: ");
        int b = scanner.nextInt(); 
        scanner.nextLine();
        
        System.out.println("Enter number of terms n: ");
        int n = scanner.nextInt(); 
        scanner.nextLine();
        
        int k = b-1,count = 0;
        
        System.out.println("First "+n+" cullen numbers with base "+b+" are: ");
        while(count<n)
        {
            System.out.print(cullen(k,b)+", ");
            k++;
            count++;
        }
    }
    
    int cullen(int k, int b)
    {
        //this function the (count)th cullen number
        return (int)(k * Math.pow(b,k))+1;
    }
}
        
/*
 * Test Case-
 * 
 * Enter base b: 
 * 3
 * Enter number of terms n: 
 * 5
 * First 5 cullen numbers with base 3 are: 
 * 19, 82, 325, 1216, 4375, 
 * 
 * Time Complexity: O(n)
 * where n is the number of terms extracted.
 * Space Complexity: O(n)
 */            