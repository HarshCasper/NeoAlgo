/*
In this code, we will see how to count number of bits in a number. 
We are given a number and we have to count the number of bits in its binary representation.
For count number of bits in a number, we follow the following algorithm:
First, we convert the number into its binary representation.
Count number of bits in binary representation.
Print the value of count.
*/

#include<bits/stdc++.h>
using namespace std;

//function for counting number of bits
int count_bits(int n)
{
  //initialize count with 0
   int count=0;
   
   //  counting number of bits in binary representation of number
   while(n!=0)
   {
     count++;
     n=n/2;
   }
   return count;
}

//main function
int main()
{
  int n;

  //Taking number as input
  cout<<"Enter the number: ";
  cin>>n;

  //Printing count of bits of given number
  cout<<"No. of bits: "<<count_bits(n)<<endl;
  return 0;
}

/*
Input:
Enter the number: 10

Output:
No. of bits: 4

Input:
Enter the number: 3

Output:
No. of bits: 2

Time Complexity: O(logn)
Space Complexity: O(1)
where n is the number of elements.
*/
