/*
In mathematics, matrix addition is the operation of adding two matrices by adding 
the corresponding entries together.This program takes two matrices of order n*m and 
stores it in two-dimensional array. Then, the program adds these two matrices and 
displays it on the screen.
*/

function matrix_addition(a_1, n1, m1, a_2) {
    //res is the result array
    let res = new Array(n1);
    for (let i = 0; i < n1; i++) {
        res[i] = new Array(m1);
    }
    for (let i = 0; i < n1; i++) {
        for (let j = 0; j < m1; j++) {
            res[i][j] = a_1[i][j] + a_2[i][j];
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
    let res = matrix_addition(a_1, n1, m1, a_2);
    let s = '';
    for (let i = 0; i < n1; i++) {
        for (let j = 0; j < m1; j++) {
            s += res[i][j] + " ";
        }
        s += '\n';
    }
    console.log("Result of matrix addition is");
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
3
Enter the elements of the second matrix
Enter the element at position 0 , 0
9
Enter the element at position 0 , 1
8
Enter the element at position 0 , 2
7
Enter the element at position 1 , 0
6
Enter the element at position 1 , 1
5
Enter the element at position 1 , 2
4
Enter the element at position 2 , 0
3
Enter the element at position 2 , 1
2
Enter the element at position 2 , 2
1
Result of matrix addition is
10 10 10
10 10 10
10 10 10

Time complexity : O(n^2)
Space complexity : O(n^2)
*/

