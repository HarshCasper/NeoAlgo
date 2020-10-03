/*
There is an array of n integers. There are also 2 disjoint sets, A and B, each containing m integers.
You like all the integers in set A and dislike all the integers in set B. Your initial happiness is 0.
For each i integer in the array, if i e A , you add 1 to your happiness. If i e B, you add -1 to your happiness.
Otherwise, your happiness does not change. Output your final happiness at the end.
	Input Format

	The first line contains integers n and m separated by a space.
	The second line contains n integers, the elements of the array.
	The third and fourth lines contain m integers, A and B, respectively.

	Output Format

	Output a single integer, your total happiness.

Problem Link: https://www.hackerrank.com/challenges/no-idea/problem
*/

import java.util.Scanner;

public class HappinessProblem {
    public static int findHappiness(int[] arr, int A[], int B[]) {
        int happiness = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < A.length; j++) {
                if (arr[i] == A[j]) {
                    happiness++;
                    break;
                }
                if (arr[i] == B[j]) {
                    happiness--;
                    break;
                }
            }
        }
        return happiness;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter n and m:");
        // 1st line of input
        int n = sc.nextInt(), m = sc.nextInt();
        int[] A = new int[m], B = new int[m], arr = new int[n];

        System.out.println("Enter elements of array:");
        // 2nd Line of input
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Enter elements of A:");
        // 3rd line of input
        for (int i = 0; i < m; i++) {
            A[i] = sc.nextInt();
        }

        System.out.println("Enter elements of B:");
        // 4th line of input
        for (int i = 0; i < m; i++) {
            B[i] = sc.nextInt();
        }

        int happiness = findHappiness(arr, A, B);
        System.out.println("Happiness: " + happiness);

        sc.close();
    }
}

/*
 * Sample input: Enter n and m: 3 2 Enter elements of array: 1 5 3 Enter
 * elements of A 3 1 Enter elements of B: 5 7
 *
 * Sample output: Happiness:1
 *
 * Time complexity: O(n^2) Space complexity: O(n)
 */