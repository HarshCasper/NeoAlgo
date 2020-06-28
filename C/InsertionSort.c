//INSERTION SORT
#include <stdio.h>
void main()
{
    int arraySize , index , temp , key ;
    printf("Please enter the size of the array\n");
    scanf("%d",&arraySize);
    int arr[arraySize]; // declaring array by - 'arr'
     printf("Please enter the elements to sort\n");
    for(index=0;index<arraySize;index++)
    {
        scanf("%d",&arr[index]);
    }

    for(index=1;index<arraySize;index++)
    {
        key=arr[index]; // the key stores the value at the index position
        temp=index-1;
        while(temp>=0&&arr[temp]>key)
        {
arr[temp+1]=arr[temp];
temp--;
        }
        
    arr[temp+1]=key;
        }
   printf("SORTED ARRAY\n");
    for(index=0;index<arraySize;index++)
    {
        printf("%d\t",arr[index]);
    }
}
