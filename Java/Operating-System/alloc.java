/* 
Title: Memory Allocation in Operating Systems in Java

Description:
(a) First-Fit: 
- Allocate the first hole that is big enough. 
- Searching can start either at the beginning of the set of holes or where the previous first search ended. 
- Stop searching as soon as we find a free hole that is large enough.
(b) Best-Fit: 
- Allocate the smallest hole that is big enough. 
- Search the entire list unless the list is ordered by size.
(c) Worst-Fit: 
- Allocate the largest hole. 
- Search the entire list unless the list is ordered by size.
 
*/

import java.util.ArrayList;
import java.util.Scanner;

public class memory1 {
 public void first()
 {
  System.out.println("ENTER THE NUMBER OF PROCESSES");
        int size = s.nextInt();
        System.out.println("ENTER THE SIZES OF PROCESSES");
        int s1[] = new int[size];
        for (int i = 0; i < size; i++) {
          int a = s.nextInt();
          s1[i] = a;
        }

        System.out.println("ENTER THE SIZE OF MEMORY BLOCK");
        int size1 = s.nextInt();
        System.out.println("ENTER THE MEMORY PARTITIONS");
        int s2[] = new int[size1];
        for (int i = 0; i < size1; i++) {
          int a1 = s.nextInt();
          s2[i] = a1;
        }
        int allocation[] = new int[size];

        for (int i = 0; i < allocation.length; i++) //initialize to -1
        {
          allocation[i] = -1;
        }

        for (int i = 0; i < size; i++) {
          for (int j = 0; j < size1; j++) {
            if (s2[j] >= s1[i]) {

              allocation[i] = j;
              s2[j] -= s1[i];

              break;
            }
          }
        }   
        System.out.println("\nProcess No.\t\tProcess Size\t\tBlock no.");
        for (int i = 0; i < size; i++) {
          System.out.print(" " + (i + 1) + "\t\t\t" + s1[i] + "\t\t\t");
          if (allocation[i] != -1) System.out.print(allocation[i] + 1);
          else System.out.print("Not Allocated");
          System.out.println();
        }
 }
 
 public void best()
 {
  System.out.println("ENTER THE NUMBER OF PROCESSES");
        size = s.nextInt();
        System.out.println("ENTER THE SIZES OF PROCESSES");
        int s11[] = new int[size];
        for (int i = 0; i < size; i++) {
          int a = s.nextInt();
          s11[i] = a;
        }

        System.out.println("ENTER THE SIZE OF MEMORY BLOCK");
        size1 = s.nextInt();
        System.out.println("ENTER THE MEMORY PARTITIONS");
        int s21[] = new int[size1];
        for (int i = 0; i < size1; i++) {
          int a1 = s.nextInt();
          s21[i] = a1;
        }
        int allocation1[] = new int[size];
        for (int i = 0; i < allocation1.length; i++) {
          allocation1[i] = -1;
        }

        for (int i = 0; i < size; i++) {

          int best = -1;
          for (int j = 0; j < size1; j++) {
            if (s21[j] >= s11[i]) {
              if (best == -1) best = j;
              else if (s21[best] > s21[j]) best = j;
            }
          }

          if (best != -1) {

            allocation1[i] = best;
            s21[best] -= s11[i];
          }
        }        
        System.out.println("\nProcess No.\t\tProcess Size\t\tBlock no.");
        for (int i = 0; i < size; i++) {
          System.out.print("   " + (i + 1) + "\t\t\t" + s11[i] + "\t\t\t");
          if (allocation1[i] != -1) System.out.print(allocation1[i] + 1);
          else System.out.print("Not Allocated");
          System.out.println();
        }        
 }
 
