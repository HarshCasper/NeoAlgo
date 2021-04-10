// This is Competitve Programming  question

// Dividing Tasks to student is CP problem that state that There are N students in the class, i'th student has Ci task in his collection. Your task is to determine if it is possible to redistribute C1 + C2 + ... + Cn task among the student of class thus that i'th student would get i task.

// given number of students (n)
// given the task assigned to them
// output if the problem state is possible if true print Yes else No

// Algorithm
// declare and initialise sum_of_task that means sum of task given in array to 0
// declare and initialise sum_of_i_student means sum of ith student to 0
// if sum_of_task is equal to sum_of_i_student is equal print YES else NO
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    int sum_of_i_student=0;
    int sum_of_task=0;
    for(int i=1;i<=n;i++)
    {
        sum_of_i_student=sum_of_i_student+i;
        int a;
        cin>>a;
        arr.push_back(a);
        sum_of_task=sum_of_task+a;
    }
    if(sum_of_i_student==sum_of_task)cout<<"YES\n";
    else cout<<"NO\n";
}

// Test case 1
// 5
// 7 4 1 1 2
// output
// YES

// Test case 2
// 5
// 1 1 1 1 1
// output
// NO
