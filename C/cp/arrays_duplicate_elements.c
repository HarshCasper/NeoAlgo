/*
Given an array of N elements, each element's occurrence in the array can be more than once.
Find all elements whose occurrence is more than 1.
Formally find all duplicate elements of the array.
*/

#include <stdio.h>
#include <string.h>

//From this dupicate_elements function we will print duplicate elements of the array
void dupicate_elements(int ar[] ,int N)
{
    /* we will insert the array elements into visited array. if current element already
    in the visited array
    then definitely that element's occurrence is more than 1.
    Hence it is duplicate and will print it*/
    printf("Duplicate elements are : \n");
    int i = 0;
    int visited_array[N + 1];
    memset(visited_array, 0, sizeof(visited_array));
    for(i = 0; i < N; i++)
    {
        if(visited_array[ar[i]] != 0)
        {
            // this element is duplicate
            printf("%d ", ar[i]);
        }
        if(visited_array[ar[i]] == 0)
        {
            visited_array[ar[i]]++;
        }
    }
    return;
}

int main()
{
    printf("Enter the size of the array : ");
    int N;
    scanf("%d", &N);
    int ar[N + 1];
    printf("Enter array elements :\n");
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &ar[i]);
    }
    dupicate_elements(ar , N);
}

/*
Standard Input and Output

Enter the size of the array : 7
Enter array elements :
1 2 4 5 5 7 8
Duplicate elements are :
5 8

Time Complexity : O(N)
Space Complexity : O(N)

*/
