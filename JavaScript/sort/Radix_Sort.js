/* Radix sort works on the idea of digit by digit sorting from LSD (least significant digit) to 
MSD(most significant bit). We will use counting sort for this purpose.
*/


function maximumVal(arr) {
    let maximum = 0;
    for(let n of arr) {
        if(maximum<n.toString().length) {
            maximum = n.toString().length;
        }
    }
    return maximum;
}

function position(n, pos) {
    return Math.floor(Math.abs(n)/Math.pow(10, pos))%10;
}

function radixSort(arr) {
    const max = maximumVal(arr);
    for(var i = 0; i<max; i++) {
        let buckets = Array.from({length:10}, () => [])
        for(var j = 0; j < arr.length; j++) {
            buckets[position(arr[j], i)].push(arr[j]);
        }
        arr = [].concat(...buckets);
    }  
    return arr; 
}


console.log(radixSort([45, 97, 84, 9, 1, 0]));
console.log(radixSort([59, 89, 98, 23, 165, 7]));




/* Time Complexity
   If we have n input numbers and they have upto d digits. Therefore count sort algorithm is implemented d times.
   Count sort is a linear algorithm with O(n) time complexity, therefore the radix sort algorithm in whole takes 
   O(n*d) time.
*/