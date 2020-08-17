import java.util.*;

class BucketSort {

    private static void bucketSort(float[] arr, int k) {
        if (arr.length < 2)
            return;
        
        // getting upper limit for dividing numbers in buckets
        int length = arr.length;
        float max_val = arr[0];
        for (int i = 1; i<length; i++) {
            max_val = Math.max(max_val, arr[i]);
        }
        max_val += 1;

        //making bucket list and adding buckets in it
        ArrayList<ArrayList<Float>> bucketList = new ArrayList<ArrayList<Float>>();
        for (int i=0; i<k; i++) {
            bucketList.add(new ArrayList<Float>());
        }

        //dividing numbers in different buckets
        for (int i=0; i<length; i++) {
            int bucketIndex = (int) ((arr[i] * k) / max_val);
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
        Scanner sc = new Scanner(System.in);

        //taking input array
        System.out.println("Enter size of array:");
        int size = sc.nextInt();
        float arr[] = new float[size];
        System.out.println("Enter array elements:");
        for (int i=0; i<size; i++) {
            arr[i] = sc.nextFloat();
        }
        System.out.println("Enter number of buckets:");
        int bucketNum = sc.nextInt();

        // before sorting
        System.out.println("Array before bucket sort:");
        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        bucketSort(arr, bucketNum);

        // after sorting
        System.out.println("Array after Bucket sort:");
        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        sc.close();
    }
}