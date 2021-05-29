// CPP program to find Hailstone Sequence of a given number N up to 1

/* 
The Hailstone sequence of numbers can be generated from a starting positive integer, N by:
 If N = 1, then the sequence ends.
 If N is even, then the next N of the sequence = N / 2
 If N is odd, then the next N of the sequence = (3 * N) + 1 
*/

#include <bits/stdc++.h>
using namespace std;

int HailstoneSequence(int N)
{
    static int count;

    if (N == 1 && count == 0)
    {
        cout << N << " ";
        return count;
    }

    else if (N == 1 && count != 0)
    {
        cout << N << " ";
        count++;
        return count;
    }

    else if (N % 2 == 0)
    {
        cout << N << " ";
        count++;
        HailstoneSequence(N / 2);
    }

    else if (N % 2 != 0)
    {
        cout << N << " ";
        count++;
        HailstoneSequence(3 * N + 1);
    }
}

// Driver code
int main()
{
    int N, ans;
    cout << "Enter a number: ";
    cin >> N;
    cout << "\nHailstone Sequence upto 1:" << endl;
    ans = HailstoneSequence(N);
    cout <<"\n\nNumber of Steps involved: "<< ans << endl;
    return 0;
}

/*
OUTPUT 1:
Enter a number: 7
Hailstone Sequence upto 1:
7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
Number of Steps involved: 17
    
OUTPUT 2:
Enter a number: 6
Hailstone Sequence upto 1:
6 3 10 5 16 8 4 2 1
Number of Steps involved: 9
*/
