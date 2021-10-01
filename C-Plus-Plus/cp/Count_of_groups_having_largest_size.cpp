/*
Description : 
        Given an integer N, the task is to find the number of groups having the largest size.
        Each number from 1 to N is grouped according to the sum of its digits.
*/

#include <bits/stdc++.h>
using namespace std;

//for finding the sum of number
int sum_of_digi(int n)
{
    //initial sum is zero
    int sum = 0;
    while (n)
    {
        //taking out the sum
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

//map for holding the unqiue sum of number
map<int, int> mp(int n)
{
    //for returning answer
    map<int, int> sum_mp;

    for (int i = 1; i < n + 1; ++i)
    {
        int sum1 = sum_of_digi(i);
        //if number found
        if (sum_mp.find(sum1) == sum_mp.end())
        {
            sum_mp[sum1] = 1;
        }
        else
        {
            sum_mp[sum1] = sum_mp[sum1] + 1;
        }
    }

    return sum_mp;
}
//for finding the biggest group in mp
int largest_grp(int n)
{
    int size = 0;
    int counter = 0;
    map<int, int> d = mp(n);
    //iterating in mp
    for (auto it = d.begin(); it != d.end(); ++it)
    {
        int x = it->first;
        int y = it->second;

        if (y > size)
        {
            size = y;
            counter = 1;
        }
        else if (y == size)
        {
            counter += 1;
        }
    }

    return counter;
}

int main()
{
    //input number
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;

    int g_num = largest_grp(num);
    cout << "The largest group : " << endl;
    cout << g_num << endl;

    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Case :
 Input :
 Enter the number : 
 15

 Output :
 6
*/

