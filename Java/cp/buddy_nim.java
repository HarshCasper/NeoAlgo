
/** 
Problem Statement: Alice, Bob and Charlie are playing a new game called Buddy NIM. The game is played at two tables; on the first table, 
there are N heaps containing A1,A2,…,AN coins and on the second table, there are M heaps containing B1,B2,…,BM coins respectively.

Initially, Alice is playing at the first table and Bob is playing at the second table. 
The players take their turns in this order: Charlie, Alice, Bob, Charlie, etc.

Alice and Bob follow the rules for classical NIM - on Alice's turn, 
Alice must remove a positive number of coins from one of the piles at her current table and on Bob's turn, 
Bob must remove a positive number of coins from one of the piles at his current table. 
Whoever cannot remove any coin from a pile loses.

Charlie does not play at any table. Instead, on his turn, 
he decides if Alice and Bob should keep playing at their respective tables or swap places.

Alice and Charlie are buddies and they cooperate, playing in the optimal way that results in Alice's victory (if possible).
It is clear that either Alice or Bob wins the game eventually. You must find out who the winner will be.

Idea: If total coins on both tables is different, Alice will always win as she will remove only one coin from her pile 
and if at ay point, number of coins at her table becomes less than the number of coins at Bob's table, Charlie will switch their places
at his turn. If total coins are equal on both tables, then Alice will only win if the structure of piles is different as she will try to
make number of coins unequal on both tables by removing the maximum coins from one of the piles on her table, in order to keep up, Bob will 
try to mirror her steps and since the structure is different, at some point, the coins will become unequal and Charlie will place Alice at 
table with maximum coins. If structure is identical, then Bob will always win since Alice makes her move before Bob and he only has to copy Alice's moves to win.

**/

import java.util.*;

class buddy_nim {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner scn = new Scanner(System.in);
        int testCases = scn.nextInt();
        while (testCases-- > 0) {
            // size of Arrays
            int N = scn.nextInt();
            int M = scn.nextInt();

            // Creating Arrays A and B, also finding their respective sum of elements.
            int A[] = new int[N];
            int B[] = new int[M];
            int sum_of_A = 0, sum_of_B = 0;
            for (int i = 0; i < N; i++) {
                A[i] = scn.nextInt();
                sum_of_A += A[i];
            }

            for (int i = 0; i < M; i++) {
                B[i] = scn.nextInt();
                sum_of_B += B[i];
            }

            // Checking if number of coins in A and B are equal or not
            if (sum_of_A != sum_of_B) {
                System.out.println("Alice");
                continue;
            }

            // Sorting the Arrays A and B
            Arrays.sort(A);
            Arrays.sort(B);

            // Finding the first non-zero index of A and B
            int i = 0, j = 0;
            while (i < N && A[i] == 0)
                i++;
            while (j < M && B[j] == 0)
                j++;

            // Checking if structure of A and B is similar or not
            while (i < N && j < M) {
                if (A[i] != B[j]) {
                    break;
                }
                i++;
                j++;
            }

            // Printing the winner's name
            if (i == N && j == M)
                System.out.println("Bob");
            else
                System.out.println("Alice");

        }
        // closing input stream
        scn.close();
    }
}

/**

Sample Input and Output

First line -- The number of test cases
Second Line -- Total number of piles on both tables
Third line -- coins in each pile of Table 1
Fourth line -- coins in each pile of Table 2

Input: 

3
3 1
1 1 1
3
3 1
1 2 4
7
1 1
1
1

Output:

Alice 
Alice 
Bob

Explanation:

1: Alice wins because total coins are equal but structure is different on both tables

2: Alice wins because total coins are equal but structure is different on both tables

3: Bob wins because coins are equal and structure is same on both tables

Complexities:

Time: O(NlogN + MlogM)
Space: O(1) or O(N+M) depending upon the type of sorting algorithm

**/