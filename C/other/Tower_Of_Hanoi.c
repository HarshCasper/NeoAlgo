#include <stdio.h>

void TowerOfHanoi(int n,int a,int b,int c){
    if(n==1){
        printf("%d -> %d\n", a,b);
        return ;
    }
    TowerOfHanoi(n-1,a,c,b);
    printf("%d -> %d\n", a,b);
    TowerOfHanoi(n-1,c,b,a);
}

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("\nThe value of n is: %d\n", n);
    TowerOfHanoi(n,1,2,3);
    return 0;
}

/*
OUTPUT
Enter the value of n: 4
The value of n is: 4
1 -> 3
1 -> 2
3 -> 2
1 -> 3
2 -> 1
2 -> 3
1 -> 3
1 -> 2
3 -> 2
3 -> 1
2 -> 1
3 -> 2
1 -> 3
1 -> 2
3 -> 2

*/
