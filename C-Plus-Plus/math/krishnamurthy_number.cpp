/*
    If the factorial of the individual digits of a number when summed up yields the number itself then the number is called Krishnamurthy 
    Number. 
    Example 1: 
    We consider the number 145
    Summing of factorials of the individual digits we get = 1! + 4! + 5! = 1 + 24 + 120 =145.
    Conclusion : 145 is not a Krishnamurthy number.
    Example 2:
    We consider the number 26
    Summing of factorials of the individual digits we get = 2! + 6! = 2 + 720 = 722.
    Conclusion: 26 is not a Krishnamurthy number.

*/

//CPP Program to find whether a number is a Krishnamurthy number

#include<iostream>

//Function to calculate the factorial of the individual digits

int Factorial ( int n )
{
    if ( n == 1 || n == 0 )
    {
        return 1;
    }
    return n * Factorial( n - 1 );
}

int main () 
{
    int number, digit, sum = 0;
    std::cout << "Enter a natural number " << std::endl;
    std::cin >> number;
    int copy = number;

    //Running a loop till we have extracted all the digits from the copy of the given number
    
    while ( copy > 0 ) 
    {
        //Extracting the last digit from existing copy of number

        digit = copy % 10;
        
        //Calculating the sum starting from zero and adding up each time we find the factorial.
        
        sum = sum + Factorial ( digit );

        //Decreasing the exisiting copy of number

        copy = copy / 10;
    }

    //Comparing if calculated sum adds up to the number

    if ( sum == number)
    {
        std:: cout << number <<" is a krishnamurthy number. ";
    }
    else
    {
        std:: cout << number <<" is not a krishnamurthy number. ";
    }
}

/*
    Test Case 1 :-
        INPUT : 37 
        OUTPUT : 37 is not a krishnamurthy number.
    Test Case 2 :-
        INPUT : 145
        OUTPUT: 145 is a krishnamurthy number.
        
*/