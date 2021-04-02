import java.util.*;
class Min_Element_Rotated_array {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the elements");
        int min = sc.nextInt();
        while (sc.hasNextInt()) {
            int num = sc.nextInt();
            if (num < min)
                min = num;
        }
        System.out.println(" Minimum element in the list : " + min);
    }
}
/* Sample Input and Output :
 * Minimum element in the list : 2
Enter the elements
3
4
5
1
2

 Minimum element in the list : 1
Time Complexity : O(n)
Space Complexity : O(1)
 */
