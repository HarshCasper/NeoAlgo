/*
The Problem states that Given array arr[n] of integer where each element arr[i] represent 
number of task given to each student.Your task is to find if it possible to redistribute the 
task where i'th student assign i number of task. Example is it possible to assign 2 task to 2nd Student. 
*/
#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
    int sum_of_task = 0, sum_of_i = 0;
    for (int i = 1; i <= n; i++)
    {
        sum_of_task = sum_of_task + arr[i];
        sum_of_i += i;
    }
    if (sum_of_i == sum_of_task)
        cout << "Yes It is possible\n";
    else
        cout << "No It is not Possible\n";
}
int main()
{
    int n;
    cout<<"Enter number of Student:";
    cin >> n;
    int arr[n];
    cout<<"Enter number of task assign to each\n";
    for (int i = 1; i <= n; i++)
    {
        cout<<"Student "<<i<<":";
        cin >> arr[i];
    }
    solve(arr, n);
    
}

/*
Sample Input:
Enter number of Student:5
Enter number of task assign to each
Student 1:7
Student 2:4
Student 3:1
Student 4:1
Student 5:2

Sample Output:
Yes It is possible

Time-Complexity: O(n)
Space-Complexity: O(1)

*/
