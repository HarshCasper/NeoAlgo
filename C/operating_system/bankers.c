/*    Some information about Banker's algorithm :-

       *  The Banker’s algorithm is a resource allocation and deadlock avoidance algorithm developed by Edsger Dijkstra.
       *  The time complexity of the Banker's algorithm as a function of the number n of processes and m of resources is o(n*n*m).
       *
      Let P be number of Process and R be number of resources.
       *  BOOLEAN function SAFESTATE is -- Determines if current state is safe
        { UNSAFE : boolean;
          AVAILABLE : array[1..R] of INTEGER
          FINISH : array[1..P] of boolean = [false, ..,false];
          I : integer;

        repeat
            UNSAFE = TRUE;
            for I = 1 to P do
                if ((not FINISH[i]) and
                    NEEDi <= WORK) then {
                    WORK = WORK + ALLOCATION_i;
                    FINISH[i] = true;
                    UNSAFE = false;
                    }
                until NOCHANGE;
            return (FINISH == (true, .., true));
       }
*/

#include <stdio.h>

// Calculating the remaining need of the resources for each process.
void CalculateRemainingNeed(int p, int r, int need[p][r], int allocated[p][r], int max[p][r]){
    int i,j;
    for(i = 0; i < p; ++i){
        for(j = 0; j < r; ++j){
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
}
// Checking whether all the process can be executed.
int CheckDeadlock(int p, int r, int need[p][r], int avail[], int allocated[p][r], int finish[], int seq[]){
    int count = 0, i, j, k, unsafe = 1;
    while (count != p){
        unsafe = 1;
        for(i = 0; i < p; ++i){
            // Checking whether particular process is executed or not.
            if (finish[i] == 0){
                for(j = 0; j < r; ++j){
                    // Checking whether the need of any process is greater than availability.
                    if (need[i][j] > avail[j]){
                        break;
                    }
                }
                // If all the resources are available for any process.
                if (j == r){
                    for (k = 0; k < r; ++k)
                        avail[k] = avail[k] + allocated[i][k];
                    finish[i] = 1;
                    seq[count] = i+1;
                    count++;
                    unsafe = 0;
                }
            }
        }
        if (unsafe == 1)
            return unsafe;
    }
}

void DisplaySafeSequence(int seq[], int p){
    int i;
    printf("The safe sequence is:\n");
    for(i = 0; i < p - 1; ++i)
        printf("P%d->", seq[i]);
    printf("P%d\n", seq[p-1]);
}

int main() {

    int p, r, i, j;

    printf("Enter number of process\n");
    scanf("%d", &p);

    printf("Enter the number of resources\n");
    scanf("%d", &r);

    int allocated[p][r], max[p][r], avail[r], need[p][r], finish[p], seq[p];

    printf("Enter the available resources\n");
    for(i = 0; i < r; ++i){
        scanf("%d", &avail[i]);
    }

    printf("Enter the allocated resources to each process\n");
    for(i = 0; i < p; ++i){
        for(int j = 0; j < r; ++j){
            scanf("%d", &allocated[i][j]);
        }
    }

    printf("Enter the maximum demand of resources by each process\n");
    for(i = 0; i < p; ++i){
        for(j = 0; j < r; ++j){
            scanf("%d", &max[i][j]);
        }
    }

    // This matrix is used to keep track of the executed process.
    // Initializing with value '0' which means no process is executed yet.
    for(i = 0; i < p; ++i){
        finish[i] = 0;
    }

    CalculateRemainingNeed(p, r, need, allocated, max);

    int unsafe = CheckDeadlock(p, r, need, avail, allocated, finish, seq);

    // Checking if there is any process which will not able to execute.
    if (unsafe == 1)
        printf("The sequence is unsafe. Deadlock will occur.\n");
    else
        DisplaySafeSequence(seq, p);

    return 0;
}


/*
        OUTPUT
Enter number of process
5

Enter the number of resources
3

Enter the available resources
2 1 0

Enter the allocated resources to each process
1 1 2
2 1 2
4 0 1
0 2 0
1 1 2

Enter the maximum demand of resources by each process
4 3 3
3 2 2
9 0 2
7 5 3
1 1 2

The safe sequence is:
P2->P5->P1->P3->P4

*/