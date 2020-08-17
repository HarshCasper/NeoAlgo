import java.util.*;

class BucketSort {

    private static void bucketSort(int[] arr, int k) {
        if (arr.length < 2)
            return;
        
        // getting upper limit for dividing numbers in buckets
        int length = arr.length;
        int max_val = arr[0];
        for (int i = 1; i<length; i++) {
            max_val = Math.max(max_val, arr[i]);
        }
        max_val += 1;

        //making bucket list and adding buckets in it
        ArrayList<ArrayList<Integer>> bucketList = new ArrayList<ArrayList<Integer>>();
        for (int i=0; i<k; i++) {
            bucketList.add(new ArrayList<Integer>());
        }

        //dividing numbers in different buckets
        for (int i=0; i<length; i++) {
            int bucketIndex = (arr[i] * k)/max_val;
            bucketList.get(bucketIndex).add(arr[i]);
        }

        // sorting each bucket one by one
        for (int i=0; i<k; i++) {
            Collections.sort(bucketList.get(i));
        }

        //joining buckets
        int pos = 0;
        for (int i=0; i<k; i++) {
            for (int j=0; j<bucketList.get(i).size(); j++) {
                arr[pos] = bucketList.get(i).get(j);
                pos += 1;
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = {49, 72, 26, 11, 99, 61, 34, 93, 89, 81};

        System.out.println("Array before bucket sort:");
        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        bucketSort(arr, 5);

        System.out.println("Array after Bucket sort:");
        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}