/**
 * Given an array of type positive integers, having ith element as feet and ith + 1 element as inches.
 * Eg: considering arr = [1,2] where 1 equals to feet and 2 equals to inches.
 * Find the maximum height, where height is calculated sum of feet and inches after converting feet into inches.
*/

#include <bits/stdc++.h>
using namespace std;

int max_height_in_array(std::vector<int>, int);

int max_height_in_array(std::vector<int> arr, int size)
{
    int max = 0;
    // check for even size.
    if ((size & 1) == 0)
    {
        for (int i = 0; i < size; i = i + 2)
        {
            if (((arr[i] * 12) + arr[i + 1]) > max)
            {
                max = ((arr[i] * 12) + arr[i + 1]);
            }
        }
        // check for odd size.
    }
    else
    {
        for (int i = 0; i < (size - 1); i = i + 2)
        {
            if (((arr[i] * 12) + arr[i + 1]) > max)
            {
                max = ((arr[i] * 12) + arr[i + 1]);
            }
        }

        // special check for last remaining element at odd th index.
        if ((arr[size - 1] * 12) > max)
        {
            max = (arr[size - 1] * 12);
        }
    }
    return (max);
}

int main()
{
    int test_cases, size, ele;
    std::cout << "Enter test cases : " << std::endl;
    std::cin >> test_cases;

    while (test_cases--)
    {
        std::vector<int> arr;
        std::cout << "Enter the size of an array : " << std::endl;
        std::cin >> size;

        std::cout << "Enter the elements in an array : " << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cin >> ele;
            arr.push_back(ele);
        }

        int result = max_height_in_array(arr, size);
        std::cout << "Maximum height in the given array is : " << result
                  << std::endl;
    }
    return (0);
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Case ;
  Input:
  Enter test cases : 
  2
  Enter the size of an array : 
  4
  Enter the elements in an array : 
  1 2 2 1
  Enter the size of an array : 
  8
  Enter the elements in an array : "
  3 5 7 9 5 6 5 5
  
  Output:
  Maximum height in the given array is : 
  25
  Maximum height in the given array is : 
  93
*/

