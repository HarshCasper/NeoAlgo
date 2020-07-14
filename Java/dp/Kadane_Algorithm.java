import java.util.*;
 class abc
{   static long findMaxSumArray(long arr[],int x)
    {   long currentSum=0,maxSum=0;int i;
        
        for(i=0;i<x;i++)
        {currentSum+=arr[i];
            if(currentSum<0)
            currentSum=0;
        maxSum=Math.max(currentSum,maxSum);}
        
       
        return maxSum;
    }
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        int i,j,k,l,m,n;
        n=sc.nextInt();long sum=0,maxSum=0;
        long a[]=new long[n];
        for(i=0;i<n;i++)
        a[i]=sc.nextLong();
        
        sum=findMaxSumArray(a,n);
        System.out.println(sum);
    }
}
/* Input/Output-
5
4 2 -3 -1 8
10 */
