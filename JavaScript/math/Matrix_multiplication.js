/*
matrix multiplication is a binary operation that produces a product matrix 
from two matrices . To multiply two matrices, the number of columns of first 
matrix should be equal to the number of rows to second matrix.
This program finds the product of two given matrices
*/

function matrix_multiplication(a_1, n1, m1, a_2, n2, m2) {
    //res is the result array
    let res = new Array(n1);
    for (let i = 0; i < n1; i++) {
        res[i] = new Array(m2);
    }
    for (let i = 0; i < n1; i++) {
        for (let j = 0; j < m2; j++) {
            res[i][j] = 0;
            for (let k = 0; k < m1; k++) {
                res[i][j] += a_1[i][k] * a_2[k][j]
            }
        }
    }
    return res;
}


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
    console.log("Enter the number of rows in the first matrix");
    let n1 = Number(await getLine());
    console.log("Enter the number of columns in the first matrix");
    let m1 = Number(await getLine());
    console.log("Enter the elements of the first matrix");
    //initializing array
    let a_1 = new Array(n1);
    for (let i = 0; i < n1; i++) {
        a_1[i] = new Array(m1);
    }
    for (let i = 0; i < n1; i++) {
        for (let j = 0; j < m1; j++) {
            console.log("Enter the element at position " + i + " , " + j);
            a_1[i][j] = Number(await getLine());
        }
    }
    console.log("Enter the number of rows in the second matrix");
    let n2 = Number(await getLine());
    console.log("Enter the number of columns in the second matrix");
    let m2 = Number(await getLine());
    console.log("Enter the elements of the second matrix");
    //initializing array
    let a_2 = new Array(n2);
    for (let i = 0; i < n2; i++) {
        a_2[i] = new Array(m2);
    }
    for (let i = 0; i < n2; i++) {
        for (let j = 0; j < m2; j++) {
            console.log("Enter the element at position " + i + " , " + j);
            a_2[i][j] = Number(await getLine());
        }
    }
    let res = matrix_multiplication(a_1, n1, m1, a_2, n2, m2);
    let s = '';
    for (let i = 0; i < n1; i++) {
        for (let j = 0; j < m2; j++) {
            s += res[i][j] + " ";
        }
        s += '\n';
    }
    console.log("Result of matrix multiplication is");
    console.log(s);
    process.exit(0);
};

main();


/*
Sample I/O:

Enter the number of rows in the first matrix
3
Enter the number of columns in the first matrix
3
Enter the elements of the first matrix
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
Enter the number of rows in the second matrix
3
Enter the number of columns in the second matrix
4
Enter the elements of the second matrix
Enter the element at position 0 , 0
1
Enter the element at position 0 , 1
2
Enter the element at position 0 , 2
3
Enter the element at position 0 , 3
4
Enter the element at position 1 , 0
5
Enter the element at position 1 , 1
6
Enter the element at position 1 , 2
7
Enter the element at position 1 , 3
8
Enter the element at position 2 , 0
9
Enter the element at position 2 , 1
10
Enter the element at position 2 , 2
11
Enter the element at position 2 , 3
12
Result of matrix multiplication is
38 44 50 56
83 98 113 128
128 152 176 200

Time complexity : O(n^3)
Space complexity : O(n^2)
*/

