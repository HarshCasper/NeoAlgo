/* ROD CUTTING PROBLEM(DP)(C++)

Given a rod of length ‘n’ units. The rod can be cut into different sizes and each size has a cost
associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.
Eg:
Input: rod length=5, prices of rod length from 1 to 5 = 2 5 7 8 10
Output: max profit= 12

Explanation:
Rod of length 5 can be cut as 1,1,1,1,1 (profit=10) or 1,2,2 (profit=12) or 5 (profit=10) and so on.
Max profit from a rod of length n can be found as:
For length=1, since 1 length can't be divided, profit = 2
For length=2, rod can be either taken as whole (profit=5),or two rods of length 1 (profit=2+2=4)
..
For length=5,
At first, we will divide the rod into 2 parts, and each part can be further divided into more parts.
The two parts can be (1,4),(2,3),(3,2),(4,1) and without cut (5).
Here, we have taken the max profit of each smaller rod, which means if we cut 5 into 1 and 4 lengths,
then we will add the maximum possible profit for lengths 1 and 4, which will be stored in our dp array.
Since profit by cutting rod as 1,4 and 4,1 is same, we will find sum of profits of rods where
value of left side of rod goes from 1 to length/2.
Given length=5, 5/2= 2, so we will find profits by pairs (1,2),(2,3) only and then compare with (5).
Maximum of them will be our answer which is maximum profit for length of rod=5.
*/

#include <iostream>
using namespace std;

//Function that returns maximum value by cutting n length rod
int rodCutting(int price_arr[], int n)
{
    int max_val[n],beg,last;

    max_val[0]=price_arr[0]; //max price of length 1 is price of 1 itself

    //curr_len is iterator to find max price by cutting rod of length curr_len+1
    for(int curr_len=1; curr_len<n; curr_len++)
    {
        max_val[curr_len]=price_arr[curr_len]; //maximum value of current length without any cuts
        beg=0; //iterator going from beginning (rod length=1) to length= current length/2
        last=curr_len-1; //iterator decreasing from rod length= current-1 to length= current length/2

        /*Compare sum of optimal values of left and right side of rod (where left rod length goes from 1 till
        mid of current length) with current max value stored*/
        while(beg<=last)
        {
            if(max_val[curr_len]< max_val[beg]+max_val[last])
            {
                max_val[curr_len]= max_val[beg]+max_val[last];
            }
            beg++;
            last--;
        }
    }
    return max_val[n-1]; //max value obtained by all cuts of n length rod
}

int main()
{
    int n; //size of price array
    cout<<"Enter size of price array: ";
    cin>>n;
    int prices[n]; //prices for each length of rod
    cout<<"Enter prices for each length of rod: "<<endl;
    for(int i=0; i<n; i++)
        cin>>prices[i];

    cout<<"Maximum value is: "<<rodCutting(prices, n)<<endl;
    return 0;
}
/*
Test Cases:
    Input:
    8
    1 5 8 9 10 17 17 20
    Output:
    22

    Input:
    6
    3 5 6 7 10 12
    Output:
    18

Time Complexity: O(n^2)
Space Complexity: O(n)
*/
