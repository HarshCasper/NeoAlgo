#include<stdio.h>

int max(int a,int b) {
    return (a >= b) ? a : b;
}

int max_sum_crossing(int arr[], int lo, int mid, int hi) {
    int cur = 0, presum = -1e9;
    for (int i = mid; i >= lo; --i) {
        cur += arr[i];
        presum = max(presum, cur);
    }
    cur = 0;
    int postsum = -1e9;
    for (int i = mid + 1; i <= hi; ++i) {
        cur += arr[i];
        postsum = max(postsum, cur);
    }

    return max(max(presum, postsum), presum + postsum);

}

int max_sum_subarray(int arr[], int lo, int hi) {
    if(lo == hi) {
        return arr[lo];
    }
    int mid = lo + (hi - lo) / 2;
    return max(max(max_sum_subarray(arr, lo, mid), max_sum_subarray(arr, mid+1, hi)), max_sum_crossing(arr, lo, mid, hi));
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int ans = max_sum_subarray(arr, 0, n-1);
    printf("The maximum sum subarray is: %d", ans);
    return 0;
}

/*
Time Complexity: O(N logN)

INPUT 1:
5
1 3 2 4 7
OUTPUT 1:
The maximum sum subarray is: 17

INPUT 2:
5
1 -1 2 3 -2
OUTPUT 2:
The maximum sum subarray is: 5

*/
