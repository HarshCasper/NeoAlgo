function bucketSort(arr, bucketSize) {
    if (arr.length < 2) {
        return arr;
    }
    // create buckets and distribute the elements
    const buckets = createBuckets(arr, bucketSize);
    // sort the buckets using insertion sort and add all bucket elements to sorted result 
    return sortBuckets(buckets);
}

function createBuckets(arr, bucketSize) {
    // determine the bucket count
    let min = arr[0];
    let max = arr[0];
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }
    const bucketCount = Math.floor((max - min) / bucketSize) + 1;

    // initialize each bucket (a multidimensional array)
    const buckets = [];
    for (let i = 0; i < bucketCount; i++) {
        buckets[i] = [];
    }

    // distribute elements into buckets
    for (let i = 0; i < arr.length; i++) {
        const bucketIndex = Math.floor((arr[i] - min) / bucketSize);
        buckets[bucketIndex].push(arr[i]);
    }
    return buckets;
}

function sortBuckets(buckets) {
    const sortedArr = [];
    for (let i = 0; i < buckets.length; i++) {
        if (buckets[i] != null) {
            insertionSort(buckets[i]); // quick sort is another good option
            sortedArr.push(...buckets[i]);
        }
    }
    return sortedArr;
}
