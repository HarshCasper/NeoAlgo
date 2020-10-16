#include <stdio.h> 
int ternarySearch(int l, int r, int key, int ar[]) 
{ 
    if (r >= l) { 
        int mid1 = l + (r - l) / 3; 
        int mid2 = r - (r - l) / 3; 
        if (ar[mid1] == key) { 
            return mid1; 
        } 
        if (ar[mid2] == key) { 
            return mid2; 
        }
        if (key < ar[mid1]) { 
            return ternarySearch(l, mid1 - 1, key, ar); 
        } 
        else if (key > ar[mid2]) { 
            return ternarySearch(mid2 + 1, r, key, ar); 
        } 
        else { 
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar); 
        } 
    } 
    return -1; 
} 

int main() 
{ 
    int num;
    printf("Enter number of elements: ");
    scanf("%d",&num);
    printf("\nEnter %d sorted elements: ",num);
    int array[num];
    for(int i = 0;i<num;i++){
        scanf("%d",&array[i]);
    }
    int key, index;
    printf("\nEnter Key to be searched: ");
    scanf("%d",&key);
    index = ternarySearch(0, num, key, array); 
    printf("Index of %d is %d\n", key, index); 
} 
/*
Time Complexity: O(log3 n)
Space Complexity: O(1)

Enter number of elements: 8

Enter 8 elements: 12 25 48 52 67 78 89 91

Enter Key to be searched: 52
Index of 52 is 3
*/