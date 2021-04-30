/*
The worst fit strategy is a reverse of the best-fit strategy. It allocates the largest block available in the storage list.
The idea behind worst-fit is to reduce the rate of production of small blocks. The below program is an implementation of
the worst fit algorithm using array data structure.
*/

import java.util.Scanner;
//Block class is used as the fixed memory blocks for allocation
class Block {
    int size;
    int ID;
    int fragment;
}
// process class is used for allocating memory for the requesting processes
class process {
    int Num;
    int size;
    Block block;
}

class Code {
    // initialiseBlocks function initializes all the blocks with sizes and id
    void initialiseBlocks(Block arr[], int sizes[], int n) {
        for (int i = 0; i < n; i++) {
            arr[i].size = sizes[i];
            arr[i].fragment = sizes[i];
            arr[i].ID = i + 1;
        }
    }
    // printResult function prints the result of the memory allocation strategy
    void printResult(process arr2[], int numOfprocess) {
        System.out.println(
            "Process No            Process Size          Block ID          Block Size         Block Fragment\n");
        for (int i = 0; i < numOfprocess; i++)
            System.out.println(arr2[i].Num + "                     " + arr2[i].size + "                     "
                               + arr2[i].block.ID + "                     " + arr2[i].block.size + "                     "
                               + arr2[i].block.fragment + "\n");
    }
    // worstfit function allocates memory to processes using worstfit allocation algorithm
    void worstfit(Block arr[], int sizes[], int n, process arr2[], int numOfprocess) {
        initialiseBlocks(arr, sizes, n);
        Block maxBlock = new Block();
        for (int i = 0; i < numOfprocess; i++) {
            int max = 0;
            for (int j = 0; j < n; j++) {
                if (arr2[i].size <= arr[j].fragment && arr[j].fragment > max) {
                    max = arr[j].fragment;
                    maxBlock = arr[j];
                }
            }
            maxBlock.fragment = maxBlock.fragment - arr2[i].size;
            arr2[i].block = maxBlock;
        }
        System.out.println("\nWORST FIT ALLOCATION\n");
        printResult(arr2, numOfprocess);
    }
    // Driver code
    public static void main(String[] args) {
        int sizes[] = { 60, 20, 12, 35, 64, 42, 31, 35, 40, 50 };
        Block arr[] = new Block[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = new Block();
        }
        Code c = new Code();
        c.initialiseBlocks(arr, sizes, 10);
        System.out.println("Enter the number of process for memory to be allocated");
        int numOfProcess;
        Scanner sc = new Scanner(System.in);
        numOfProcess = sc.nextInt();
        System.out.println("Enter the sizes required by the processes in the order of requirement");
        process[] arr2 = new process[numOfProcess];
        for (int i = 0; i < numOfProcess; i++) {
            arr2[i] = new process();
        }
        for (int i = 0; i < numOfProcess; i++) {
            arr2[i].size = sc.nextInt();
            arr2[i].Num = i + 1;
        }
        sc.close();
        c.worstfit(arr, sizes, 10, arr2, numOfProcess);
    }
}

/*
Sample I/O:
Enter the number of process for memory to be allocated
5
Enter the sizes required by the processes in the order of requirement
10 20 11 12 13

WORST FIT ALLOCATION
Process No            Process Size          Block ID          Block Size         Block Fragment
     1                     10                   5                  64                  54
     2                     20                   1                  60                  40
     3                     11                   5                  64                  43
     4                     12                   10                 50                  38
     5                     13                   5                  64                  30

Time complexity : O(n)
space complexity : O(n)

*/
