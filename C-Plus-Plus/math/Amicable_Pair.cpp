/*
Amicable numbers are two different numbers so related that the sum of the proper divisors of each is equal to 
the other number. (A proper divisor of a number is a positive factor of that number other than the number itself.
Given two Numbers A and B, find whether they are Amicable Numbers or not. Print 1 if they are Amicable else 0.
                    
*/

#include <bits/stdc++.h>
using namespace std;

class Sol
{
public:
    //  to get the sum of all proper divisors of a number.
    long long div_sum(int n)
    {
        long long result = 0;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                if (i == (n / i))
                    result += i;
                else
                    result += (i + n / i);
            }
        }
        return (result + 1);
    }

    int isAmicable(int A, int B)
    {

        // If and only if sum of proper divisors of A is equal to B

        if (A != B && div_sum(A) == B && div_sum(B) == A)
            return 1;
        else
            return 0;
    }
};

int main()
{
    int a, b;
    cout << "Enter the a and b" << endl;
    cin >> a >> b;
    Sol obj;
    cout << "Amicable Pair : " << endl;
    cout << obj.isAmicable(a, b) << endl;

    return 0;
}

/*

Time complexity : O(sqrt(A,B))
Space complexity : O(1)

*/

/*

Test Case : 
     Test case 1 :
     Enter the a and b
      220  284

    Test case 2 : 
    Amicable Pair : 
    1
*/

