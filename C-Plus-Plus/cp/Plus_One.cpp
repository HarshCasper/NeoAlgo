/*
Introduction 
Given a non-empty vector of decimal digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, 
and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Argument/Return Type
Given a vector as input
return answer as vector and print the result
*/

#include <bits/stdc++.h> 
using namespace std;

//Function to print the elements of the given vector
void printVector(vector<int>& digits)
{
    //Print digits without space between them
    for(int i: digits)
      cout<<i;
}

//Function which adds 1 to the number given by 
vector<int> plusOne(vector<int>& digits) 
{
    /* If the last didgit is not 9 
    Add one to it and return the vector */
    if(digits[digits.size()-1]!=9)
    {
        digits[digits.size()-1]+=1;
        return digits;
    }

    /*Else traverse the vector from the end
     till we reach a non '9' digit */
    int index=digits.size()-1;
    while(digits[index]==9)
    {
        //Make each digit as '0'
        digits[index--]=0;

        /* If there are no more elements in vector
        insert a '1' at the beginning of the vector and return it */
        if(index<0)
        {
            digits.insert(digits.begin(),1);
            return digits;
        }
    }

    /*After crossing all digits which are '9'
      make the element at current index as digit '1' */
    digits[index]=digits[index]+1;
    return digits;  
}


// Driver code
int main()
{
    //Take the input of total no.of digits
    int n;
    cout<<"Enter the total no.of digits : ";
    cin>>n;

    //Take input of the digits as vector
    vector<int>digits;
    cout<<"Enter each digit of the number with space between them in order : ";
    for(int i=0;i<n;i++)
    {
        int digit;
        cin>>digit;
        digits.push_back(digit);
    }

    //Call the function and print the result
    vector<int>result;
    result=plusOne(digits);
    cout<<"Hence the result is ";
    printVector(result);

    return 0; 
}
    
/*
Input:
1 <= digits.length <= 100
0 <= digits[i] <= 9

Sample Test Case 1  

Input Format : 
Example :
Enter the total no.of digits : 5
Enter each digit of the number with space between them in order : 1 5 9 9 9

Output Format :
Example : ( Output to the above input example ) 
Hence the result is 16000

Time/Space Complexity
  Time Complexity : O(n) 
  Space Complexity : O(1) 
*/
