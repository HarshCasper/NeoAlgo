/*
Problem statement : 
There is a fence with n posts, you are given k colors to paint the fence. 
Each post can be painted with one of the k colors. You have to paint all the posts 
with the k colors such that atmost two adjacent posts have the same color. 
You have to find the total number of ways to paint the fence.
*/

function painting_fence(n, k) {
    let same = k;
    let diff = k * (k - 1);
    let total = k * k;
    for (let i = 0; i < n - 2; i++) {
        same = diff;
        diff = total * (k - 1);
        total = same + diff;
    }
    return total;
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
    console.log("Enter n, the number of posts");
    let n = Number(await getLine());
    console.log("Enter k, the number of colors");
    let k = Number(await getLine());
    console.log("Number of possiblilities for painting the fence is : " + painting_fence(n, k));
    process.exit(0);
};

main();

/*
Sample I/O:

Enter n, the number of posts
3
Enter k, the number of colors
2
Number of possiblilities for painting the fence is : 6

Time complexity : O(n)
Space complexity : O(1)
*/
