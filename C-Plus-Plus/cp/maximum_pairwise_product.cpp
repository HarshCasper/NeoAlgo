/*
Program in C++ to find the maximum product possible by multiplying any two elements of the input array that may contain negative numbers using the most optimised algorithm
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    //Declaring variable that stores number of elements in the Aay
    int n;

    //Taking the number of elements of Aay as input
    cin>>n;

    if (n < 2)
    {
        cout << "There are no pairs so no pairwise product possible\n";
        return 0;
    }

    //Declaring 1-D Aay
    int A[1000];

    //Declaring iteration variables
    int i,j;

    //Taking elements of Aay as input
    for(i=0;i<n;i++)
    {
        cin>>A[i];
        

    }
    if (n == 2)
    {
        cout << "Max product pair is {" << A[0] << ", "<< A[1]<< "}"<<" and product is "<<A[0]*A[1];
        return 0;
        
    }
    // Iniitialize maximum and second maximum positive numbers to default min value
    int p_max1 = INT_MIN, p_max2 = INT_MIN;
 
    // Iniitialize minimum and second minimum negative numbers to default min value
    int n_max1 = INT_MIN, n_max2 = INT_MIN;
 
    // Traverse the Array
    for (int i = 0; i < n; i++)
    {
        // Update maximum and second maximum if needed
        if (A[i] > p_max1)
        {
            p_max2 = p_max1;
            p_max1 = A[i];
        }
        else if (A[i] > p_max2)
            p_max2 = A[i];
 
        // Update minimum and second minimum if needed
        if (A[i] < 0 && abs(A[i]) > abs(n_max1))
        {
            n_max2 = n_max1;
            n_max1 = A[i];
        }
        else if(A[i] < 0 && abs(A[i]) > abs(n_max2))
            n_max2 = A[i];
    }
 
    if (n_max1*n_max2 > p_max1*p_max2)
        cout << "Max product pair is {" << n_max1 << ", "<< n_max2 << "}"<<" and product is "<<n_max1*n_max2;
    else
        cout << "Max product pair is {" << p_max1 << ", "<< p_max2 << "}"<<" and product is "<<p_max1*p_max2;

    return 0;
}

/*
Test Case 1:
4
2 -2 3 4
Max product pair is {4, 3} and product is 12

Test Case 2:
4
1 0 -8 -8
Max product pair is {-8, -8} and product is 64
*/

/*
Time complexity: O(n) 
Space Complexity: O(1)
*/
