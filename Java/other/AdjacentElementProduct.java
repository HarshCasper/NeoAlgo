/*Find the pair of adjacent elements that have the largest product   
 in a given array and return that product.
 
 Example: Let a={3, 6, -2, -5, 7, 3} be an array, then adjacent
 elements at position 4 & 5 i.e. 7 & 3 in the given array
 have the maximum product among adjacent elements = 21.
 Hence, the method will return 21.
 */

import java.util.*;

public class AdjacentElementProduct {
    //method to find largest adjacent elements product
    public static int largest_product(int[] arr) {
        /*let the initial max_prod be product of first two elements &
         then go on comparing it with the next adjacent element's products.
         If it is more then current max_prod value, update max_prod value. 
         */
        int max_product = arr[0] * arr[1];
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] * arr[i + 1] > max_product) {
                max_product = arr[i] * arr[i + 1];
            }
        }
        return max_product;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of the array : ");
        int n = sc.nextInt();

        int[] a = new int[n];
        System.out.print("Enter array elements : ");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        System.out.print("Largest adjacent elements product is : " 
                         +largest_product(a));
    }
}

/*SAMPLE TEST CASE:
Enter size of the array : 10
Enter array elements : 2 -9 30 4 -8 10 11 7 -61 100
Largest adjacent elements product is : 120

Time Complexity : O(n)
Space Complexity : O(n)
*/
