/*
Given a binary array, binary means array's element will be 0 or 1.
find the maximum number of consecutive 1's in this array.
*/

#include <bits/stdc++.h>
using namespace std;

int get_max_consecutive_ones(int ar[] , int N)
{
    int max_consecutive_ones = 0 , count_1 = 0;
    for(int i = 0; i < N; i++)
    {
        if(ar[i] == 1)
        {
            count_1++;
            /* here we will keep the maximum value of consecutive
            1's  */
            max_consecutive_ones = max(max_consecutive_ones, count_1);
        }
        else if(ar[i] == 0)
        {
            count_1 = 0;
            /* as array's element is zero (0)
            we will set count_1 as zero */

        }
    }
    return max_consecutive_ones;
}

int main()
{
    cout << "Enter the size of the array : \n";
    int N;
    cin >> N;
    int ar[N + 1];
    cout << "Enter array elements :\n";
    for (int i = 0; i < N; i++) 
    {
	 cin >> ar[i];
    }
    int max_consecutive_ones = get_max_consecutive_ones(ar , N);
    cout << "Maximum Consecutive Ones in this array is : ";
    cout << max_consecutive_ones << endl;
}
/*
Standard Input and Output

Enter the size of the array :
6
Enter array elements :
1 1 0 1 1 1
Maximum Consecutive Ones in this array is : 3

Time Complexity : O( N )
Space Complexity : O( 1 )

*/
