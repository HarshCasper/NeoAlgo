// CPP Program to print Leibniz Harmonic Triangle
#include <bits/stdc++.h>
using namespace std;
 //function
void LeibnizHarmonicTriangle(int num)
{
    int C[num + 1][num + 1];
 
    // Calculate value of Binomial Coefficient in
    // bottom up manner
    for (int i = 0; i <= num; i++) {
        for (int j = 0; j <= min(i, num); j++) {
 
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previously
            // stored values
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
 
    // printing Leibniz Harmonic Triangle
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= i; j++)
            cout << "1/" << i * C[i - 1][j - 1] << " ";
 
        cout << endl;
    }
}

int main()
{
    int num = 4;
    LeibnizHarmonicTriangle(num);
    return 0;
}
