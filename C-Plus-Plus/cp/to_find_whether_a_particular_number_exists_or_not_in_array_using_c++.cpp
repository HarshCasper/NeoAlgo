//Given an array of numbers, find whether a particular number exists or not in the numbers of array.
//For example:-

//INPUT:
//number of test cases(t)   1
//size of the array(n)   7
//corresponding array elements    85, 999, 00, 50, 1, 6, 707
//element to be found out(number)     6

//OUTPUT:
//Exists


#include<iostream>
using namespace std;
bool num_exists(int arr[],int n,int num){
    for(int i=0;i<=n-1;i++){
        if(arr[i]==num){
            cout<<"Exists"<<endl;
            return false;
        }
    }
    cout<<"Number not found";
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        int num;
        cin>>num;
        num_exists(arr,n,num);
    }
    return 0;
}
