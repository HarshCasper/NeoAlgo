/*
  Code to find the Kth Largest element in an array is given below.
*/

#include <bits/stdc++.h>

using namespace std;

/*
  The following function finds the Kth Largest element by using Min Heap.
    1. It Keeps pushing the element to the heap till size k.
    2. And when it exceeds the size k, It starts checking for another element
        larger than top of the heap remained in the array.
    3. After traversing through all the elements it returns the top of heap that is the required output.
*/

int findKthLargest(vector<int> &a, int k)
{
    priority_queue<int, vector<int>, greater<int>> heap;       //creating a min heap

    for (auto u : a) //iterating through vector
    {
        if (heap.size() < k)
            heap.push(u); //keep filling the heap till K
        else
        {
            if (u > heap.top()) /*checking if there is another element larger
                                  than top of the heap remaining in the vector array. */
            {
                heap.pop();
                heap.push(u);
            }
        }
    }
    return heap.top(); /*The element on the top of the heap after 
                          traversing the whole array will be the Kth Largest ELement. */
}

int main()
{
    cout << "Enter the size of the vector array: ";
    int size, k;
    cin >> size;
    cout << "Enter the value of k: ";
    cin >> k;
    vector<int> vec;
    int ele;
    cout << "Enter vector array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> ele;
        vec.push_back(ele);
    }
    cout << "The Kth Largest Element: " << findKthLargest(vec, k) << endl;
    return 0;
}

/*
Sample Input:
Enter the size of the vector array: 8
Enter the value of k: 2
Enter vector array elements: 3 2 1 5 6 4
Sample Output:
The Kth Largest Element: 5
Time Complexity: O(nlogk)
Space Complexity: O(k)
*/
