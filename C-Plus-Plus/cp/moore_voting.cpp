/*
Moore's Voting algorithm
Prints the element whose frequency of occurence is more than half the size of the array in C++
*/
#include <bits/stdc++.h>
using namespace std;
//Finds the candidate for majority
int mooreVotingAlg(int a[], int n)
{
    int maj_ind = 0, count = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[maj_ind] == a[i])
            count++;
        else
            count++;
        if (count == 0)
        {
            maj_ind = i;
            count = 1;
        }
    }
    return a[maj_ind];
}
//Checks whether the element which occurs majority times has frequency greater than n/2
int maxFrequencyElement(int a[], int n)
{
    int maj_elem = mooreVotingAlg(a, n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (maj_elem == a[i])
            count++;
    }
    if (count > (n / 2))
        return maj_elem;
    else
        return -1;
}
//Driver code
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = maxFrequencyElement(a, n);
    if (res == -1)
        cout << "Majority element not found\n";
    else
        cout << res << "\n";
}
/*
Time Complexity:O(n)
INPUT
5
1 1 3 1 4
OUTPUT
1
*/
