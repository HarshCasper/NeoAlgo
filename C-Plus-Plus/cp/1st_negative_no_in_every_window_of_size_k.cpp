/**
 *  First Negative Integer in Every Window of Size K
 *  Cpp program to find first negative integer in each subarray
 *  of fixed size k, given an array of integers, using the 'Sliding
 *  Window Technique'. In case there is no negative integer in selected
 *  window, print 0.
 */

#include <bits/stdc++.h>

using namespace std;

/* function to find the first negative 
 integer in every window of size k*/
void printFirstNegativeInteger(int len, int k, int arr[])
{
    //A dynamic Array to store negative integers for current window of size k.
    vector<int> list;
    //Dynamic array to store 1st negative of each window
    vector<int> ans;
    int start = 0, end = 0;
    while (end < len) {
        //Add current element at the back of list if it is a negative integer
        if (arr[end] < 0)
            list.push_back(arr[end]);
        //When window size less than k, increase the size of window
        if (end - start + 1 < k)
            end++;
        //On reaching window size
        else if (end - start + 1 == k) { //If list is empty then the window does not have negative integer
            if (list.size() == 0)
                ans.push_back(0);
            else { //Else is not empty then element at the front
                //of list is the first negative integer of previous window
                ans.push_back(list.front());
                // Remove the elements which are out of this window
                if (arr[start] == list.front())
                    list.erase(list.begin());
            }
            //slide the window
            start++;
            end++;
        }
    }
    //Print the first negative integer of each window
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    //taking input from user
    int len;
    cout << "Enter the length of array of integers: ";
    cin >> len;
    int arr[len];
    cout << "Enter array of integers: ";
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    int k;
    cout << "Enter size of window: ";
    cin >> k;
    printFirstNegativeInteger(len, k, arr);
    return 0;
}

/*
    Test cases:

    INPUT:-
    Enter the length of array of integers: 8
    Enter array of integers: 12 3 -7 8 -15 39 15 20
    Enter size of window: 3
    OUTPUT:-
    -7 -7 -7 -15 -15 0

    INPUT:-
    Enter length of array of integers: 9
    Enter array of integers: -1 2 0 3 -2 -1 -2 10 8
    Enter size of window: 5
    OUTPUT:-
    -1 -2 -2 -2 -2

    Time complexity: O(N)
    Space complexity: O(k)

*/
