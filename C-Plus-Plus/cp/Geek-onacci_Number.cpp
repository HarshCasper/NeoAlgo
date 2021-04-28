/*
Description : 
        Geek created a random series and given a name geek-onacci series. Given four 
        integers x, y, z, N. x, y, z represents the first three numbers of geek-onacci series. 
        Find the Nth number of the series. The nth number of geek-onacci series is a sum of the 
        last three numbers (summation of N-1th, N-2th, and N-3th geek-onacci numbers).
*/

#include <iostream>
using namespace std;

//function to find geek number
int geek_num(int a, int b, int c, int n)
{
    int sum;
    for (int i = 4; i <= n; i++)
    {
        sum = a + b + c;
        a = b;
        b = c;
        c = sum;
    }
    return sum;
}

int main()
{
    int a, b, c, n;
    cout << "Enter first , second , third and Nth number : " << endl;
    cin >> a >> b >> c >> n;
    cout << "Nth number of the series : " << endl;
    //function call
    cout << geek_num(a, b, c, n) << endl;

    return 0;
}

/*
Time complexity : O(log n)
Space complexity : O(1)
*/

/*
Test Case :
 Input :
 Enter first , second , third and Nth number : 
 1 3 2 4

 Output :
 Nth number of the series :
 6
*/

