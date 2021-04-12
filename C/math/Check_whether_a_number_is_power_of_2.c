/*
Given a number , check whether the number is power of 2 or not.
We can check this by doing some bitwise operation.
Bitwise operations are best because they perform the operation in least possible time.
*/

#include <stdio.h>
#include <math.h>

// this number_is_power_of_2 will tell us whether a number is power of 2
int number_is_power_of_2(int number)
{
    /* if bitwise and of number and number - 1 is zero
    then we can say that number is power of 2
    otherwise it is not.
    */
    if((number & (number - 1)) == 0)
    {
        return 1;
    }
    return 0;
}
int main()
{
    printf("Enter the number \n");
    int number;
    scanf("%d", &number);
    int solve = number_is_power_of_2(number);
    if(solve)
    {
        printf("The Number is power of 2\n");
    }
    else
    {
        printf("No. the number is not power of 2\n");
    }
}

/*
Standard Input and Output
Enter the number
64

The Number is power of 2

Enter the number
34

No. the number is not power of 2

Time Complexity : O(1)
Space Complexity : O(1)

*/
