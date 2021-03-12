/*
SELECTION SORT:
    Selection sort is a simple inplace sorting algorithm.
*/

//importing readline module to read user input.
var readline = require('readline');
//initializing process.stdin and process.stdout for inputstream and outputstream respectively. 
var rl = readline.createInterface(
    process.stdin, process.stdout);
    
function selectionSort(arr){
    let n = arr.length;
    // i is the current index
    for(let i=0; i<n-1; i++){
        //minPos stores the position of smallest element
        let minPos = i;

        //finding the minimum element from arr.
        for(let j=i+1; j<n; j++){
            if(arr[j] < arr[minPos]){
                minPos = j;
            }
        }
        //swapping current element and smallest element;
        let temp = arr[minPos];
        arr[minPos] = arr[i];
        arr[i] = temp;
    }
    return arr;
}

//input array of numbers as a string
rl.question('Enter array elements in a line: ', (input) => {
    //converting string into array of integers.
    let output = selectionSort(input.split(" ").map(x => parseInt(x)));
    console.log(output);
	rl.close();
});

/*
Time Complexity - O(n^2)
Space Complexity - O(1)
*/