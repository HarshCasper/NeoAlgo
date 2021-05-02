//                      Best Fit , First Fit , Worst Fit

//      Simulate first-fit, best-fit and worst-fit memory allocations

/*

    FIRST FIT (FF) 
*A resource allocation scheme (usually for memory). 
*First Fit fits data into memory by scanning from the beginning of available memory to the end, 
until the first free space which is at least big enough to accept the data is found.
*This space is then allocated to the data.
*Any left over becomes a smaller, separate free space. 
*If the data to be allocated is bigger than the biggest free space, 
the request cannot be met, and an error will be generated


    BEST FIT (BF) 
*The best fit deals with allocating the smallest free partition which meets the requirement of the requesting process. 
*This algorithm first searches the entire list of free partitions and considers the smallest hole that is adequate.
*It then tries to find a hole which is close to actual process size needed.


    WORST FIT (WF) 
*The algorithm searches for free-space in memory in which it can store the desired information. 
*The algorithm selects the largest possible free space that the information can be stored on 
(i.e. that is bigger than the information needing to be stored) and stores it there.
*This is directly opposed to the best fit algorithm which searches the memory in much the same way as before.



*/

import java.util.*;

public class MemoryAllocations {

    // Array for storing the size of differnt memory blocks
    static int block[] = new int[10];

    // Array for storing the size of memory
    // required by each process
    static int process[] = new int[10];

    static int i;
    static int j;
    static int b;
    static int p;

    public static void initialize() {

        // Creating Scanner Object to read input from user
        Scanner t = new Scanner(System.in);

        // Fill the number of blocks
        System.out.println("Enter the number of memory blocks");
        b = t.nextInt();

        // Fill the size of the blocks
        System.out.println("Enter the size of each memory block");
        for (i = 0; i < b; i++) {
            block[i] = t.nextInt();
        }

        // Fill the number of processes
        System.out.println("Enter the number of processes");
        p = t.nextInt();

        // Fill the size of the processes
        System.out.println("Enter the size of each process");
        for (i = 0; i < p; i++) {
            process[i] = t.nextInt();
        }

    }

    // Function to implement first fit allocation
    public static void firstfit() {

        int flag[] = new int[10];
        int allocated[] = new int[10];

        // Function call to initialize memory and process blocks
        initialize();

        System.out.println("First-Fit Memory Allocation");

        // Initially no block is assigned to any process
        for (i = 0; i < 10; i++) {
            flag[i] = 0;
            allocated[i] = -1;
        }

        /* pick each process and find suitable blocks
         according to its size and assign to it */
        for (i = 0; i < p; i++) {
            for (j = 0; j < b; j++) {
                if (flag[j] == 0 && block[j] >= process[i]) {
                    allocated[j] = i;
                    flag[j] = 1;
                    break;
                }
            }
        }

        // printing result after memory allocation
        System.out.println("Block no.\tsize\t\tprocess no.\t\tsize");

        for (i = 0; i < b; i++) {

            System.out.printf("\n%d\t\t%d\t\t", i + 1, block[i]);

            if (flag[i] == 1)
                System.out.printf("%d\t\t\t%d", allocated[i] + 1, process[allocated[i]]);

            else
                System.out.printf("Not allocated");

        }
    }

