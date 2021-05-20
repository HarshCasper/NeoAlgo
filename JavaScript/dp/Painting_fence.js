/*
Problem statement : 
There is a fence with n posts, you are given k colors to paint the fence. 
Each post can be painted with one of the k colors. You have to paint all the posts 
with the k colors such that atmost two adjacent posts have the same color. 
You have to find the total number of ways to paint the fence.

Explanation : 
Suppose we have a single post, The number of ways of painting the fence with k 
colors is k Now we consider 2 posts, Then the number of ways of painting the 
second fence with the same color as the first post is k, and the number of ways 
of painting the second post with a different color is k*(k-1) as we have k-1 colors 
that are different from the first post's color. So the total number of ways of 
painting 2 fences is k*(k-1) + k. Now we consider 3 posts, Then the number of ways 
of painting the third fence same as the second fence is the number of ways of painting 
the second fence with a different color that is k*(k-1). The number of ways of painting 
the third fence using a different color is equal to the total number of ways of painting 
the second fence times (k-1). Hence the total number of ways of painting 3 fences is 
k*(k-1) + (k+k*(k-1))*(k-1). This way we can find the total number of ways of painting 
n fences
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
