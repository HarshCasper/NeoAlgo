/*
 * A polygonal number is the number of equally spaced dots needed to draw a polygon.
 * It is given by the formula:
 *                                  Z = k/2 [2 + (k - 1)d]
 *        where k is the kth term and d is (number of vertices in the polygon - 2)
 *        
 * This program generates the first n polygonal numbers with input number of vertices.
 */
import java.util.*;

public class polygonal_number
{
    void main()
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter n: ");
        int n = scanner.nextInt();
        scanner.nextLine();
        
        System.out.println("Enter number of vertices: ");
        int d = scanner.nextInt();
        scanner.nextLine();
        
        d-=2;
        
        int k = 1;
        
        System.out.println("First "+n+" polygonal numbers with "+(d+2)+" vertices are:");
        while(k <= n)
        {
            System.out.print(polygonal(k,d)+", ");
            k++;
        }
    }
    int polygonal(int k, int d)
    {
        return (k*(2 + (k-1))*d)/2;
    }
}
            
/*
 * Test Case-
 * Enter n: 
 * 5
 * Enter number of vertices: 
 * 3
 * First 5 polygonal numbers with 3 vertices are:
 * 1, 3, 6, 10, 15, 
 * 
 * Time Complexity: O(n)
 * where n is the number of terms calculated
 * Space Complexity: O(n)
 */            