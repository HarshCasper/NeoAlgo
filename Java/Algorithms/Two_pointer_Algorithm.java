 /*
  * It's the use of two different pointers (usually to keep track of array or string indices)
  * to solve a problem involving said indices with the benefit of saving time and space.
  *
  */
 import java.util.Scanner;
 public class two_pointer {
   public two_pointer(int array[], int k) {
     int j = array.length - 1;
     while (j > 0) {
       for (int i = 0; i < j; i++) {
         if (array[i] + array[j] > k) {
         --j;
           if (i == j) {
             break;
            }
          }
         /*
          * Check if sum of two digit is equal to k or not.
          * if it is equal to the value of k then print those digits.
          */
           if (array[i] + array[j] == k) {
             System.out.println("The sum of these two digit " + array[i] + "," + array[j] + "will be equal to k");
             break;
          }
          j--;
       }
    }
  }
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    System.out.println("Please enter length of the array : ");
    int l = scan.nextInt();
    System.out.println("Please enter value the sum you want to be : ");
    int k = scan.nextInt();
    int array[] = new int[l];
    for (int n = 0; n < l - 1; n++) {
      array[n] = scan.nextInt();
    }
    two_pointer obj = new two_pointer(array, k);
  }
}
 /*
  * Time complexity is O(n)
  * Space complexity is O(n)
  *
  * Input :
  * Please enter length of the array :
  * 10
  * Please enter value the sum you want to be :
  * 10
  * enter array
  * 2 3 4 4 5 6 7 8 9 1
  *
  * OUTPUT :
  * The sum of these two digit 4,6 will be equal to 10
  * */