/*Below code is an implementation of 2 Pointer Method in C++.
Two pointers is really an easy and effective technique which
is typically used for searching pairs in a sorted array.
Given a sorted array A(sorted in ascending order), having N integers,
find if there exists any pair of elements (A[i], A[j]) such that their sum is equal to X.*/
#include <iostream>
#include<algorithm>
using namespace std;

bool twoPointerSum(int a[], int n, int x){
    int i = 0;
    int j = n - 1;
    while (i < j) {

        if (a[i] + a[j] == x){
            cout<<"The values whose sum is "<<x<<" are "<<a[i]<<" and "<<a[j];
            return true;
        }

        // If sum of elements at current
        // pointers is less, we move towards
        // higher values by doing i++
        else if (a[i] + a[j] < x)
            i++;

        // If sum of elements at current
        // pointers is more, we move towards
        // lower values by doing j--
        else
            j--;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int x;
    cin>>x;
    if(twoPointerSum(a,n,x)){
        return 0;
    }
    else{
        cout<<"There is no two values in the array whose sum is "<<x;
    }
    cout<<endl;
    return 0;
}