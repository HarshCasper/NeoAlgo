#include <stdio.h>

int painters(int * arr, int maxtime, int len, int num) {
    int time = 0, count = 1;
    for (int i = 0; i < len; i++) {
        time += arr[i];
        if (time > maxtime) {
            time = arr[i];
            count++;
            if (count > num) {
                return 0;
            }
        }
    }
    return 1;
}

int get_max(int arr[], int len) {
    int max = arr[0];
    for (int i = 1; i < len; i++) {

        if (max < arr[i]) max = arr[i];
    }
    return max;
}

int main() {
    int len, num, time;
    int sum = 0;
    printf("Enter the length of array, num of painters and time: ");
    scanf("%d%d%d", & len, & num, & time);

    int arr[len];

    printf("Enter the array: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", & arr[i]);
        sum += arr[i];
    }

    // Finding the max of array
    int start = get_max(arr, len);
    int end = sum, ans;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (painters(arr, mid, len, num)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    ans = ans * time;
    printf("Total time taken: %d", ans);

    return 0;
}
/*
Output:

Enter the length of array,num of painters and time: 2 2 5
Enter the array: 1 10
Total time taken: 50
Time complexity : O(n*log(N)) (where N is sum of array elements)
space complexity : O(n)     (n is size of array)
*/
