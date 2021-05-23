/*
Introduction 
Given a roman numeral, convert it to an integer.

Argument/Return Type
Given a string which represents a roman numeral ,
return its corresponding decimal integer value
*/

#include <bits/stdc++.h> 
using namespace std;

//Function to convert the given roman numeral to its corresponding integer value
int romanToInt(string roman) 
{ 
    //Define a map     
    map<string,int>value;
    
    //Store the integer values of all valid roman symbols
    value["I"]  = 1;
    value["IV"] = 4;
    value["V"]  = 5;
    value["IX"] = 9;
    value["X"]  = 10;
    value["XL"] = 40;
    value["L"]  = 50;
    value["XC"] = 90;
    value["C"]  = 100;
    value["CD"] = 400;
    value["D"]  = 500;
    value["CM"] = 900;
    value["M"]  = 1000;
    
    //Now traverse over all characters of string
    int index=0;
    //Initiate the decimal value with 0
    int decimalValue=0;

    while(index<roman.length())
    {
        //If there is one more char after the current position
        if(index<roman.length()-1)
        {
            /* check if the substring corresponding to two chars 
            is a valid roman symbol */
            string sub=roman.substr(index,2);
            if(value[sub])
            {
                /* If substring is a valid roman symbol 
                 add it to decimal value and move the index forward two times */
                decimalValue=decimalValue+value[sub];
                index=index+2;
            }
            else
            {
                // else add the decimal value the char at this position 
                sub=roman.substr(index,1);
                decimalValue=decimalValue+value[sub];
                index=index+1;
            }
        }
        else
        {
            /* If current position is end of the string
             add the decimala value of this char and continue */
            string sub=roman.substr(index,1);
            decimalValue=decimalValue+value[sub];
            index=index+1;
        }
        
    }
    
    return decimalValue;
}


// Driver code
int main()
{
    //Take input of a roman numeral string
    string roman;
    cout<<"Enter a roman numeral : ";
    cin>>roman;

    //Call the function and print the result
    cout<<"Hence the integer value of given roman numeral is ";
    cout<<romanToInt(roman);

    return 0; 
}
    
/*
Input:
1 <= roman.length <= 15
roman contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].

Sample Test Case 1  

Input Format : 
Example :
Enter a roman numeral : MCMXCIV

Output Format :
Example : ( Output to the above input example ) 
Hence the integer value of given roman numeral is 1994

Time/Space Complexity
Time Complexity : O(n) 
Space Complexity : O(1) 
*/
