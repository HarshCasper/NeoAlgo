/*
a linear search or sequential search is a method for finding an element within a list. 
It sequentially checks each element of the list until a match is found or the whole list 
has been searched.

It has time complexity of O(n).
____________________
|1|5|8|9|0|10|11|12|  -----> search(9)
                                |
                                |
___________________        
|1|5|8|9|0|10|11|12|

 |_______________________is i==9 false next element i=1
   |_____________________is i==9 false next element i=5
     |___________________is i==9 false next element i=8
        |________________is i==9 true return found and break the loop i=9

So it is searching the whole array linearly.

*/

#include<stdio.h>
#include<stdlib.h>

//base utility function to create the array
int* create(int n){
    int *a = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        /* code */
        scanf("%d",(a+i));
    }
    
    return a;
}


//linear searching a element
void linear_search(int element,int *a,int n){

     //loop intitialisation
     for (int i = 0; i < n; i++)
     {
         /* check if the element is in the array */
         if(*(a+i)==element){
             printf("\nelement found at:%d position",i);
             break;
         }
     }
     
}

//printting the array function
void display(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        /* code */

        printf("%d ",*(a+i));
    }
    
}

//main function
int main(int argc, char const *argv[])
{
    int n;

    printf("\nenter the size of the array:");
    scanf("%d",&n);

    int *arr = create(n);
    
    printf("\n the array is:");
    display(arr,n);

    int element;//element to search

    printf("\n enter the element to search:");
    scanf("%d",&element);

    linear_search(element,arr,n);
    return 0;
}

