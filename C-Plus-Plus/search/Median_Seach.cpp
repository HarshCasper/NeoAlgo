// C++ program to find the median of a given array of integers
#include <iostream>
using namespace std;
  
// Function for calculating median
double findMedian(int a[], int n)
{
    // First we sort the array
    sort(a, a + n);
  
    // check for even case
    if (n % 2 != 0)
        return (double)a[n / 2];
  
    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}
  
// Driver program
int main()
{
    int n;
    cout<<"enter the number of elements \n";
    cin>>n;
    int i,a[n];
    for(i=0;i<n;i++){
        cin>>a[i]
    }
    cout << "Median = " << findMedian(a, n) << endl;
    return 0;
}
/* 
Time Complexity to find median = O(n Log n)
As we need to sort the array first.

Sample Input 1
enter the number of elements 8
1 3 4 2 6 5 8 7

Output
Median = 4.5

Sample Input 2
enter the number of elements 5
4 4 4 4 4

Output
Median = 4
*/
