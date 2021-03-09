/* 
Divisors of a natural number.

For a given natural number num,
your task is to find out all the possible divisors of the given natural number and print them.
It is given that the output should have all the distinct divisors.
And the output is expected to be always sorted in ascending order.

*/

#include <bits/stdc++.h>

using namespace std;

//function to print all the possible divisors of num.
void divisorsOfNumber(int num)
{
    int pass;

    for(pass = 1; pass*pass < num; pass++)
    {
        if(num % pass == 0)
        {
            cout << pass << " ";
        }
    }

    for(pass = sqrt(num); pass >= 1; pass--)
    {
        if(num % pass == 0)
        {
            cout << (num/pass) << " ";
        }
    }
    cout << endl;
}

//main function
int main()
{
    int testCases;
    cout << "Enter the number of testcases: ";
    cin >> testCases;
    
    while(testCases--)
    {
        int num;
        cout << "Enter a natural number: ";
        cin >> num;

        cout << "All the possible divisors of " << num << " are: ";
        //calling the function divisorsOfNumber() by passing the natural number, which will print the divisors 
        divisorsOfNumber(num); 
    }

    return 0;
}

/*

FOR EXAMPLE:--

Example 1:
Input:-
Enter the number of testcases: 1
Enter a natural number: 60
Output:-
All the possible divisors of 60 are: 1 2 3 4 5 6 10 12 15 20 30 60

Example 2:
Input:-
Enter the number of testcases: 1
Enter a natural number: 101
Output:-
All the possible divisors of 101 are: 1 101

Example 3:
Input:-
Enter the number of testcases: 2
Enter a natural number:40
Enter a natural number:70
Output:-
All the possible divisors of 40 are: 1 2 4 5 8 10 20 40
All the possible divisors of 70 are: 1 2 5 7 10 14 35 70

SPACE COMPLEXITY = O(sqrt(N))
TIME COMPLEXITY = O(1)

*/
