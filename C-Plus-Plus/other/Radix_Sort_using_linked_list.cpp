/* The following C++ program implements the 
 Radix Sort algorithm which works by doing 
 digit by digit sort starting from least 
 significant digit to most significant digit.
 The algorithm sorts non-negative integers using 
 and is implemented using linked list.*/ 
#include <bits/stdc++.h>
using namespace std;

// Function to find the number of digits in an integer
int digits(int n){
    int noofdigits=0;
    while(n>0){
        noofdigits++;
        n/=10;
    }
    return noofdigits;
}

// Function to print our vector
void print(vector<int> a){
    int n=a.size();
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// Main function to implement Radix Sort
void radix_sort(vector<int> &a, int maxdigits){
    int n= a.size();
    int i,j,m,index,temp;
    int p=1,count=0;
    // 10 is the radix of a number in the decimal system
    list<int> pocket[10];
    for(int i=0;i<maxdigits;i++){
        m=pow(10,i+1);
        p=pow(10,i);
        for(j=0;j<n;j++){
            temp=a[j]%m;
            // Finding index for the pocket arraya
            index=temp/p; 
            pocket[index].push_back(a[j]);
        }
        count=0;
        for(j=0;j<10;j++){
            // Deleting elements from linked list
            // and storing in the vector 
            while(!pocket[j].empty()){
                a[count]=*(pocket[j].begin());
                pocket[j].erase(pocket[j].begin());
                count++;
            }
        }
    }
}
int main()
{
    int n;cin>>n;
    vector<int> a(n);
    // Input the array
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // Finding the maximum element in array
    // to find maximum no of digits
    vector<int> temp= a;
    sort(temp.begin(),temp.end(),greater<int>());
    int maxelement= temp[0];
    int maxdigits= digits(temp[0]);

    // Outputting array before sorting
    cout<<"Before Sorting: ";
    print(a);
    // Calling the radix sort function
    radix_sort(a,maxdigits);
    // Outputting array after sorting
    cout<<"After Sorting: ";
    print(a);

    return 0;
}

/* 
// N -> No of elements
// K -> Maximum element in the array
Note: Base of log function used below is 10
Time Complexity: O(N*log(K)) 
Sample Input:
6                   // No of elements
8 3 22 66 11 33     // Array of elements

Sample Output:
Before Sorting: 8 3 22 66 11 33 
After Sorting: 3 8 11 22 33 66 

*/

