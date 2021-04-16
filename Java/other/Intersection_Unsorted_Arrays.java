/*
This is the solution to find the intersection array of two unsorted arrays without using the built in set intersection method.
There should be no duplicate elements in the result array and the order of the elements does not matter.
Display an error message if no intersecting elements found.

NOTE : set1.retainAll(set2) is the built-in method to find the intersection of two sets, set1 and set2.

Approach:
1)Add all the elements of the first array to a set.
2)Traverse the second array and check if each element is present in the set.
	If present,add this element to the result array.
	Remove this element from the set so that no duplicates are present in the result array.
3)Return the result array with its final length.
*/


import java.util.*;
public class Intersection_Unsorted_Arrays {

    //Function which finds the intersection array of the two unsorted arrays and returns it.
    public static int[] intersection(int[] nums1, int[] nums2) {
        Set < Integer > elements = new HashSet < Integer > ();
        //Add all the elements of nums1 to the set
        for (Integer i: nums1) {
            elements.add(i);
        }
        //The maximum length of result array will be the size of the set
        int[] result = new int[elements.size()];
        int c = 0;
        //Check for common elements in nums2
        for (Integer i: nums2) {
            if (elements.contains(i)) {
                result[c++] = i;
                elements.remove(i);
            }
        }
        //Return copy of array because the result array size can be smaller than the set size
        return Arrays.copyOf(result, c);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of elements in first array");
        int len1 = sc.nextInt();
        int[] nums1 = new int[len1];
        System.out.println("Enter elements of first array");
        for (int i = 0; i < len1; i++) {
            nums1[i] = sc.nextInt();
        }

        System.out.println("Enter number of elements in second array");
        int len2 = sc.nextInt();
        int[] nums2 = new int[len2];
        System.out.println("Enter elements of second array");
        for (int i = 0; i < len2; i++) {
            nums2[i] = sc.nextInt();
        }

        int[] result = intersection(nums1, nums2);
        if (result.length == 0)
            System.out.println("No intersection elements present");
        else {
            System.out.println("Intersection array is:");
            for (int i: result)
                System.out.print(i + " ");
        }
        sc.close();
    }
}
/*
Sample Input:
Enter number of elements in first array
4
Enter elements of first array
4
6
9
4
Enter number of elements in second array
6
Enter elements of second array
8
5
4
9
4
6

Sample Output:
Intersection array is:
4 9 6

Time Complexity : O(len1+len2),where len1 and len2 are the lengths of the two arrays
Space Complexity  : O(n)
*/
