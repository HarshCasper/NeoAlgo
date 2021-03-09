/* WIGGLE SORT
   *This program accepts an array of unsorted numbers and
    sorts the array such that arr[0]<arr[1]>arr[2]<arr[3]...
    Eg: Given array [1,3,2,2,3,1]
        One possible answer is: [2,3,1,3,1,2]

   * The given array is stored in a vector arr and sorted with the built-in sort() function.
   * A new vector x is initialized to store wiggle sorted array
   * The vector arr is then partitioned into two as left sub-array and right sub-array.
   * Elements in the left sub-array are added to the even indices of vector x
   * Elements in the right sub-array are added to the odd indices of vector x


   Time Complexity : O(nlogn)   (Sorting takes O(n logn) and traversal takes O(n))
   Space Complexity : O(n)   (New array to store the wiggle sorted elements)
*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
    int left,right,a,i,n;
    cin>>n;
    vector<int> arr ;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    vector <int> x(arr);
    sort(x.begin(), x.end());
    left=(n-1)/2;
    right=n-1;
    for(int k = 0; k < n; k +=2)
        arr[k] = x[left--];
    for(int k = 1; k < n; k +=2)
         arr[k] = x[right--];
    cout << "[";
    for(int i = 0; i<n; i++){
        cout << arr[i];
        if(i!=n-1)
            cout<< ", ";
    }
    cout << "]"<<"\n";
   return 0;
}
