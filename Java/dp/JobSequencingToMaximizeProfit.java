/* Problem Description

You are given a two-dimensional list of integers intervals where each list 
contains three values [start, end, profit]. Given you can only perform one
task at a time, return the maximum profit you can gain. */


import java.util.*;

public class JobSequencingToMaximizeProfit
{

    /* Creating a Job Class which stores the start time, end time and profit for that particular job */
    static class Job{
        int start;
        int end;
        int profit;
        Job(int start, int end, int profit){
            this.start = start;
            this.end = end;
            this.profit = profit;
        }
    }
    
    /* Defining a Comparator which sorts the Jobs based on end time in ascending order */
    static class SortByEndTime implements Comparator<Job>{
        
        public int compare(Job A, Job B){
            return A.end - B.end;
        }
    }

    /* Function created to get maximum profit in the intervals provided */
    public static int getMaxProfit(int[][] intervals) {

        /* Creating an Jobs array to easily sort the jobs */
        ArrayList<Job> array = new ArrayList<>();
        int n = intervals.length;

        /* Adding the jobs to the jobs array */
        for(int i=0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            int profit = intervals[i][2];
            array.add(new Job(start, end, profit));
        }
        
        /* Sorting the jobs based on End time */
        Collections.sort(array, new SortByEndTime());
        
        /* Initializing a dp array to store the max profit for i particular jobs i.e 
         It stores the maximum profit gained when only i jobs are present */
        int dp[] = new int[n];

        /* When we are including only one job, we can have a maximum profit of that particular job */
        dp[0] = array.get(0).profit;

        /* Filling the dp array */
        for(int i=1; i<n; i++){

            Job curr = array.get(i);

            /* Getting the current Jobs Profit */
            int ans = curr.profit;

            /* Getting the index of the first non-conflicting job */
            int index = lowerBound(array, curr.start, 0, i-1);

            /* Max profit we get by including the current job */
            if(index != -1){
                ans += dp[index];
            }

            /* Storing the max profit we get by either including the current job or excluding it */
            dp[i] = Math.max(dp[i-1], ans);
        }

        /* Returning the max Profit when we have "n" jobs */
        return dp[n-1];
        
    }

    /* Getting the index of the first non conflicting job using Binary Search */
    public static int lowerBound(ArrayList<Job> array, int start, int low, int high){


        int l = low;
        int h = high;
        int ans = -1;

        /* Iterative Binary Search */
        while(l <= h){
            int mid = (l+h)/2;
            Job j = array.get(mid);

            /* Going to the right if we found a non-conflicting job */
            if(j.end <= start){
                ans = mid;
                l=mid+1;
            }
            /* Going to the left if we found a conflicting job */
            else{
                h=mid-1;
            }
        }

        /* Returning the index */
        return ans;
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        int jobs = sc.nextInt();

        int intervals[][] = new int[jobs][3];

        for(int i=0; i<jobs; i++){
            int start = sc.nextInt();
            int end = sc.nextInt();
            int profit = sc.nextInt();

            intervals[i][0] = start;
            intervals[i][1] = end;
            intervals[i][2] = profit;
        }

        System.out.println(getMaxProfit(intervals));
    }  
}


/* Input

intervals = [
    [1, 2, 50],
    [3, 5, 20],
    [6, 19, 100],
    [2, 100, 200]
]

Output
250

Explanation
We can take intervals [1, 2, 50] and [2, 100, 200] thereby maximizing our profit, which is coming out to be 250


Time Complexity : O(N)
Space Complexity : O(N)
*/

