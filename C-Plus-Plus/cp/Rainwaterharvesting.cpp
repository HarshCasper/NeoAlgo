/*
A very popular problem asked in interviews medium difficulty
Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase: 
![image](https://user-images.githubusercontent.com/44130067/94519631-84921880-0248-11eb-8515-416d81534168.png)
So the total units of water she can save is 5 units

**Input Format**
First line contains an integer n. Second line contains n space separated integers representing the elevation map.

**Constraints**
1 <= N <= 10^6

**Output Format**
Print a single integer containing the maximum unit of waters she can save.

**Sample Input**
10
0 2 1 3 0 1 2 1 2 1
**Sample Output**
5
**Explanation**
Refer to the image for explanation. Count the number of cells having water in them.
*/
#include<iostream>
using namespace std;
int maxWater_optimized(int arr[], int n)
{
    int water = 0; // To store the final ans

    int left_max = 0;  // Which stores the current max height of the left side
    int right_max = 0; // Which stores the current max height of the right side

    int lo = 0;     // Counter to traverse from the left_side
    int hi = n - 1; // Counter to traverse from the right_side

    while (lo <= hi)
    {

        if (arr[lo] < arr[hi])
        {

            if (arr[lo] > left_max)
            {
                left_max = arr[lo]; // Updating left_max
            }
            else
            {

                water += left_max - arr[lo]; // Calculating the ans
            }
            lo++;
        }
        else
        {

            if (arr[hi] > right_max)
            {
                right_max = arr[hi]; // Updating right_max
            }
            else
            {
                water += right_max - arr[hi]; // Calculating the ans
            }
            hi--;
        }
    }

    return water;
}
int main() {
	int n,arr[1000000];
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int water=maxWater_optimized(arr,n);
	cout<<water;
	return 0;
}
