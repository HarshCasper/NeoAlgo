/*
Transpose of a matrix is a matrix obtained by changing rows to columns and columns
to rows.In other words, transpose of Arr[][] is obtained by changing Arr[i][j] to Arr[j][i].
The below program finds transpose of matrix[][] and stores the result in result[][]
*/
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
    console.log("Enter the number of rows in the matrix");
    let n = Number(await getLine());
    console.log("Enter the number of columns in the matrix");
    let m = Number(await getLine());
    console.log("Enter the elements of the matrix");
    //initializing array
    let a_1 = new Array(n);
    for (let i = 0; i < n; i++) {
        a_1[i] = new Array(m);
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            console.log("Enter the element at position " + i + " , " + j);
            a_1[i][j] = Number(await getLine());
        }
    }
    //initializing array
    let res = new Array(n);
    for (let i = 0; i < n; i++) {
        res[i] = new Array(m);
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            res[i][j] = a_1[j][i];
        }
    }
    let s = '';
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            s += res[i][j] + " ";
        }
        s += '\n';
    }
    console.log("Transpose of matrix is");
    console.log(s);
    process.exit(0);
};

main();


/*
Sample I/O:

Enter the number of rows in the matrix
3
Enter the number of columns in the matrix
3
Enter the elements of the matrix
Enter the element at position 0 , 0
1
Enter the element at position 0 , 1
2
Enter the element at position 0 , 2
3
Enter the element at position 1 , 0
4
Enter the element at position 1 , 1
5
Enter the element at position 1 , 2
6
Enter the element at position 2 , 0
7
Enter the element at position 2 , 1
8
Enter the element at position 2 , 2
9
Transpose of matrix is
1 4 7
2 5 8
3 6 9

Time complexity : O(n^2)
Space complexity : O(n^2)
*/

