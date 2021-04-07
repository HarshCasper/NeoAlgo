/*
  Code to find the Kth Largest element in an array is given below.
*/

#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;
int findKthLargest(vector<int> &a, int k)
{

    //creating a min heap
    priority_queue<int, vector<int>, greater<int>> heap;

    for (auto u : a) //iterating through vector
    {
        if (heap.size() < k)
            heap.push(u); //keep filling the heap till K
        else
        {
            if (u > heap.top()) //checking if there is another larger element that top of the heap remaining in the vector array.
            {
                heap.pop();
                heap.push(u);
            }
        }
    }
    return heap.top(); //The element on the top of the heap after traversing the whole array will be the Kth Largest ELement.
}

int main()
{
    cout << "Enter the size of the vector array: ";
    int n, k;
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    vector<int> vec;
    int ele;
    cout << "Enter vector array elements: ";
    for (int i = 0; i < n; i++)
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
