#include <stdio.h>

void TowerOfHanoi(int n,int a,int b,int c){
    if(n){
        TowerOfHanoi(n-1,a,c,b);
        printf("%d -> %d\n", a,b);
        TowerOfHanoi(n-1,c,b,a);
    }
}

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d\n",&n);
    printf("Enter the array:\n");
    int a[n+1];
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
  
    for (int i = 1; i <= n; i++) {
        if (a[i] <= 0 || a[i] > n) 
            continue; 
  
        int x = a[i]; 
        while (a[x] != x) { 
            int next_ele = a[x]; 
            a[x] = x; 
            x = next_ele;
            if (x <= 0 || x > n) 
                break; 
        } 
    }
    int ans = n + 1;
    for (int i = 1; i <= n; i++) { 
        if (a[i] != i) { 
            ans = i;
            break;
        } 
    }
    printf("%d", ans);
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
