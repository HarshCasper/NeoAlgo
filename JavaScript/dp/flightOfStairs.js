/*You are given positive integers n and k. You are currently at stair 0 and want to climb to stair n. 
You can either climb 1, 2, or 3 stairs at a time, but you can only climb 3 stairs at most k times.
Return the number of ways to climb to the nth stair.
*/

const FlightOfStairs = (n, k) => {
    const memo = new Array(n + 1);
    for (let i = 0; i < n + 1; i++)
    {
        memo[i] = new Array(k + 1).fill(0);
    }

    /*passing to the utility function*/
    console.log("The answer is ",solveUtil(n, k, memo));
};

const solveUtil = (n, k, memo) =>{

    /*base cases*/
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;
    else if (memo[n][k] != 0)
        return memo[n][k];

    /*calls for 1 and 2 steps*/
    memo[n][k] = solveUtil(n - 1, k, memo) + solveUtil(n - 2, k, memo);

    /*checking k before making calls for 3 steps*/
    if (k > 0)
        memo[n][k] += solveUtil(n - 3, k - 1, memo);

    return memo[n][k];
};

/*taking arguments using command line arguments*/
console.log("Enter the values of n and k: ");
var arguments = process.argv;
FlightOfStairs(parseInt(arguments[2]),parseInt(arguments[3]));

  
/*
Input:
Enter the values of n and k: 
4 1

Output:
The answer is 7
*/

/*
Time complexity: O(n*k)
Space complexity: O(n*k)
*/
