//This is a problem of taking a number as a input
//and then display the number is prime or not.
// e.g :
// Input : 
// Enter a number : 13
// Output : 
// 13 is a Prime Number.

using System;

namespace primenumber
{
    class prime
    {
        //This function isPrime checks whether the number is prime or not.
        //This function takes the number as a parameter.
        //Then it checks if the number is divisible by any other number other
        //than 1 or itself it returns a false value else a true value.
        static bool isPrime(int number)
        {
            //handles the case if the entered number is equal to 1 or less than that
            if (number <= 1)
            {
                return false;
            }
            else
            {
                //The iteration starts from the smallest prime number
                for (int iteration = 2; iteration <= Math.Sqrt( number ); iteration++)
                {
                    //Checks if the number is divisible by any other number other than 1 or itself
                    if (number % iteration == 0)
                    {
                        return false;
                    }
                }
                return true;
            }
        }
        //The value from the isPrime comes to this main function and display accordingly
        static void Main(string[] args)
        {
           {
                int number;
                bool prime;
                Console.WriteLine( "Input :" );
                Console.Write( "Enter a number :" + " " );
                //Reads the input from the user
                number = int.Parse(Console.ReadLine());
                //The value from the isPrime either true or false is stored in the variable prime
                prime = isPrime(number);
                Console.WriteLine( "Output :" );
                //True condition
                if (prime)
                {
                    Console.WriteLine( number + " is prime number" );
                }
                //False condition
                else
                {
                    Console.WriteLine( number + " is not prime number" );
                }
            }
        }
    }
}
//Approach of Time Complexity O(sqrt(n)) and space complexity O(1)

//End of the program