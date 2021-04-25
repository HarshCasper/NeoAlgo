/*
Given the size of the array and its element. We have to compute the 
amount of water that can be stored in every element of the array.
*/

#include <iostream>
using namespace std;
int maxWater_stored(int a[], int n)
{
    int water_stored = 0; 
    // To store the final ans
    int left_max = 0; 
    // Which stores the current max height of the left side
    int right_max = 0; 
    // Which stores the current max height of the right side
    int low = 0; 
    // Counter to traverse from the left_side
    int high = n - 1;
     // Counter to traverse from the right_side
    while (low <= high)
    {
        if (a[low] < a[high])
        {
            if (a[low] > left_max)
                left_max = a[low]; 
                // Updating left_max
            else
                water_stored += left_max - a[low]; 
                // Calculating the ans
            low++;
        }
        else
        {
            if (a[high] > right_max)
                right_max = a[high]; 
                // Updating right_max
            else
                water_stored += right_max - a[high]; 
                // Calculating the ans
            high--;
        }
    }
    return water_stored;
}
int main() {
    int n;
    //storing the size of the array
    cout<<"Enter the size of array : ";
    cin>>n;
    int a[n];
    //storing the array
    cout<<"Enter the array elements : ";
    for(int i=0;i<n;i++)
    cin>>a[i];
    //calling the function and storing the answer
    int ans=maxWater_stored(a,n);
    cout<<"The amount of water stored is "<<ans<<" units";
    return 0;
}

/*
Sample Input :
Enter the size of array : 6
Enter the array elements : 3 0 0 2 0 4
Output :
The amount of water stored is 10 units
*/

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/
