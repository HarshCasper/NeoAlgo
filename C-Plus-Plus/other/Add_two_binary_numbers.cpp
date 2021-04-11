/*
Add two binary numbers

For given two binary numbers,
your task is to add the two binary numbers and return their sum.
*/

#include <bits/stdc++.h>

using namespace std;

//function to revers the binary numbers
//which will then be added 
int reverseNumber(int num)
{
    int lastBit, result = 0;
    while(num > 0)
    {
        lastBit = num % 10;
        result = result * 10 + lastBit;
        num = num / 10;
    }
    return result;
}

//function to add the binary numbers
//there are three cases-->
//0 + 0 = 0, 0 + 1 = 1, 1 + 1 = 0 (carry=1)
int binarySum(int num1, int num2)
{
    int result = 0;
    int previousCarry = 0;
    //only for positive numbers
    while(num1 > 0 && num2 > 0)
    {
        if(num1 % 2 == 0 && num2 % 2 == 0)
        {
            result = result * 10 + previousCarry;
            previousCarry = 0;//no previous carry will be generated
        }
        else if((num1 % 2 == 0 && num2 % 2 == 1) || (num1 % 2 == 1 && num2 % 2 == 0))
        {
            if(previousCarry == 1)
            {
                result = result * 10 + 0;
                previousCarry = 1;//further carry generated
            }
            else 
            {
                result = result * 10 + 1;
                previousCarry = 0;//no previous carry will be generated
            }
        }
        else
        {
            result = result * 10 + previousCarry;
            previousCarry = 1;//carry will be generated in both the cases
        }
        num1 = num1 / 10;
        num2 = num2 / 10;
    }
    while(num1 > 0)
    {
        if(previousCarry == 1)
        {
            if(num1 % 2 == 1)
            {
                result = result * 10 + 0;
                previousCarry = 1;
            }
            else
            {
                result = result * 10 + 1;
                previousCarry = 0;
            }
        }
        else
        {
            result = result * 10 + (num1 % 2);
        }
        num1 = num1 / 10;
    }
    while(num2 > 0)
    {
       if(previousCarry == 1)
        {
            if(num2 % 2 == 1)
            {
                result = result * 10 + 0;
                previousCarry = 1;
            }
            else
            {
                result = result * 10 + 1;
                previousCarry = 0;
            }
        }
        else
        {
            result = result * 10 + (num2 % 2);
        } 
        num2 = num2 / 10;
    }
    //for any previous carry prevaling
    if(previousCarry == 1)
    {
        result = result * 10 + 1;
    }
    //since we add reversed numbers the actual sum will be revese of that obtained
    result = reverseNumber(result);
    return result;
}

//driver code
int main()
{
    int num1, num2;
    cout << "Enter two binary numbers: ";
    cin >> num1 >> num2;
    cout << "The sum of binary numbers is :";
    cout << binarySum(num1, num2);
    cout << endl;
}

/*
EXAMPLE--
Input-->
Enter two binary numbers: 10101 11011
Output-->
The sum of binary numbers is : 110000

TIME COMPLEXITY --> O(N), where N is the size of binary number
SPACE COMPLEXITY --> )(1) 
*/
