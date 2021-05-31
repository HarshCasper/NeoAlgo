/*
The worst fit strategy is a reverse of the best-fit strategy. It allocates the largest block available in the storage list.
The idea behind worst-fit is to reduce the rate of production of small blocks. The below program is an implementation of
the worst fit algorithm using array data structure.
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

class Worstfit{
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
    worstfit(arr, sizes, n, arr2, numOfProcess){
        let maxBlock = new Block()
        for(let i = 0; i <numOfProcess;i++){
            let max = 0
            for(let j=0;j<n;j++){
                if(arr2[i].size <= arr[j].fragment && arr[j].fragment > max){
                    max = arr[j].fragment
                    maxBlock = arr[j]
                }
            }
            maxBlock.fragment = maxBlock.fragment - arr2[i].size
            arr2[i].block = new Block()
            arr2[i].block.size = maxBlock.size
            arr2[i].block.ID = maxBlock.ID
            arr2[i].block.fragment = maxBlock.fragment
        }
        console.log("Worst Fit Allocation")
        this.printResult(arr2, numOfProcess)
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
    obj.worstfit(arr, sizes, 10, arr2, numOfProcess)
    process.exit(0)
}

main();

/*
Sample I/O:

Enter the number of process for memory to be allocated
5
Enter the sizes required by the processes in the order of requirement
10
20
11
12
13
Worst Fit Allocation
Process No            Process Size          Block ID          Block Size         Block Fragment
1                     10                     5                     64                     54
2                     20                     1                     60                     40
3                     11                     5                     64                     43
4                     12                     10                    50                     38
5                     13                     5                     64                     30

Time complexity : O(n)
space complexity : O(n)
*/
