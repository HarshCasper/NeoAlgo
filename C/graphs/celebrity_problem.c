/*
Celebrity Problem

Problem: In a party, we need to check if there is a celebrity who is known to everyone and he/she knows no one.
Input: A 2D co-relation matrix where rows and columns represent ids of persons present in the party and 
a value of matrix[i][j] = 1 indicates that the i'th person knows j'th person and a value of 0 indicates that
i'th person don't know j'th person. The primary diagonal must always be filled with zeroes, as a default value,
as thier values dont alter the solution logic.
*/

// C program to solve the Celebrity Problem
#include <stdio.h>

/* If a celeb is present in the party, then his/her id'th column would be filled with 1 as values 
   except for the diagonal element and td'th row would be filled with 0s. */
int find_celebrity(int person[][9000], int n) {
    int low = 0;
    int high = n - 1;

    /* While loop to check if there is a column with value as 1 only except the diagonal value. 
       We start checking from the last column indexin the first row. */
    while (1) {
        if (low == high)
            break;

        if (person[low][high] == 1)
            low++;

        else
            high--;
    }
    for (int i = 0; i < n; i++) {
        if (low == i)
            continue;
        /* Check if low'th index is a celeb or not by checking
           if he/she knows anyone or anyone knows the celeb */
        if (person[low][i] == 1 || person[i][low] == 0)
            return -1;
    }
    return low;
}

int main() {
    int n;
    printf("How many people are present in the party? ");
    scanf("%d",&n);
    int person[n][9000];
    printf("Enter thier co-relation graph: ");
    // Input the co-relation matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",&person[i][j]);
        }
    }
    int celeb = find_celebrity(person, n);
    if (celeb >= 0) {
        printf("Celebrity is present at the %d", celeb);
        printf("th index of the given co-relation graph");
    } else {
        printf("Celebrity is not present in the party.");
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n^2)

SAMPLE INPUT AND OUTPUT

How many people are present in the party? 3
Enter thier co-relation graph: 0 1 0
                               0 0 1 
                               1 0 0
Celebrity is not present in the party.
*/
