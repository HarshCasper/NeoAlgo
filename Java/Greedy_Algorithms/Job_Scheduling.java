/* Problem Description
Given a set of N jobs where each job i has a deadline and profit associated to it. 
Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
We earn the profit if and only if the job is completed by its deadline.
The task is to find the maximum profit and the number of jobs done.
*/

import java.io.*;
import java.lang.*;
import java.util.*;

public class Job_Scheduling_Greedy {
    // this Job class will store the id, profit, deadline property 
	static class Job {
	    int id, profit, deadline;
	    Job(int id, int deadline, int profit){
            this.id = id;
            this.profit = profit;
            this.deadline = deadline;
        }
	};
	
	// solve() will do the task of getting the profit
	static int[] solve (Job[] arr , int n )
	{
		// Sort the array in descending order according to profit
		Arrays.sort(arr , (a,b) -> b.profit - a.profit );
		int res[]  = new int[2] ;
		int totalProfit = 0;
		int count = 0 ;        
		Boolean[] slots = new Boolean[n];
		Arrays.fill(slots, false);
	       /* iterate through the jobs with minDeadLine to remaining jobs and
		 check if there is any slote available and also claculate the profit
	       */
		for (int i = 0; i < n; i++) {
		    int minDeadLine = Math.min( arr[i].deadline - 1 , n- 1) ;
		    for (int j = minDeadLine ; j >= 0; j--) 
		    {
			if (slots[j] == false) {
			    count ++ ;
			    slots[j] = true;
			    totalProfit += arr[i].profit ;
			    break;
			}
		    }
		}
		// store the count and profit in res array and return the result
		res[0] = count ;
		res[1] = totalProfit ;
		return res ;
	}
	
 	public static void main(String[] args) throws IOException{
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    System.out.println("Enter number of testcase");
	    int test = Integer.parseInt(br.readLine().trim());
	    while(test-->0){
            // input the no. of jobs
            System.out.println("Enter number of jobs");
            String input[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(input[0]);
            // Make a reference to Job and set size number of jobs 
            Job[] arr = new Job[n];
            System.out.println("Enter values of jobs");
            input = br.readLine().trim().split(" ");
            for(int i=0, k=0; i<n; i++){
                arr[i] = new Job(Integer.parseInt(input[k++]), Integer.parseInt(input[k++]), Integer.parseInt(input[k++]));
            }
            // call the method to get the result
            int[] result = solve(arr, n);
            // Print the required result
            System.out.println ("Maximum Profit : " + result[0] + " " + result[1]);            
        }
    }
}

/* Input
Enter number of testcase
1
Enter number of jobs
4
Enter values of jobs
1 4 20 2 1 10 3 1 40 4 1 30

Output :
Maximum Profit : 2 60

Explanation
Sort all the jobs according to descending in terms of profit and loop the jobs and check if slot is available or not
and according insert value to res array and output the result.

Time Complexity : O(NLogN)
Space Complexity : O(N)
*/


