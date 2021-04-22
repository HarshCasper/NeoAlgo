/*
Total ones 

For the given an integer num,
your task is to count the total number of digit 1s
appearing in all the non-negative integers which are
less than or equal to num.
*/

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

//here we observe the pattern of 1s appearing in the ones place,
//tens place, hundreds and so on
//No. of 1s in ones place can be calculated by = (num / 10) + (num % 10 != 0)
//No. of 1s in tens place can be calculated by
//                   = (num / 100) * 10 + min(max(num % 100 -10 + 1, 0) , 10)
//No. of 1s in hundres place can be calculated by
//                   = (num / 1000) * 100 + min(max(num % 1000 -100 + 1, 0) , 100)
//Idea is implemented as--

//function that returns the total count of 1s
//appearing in all the non-negative integers which are
//less than or equal to num. 
int totalOnes(int num)
{
    int count1s = 0;
    //for each places i.e ones place, tens place, hundreds..
    for (ll pass = 1; pass <= num; pass *= 10)
    {
        ll numRemaining = pass * 10;
        //working according to the formula obtained
        count1s += (num / numRemaining) * pass + min(max(num % numRemaining - pass + 1, 0LL), pass);
    }
    return count1s;
}

//driver code
int main()
{
    //taking input
    int num;
    cout << "Enter the number : ";
    cin >> num;

    //for output
    cout << "The total number of 1s obtained is : ";
    cout << totalOnes(num);
    cout << endl;
}

/*
EXAMPLE-->

Input--
Enter the number : 13
Output--
The total number of 1s obtained is : 6
 
Input--
Enter the number : 0
Output--
The total number of 1s obtained is : 0

TIME COMPLEXITY --> O(log(N)) ; where N is the num
SPACE COMPLEXITY --> O(1)
*/