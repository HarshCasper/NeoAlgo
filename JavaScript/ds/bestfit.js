/*
The best fit strategy will not allocate a block of size > N , as it is found in the first-fit method;
instead it will continue searching to find a suitable block so that the block size is closer to the block size of request.
The below program is an implementation of best fit algorithm using array data structure.
*/

class Block{
    constructor(){
        this.size = 0
        this.ID = 0
        this.fragment = 0
    }
}

class Process{
    constructor(){
        this.Num = 0
        this.size = 0
        this.block = null
    }
}

class Bestfit{
    initialiseBlocks(arr,sizes,n){
        for(let i=0;i<n;i++){
            arr[i].size = sizes[i]
            arr[i].fragment = sizes[i]
            arr[i].ID = i + 1
        }
    }

    printResult(arr2, numOfProcess){
        console.log(
        "Process No            Process Size          Block ID          Block Size         Block Fragment"
        );
        for(let i=0;i<numOfProcess;i++){
            console.log(
                arr2[i].Num
                + "                     "
                + arr2[i].size
                + "                     "
                + arr2[i].block.ID
                + "                     "
                + arr2[i].block.size
                + "                     "
                + arr2[i].block.fragment
            )
        }

    }
    bestfit(arr, sizes, n, arr2, numOfProcess){
        let minBlock = new Block()
        for(let i=0;i<numOfProcess;i++){
            let min = 100
            for(let j=0;j<numOfProcess;j++){
                if(arr2[i].size <= arr[j].fragment && arr[j].fragment < min){
                    min = arr[j].fragment
                    minBlock = arr[j]
                }

            }
            minBlock.fragment = minBlock.fragment - arr2[i].size
            arr2[i].block = new Block()
            arr2[i].block.size = minBlock.size
            arr2[i].block.ID = minBlock.ID
            arr2[i].block.fragment = minBlock.fragment
        }
        console.log("Best Fit Allocation")
        this.printResult(arr2, numOfProcess);
    }
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
    let obj = new Bestfit()
    let sizes = [60, 20, 12, 35, 64, 42, 31, 35, 40, 50]
    let arr = []
    for(let i=0;i<10;i++){
        arr.push(new Block());
    }
    obj.initialiseBlocks(arr,sizes,10)
    console.log("Enter the number of process for memory to be allocated");
    let numOfProcess = Number(await getLine());
    console.log("Enter the sizes required by the processes in the order of requirement")
    let psize = []
    let temp = 0;
    for(let i=0;i<numOfProcess;i++){
        temp = Number(await getLine());
        psize.push(temp)
    }
    let arr2 = []
    for(let i=0;i<numOfProcess;i++){
        arr2.push(new Process())
        arr2[i].size = psize[i];
        arr2[i].Num = i + 1;
    }
    obj.bestfit(arr, sizes, 10, arr2, numOfProcess)
    process.exit(0)
}

main();

/*
Sample I/O:

Enter the number of process for memory to be allocated
5
Enter the sizes required by the processes in the order of requirement
12
11
10
5
23
Best Fit Allocation
Process No            Process Size          Block ID          Block Size         Block Fragment
1                     12                     3                     12                     0
2                     11                     2                     20                     9
3                     10                     7                     31                     21
4                     5                      2                     20                     4
5                     23                     4                     35                     12

Time complexity : O(n)
space complexity : O(n)
*/
