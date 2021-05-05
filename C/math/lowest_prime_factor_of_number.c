/*
Given a number. find it's lowest prime factor.
we have to get the lowest factor of that number and
that lowest factor has to be a prime number.
*/

#include <stdio.h>

// From this chech_prime function we will whether a number is prime or not
int check_prime(int number)
{
    /* check whether number is prime or not */
    int i = 0;
    for(i = 3; i * i <= number; i += 2)
    {
        if(number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// From this function we will get lowest prime factor of a number
int get_lowest_prime_factor(int number)
{
    int get_factor = 0, i = 0;
    /*
    loop runs till sqrt( number )
    for not getting precision errors
    use i * i <= number
    */
    for(i = 3 ; i * i <= number; i += 2)
    {
        if(number % i == 0)
        {
            get_factor = 1;
            int prime = check_prime(i);
            if(prime)
            {
                /* that means the number is lowest prime factor */
                return i;
            }
        }
    }
    if(!get_factor)
    {
        /*
        that means the number itself it's lowest prime factor.
        Ex : 17
        so we can return the number.
        */
        return number;
    }
}

int main()
{
    printf("Enter the number : \n");
    int number;
    scanf("%d", &number);
    /*
    if the number is even, we can say that the lowest prime factor
    is 2 for any even number.
    because 2 is prime and it's a factor of
    every even number.
    */
    if(number % 2 == 0)
    {
        printf("Lowest prime factor for this number is : 2\n");
    }
    else if(number % 2)
    {
        int lowest_prime_factor = get_lowest_prime_factor(number);
        printf("Lowest prime factor for this number is : \n");
        printf("%d\n" , lowest_prime_factor);
    }
}

/*
Standard Input and Output
1. Even number
Enter the number :
435346
Lowest prime factor for this number is : 2
2. Odd Number
Enter the number :
35345
Lowest prime factor for this number is :
5
3. Odd Prime Number :
Enter the number :
23
Lowest prime factor for this number is :
23
Time Complexity : O(sqrt (N) )
Space Complexity : O( 1 )

*/
