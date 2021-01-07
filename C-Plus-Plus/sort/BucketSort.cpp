/*
Bucket sort is a sorting algorithm that works by distributing the elements
of an array into a number of buckets. 
Each bucket is then sorted individually, either using a different sorting algorithm, 
or by recursively applying the bucket sorting algorithm.
*/
#include<bits/stdc++.h>
using namespace std;

//function for Bucket Sort
void BucketSort(float arr[], int n){
    //Creation of buckets
    vector<float> buckets[n];

    //put array elements in different buckets
    //bucketIndex is index in buckets 
    for(int i=0;i<n;i++){
        int bucketIndex = n*arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    //sort individual buckets.
    for(int i=0;i<n;i++){
        sort(buckets[i].begin(), buckets[i].end());
    }

    //combine all buckets into array arr.
    int index=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<buckets[i].size();j++){
            arr[index++]=buckets[i][j];
        }
    }

}

int main(){
    //declaration of array and size of array.
    float arr[100];
    int n;
    //Taking input of size of array and array.
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    //function calling
    BucketSort(arr,n);
    //Print  sorted array
    cout<<"\nSorted Array is : \n";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}

/*

Inputs are : n=7 
arr={0.563, 0.785, 0.875, 0.978, 0.212, 0.637, 0.274}

Output is :
Sorted Array is : 
0.212 0.274 0.563 0.637 0.785 0.875 0.978

*/