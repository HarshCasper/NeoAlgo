/*
Banker's Algorithm

Banker's Algorithm is a technique used for deadlock avoidance when there are multiple instances of a resource.
The banker's algorithm for deadlock-free resource allocation is one of the basic algorithms in concurrent and distributed systems.
User process may only request one resource at a time. System grants request only if the request will result in a safe state.
A state is considered to be safe if it is possible for all the processes to complete its execution without causing any deadlocks.
An unsafe state is the one in which the processes cannot complete its execution.

The time complexity for n processes and m resources is o(n*n*m).
The space complexity for n processes and m resources is o(n*m).
*/

import java.util.Scanner;

class algorithm {

    void display(int r, int p, int[] avail, int max[][], int need[][], int allocation[][], int res[]) {
        
        //Checking for available resources inline.
        System.out.println("THE MAXIMUM RESOURCES MATRIX IS AS FOLLOWS :");
        System.out.print("   ");
        for (int i = 0; i < r; i++) {
            System.out.print(" " + (i + 1));
        }
        System.out.println(" ");
        System.out.println("_______________________");
        for (int i = 0; i < p; i++) {
            System.out.print("P" + i + "|");
            for (int j = 0; j < r; j++) {
                System.out.print(" " + max[i][j]);
            }
            System.out.println(" ");
        }

        System.out.println(" ");

        System.out.println("THE ALLOCATION MATRIX IS AS FOLLOWS :");
        System.out.print("   ");
        for (int i = 0; i < r; i++) {
            System.out.print(" " + (i + 1));
        }
        System.out.println(" ");
        System.out.println("_______________________");
        for (int i = 0; i < p; i++) {
            System.out.print("P" + i + "|");
            for (int j = 0; j < r; j++) {
                System.out.print(" " + allocation[i][j]);
            }
            System.out.println(" ");
        }
        System.out.println("");


        System.out.print("AVAILABLE ARRAY IS :");
        for (int i = 0; i < r; i++) {
            int sum = 0;
            avail[i] = 0;
            for (int j = 0; j < p; j++) {
                sum = sum + allocation[j][i];
                avail[i] = res[i] - allocation[j][i];
            }
            avail[i] = res[i] - sum;
            System.out.print(avail[i] + "  ");
        }
        System.out.println(" ");
        System.out.println(" ");

        for (int i = 0; i < p; i++) {

            for (int j = 0; j < r; j++) {
                // Need of instance = maxm instance -allocated instance 
                need[i][j] = max[i][j] - allocation[i][j]; 
            }

        }
        System.out.println(" ");
        System.out.println("THE NEED MATRIX IS AS FOLLOWS :");
        System.out.print("   ");
        for (int i = 0; i < r; i++) {
            System.out.print(" " + (i + 1));
        }
        System.out.println(" ");
        System.out.println("_______________________");
        for (int i = 0; i < p; i++) {
            System.out.print("P" + i + "|");
            for (int j = 0; j < r; j++) {
                System.out.print(" " + need[i][j]);
            }
            System.out.println(" ");
        }
    }
    boolean check(int proces[], int avail[], int maxm[][],
        int allot[][], int P, int R, int need[][]) {


        boolean[] finish = new boolean[P];
        
        //for storing the final sequence
        int[] safe = new int[P]; 


        int[] work = new int[R];
        System.out.print("INTIALLY WORK/AVAILABLE     : ");
        for (int i = 0; i < R; i++) {
            work[i] = avail[i];
            System.out.print(work[i] + " ");
        }
        System.out.println(" ");

        // While all processes are not over/system isn't safe run this loop
        int c1 = 0;
        while (c1 < P) {
            boolean found = false;
            for (int p = 0; p < P; p++) {
                //if process is not completed
                if (finish[p] == false) {
                    int j;
                    for (j = 0; j < R; j++)
                        if (need[p][j] > work[j])
                            break;

                    if (j == R) {
                        System.out.print("AFTER EXECUTION OF PROCESS " + p + " : ");
                        for (int k = 0; k < R; k++) {
                            work[k] += allot[p][k];
                            System.out.print(work[k] + " ");
                        }
                        System.out.println("");


                        safe[c1++] = p; 

                        //make finish[i]=true
                        finish[p] = true;

                        found = true;
                    }
                }
            }

            //if process is not safe
            if (found == false) {
                System.out.print("SYSTEM IS NOT IN SAFE STATE");
                return false;
            }
        }
        System.out.println(" ");
        System.out.println("SYSTEM IS IN SAFE STATE");
        System.out.println(" ");
        System.out.println("SAFE SEQUENCE IS : ");
        //to print the sequence
        for (int i = 0; i < P; i++) {
            System.out.print("P" + safe[i]);
            if (i != P - 1)
                System.out.print(" -> ");
        }
        System.out.println(" ");
        return true;
    }
}

