#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d\n",&n);
    printf("Enter the array:\n");
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    if (arr == NULL) { 
        printf("Memory not allocated.\n"); 
        return 0;
    } 
    else {
        for (int i = 1; i <= n; i++) {
            if (arr[i] <= 0 || arr[i] > n) 
                continue; 

            int x = arr[i]; 
            while (arr[x] != x) { 
                int next_ele = arr[x]; 
                arr[x] = x; 
                x = next_ele;
                if (x <= 0 || x > n) 
                    break; 
            } 
        }
        int ans = n + 1;
        for (int i = 1; i <= n; i++) { 
            if (arr[i] != i) { 
                ans = i;
                break;
            } 
        }
        printf("%d", ans);
    } 
    
    return 0;
}

/*
Time Complexity: O(N)
Space Complexity: O(1)
OUTPUT
Enter the value of n: 4
Enter the array:
3 4 -1 1
2
*/
