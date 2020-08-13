
/* To find the  k-th prime factor of a given number

//Example : n=12 ,  k=3
  Output  : 3
*/



#include<iostream>

int kPrimeFactor(int n, int k)
{
    while (n%2 == 0)
    {
        k--;
        n = n/2;
        if (k == 0)
        return 2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
      while (n%i == 0)
      {
        if (k == 1)
        return i;

        k--;
        n = n/i;
      }
    }
    if (n > 2 && k == 1)
        return n;

    return -1;
}


int main()
{
    cout << kPrimeFactor(n, k) << endl;
    return 0;
}


