/*Given two arrays, the task is to calculate the product of max element of first array and min element of second array*/

#include<bits/stdc++.h>
using namespace std;

//main function
int main()
{
    //initialising and declaring two array 
    int a[] = { 7, 3, 5, 8, 4};
    int b[] = { 9, 8, 6, 4, 2};
    
    //calculating the number of elements in the two array
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    
    //main logic 
    int num1=*max_element(a, a+ n);
    int num2=*min_element(b, b+ m);
    int r=num1*num2;
    cout<<r;
    return 0;
}

/* Input1 : a[] = { 7, 3, 5, 8, 4},  
           b[] { 9, 8, 6, 4, 2}

  Output : 16
  max element in first array 
  is 8 and min element in second array 
  is 2. The product of these two is 16.
  
  Input1 : a[] = { 7, -3, 5, -8, 4},  
           b[] { 9, 8, 6, -4, 2}

  Output : -28
  max element in first array 
  is 7 and min element in second array 
  is -4. The product of these two is -28.
*/
  