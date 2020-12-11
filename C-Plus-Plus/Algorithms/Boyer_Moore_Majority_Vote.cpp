#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// Function to find majority element
int majorityElement(vector<int> A)
{
    // creation of an empty map
    unordered_map<int, int> map;
 
    // input size
    int n = A.size();
 
for (int i = 0; i < n; i++)
    {
        if (++map[A[i]] > n/2)
            return A[i];
    }
    // return -1 if no majority element is present
    return -1;
}
 

/* Test Case: 
int main()
{
    vector<int> vec = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 };
 
    int res = majorityElement(vec);
    if (res != -1)
        cout << "Majority element is " << res;
    else
        cout << "Majority element doesn't exists";
 
    return 0;
} */
// The majority element is 2

// Time Complexity is O(n)
// Space Complexity is O(n)
