/*
Previous Greater Element
===================
You are given an array of size N and are required to print the left most 
previous greater element. 
Application: Stack data structure
Time Complexity: O(n)
Space Complexity: O(n)
*/

// Naive Approach: Time O(n*n)
 
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n; cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     // using two for loop
//     for(int i=0;i<n;i++){
//         int j;
//         for(j=i-1;j>=0;j--){ // for comparing left elements with the curr element 
//             if(arr[i]<arr[j]){ // if the left most is greater than the curr element 
//                 cout<<arr[j]<<" ";
//                 break;
//             }
//         }
//         if(j==-1) cout<<-1<<" "; // if not then print -1
//     }
//     return 0;
// }


// Efficient Approach O(N)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int> s; 
    s.push(arr[0]); 
    for(int i=0;i<n;i++){
        while(s.empty() == false and s.top()<=arr[i]) // if stack is not empty and top of stack is less than or equal to curr element
            s.pop(); // remove the s.top()
        
        s.empty() ? cout<< "-1 " : cout<<s.top()<<" ";  // if stack is empty than print -1 (for first element it will always be -1) 
        // and if stack is not empty print top of stack as it is the previous greater value.
        s.push(arr[i]); 
    }
    return 0;
}

// Output: 
// n = 8
// arr[] = {15 10 18 12 4 6 2 8}
// output arr[] = {-1 15 -1 18 12 12 6 12}
