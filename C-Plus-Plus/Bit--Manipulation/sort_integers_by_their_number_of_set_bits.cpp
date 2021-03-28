// C++ program to sort integers by the number of set bits present in their binary equivalence
/*
Given an integer array of numbers, We have to sort these integers in the ascending order by the 
number of set bits(1's) present in their binary equivalence. In case two integers have equal 
number of set bits we have to sort them in ascending order of magnitude.
*/

#include <bits/stdc++.h>
using namespace std;

/* We modify the compare method to sort the numbers w.r.t their number of set bits */
static bool compare(const int &a, const int &b)
{
    /* count stores the number of set bits
        and temp variables hold the values of a and b temporarily */
    int count_a_1 = 0, count_b_1 = 0, temp_a = a, temp_b = b;
    // Count number of set bits in a
    while (temp_a)
    {
        temp_a = temp_a & (temp_a - 1);
        count_a_1++;
    }
    // Count number of set bits in b
    while (temp_b)
    {
        temp_b = temp_b & (temp_b - 1);
        count_b_1++;
    }

    // If their counts are equal, check their magnitude.
    if (count_a_1 == count_b_1)
        return a < b;
    return count_a_1 < count_b_1;
}

int main()
{
    int n, ele;
    cout << "How many numbers do you want to sort w.r.t the number of set bits? ";
    cin >> n;
    if (n == 0)
    {
        cout << "There are no numbers to sort!!";
        return 0;
    }
    vector<int> arr;
    cout << "Enter the numbers:";
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }
    // Call the sort method, with our modified compare method
    sort(arr.begin(), arr.end(), compare);
    cout << "\nThe sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*

Time Complexity: O(logn)
Space Complexity: O(n)

SAMPLE INPUT AND OUTPUT

How many numbers do you want to sort w.r.t the number of set bits? 5
Enter the numbers: 13 2 9 34 22 

The sorted array is: 2 9 34 13 22  

*/
