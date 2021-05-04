/*
    Problem Statement:-Given a sorted array of words to be searched and an array p[0.. n-1] 
    of frequency counts, where p[i] is the number of searches to keys[i]. 
    Also given an array q[0.. n-1] of frequency counts, where q[i] is the number of searches 
    for word keys[i] misspelled by the user. Construct a Binary Search Tree of all words such that 
    the total cost of all the searches(including the misspelled words) is as small as possible.
*/

import java.util.*;

public class Optimal_Binary_Search_tree_using_DP {
    public static void optimal_BST(int p[], int q[], String words[]){
        final int INF = 99999;

        //Creating the weight, cost and root matrices to get the Optimal BST
        //Weight matrix is used for creating our Cost Table
        //Cost table has values for optimal BST cost for the selected words everytime
        //root table contains the structure for Optimal BST
        int weight[][], cost[][], root[][];
        weight = new int[q.length][q.length];
        cost = new int[q.length][q.length];
        root = new int[q.length][q.length];

        //Creating Memoization Tables

        /*Recurrence Relation for Weight Table:-
            if(i == j) -> weight[i][j] = q[i]
            else -> weight[i][j] = weight[i][j-1] +q[j] + p[j-1]
        */

        //Filling Weight matrix diagonally
        for (int g = 0; g < q.length; g++) {
            for (int i = 0, j = g; j < q.length; j++, i++) {
                if (i == j)
                    weight[i][j] = q[i];
                else {
                    weight[i][j] = weight[i][j-1] +q[j] + p[j-1];
                }
            }
        }

        /*Recurrence Relation for Weight Table:-
            if(i == j) -> cost[i][j] = 0
            else -> cost[i][j] = weight[i][j] + min(cost[i][k] + cost[k+1][j])    where i<=k<j
        */

        //Filling Cost matrix diagonally
        for (int g = 1; g < q.length; g++) {
            for (int i = 0, j = g; j < q.length; j++, i++) {
                if (i == j)
                    cost[i][j] = 0;
                else {
                    int min = INF;
                    int m = i;
                    for (int k = i; k < j; k++) {
                        int partial_cost = cost[i][k] + cost[k+1][j];
                        if (partial_cost < min) {
                            min = partial_cost;
                            m = k+1;
                        }
                    }
                    cost[i][j] = min + weight[i][j];
                    //Storing 'm' in root matrix for defining the structure of BST in the root matrix
                    root[i][j] = m;
                }
            }
        }
        System.out.println("Cost of Optimal BST is:- " + cost[0][cost.length - 1]);
        print_Matrices(weight, cost, root);
    }

    public static void print_Matrices(int weight[][], int cost[][], int root[][]){
        System.out.println("Weight Matrix:- ");
        for (int i = 0; i < weight.length; i++) {
            for (int j = 0; j < weight.length; j++) {
                System.out.print(weight[i][j] + "\t");
            }
            System.out.println();
        }
        
        System.out.println("\n\nCost Matrix:- ");
        for (int i = 0; i < cost.length; i++) {
            for (int j = 0; j < cost.length; j++) {
                System.out.print(cost[i][j] + "\t");
            }
            System.out.println();
        }

        System.out.println("\n\n\nRoot matrix:-");
        for (int i = 0; i < root.length; i++) {
            for (int j = 0; j < root.length; j++) {
                System.out.print(root[i][j] + "\t");
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the no of words:- ");
        int n = sc.nextInt();
        
        System.out.println("Enter the words:- ");
        String words[] = new String[n];
        for(int i = 0; i<words.length; i++){
            words[i] = sc.next();
        }

        System.out.println("Enter the no of searches for each word:- ");
        int p[] = new int[n];
        for(int i = 0; i<n; i++){
            p[i] = sc.nextInt();
        }

        System.out.println("Enter the no of searches for each misspelled word");
        int q[] = new int[n+1];
        for(int j = 0; j<q.length; j++){
            q[j] = sc.nextInt();
        }        
        optimal_BST(p, q, words);
    }
}
/*
    Time Complexity:- O(n^3)
    Space Complexity:- O(n^2)
*/

/*
Sample Testcase:
Enter the no of words:-
4
Enter the words:-
words = {"auto", "for", "int", "short"}
Enter the no of searches for each word:-
p = {7, 3, 5, 2}
Enter the no of searches for each misspelled word:-
q = {1, 2, 4, 7, 3}

Output:-
Cost of Optimal BST is:- 72
Weight Matrix:- 
1       10      17      29      34      
0       2       9       21      26
0       0       4       16      21
0       0       0       7       12
0       0       0       0       3

Cost Matrix:-
0       10      26      55      72
0       0       9       30      47
0       0       0       16      33
0       0       0       0       12
0       0       0       0       0

Root matrix:-
0       1       1       2       3
0       0       2       3       3
0       0       0       3       3
0       0       0       0       4
0       0       0       0       0
*/
