/*
Description : 
       Given two numbers M and N. The task is to find the position of the 
       rightmost different bit in the binary representation of numbers.
       And return the index
*/

#include<bits/stdc++.h>
using namespace std;

// for finding the index
int get_right(int num1,int num2)
{
    int idx=1;
    if(num1 == num2){
        return -1;
    }
    while((num1 & 1) == (num2 & 1))
    {
        idx +=1;
        num1= num1 >>1;
        num2 = num2 >> 1;
    }
    return idx;
}
int main()
{
    int num1 , num2;
    cout<<"Enter the first number : "<<endl;
    cin>>num1;
    cout<<"Enter the second number  : "<<endl;
    cin>>num2;

    cout<<"Index of the rightmost different bit : "<<endl;
    cout<<get_right(num1,num2);
    return 0;
}

/*
Time complexity : O(max (log num1 , log num2))
Space complexity  : O(1)
*/

/*
Test Case :
Input :
    Enter the first number :
    11
    Enter the second number  :
    9

Output : 
    Index of the rightmost different bit :
    2
*/

