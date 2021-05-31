/*
Given an array find out whether it is possible to partition the array into equal sum.
*/ 
import java.util.*;

class Main
{
    static boolean equalPartitionSubset(int a[],int n, int sum)
    {
        boolean [][] dp = new boolean[sum+1][n+1];
        
        //Base conditions
        for(int i=0;i<n+1;i++)
        dp[0][i]=true;

        for(int j=0;j<sum+1;j++)
        dp[j][0]=false;

        for(int i=1;i<sum+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(a[j-1]>i)
                dp[i][j]=dp[i][j-1];
                if(a[j-1]<=i)
                dp[i][j]=dp[i][j-1] || dp[i-a[j-1]][j-1];
            }
        }
        return dp[sum][n];
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner( System.in );        
        System.out.println("Enter number of elements: ");
        int n = scanner.nextInt();
        System.out.println("Enter the elements: ");
        int a[]=new int[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            a[i]=scanner.nextInt();   
            sum+=a[i]; 
        }

        if(sum%2!=0)
        System.out.println("Equal sum partition not possible");
        else 
        {
            boolean res=equalPartitionSubset(a,n,sum/2);
            if(res)
            System.out.println("Equal sum partition possible");
            else 
            System.out.println("Equal sum partition not possible");
        }
    }
}

/*
Time Complexity: O(n*sum)

Space Complexity: O(sum)

Input:

Enter number of elements: 
4
Enter the elements: 
1 3 4 6

Output:

Equal sum partition possible
*/
