//bilinear search is a modified version of linear search where it search from both direction

#include<stdio.h>
#include<stdlib.h>


int* create(int n){
    int* a = (int*)malloc(n*sizeof(int));

    printf("enter the elements:");
    for (int i = 0; i < n; i++)
    {
        /* take input from user and create an array */
        scanf("%d",(a+i));
    }

    return a;
    
}

void display(int* a,int n){
    for (int i = 0; i < n; i++)
    {
        /* display the array */
        printf("%d ",*(a+i));
    }
    
}

void bilinear_search(int *a,int ele,int n){

    int i = 0;
    int j = n-1;
    int p = 0;
    
    if(a[n/2] == ele){
            p = 1;
        }

    while (i<j)
    {
        /* searching start */
        if (a[i] != ele && a[j] != ele)
        {
            /* checking condition if the element in the array or not */
            i++;
            j--;
            
        }
        else
        {
            p = 1;
            break;
        }
        
        
    }

    if (p == 1)
    {
        printf("\n element found in array");
    }
    else if(p == 0)
    {
        printf("\n element not found");
    }
}

int main(int argc, char const *argv[])
{
    int ele,n;

    printf("enter the size of the array:");
    scanf("%d",&n);

    int *a = create(n);

    display(a,n);

    printf("\n enter the element to search:");
    scanf("%d",&ele);

    bilinear_search(a,ele,n);
    return 0;
}
