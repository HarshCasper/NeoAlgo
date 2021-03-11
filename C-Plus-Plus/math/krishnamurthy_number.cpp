/*
    If the factorial of individual digits of a number when summed up yields the number itself then the number is called Krishnamurthy 
    Number. 
    Example : 
    Consider the number 145
    Summing of factorials of the individual digits we get = 1! + 4! + 5! = 1 + 24 + 120 =145.
    Hence 145 is not a Krishnamurthy number.
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

int Krishnamurthy_No ( int num )
{
    int digit, sum = 0 ,copy = num;

    //Running a loop till we have extracted all the digits from the copy of the given number
    
    while ( copy > 0 ) 
    {
        digit = copy % 10;
        sum = sum + Factorial ( digit );
        copy = copy / 10;
    }
    return sum;
}

int main () 
{
    int number, digit, sum = 0;
    std::cout << "Enter a natural number " << std::endl;
    std::cin >> number;
    int answer = Krishnamurthy_No ( number ); 

    //Comparing if calculated sum adds up to the number

    if ( answer == number)
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
