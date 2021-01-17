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
        final CountDownLatch countDone = new CountDownLatch(array.length);
        System.out.println("\nThe sorted array is: ");
        for (final int num : array) {
            new Thread(new Runnable() {
                public void run() {
                    countDone.countDown();
                    try {

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
 */