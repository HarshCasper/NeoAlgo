/*Taking input as array containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other
two number occur exactly once and are distinct. Find the other two numbers.

Time Complexity: O(n) 
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
 
/*  To set the values of *a and *b to non-repeating elements*/

void NonRepeatingInt(int arr[], int n, int *a, int *b)
{
    int Xor = arr[0];
   
    int set_bit;
    int i;
    *a = 0;
    *b = 0;
     
    for(i = 1; i < n; i++)
    Xor ^= arr[i];
     
    set_bit = Xor & ~(Xor-1);
     
    /* dividing the elements in two sets by comparing rightmost set bit of Xor with bit
    at same position in each element. */
    for(i = 0; i < n; i++)
    { 
        
      if(arr[i] & set_bit)
        *a = *a ^ arr[i];
        
      else
      {
        *b = *b ^ arr[i];
      }
    }
}
 
 
int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *a = new int[(sizeof(int))];
    int *b = new int[(sizeof(int))];
    NonRepeatingInt(arr, n, a, b);
    cout<<"The non-repeating elements in the array are "<<*a<<" and "<<*b;
}
 


/*
OUTPUT:
Enter the size of the array:6

Enter the array elements:1 2 3 1 2 5 

The non-repeating elements in the array are 3 and 5

*/
