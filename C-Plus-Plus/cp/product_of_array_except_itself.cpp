/*
Given a vector, return a vector
where each element is equal to the product of all the elements
of except that particular element.
*/

#include <bits/stdc++.h>
using namespace std;

vector < int > get_Product_Except_Self(vector < int > &ar)
{
        /* take a vector Product_ExceptSelf where each element is 1 */
        vector < int > Product_ExceptSelf( ar.size(), 1);
        int x = 1;
        for(int i = 1; i < ar.size() ; i++)
        {
            Product_ExceptSelf[i] = Product_ExceptSelf[i-1] * ar[i-1];
        }
        for(int i = Product_ExceptSelf.size() - 1 ; i >= 1 ; i--)
        {
            /* here we keep multiplied x with ar[i]
            and then multiply Product_ExceptSelf[i-1]
            with current x value */
            x *= ar[i];
            Product_ExceptSelf[i-1] *= x;
        }
        return Product_ExceptSelf;
}

int main()
{
    cout << "Enter the size of the vector : \n";
    int N; 
    cin >> N;
    vector < int > ar(N , 0);
    cout << "Enter vector elements :\n";
    for (int i = 0; i < N; i++) 
    {
	cin >> ar[i];
    }
    vector < int > Product_Except_Self = get_Product_Except_Self(ar);
    cout << "The New vector is :\n";
    for(auto i : Product_Except_Self)
    {
        cout << i << ' ';
    }
    cout << endl;
}

/*
Standard Input and Output

1.
Enter the size of the vector :
6
Enter vector elements :
4 53 23 9 3 2
The New vector is :
65826 4968 11448 29256 87768 131652

2.
Enter the size of the vector :
5
Enter vector elements :
0 0 0 3 5
The New vector is :
0 0 0 0 0

Time Complexity : O( N )
Space Complexity : O( N )

*/
