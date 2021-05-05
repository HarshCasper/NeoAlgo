/*
First fit is the simplest of all the storage allocation strategies.
Here the list of storages is searched and as soon as a free storage block of size >= N is found ,
the pointer of that block is sent to the calling program after retaining the residue space.Thus, for example,
for a block of size 5k , 2k memory will be sent to the caller . The below program is a simulation of the first fit strategy
using array data structure.
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
    // firstfit function allocates memory to processes using firstfit allocation algorithm
    void firstfit(Block arr[], int sizes[], int n, process arr2[], int numOfprocess) {
        initialiseBlocks(arr, sizes, n);
        for (int i = 0; i < numOfprocess; i++) {
            for (int j = 0; j < n; j++) {
                if (arr2[i].size <= arr[j].fragment) {
                    arr[j].fragment = arr[j].fragment - arr2[i].size;
                    arr2[i].block = arr[j];
                    break;
                }
            }
        }
        System.out.println("\nFIRST FIT ALLOCATION\n");
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
        c.firstfit(arr, sizes, 10, arr2, numOfProcess);
    }
}

/*
Sample I/O:

Enter the number of process for memory to be allocated
5
Enter the sizes required by the processes in the order of requirement
15 12 13 20 11

FIRST FIT ALLOCATION
Process No            Process Size          Block ID          Block Size         Block Fragment
     1                     15                   1                  60                  45
     2                     12                   1                  60                  33
     3                     13                   1                  60                  20
     4                     20                   1                  60                  0
     5                     11                   2                  20                  9

Time complexity : O(n)
Space complexity : O(n)
*/