    // Function to implement best fit allocation
    public static void bestfit() {

        final int barray[] = new int[20];
        final int parray[] = new int[20];
        int fragment[] = new int[20];
        int temp;
        int lowest = 9999;

        // Function call to initialize memory and process blocks
        initialize();

        System.out.println("Best-Fit Memory Allocation");

        /* pick each process and find suitable blocks
         according to its size and assign to it
        */
        for (i = 0; i < p; i++) {

            // Find the best fit block for current process
            for (j = 0; j < b; j++) {

                if (barray[j] != 1) {

                    temp = block[j] - process[i];

                    if (temp >= 0) {

                        if (lowest > temp) {

                            parray[i] = j;

                            lowest = temp;
                        }
                    }
                }
            }
            // Remaining Size of that particular block selected after memory allocation
            fragment[i] = lowest;

            barray[parray[i]] = 1;

            lowest = 10000;

        }

        // printing result after memory allocation
        System.out.printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");

        for (i = 0; i < p && parray[i] != 0; i++)
            System.out.printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, process[i], parray[i], block[parray[i]], fragment[i]);

    }

    // Function to implement worst fit allocation
    public static void worstfit() {

        int temp;
        int highest = 0;
        int fragments[] = new int[10];
        final int blockArr[] = new int[10];
        final int fileArr[] = new int[10];

        // Function call to initialize memory and process blocks
        initialize();

        System.out.printf("\n Worst-Fit Memory Allocation");
        for (i = 0; i < p; i++) {
            // Find the best fit block for current process
            for (j = 0; j < b; j++) {

                if (blockArr[j] != 1) {

                    temp = block[j] - process[i];

                    if (temp >= 0) {

                        if (highest < temp) {

                            fileArr[i] = j;
                            highest = temp;

                        }
                    }
                }

                // Remaining Size of that particular block selected after memory allocation
                fragments[i] = highest;
                blockArr[fileArr[i]] = 1;
                highest = 0;
            }

        }

        // printing result after memory allocation
        System.out.printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment");
        for (i = 0; i < p; i++) {

            System.out.printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, process[i], fileArr[i], block[fileArr[i]],
                    fragments[i]);

        }
        System.out.printf("\n");

    }

    public static void main(String[] args) {

        int choice;
        boolean flag = true;

        System.out.println("Press 1 to simulate first-fit memory allocation");
        System.out.println("Press 2 to simulate best-fit memory allocation");
        System.out.println("Press 3 to simulate worst-fit memory allocation");
        System.out.println("Press 4 to exit");
        System.out.println();

        while (flag) {
            System.out.printf("\nEnter the choice\n");
            // Creating Scanner Object to read input from user
            Scanner s = new Scanner(System.in);

            // Read the choice given by the user
            choice = s.nextInt();

            switch (choice) {
            case 1:
                firstfit();
                break;
            case 2:
                bestfit();
                break;
            case 3:
                worstfit();
                break;

            case 4:
                flag = false;
                break;
            }

        }

    }
}



/*
 * TEST CASES
 * 
 * 
 * Press 1 to simulate first-fit memory allocation 
 * Press 2 to simulate best-fit memory allocation 
 * Press 3 to simulate worst-fit memory allocation 
 * Press 4 to exit
 * 
 * 
 * Enter the choice 
 * 2 
 * Enter the number of memory blocks 
 * 5 
 * Enter the size of each memory block 
 * 10 15 5 9 3 
 * Enter the number of processes 
 * 4 
 * Enter the size of each process 
 * 1 4 7 12 
 * 
 * Best-Fit Memory Allocation
 * Process_no   Process_size   Block_no   Block_size  Fragment
 *  0           1              4          3           2          
 *  1           4              2          5           1 
 *  2           7              3          9           2
 *  3           12             1          15          3
 * 
 * 
 * Enter the choice 
 * 3 
 * Enter the number of memory blocks 
 * 5 Enter the size of each memory block 
 * 5 4 3 6 7 
 * Enter the number of processes 4 
 * Enter the size of each process 
 * 1 3 5 3
 * 
 * Worst-Fit Memory Allocation
 * File Number   File Size   Block Number   Block Size  Fragment 
 * 0             1           4              7           6 
 * 1             3           0              5           0 
 * 2             5           0              5           0 
 * 3             3           0              5           0
 * 
 * 
 * 
 * Enter the choice 
 * 1 
 * Enter the number of memory blocks 
 * 3 
 * Enter the size of each memory block 
 * 12 7 4 
 * Enter the number of processes 
 * 3 
 * Enter the size of each process 
 * 7 4 9 
 * 
 * First-Fit Memory Allocation
 * Block no.     size      process no.   size
 * 
 * 1             12        1              7 
 * 2             7         2              4 
 * 3             4         3              Not allocated
 * 
 * 
 * 
 * 
 */


  
