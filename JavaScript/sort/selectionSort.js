/*
SELECTION SORT:
    Selection sort is a simple inplace sorting algorithm.
    Time Complexity - O(n^2)
    Space Complexity - O(1) 
*/

selectionSort = (arr) => {
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
//For  dynamic input use the below line.
//var arr = prompt("Enter numbers to sort comma separated: ").split(",");
var arr = [9, 8, 7, 6, 5, 4, 3];
console.log(selectionSort(arr));
//Expected output : [3,4,5,6,7,8,9]