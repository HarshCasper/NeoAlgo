/*In word wrap problem we've given a sequence of words as input
We have to find the number of words that can be fitted in a single line
at a time. So, for achieving this, we put breaks in the given sequence such
that the printed document looks good. The word editors such as MS office,
Libre Office, etc. use line breaks to make the document look nice.

We also have to assume that our word length does not exceed the line size.
This problem can be solved by following greedy as well as dynamic approaches.
Below is the Dynamic approach for achieving this.*/
import java.util.*;
import java.lang.*;
import java.io.*;
public class WordWrapProblem
{
    static int returnWordWrap (int wordSize[], int n, int lineSize)
    {
        int spareSpace[][] = new int[n+1][n+1];
        int leastCost[] = new int[n+1];
        for (int i=1;i<=n;i++)
        {
            spareSpace[i][i] = lineSize - wordSize[i-1];
            for (int j=i+1;j<=n;j++)
                spareSpace[i][j] = spareSpace[i][j-1] - wordSize[j-1] - 1;
        }
        leastCost[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            leastCost[i] = Integer.MAX_VALUE;
            for (int j = 1; j <= i; j++)
            {
                // For storing cost of storing words[i, j]
                int cost;
                /*If spareSpace required is negative, then we can't place
                words[i,j] in a single line, else if we placed our last
                word, then we don't consider spareSpace, else calculate
                cost as per given cost function.*/
                if(spareSpace[j][i]<0){
                    cost = Integer.MAX_VALUE;
                }
                else if(i==n && spareSpace[j][i]>=0){
                    cost = 0;
                }
                else{
                    cost = spareSpace[j][i]*spareSpace[j][i]*spareSpace[j][i];
                }

                if (leastCost[j-1] != Integer.MAX_VALUE && cost != Integer.MAX_VALUE
                        && (leastCost[j-1] + cost < leastCost[i])) {
                    leastCost[i] = leastCost[j - 1] + cost;
                }
            }
        }
        return leastCost[n];
    }

    public static void main(String args[])
    {   //Below is the input code for finding least cost for word wrap
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of test cases you want to perform: ");
        int k = sc.nextInt();
        while(k-- > 0) {
            System.out.print("Enter size for an array of word size: ");
            int n = sc.nextInt();
            int[] wordSize = new int[n];
            System.out.print("Enter word size array elements: ");
            for(int i=0;i<n;i++) {
                wordSize[i] = sc.nextInt();
            }
            System.out.print("Enter the line size: ");
            int lineSize = sc.nextInt();
            int sol = returnWordWrap(wordSize, n, lineSize);
            System.out.println(sol);
        }
    }
}
/*
Sample Input/Output:
Input: Enter number of test cases you want to perform: 2
         Enter size for an array of word size: 4
         Enter word size array elements: 1 1 1 1
         Enter the line size: 5
         Enter size for an array of word size: 4
         Enter word size array elements: 3 1 2 4
         Enter the line size: 6

Output: 0
        35

Time and space complexity for this approach:
Time Complexity: O(n^2)
Auxiliary Space: O(n^2)
*/
