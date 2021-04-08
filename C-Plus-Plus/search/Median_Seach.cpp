
#include <iostream>
using namespace std;
  
double findMedian(int a[], int n)
{
    sort(a, a + n);
  
    if (n % 2 != 0)
        return (double)a[n / 2];
  
    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}
  
int main()
{
    int a[] = { 1, 3, 4, 2, 7, 5, 8, 6 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Median = " << findMedian(a, n) << endl;
    return 0;
}