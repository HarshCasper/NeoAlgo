/*
Description : 
       Unique Number : In the given range, print all numbers having unique digits.
                       e.g. In range 10 to 20 should print all numbers except 11.
                       As "11" comprises of both same digit .
*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool func(int n)
    {
        //an empty variable
        int var;
        //an empty array ,currently filled with 0
        int A[10] = {0};
        while (n)
        {
            //taking out the last digit of number
            var = n % 10;
            A[var]++;
            n = n / 10;
        }
        //checking if any number in digit occured more than once or not
        for (int i = 0; i < 10; i++)
            if (A[i] > 1)
                return 0;

        return 1;
    }
    vector<int> uniqueNumbers(int L, int R)
    {
        //result vector will contain unique digit numbers in given range
        vector<int> result;
        for (int i = L; i < R + 1; i++)
        {
            if (func(i))
                result.push_back(i);
        }
        return result;
    }
};

int main()
{
    //range of the number
    int start, end;
    cout << "Enter start and end of the range : " << endl;
    cin >> start >> end;
    solution ob;
    vector<int> number = ob.uniqueNumbers(start, end);
    cout << "The unique digit number in the range are : " << endl;
    //for displaying the answer
    for (int num : number)
    {
        cout << num << " ";
    }
    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/
/*
Test Cases: 
Test case 1:
    Input : Enter start and end of the range : 10 20
	Output : 10 12 13 14 15 16 17 18 19 20 21 

Test Case 2: 
    Input : Enter start and end of the range : 1 9
	Output : 1 2 3 4 5 6 7 8 9
*/

