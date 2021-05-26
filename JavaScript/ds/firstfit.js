/*
First fit is the simplest of all the storage allocation strategies.
Here the list of storages is searched and as soon as a free storage block of size >= N is found ,
the pointer of that block is sent to the calling program after retaining the residue space.Thus, for example,
for a block of size 5k , 2k memory will be sent to the caller . The below program is a simulation of the first fit strategy
using array data structure.
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


class Firstfit{
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

    firstfit(arr, sizes, n, arr2, numOfProcess){
        for(let i=0;i<numOfProcess;i++){
            for(let j=0;j<n;j++){
                if(arr2[i].size <= arr[j].fragment){
                    arr[j].fragment -= arr2[i].size;
                    arr2[i].block = new Block();
                    arr2[i].block.size = arr[j].size;
                    arr2[i].block.ID = arr[j].ID;
                    arr2[i].block.fragment = arr[j].fragment;
                    break;
                }
            }
        }
        console.log("First Fit Allocation")
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
    let obj = new Firstfit()
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
    obj.firstfit(arr, sizes, 10, arr2, numOfProcess)
    process.exit(0)
}

main();

/*
Sample I/O:

Enter the number of process for memory to be allocated
5
Enter the sizes required by the processes in the order of requirement
15
12
13
20
11
First Fit Allocation
Process No            Process Size          Block ID          Block Size         Block Fragment
1                     15                     1                     60                     45
2                     12                     1                     60                     33
3                     13                     1                     60                     20
4                     20                     1                     60                     0
5                     11                     2                     20                     9

Time complexity : O(n)
space complexity : O(n)
*/
