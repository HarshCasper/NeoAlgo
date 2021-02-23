/*Selection sort is a simple sorting algorithm. ... The smallest element is
 selected from the unsorted array and swapped with the leftmost element, and
that element becomes a part of the sorted array. This process continues moving
unsorted array boundary by one element to the right. */


function selectionSort(inputArray) {
    let n = inputArray.length;

    for (let i = 0; i < n; i++) {
        // Finding the smallest number in the subarray
        let min = i;
        for (let j = i + 1; j < n; j++) {
            if (inputArray[j] < inputArray[min]) {
                min = j;
            }
        }
        if (min != i) {
            // Swapping the elements
            let temp = inputArr[i];
            inputArray[i] = inputArray[min];
            inputArray[min] = temp;
        }
    }
    return inputArray;
}


let inputArray = [12, 2, 34, 1, 19];
selectionSort(inputArray);
console.log(inputArray);

(5)[1, 2, 12, 19, 34] /*output*/ 