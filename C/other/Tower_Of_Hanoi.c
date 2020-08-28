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
    scanf("%d",&n);
    TowerOfHanoi(n,1,2,3);
    return 0;
}
