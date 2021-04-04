/*
    Sleep sort is a sorting algorithm used to sort non-negative integers. Sleep sort works by creating a separate thread for each item in the input which is to be sorted and then each thread sleeps for an amount of time which is proportional to the value of corresponding array element. Therefore, the thread which is having the least amount of sleep time wakes up first and the element gets printed and then the second least element and so on. The largest element wakes up after a long time and then the element gets printed at the last and thus the output obtained is a sorted array.
        
*/

import java.util.Scanner;
import java.util.concurrent.*;

public class SleepSort {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of elements in an array: ");
        int number = sc.nextInt();

        System.out.println("\nEnter the elements in an array: ");
        int array[] = new int[number];

        for (int i = 0; i < number; i++) {
            array[i] = sc.nextInt();

        }
        sleepSort(array);
    }

    public static void sleepSort(int[] array) {
        
        // CountDownLatch in java is used to make sure that a task waits for other threads before it starts.
        // Here the task is going to wait for threads which is equal to array length before it starts.
        final CountDownLatch countDone = new CountDownLatch(array.length);
        System.out.println("\nThe sorted array is: ");
        
        for (final int num : array) {
            // Creates a new thread.
            new Thread(new Runnable() {
                public void run() {
                    // Decrements the count of the countDone
                    countDone.countDown();
                    try {
                        //Causes the current thread to wait until the countDone has counted down to zero
                        countDone.await();
                        Thread.sleep(num);
                        System.out.println(num);

                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
    }

}

/*
 * Output -
 * 
 * Enter the number of elements in an array: 7
 * 
 * Enter the elements in an array: 10 5 9 77 30 981 14
 * 
 * The sorted array is: 5 9 14 10 30 77 981
 *
 
Time Complexity -
    1. Best case - O(NlogN + max(input))
    2. Average case - O(NlogN + max(input))
    3. Worst case - O(NlogN + max(input))
    where N = number of elements in the input array, and array = input array elements
    
Space Complexity - O(N)
 
 */