// main public class
public class banker 
{
    // Driver code 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        int p = 0;
        int r = 0;

        System.out.println("ENTER THE NUMBER OF PROCESSES");
        do {
            p = sc.nextInt();
            if (p < 0) {
                System.out.println("THE VALUE CANNOT BE NEGATIVE. TRY AGAIN");
            }
        } while (p < 0);
        int pro[] = new int[p];

        for (int i1 = 0; i1 < p; i1++) {
            pro[i1] = i1;
        }

        System.out.println(" ");
        System.out.println("ENTER THE TOTAL NUMBER OF RESOURCES");
        do {
            r = sc.nextInt();
            if (r < 0) {
                System.out.println("THE VALUE CANNOT BE NEGATIVE. TRY AGAIN");
            }
        } while (r < 0);
        int res[] = new int[r];
        
        // array defines the maximum demand of each process in a system.
        int max[][] = new int[p][r];
        
        //array about the number of resources of each type currently allocated to each process.
        int allocation[][] = new int[p][r];
        
        int need[][] = new int[p][r];
        //available/work array
        int[] avail = new int[r]; 
        
        //array about how many more resources can be allocated in the future
        int[] req = new int[r];
        
        //create the object
        algorithm al1 = new algorithm(); 

        do {
            System.out.println("PRESS 1 TO ACCEPT DATA");
            System.out.println("PRESS 2 TO DISPLAY THE MATRICES ");
            System.out.println("PRESS 3 TO DISPLAY SEQUENCES ");
            System.out.println("PRESS 4 FOR RESOURCE REQUEST");
            System.out.println("PRESS 0 TO EXIT");
            System.out.println(" ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.println(" ");

                    for (int i1 = 0; i1 < r; i1++) {
                        System.out.println("ENTER THE TOTAL NUMBER OF INSTANCES FOR RESOURCE " + (i1 + 1) + " ");
                        res[i1] = sc.nextInt();
                    }

                    System.out.println(" ");

                    System.out.println("ENTER THE MATRIX FOR MAXIMUM RESOURCES ");
                    for (int i = 0; i < p; i++) {
                        for (int j = 0; j < r; j++) {
                            max[i][j] = sc.nextInt();
                        }
                    }


                    System.out.println(" ");
                    System.out.println("ENTER THE MATRIX FOR RESOURCES WHICH ARE ALLOCATED");
                    for (int i = 0; i < p; i++) {
                        for (int j = 0; j < r; j++) {
                            allocation[i][j] = sc.nextInt();
                        }
                    }

                    System.out.println("  ");

                    break;

                case 2:
                    al1.display(r, p, avail, max, need, allocation, res);
                    System.out.println("");

                    break;

                case 3:

                    al1.check(pro, avail, max, allocation, p, r, need);
                    System.out.println(" ");

                    break;

                case 4:
                    int allocation1[][] = new int[p][r];
                    int need1[][] = new int[p][r];
                    int[] avail1 = new int[r]; //available/work array

                    int flag = 0;
                    System.out.println("ENTER PROCESS NUMBER");
                    int p1 = sc.nextInt();
                    System.out.println("ENTER RESOURCES REQUESTED BY P" + p1);
                    for (int i = 0; i < r; i++) {
                        req[i] = sc.nextInt();
                    }
                    for (int i = 0; i < r; i++) {
                        //check if available resources are greater than required
                        if (avail[i] < req[i]) 
                        {
                            flag = 1;
                            break;
                            
                        } //check if needed resources are greater than required
                        else if (req[i] > need[p1][i]) 
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1) {
                        System.out.println("THE REQUEST FOR PROCESS P" + p1 + " CANNOT BE GRANTED");
                        System.out.println("  ");
                    } else {
                        allocation1 = allocation;
                        need1 = need;
                        avail1 = avail; //available/work array	

                        for (int i = 0; i < r; i++) {
                            allocation1[p1][i] = allocation1[p1][i] + req[i];
                        }

                        for (int i = 0; i < r; i++) {
                            need1[p1][i] = need1[p1][i] - req[i];
                        }

                        for (int i = 0; i < r; i++) {
                            avail1[i] = avail1[i] - req[i];
                        }

                        al1.check(pro, avail1, max, allocation1, p, r, need1);
                        System.out.println(" ");

                    }
                    System.out.println("  ");
                    break;

                case 0:
                    System.out.println(" ");
                    System.out.println("THANK YOU !");
                    System.out.println();
                    break;
                default:
                    System.out.println("WRONG CHOICE");
                    System.out.println(" ");
                    break;
            }
        } while (choice != 0);

    }
}
