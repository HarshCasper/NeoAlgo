/*
Find the minimum element in a sorted and rotated array.
*/
#include <iostream>
using namespace std;

int find_min_in_array(int A[],int n) {
    //if the first element is less than the last element then array is NOT ROTATED
    if(A[0]<A[n-1]){
        return A[0];
    }
    //initialising the left, right and mid indicators
    int left=0;
    int right=n-1;
    int mid;

    while(right>left+1){
        mid=left+(right-left)/2;
        //if the middle element is less than the right element, then min will be found on the left portion
        if(A[mid]<A[right]){
            right=mid;
        }else{
            left=mid;
        }
    }
    //the index of the minimum element will be stored in right indicator
    return A[right];
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //calling the function
    int min_element= find_min_in_array(arr,n);
    cout<<"The minimum element in this array is: "<<min_element<<endl;
    return 0;
}

/*
Time complexity: O(log(n)) 
As we can discard half of the array everytime we do a check

Sample case 1:-
Input: 
5 
4 5 1 2 3
Output:
The minimum element in this array is: 1

Sample case 2:-
Input: 
6
4 4 4 5 2 4
Output:
The minimum element in this array is: 2
*/