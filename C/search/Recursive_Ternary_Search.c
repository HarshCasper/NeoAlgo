/* 
 Ternary search is a searching technique that is used to determine the position of a specific value in an array.
  In ternary search,array is divided into three parts and then  determine in which part the element exists.
  for ternary search, array must be sorted.   
*/

#include<stdio.h>
#define MAX 100
// A recursive ternary search function. It returns 
// location of x in the given array if the searched element is present,
// otherwise -1 

//n is the size of array and  x is the element we are searching for.
//l is leftmost element and r is the rightmost element.
int ternarySearch(int l, int r, int x, int a[])
{

    if(l<=r)
    {   
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        // If the element is present at the mid1 itself
        if(a[mid1] == x)
            return mid1;
         // If the element is present at the mid2 itself 
        if(a[mid2] == x)
            return mid2;
            
        if(x<a[mid1])
         // The element lies in between l and mid1
            return ternarySearch(l,mid1-1,x,a);
        else if(x>a[mid2])
         // The element lies in between mid2 and r
            return ternarySearch(mid2+1,r,x,a);
        else
        
            // The element lies in between mid1 and mid2
            return ternarySearch(mid1+1,mid2-1,x,a);

    }
    //if element not found
    return -1;
}
int main(){
	int a[MAX];
    int size, i;
    printf("enter the size of array you want:");
    scanf("%d", &size);
    
    for (i = 0; i < size; i++)
    {
        /* take the elements from user in the array */
        printf("\n");
        printf("enter the element of the array:");
        scanf("%d", &a[i]);
    }
    printf("\n");
    int x;
    printf("enter the element want to search in the array:");
    scanf("%d", &x);
    
    int p= ternarySearch(0,size-1,x,a);
    
    if(p==-1)
    {
    	printf("\nsearched element is not present in the array ");
    	
	}
    else{
    	printf("\nelement present at index %d ",p);
	}

}
/* sample output:
enter the size of array you want:6

enter the element of the array:12

enter the element of the array:45

enter the element of the array:65

enter the element of the array:89

enter the element of the array:98

enter the element of the array:100

enter the element want to search in the array:100

element present at index 5
*/