 public void worst(){
  System.out.println("ENTER THE NUMBER OF PROCESSES");
        size = s.nextInt();
        System.out.println("ENTER THE SIZES OF PROCESSES");
        int s111[] = new int[size];
        for (int i = 0; i < size; i++) {
          int a = s.nextInt();
          s111[i] = a;
        }

        System.out.println("ENTER THE SIZE OF MEMORY BLOCK");
        size1 = s.nextInt();
        System.out.println("ENTER THE MEMORY PARTITIONS");
        int s211[] = new int[size1];
        for (int i = 0; i < size1; i++) {
          int a1 = s.nextInt();
          s211[i] = a1;
        }
        int allocation11[] = new int[size];

        for (int i = 0; i < allocation11.length; i++) {
          allocation11[i] = -1;
        }
        for (int i = 0; i < size; i++) {

          int wst = -1;
          for (int j = 0; j < size1; j++) {
            if (s211[j] >= s111[i]) {
              if (wst == -1) wst = j;
              else if (s211[wst] < s211[j]) wst = j;
            }
          }

          if (wst != -1) {

            allocation11[i] = wst;

            s211[wst] -= s111[i];
          }
        }        
        System.out.println("\nProcess No.\t\tProcess Size\t\tBlock no.");
        for (int i = 0; i < size; i++) {
          System.out.print("   " + (i + 1) + "\t\t\t" + s111[i] + "\t\t\t");
          if (allocation11[i] != -1) System.out.print(allocation11[i] + 1);
          else System.out.print("Not Allocated");
          System.out.println();
        }       
 }
}

public class alloc {

  public static void main(String[] args) {
    Scanner s = new Scanner(System. in );
    int u = 0;
    System.out.println("MEMORY ALLOCATION TECHNIQUES");
    do {
      memory1 c1=new memory1();
      System.out.println("ENTER 1 FOR FIRST FIT");
      System.out.println("ENTER 2 FOR BEST FIT");
      System.out.println("ENTER 3 FOR WORST FIT");
      System.out.println("PRESS O FOR EXIT ");
      u = s.nextInt();
      switch (u) {
      case 1:
        c1.first();
        break;

      case 2:
        c1.best();
        break;

      case 3:
        c1.worst();
        break;
      }
    } while ( u != 0 );
   
   }
 
}

  /*
 *MEMORY ALLOCATION TECHNIQUES
ENTER 1 FOR FIRST FIT
ENTER 2 FOR BEST FIT
ENTER 3 FOR WORST FIT
PRESS O FOR EXIT 
1
ENTER THE NUMBER OF PROCESSES
5
ENTER THE SIZES OF PROCESSES
210
167
34
356
267
ENTER THE SIZE OF MEMORY BLOCK
5
ENTER THE MEMORY PARTITIONS
100
300
200
400
378

Process No.		Process Size		Block no.
 1			210			2
 2			167			3
 3			34			1
 4			356			4
 5			267			5

ENTER 1 FOR FIRST FIT
ENTER 2 FOR BEST FIT
ENTER 3 FOR WORST FIT
PRESS O FOR EXIT 
1
ENTER THE NUMBER OF PROCESSES
5
ENTER THE SIZES OF PROCESSES
200
13
678
456
789
ENTER THE SIZE OF MEMORY BLOCK
5
ENTER THE MEMORY PARTITIONS
100
500
200
346
135

Process No.		Process Size		Block no.
 1			200			2
 2			13			1
 3			678			Not Allocated
 4			456			Not Allocated
 5			789			Not Allocated

ENTER 1 FOR FIRST FIT
ENTER 2 FOR BEST FIT
ENTER 3 FOR WORST FIT
PRESS O FOR EXIT 
3
ENTER THE NUMBER OF PROCESSES
5
ENTER THE SIZES OF PROCESSES
100
300
478
124
245
ENTER THE SIZE OF MEMORY BLOCK
5
ENTER THE MEMORY PARTITIONS
100
500
300
245
357

Process No.		Process Size		Block no.
   1			100			2
   2			300			2
   3			478			Not Allocated
   4			124			5
   5			245			3
   
ENTER 1 FOR FIRST FIT
ENTER 2 FOR BEST FIT
ENTER 3 FOR WORST FIT
PRESS O FOR EXIT 
0
*/
