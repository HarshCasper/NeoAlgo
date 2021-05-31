/*
Given a sorted and rotated array.
The array is rotated between 1 and n times[ n = array size]
find the minimum element of the input array.
array may contain duplicate elements.
*/

#include <stdio.h>

// this function  will give us the minimum element
int get_minimum_element(int ar[], int N)
{
    int first = 0, last = N - 1;
    int minelement = -1;
    while(first < last)
    {
        //if ar[first] > ar[last] then we will increment first and last remains same
        if(ar[first] > ar[last])
        {
            first++;
            minelement = ar[last];

        }
        //if ar[first] <=  ar[last] then we will decrement last and first remains same
        if(ar[first] <= ar[last])
        {
            last--;
            minelement = ar[first];

        }
    }
    return minelement;
}
int main()
{
    printf("Enter the size of the array : \n");
    int N;
    scanf("%d", &N);
    int ar[N + 1];
    printf("Enter array elements :\n");
    for (int i = 0; i < N; i++)
    {
	    scanf("%d", &ar[i]);
    }
    int minimum_element = get_minimum_element(ar, N);
    printf("Minimum Element of the array is: \n");
    printf("%d \n", minimum_element);

}

/*

Standard Input and Output

Enter the size of the array :
12
Enter array elements :
465 7878 3535 68 3435 89897 466 878 44 7879 3 67868

Minimum Element of the array is:
3

Time Complexity : O( N )
Space Complexity : O(1)

*/
