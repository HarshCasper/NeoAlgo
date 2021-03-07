//Problem statement :
//Given an array of integers, sort the array into a wave like arrangement,
//that is A[0 to n-1] is sorted in the form A[0]>=A[1]<=A[2]>=A[3]....

#include<bits/stdc++.h>
using namespace std;
vector<int> wave_sort(vector<int> &v,int n) {
    for(int i=0;i<n;i+=2) {
        if(v[i]<v[i-1] and i!=0) { //If the current element is lesser in value than the previous and is not the first..
            swap(v[i],v[i-1]); //then the values are swapped
        }
        if(v[i]<v[i+1] and i!=n-1) { //If the current element is lesser in value than the next and is not the last..
            swap(v[i],v[i+1]); //then the values are swapped
        }
    }
    return v;
}

int main() {
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++) { 
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    wave_sort(v,n); 
    //Printing the final vector
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
    return 0;
}
//Example 1:
//Input[] : {20 80 40 35 10 15 70}
//Output[] : {80 20 40 10 35 15 70}

//Example 2:
//Input[] = {12 20 45 60 5}
//Output[] : {20 12 60 5 45}