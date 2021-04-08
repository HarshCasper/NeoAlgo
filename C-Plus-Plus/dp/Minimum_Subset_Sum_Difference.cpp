/*
Minimum Subset Sum Difference:
        Partition the Set into two subsets Set1, Set2 such that the
        difference between the sum of elements in Set1 and the sum
        of elements in Set2 is minimized

    Written by- @Mohim-Singla
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Standard inputs
    int n;
    cout<<"Enter number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements in the array: ";
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }


    int array_sum=0;
    array_sum=accumulate(arr, arr+n, array_sum);

    //Applying top-down approach in dynamic programing
    bool mat[n+1][array_sum+1];
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=array_sum;j++)
        {
            if (i==0)
            {
                mat[i][j]=false;
            }
            else if (j==0)
            {
                mat[i][j]=true;
            }
            else
            {
                if (arr[i]<=j)
                {
                    mat[i][j] = mat[i][j-arr[i]] || mat[i-1][j];
                }
                else
                {
                    mat[i][j] = mat[i-1][j];
                }
            }
        }
    }

    //since minimum difference = Total_sum - 2*(maximum sum of subset 1(not exceeding half vale))
    int sum_of_subset1=0;

    //accessing last row of the top-down matrix
    for (int i=0;i<=array_sum/2;i++)
    {
        if (mat[n][i])
        {
            sum_of_subset1 = i-1;
        }
    }

    //Standard final Output
    int min_difference=array_sum-2*sum_of_subset1;
    cout<<"Minimum Difference: "<<min_difference<<endl;


}

/*
--------------------------------------------------------------------
Test case:
    Input format:
        1st line contains n -- number of elements in the list.
        2nd line contains space separated elements of the list.
    Output Format:
        Gives desired output in a single line.
--------------------------------------------------------------------
Test case 1:
Input:
    7
    2 3 4 5 6 7 30
Output:
    Minimum Difference: 3
--------------------------------------------------------------------
Test case 2:
    Input:
        3
        1 2 7
    Output:
        Minimum Difference: 4
--------------------------------------------------------------------

Time Complexity: O(m*n)            n=number of elements
Space Complexity: O(m*n)           m=total sum of the list

--------------------------------------------------------------------
*/
