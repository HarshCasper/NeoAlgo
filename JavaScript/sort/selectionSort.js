/*
SELECTION SORT:
    Selection sort is a simple inplace sorting algorithm.
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

var arr = prompt("Enter numbers to sort comma separated: ").split(",");
console.log(selectionSort(arr));
/*
Time Complexity - O(n^2)
Space Complexity - O(1)
*/