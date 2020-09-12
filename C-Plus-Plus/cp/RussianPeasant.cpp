// Russian Reasant Algorithm
// Multiply two numbers using bitwise operations, without "*" operator to multiply.

#include <iostream>
using namespace std;
int main()
{
    int a, b, result = 0;

    cout << "Enter two numbers to multiply: \n";
    cin >> a >> b;
    while (b > 0)
    {
        if (b % 2 != 0)
        {
            result += a;
        }
        a = a << 1;
        b = b >> 1;
    }
    cout << "Product: " << result;
    return 0;
}

/*Input:
Enter two numbers to multiply: 
4 20

Output:
Product: 80
*/