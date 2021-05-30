/* ROD CUTTING PROBLEM(DP)(C++)

Given a rod of length ‘n’ units. The rod can be cut into different sizes and each size has a cost
associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.
*/

#include <iostream>
using namespace std;

//Function that returns maximum value by cutting n length rod
int rodCutting(int price_arr[], int n)
{
    int max_val[n],beg,last;

    //max price of length 1 is price of 1 itself
    max_val[0]=price_arr[0];

    //curr_len is iterator to find max price by cutting rod of length curr_len+1
    for(int curr_len=1; curr_len<n; curr_len++)
    {
        //maximum value of current length without any cuts
        max_val[curr_len]=price_arr[curr_len];
        //iterator going from beginning (rod length=1) to length= current length/2
        beg=0;
        //iterator decreasing from rod length= current-1 to length= current length/2
        last=curr_len-1;

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
    return max_val[n-1];
}

int main()
{
    //size of price array
    int n;
    cout<<"Enter size of price array: ";
    cin>>n;
    //prices for each length of rod
    int prices[n];
    cout<<"Enter prices for each length of rod: "<<endl;
    for(int i=0; i<n; i++)
        cin>>prices[i];

    cout<<"Maximum value is: "<<rodCutting(prices, n)<<endl;
    return 0;
}
/*
Test Cases:
    Input:
    Enter size of price array: 8
    Enter prices for each length of rod:
    1 5 8 9 10 17 17 20

    Output:
    Maximum value is: 22

    Input:
    Enter size of price array: 6
    Enter prices for each length of rod:
    3 5 6 7 10 12

    Output:
    Maximum value is: 18

Time Complexity: O(n^2)
Space Complexity: O(n)
*/
