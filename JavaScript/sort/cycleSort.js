/*CYCLE SORT:
	* an in-place unstable sorting Algorithm.
	* Optimal in terms of the total number of writes to original array.
	* Algorithm:
		STEP 1: For arr[i], find it's original_index in the sorted list by counting the smaller elements in arr.
		STEP 2: If element == arr[original_index], the iteration is skipped Else write it to original_index.
		STEP 3: If original_index is inhabited by a different element, repeat the above steps. 
		This is continued until an element is moved to the original position.This is a cycle.
		Such n cycles are executed.
*/

//importing readline module for dynamic input 
var readline = require('readline');
//initialising inputstream and outstream to process.stdin and process.stdout respectively.
var rl = readline.createInterface(
	process.stdin, process.stdout);

const cycleSort = (arr) => {
    const n = arr.length;
    //start is the index of the current element.
    for (let start = 0; start < n - 1; start++) {
        
        let currentKey = arr[start];
        let pos = start;
        for (let i = start + 1; i < n; i++) {
            if (arr[i] < currentKey)
                pos += 1;
        }
        // if pos = start => element is at original position. If so skip.
        if (pos == start) 
            continue;

        //check for duplicates in the array. 
        while (currentKey == arr[pos]) { 
            pos++ ;
        }
        //swapping current element and element at its original position.
        const temp = arr[pos];
        arr[pos] = currentKey;
        currentKey = temp;

        // rotate the rest of the cycle
        while (pos != start) {
            pos = start;
            //finding original position
            for (let i = start + 1; i < n; i++) {
                if (arr[i] < currentKey) 
                    pos += 1;
            }

            //checking for duplicates
            while (arr[pos] == currentKey) {
                pos += 1;
            }
            const temp = arr[pos];
            arr[pos] = currentKey;
            currentKey = temp;
        }
    }
    return arr;
}

//Reading input from console as a string and converting it to array 
rl.question('Enter array elements comma separated: ', (input) => {
    let numbers = input.split(",");
    numbers = numbers.map( (x) => parseInt(x));
    console.log(cycleSort(numbers));
	rl.close();
});

/*
CASE 1:
input = [1, 8, 7, 61, 5, 4, 11];
EXPECTED: [1,4,5,7,8,11,61]

CASE 2:
input = [1,8,3,9,10,10,2,4];
EXPECTED: [1,2,3,4,8,9,10,10]

    Time Complexity - O(n^2)
    Space Complexity - O(1)

*/
