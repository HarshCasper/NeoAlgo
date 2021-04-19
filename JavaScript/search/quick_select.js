// The quick select algorithm is used to find the k-th smallest element in an array in an efficient way
// It reduces the expected complexity from O(n log n) to O(n), with a worst case of O(n^2).


export default function quickselect(arr, k, l, r, cmp) {
    quickSelectAction(arr, k, l || 0, r || (arr.length - 1), cmp || defaultcmp);
}

//some helper functions :
//--------------------------------------------------------------------------------------------
function swap(arr, i, j) {
    var tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

function defaultcmp(a, b) {
    return a < b ? -1 : a > b ? 1 : 0;
}
//--------------------------------------------------------------------------------------------


// This algorithm is a modification to Quick-Sort algorithm. But after finding the pivot element, it will perform recursion only for
// the part which contains the k-th smallest element
// So if index of the partioned element is greater than k, then we will perform recursion for the left part, if it is less than k , then we will recurse for the right part
// If the index is same as k, we have found the element , so we return it
function quickSelectAction(arr, k, l, r, cmp) {

    while (r > l) {
        if (r - l > 600) {
            var n = r - l + 1;
            var m = k - l + 1;
            var z = Math.log(n);
            var s = 0.5 * Math.exp(2 * z / 3);
            var sd = 0.5 * Math.sqrt(z * s * (n - s) / n) * (m - n / 2 < 0 ? -1 : 1);
            var newl = Math.max(l, Math.floor(k - m * s / n + sd));
            var newr = Math.min(r, Math.floor(k + (n - m) * s / n + sd));
            quickSelectAction(arr, k, newl, newr, cmp);
        }

        var t = arr[k];
        var i = l;
        var j = r;

        swap(arr, l, k);
        if (cmp(arr[r], t) > 0) swap(arr, l, r);

        while (i < j) {
            swap(arr, i, j);
            i++;
            j--;
            while (cmp(arr[i], t) < 0) i++;
            while (cmp(arr[j], t) > 0) j--;
        }

        if (cmp(arr[l], t) === 0) swap(arr, l, j);
        else {
            j++;
            swap(arr, j, r);
        }

        if (j <= k) l = j + 1;
        if (k <= j) r = j - 1;
    }
}

