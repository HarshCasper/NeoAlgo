
/*
It is a monte carlo version of code with a depth,it give you the optimal or sub optimal result
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int pick_random(int *a,int n){
    int i;
    time_t t;

    srand((unsigned)time(&t));

    return a[rand()%n];
}

int* create(int n){
    int* a = (int*)malloc(n*sizeof(n));

    for (int i = 0; i < n; i++)
    {
        /* code */
        scanf("%d",(a+i));
    }

    return a;
    
}

void display(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        /* print the array */
        printf("%d ",*(a+i));
    }
    
}

int random_search(int element,int *a,int n){
    int set_depth = 1000;
     while (1 || set_depth<1000)
     {
         /* infinite loop untill get the element */
         int temp = pick_random(a,n);

         if (temp == element)
         {
             return 1;
             break;
         }

         set_depth++;
         
     }

     return 0;
     
}

int main(int argc, char const *argv[])
{
    int n;

    printf("enter the size of the array:");
    scanf("%d",&n);


    int *a = create(n);

    display(a,n);
    
    int element;

    printf("enter the element to search:");
    scanf("%d",&element);

    if(random_search(element,a,n)==1){
       printf("element found");
    }
    else
    {
        printf("element not found");
    }
    
    return 0;
}
