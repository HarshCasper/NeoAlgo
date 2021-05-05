// C program to implement Three Way Merge Sort
#include <stdio.h>

// Time Complexity: O(n*logn)
// Space Complexity: O(n)


// Merge the three sections in ascending order
void merge(int arr[], int beg, int midA, int midB, int end, int temp[])  
{  
    int i, j, k, l;
    i = beg;
    j = midA; 
    k = midB; 
    l = beg;  
  
    // Find the smallest element among the three sections 
    while ((i < midA) && (j < midB) && (k < end))  
    {  
        if(arr[i] < arr[j]) 
        { 
            if(arr[i] < arr[k]) 
            { 
                temp[l++] = arr[i++]; 
            } 
            else
            { 
                temp[l++] = arr[k++]; 
            } 
        } 
        else
        { 
            if(arr[j] < arr[k]) 
            { 
                temp[l++] = arr[j++]; 
            } 
            else
            { 
                temp[l++] = arr[k++]; 
            } 
        } 
    }  
  
    /*
    Now any two arrays would have remaining values that are yet to be merged,
    We have to identify those two arrays and merge the elements.  
    */
 
    while ((i < midA) && (j < midB))  
    {  
        if(arr[i] < arr[j]) 
        { 
            temp[l++] = arr[i++]; 
        } 
        else
        { 
            temp[l++] = arr[j++]; 
        } 
    }  
  
   
    while ((j < midB) && (k < end))  
    {  
        if(arr[j] < arr[k]) 
        { 
            temp[l++] = arr[j++]; 
        } 
        else
        { 
            temp[l++] = arr[k++]; 
        }  
    }  
  
    while ((i < midA) && (k < end))  
    {  
        if(arr[i] < arr[k]) 
        { 
            temp[l++] = arr[i++]; 
        } 
        else
        { 
            temp[l++] = arr[k++]; 
        }  
    }  
  
  /*
    Now a single array would have remaining values that are yet to be merged,
    We have identify that array and copy its remaining elements.  
  */
    
    while (i < midA)  
        temp[l++] = arr[i++];  
  
    while (j < midB)  
        temp[l++] = arr[j++];  
        
    while (k < end)  
        temp[l++] = arr[k++];  
}  



void three_way_merge_sort(int arr[], int beg, int end, int temp[])  
{  
    //If the array contains only a single element, then return  
    if (end - beg < 2)  
        return;  
  
    // Split the array into three parts
    int midA = beg + ((end - beg) / 3);  
    int midB = beg + 2 * ((end - beg) / 3) + 1;  
    
    three_way_merge_sort(temp, beg, midA, arr);  
    three_way_merge_sort(temp, midA, midB, arr);  
    three_way_merge_sort(temp, midB, end, arr);  
  
    // Merge the sorted arrays  
    merge(temp, beg, midA, midB, end, arr);  
}

int main()
{
    int n;
    printf("\nHow many numbers do you want to sort? ");
    scanf("%d",&n);
    int arr[n];

    if (n <= 0)
    {
        printf("There are no numbers to sort!!!");
        return 0;
    }
    // Input the numbers to sort
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    
    // creating a temporary array 
    int temp[n];  
  
    // Copy the elements of the temporary elements into the new array  
    for (int i = 0; i < n; i++)  
        temp[i] = arr[i];  
  
    //Call the sort function 
    three_way_merge_sort(temp, 0, n, arr);  

    printf("The numbers in sorted order is: ");
    // Print the sorted array
    for (int i = 0; i < n; i++)
        printf(" %d ", temp[i]);
    printf("\n");

    return 0;
}

/*
SAMPLE INPUT AND OUTPUT

SAMPLE 1
How many numbers do you want to sort? 5
Enter the numbers: 1 3 5 2 4
The numbers in sorted order is:  1  2  3  4  5

SAMPLE 2
How many numbers do you want to sort? 0
There are no numbers to sort!!!
*/
