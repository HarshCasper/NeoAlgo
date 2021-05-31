/*
Given two strings find out the length of the shortest supersequence formed from the two strings.
ALGORITHM:
*The idea is to find out the longest common subsequence first.
*This subsequence will be present once in both the strings.
*So on adding the length of the two strings the subsequence will be counted twice.
*Subtract the length of lcs from both the strings and add once.
*This gives length of shortest supersequence
*/ 

import java.util.Scanner;
import java.lang.Math;

public class shortestSuperSeq
{
    public static int shortestSuperSequence(String x,String y, int n,int m)
    {
        int dp[][]=new int[n+1][m+1];

        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                dp[i][j]=0;
            }
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(x.charAt(i-1)==y.charAt(j-1))
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }

    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter two strings: ");
        String x=s.next();
        String y=s.next();
        int n=x.length();
        int m=y.length();
        System.out.println("The length of the shortest supersequence: "+(n+m-shortestSuperSequence(x,y,n,m)));
    }
}

/*
Time Complexity: O(n*m)

Space complexity: O(n*m)

Input:

Enter two strings: 
abc
acd

Output:

The length of the supersequence: 4
*/
