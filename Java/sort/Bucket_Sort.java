/* Sorting floating point numbers in ascending order betweent the range of 0.0 to 0.1 by bucket sort
   hash(float value) : Returns the value of key multiplied with 10
   bucket_sorting(float[] list) : Creates 10 bucktes and sorts them */
import java.util.*;
class Bucket_Sort {
    /* Multiplying each value of the array with 10*/
    public static float hash(float value) {
        return value * 10;
    }
    public static List < Float > bucket_sorting(float[] list) {
        /* The bucket sorted array*/
        List < Float > sorted = new ArrayList < > ();
        //Creates 10 bucktes
        List < List < Float >> buckets = new ArrayList < > (10);
        for (int i = 0; i < 10; i++)
            buckets.add(new ArrayList < > ());
        // inputting values in buckets depending on values from list
        for (float values: list) {
            float key = hash(values);
            buckets.get((int) key).add(values);

        }
        //sorting individual buckets and adding them 
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets.get(i) != null) {
                Collections.sort(buckets.get(i));
                sorted.addAll(buckets.get(i));
            }
        }
        return sorted;
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter size of array. N = ");
        int n = sc.nextInt();
        float arr[] = new float[n];
        System.out.println(" Enter the elements of the array");
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextFloat();
        System.out.println("Sorted array : " + "\n" + bucket_sorting(arr));
    }
}

/* Sample Input and Output :
 * Enter size of array. N = 5
 Enter the elements of the array
0.5 0.4 0.3 0.2 0.6
Sorted array : 
[0.2, 0.3, 0.4, 0.5, 0.6]

Worst Time Complexity : O(n^2)
Average Time Complexity : O(n)

Space Complexity : O(1)
 */