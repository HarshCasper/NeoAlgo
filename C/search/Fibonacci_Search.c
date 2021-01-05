// C program implementation for Fibonacci Search 

// Worst case time complexity: Θ(logn)
// Average case time complexity: Θ(log n)
// Best case time complexity: Θ(1)
// Space complexity: Θ(1)


#include <stdio.h>
#include <string.h>
 
int Fibonacci_Search(int a[], int n, long x)
{ 
    int index = 0, position, k;
    static int n_1= -1, n_2 = -1;
    
    // Precomputed Fibonacci numbers from F_0 up to F_46.
    static int fib[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 98,
    1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811,
    514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817,
    39088169, 63245986, 102334155, 165580141};
    if (n_2 != n)
    { 
        k = 0;
        while (fib[k] < n)
            k++;
        n_1 = k;
        n_2 = n;
    }
    else
        k = n_1;
    while (k > 0)
    {
        position = index + fib[--k];
        if ((position >= n) || (x < a[position]));
        else if (x > a[position])
        {
            index = position + 1;
            k--;
        }
        else {
            return position;
        }
    }
    return -1;
}
void main()
{
    int no_element=0;
    printf("Enter the no of element in the array: "); 
        scanf("%d", &no_element);
    int arr[no_element];

    // taking input 
    printf("Enter the array: \n"); 
    for(int z=0; z < no_element; z++){
        scanf("%d", &arr[z]);
    }
    int num;
    printf("Enter an element to search: ");
    scanf("%d", &num);

    (Fibonacci_Search(arr, 10, num) == -1) ? printf("Element NOT found!! ") :
    printf("Element is at index : %d", Fibonacci_Search(arr, 10, num));
 
}
/*
____Example-1____
Enter the no of element in the array: 5                                                                                            
Enter the array:                                                                                                                   
30                                                                                                                                 
20                                                                                                                                 
28                                                                                                                                 
55                                                                                                                                 
62                                                                                                                                 
Enter an element to search: 28                                                                                                     
Element is at index : 2

____Example-2____
Enter the no of element in the array: 6                                                                                            
Enter the array:                                                                                                                   
48                                                                                                                                 
56                                                                                                                                 
24                                                                                                                                 
16                                                                                                                                 
36                                                                                                                                 
66                                                                                                                                 
Enter an element to search: 22                                                                                                     
Element NOT found!!
*/