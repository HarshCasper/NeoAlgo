/* Find Subarray of an array with given sum in O(n) time.

Input :
arr[]={1,4,20,3,10,5} ; sum=33
Output :
Sum found between indexes 2 and 4
 * 
 */
// to find Subarray of an array with given sum in O(n) time
import java.util.*;
class Subarray {
    public static void findsubarray(List < Integer > arr, int sum) {
        int startindex = 0, endindex = 0, tempsum = 0;
        boolean flag = true;
        while (tempsum != sum) {
            if (tempsum < sum) {
                tempsum += arr.get(endindex);
                endindex += 1;
            } else if (tempsum > sum) {
                tempsum -= arr.get(startindex);
                startindex += 1;
            }
            if (endindex == arr.size()) {
                flag = false;
                tempsum = sum;
            }

        }
        if (flag)
            System.out.println("Sum found between indexes " + startindex + " and " + (endindex - 1));
        else
            System.out.println(" No such subarray found");
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        List < Integer > arr = new ArrayList < > ();
        System.out.print("Enter sum : ");
        int sum = sc.nextInt();
        System.out.println("Enter elements of array");
        while (sc.hasNextInt())
            arr.add(sc.nextInt());
        //System.out.println(arr);
        findsubarray(arr, sum);

    }
}

/* Sample Input and Output : 
 * Enter sum : 33
Enter elements of array
1 4 20 3 10 5
Sum found between indexes 2 and 4
Enter sum : 33
Enter elements of array
1 4 20 3 20 5
No such subarray found

Time Complexity : O(n)
Space Complexity : O(1)
 */
