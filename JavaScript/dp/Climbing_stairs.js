/*
Problem statement : 
A Person is at the bottom of n stairs .
To reach the top he can climb either 1 or 2 stairs at a time. 
Find the number of ways he can reach the top
*/

function climbing_stairs(n) {
    let dp = new Array(n);
    dp[0] = 1
    dp[1] = 1
    for (let i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
//For reading input 
const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

const getLine = (function () {
    const getLineGen = (async function* () {
        for await (const line of rl) {
            yield line;
        }
    })();
    return async () => ((await getLineGen.next()).value);
})();

const main = async () => {
    console.log("Enter the number stairs");
    let n = Number(await getLine());
    console.log("The number of ways to climb the stairs is : " + climbing_stairs(n));
    process.exit(0);
};

main();

/*
Sample I/O:

Enter the number stairs
5
The number of ways to climb the stairs is : 8

Time complexity : O(n)
Space complexity : O(n)
*/
