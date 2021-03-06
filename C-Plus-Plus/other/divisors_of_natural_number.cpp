/* You are given a natural number, for which you have to find out all the possible distinct divisors of the given natural number.
   The output is always sorted in ascending order.
   For this we can have various approaches but the most optimized solution has a time complexity of O(sqrt(N)), and a space complexity of O(1).
*/

#include <bits/stdc++.h>

using namespace std;

//function to print the possible divisors of the given number.
void divisorsOfNumber(int num)
{
    //iterating starting from 1 to the number itself searching for the numbers that exactly divide the given natural number, dividing it into two parts.
    //this is done to minimize the complexity

    for(int pass = 1; pass*pass < num; pass++)
    {
        //if the pass value exactly divides the given natural number, then it is printed
        if(num % pass == 0)
        {
            cout << pass << " ";
        }
    }

    for(int pass = sqrt(num); pass >= 1; pass--)
    {
        //if the pass value exactly divides the given natural number, then it is printed
        if(num % pass == 0)
        {
            cout << (num/pass) << " ";
        }
    }

    //providing a line break
    cout << endl;
}

//main function
int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int testCases;
    //taking the number of test cases as the input
    cin>>testCases;
    //the code inside the while loop will be executed until the testcases become equal to zero
    while(testCases--)
    {
        int num;
        //taking the natural number as input
        cin>>num;

        cout<<"All the possible divisors of "<<num<<"are: ";
        //calling the function divisorsOfNumber() by passing the natural number, which will print the divisors 
        divisorsOfNumber(num); 
    }
    return 0;

}

/*

FOR EXAMPLE:--

Example 1:
Input:-
1
60
Output:-
1 2 3 4 5 6 10 12 15 20 30 60

Example 2:
Input:-
1
101
Output:-
1 101

Example 3:
Input:-
2
40
70
Output:-
1 2 4 5 8 10 20 40
1 2 5 7 10 14 35 70

*/