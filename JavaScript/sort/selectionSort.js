/*
SELECTION SORT:
    Selection sort is a simple inplace sorting algorithm.
    Time Complexity - O(n^2)
    Space Complexity - O(1)
*/

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

//displaying sorted array.
//CASE 1:
let input1 = [9,8,7,6,5,4,3,2,1];
console.log(selectionSort(input1));
//Expected output: [1,2,3,4,5,6,7,8,9]

//CASE 2:
let input2 = [2,8,3,10,23,1,5]
console.log(selectionSort(input2));
//Expected output: [1,2,3,5,8,10,23]