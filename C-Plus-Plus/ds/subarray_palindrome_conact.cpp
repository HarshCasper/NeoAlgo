/*SUBARRAY OF SIZE K WITH PALINDROMIC CONCATENATION
PALINDROME: words that are spelled the same from forward as well as backward.
PROBLEM: for a given array and an integer k, check if any subarray of size k exists in the array 
such that concatenation of elements form a palindrome.
APPROACH:        SLIDING WINDOW APPROACH
1.store concatenation of initial k elements.
2.iterate over the array & start deleting elements from the start and adding elements from the end.
3.at each step,check if concatenation is a palindrome.
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//functions that checks whether number is palindrome or not
bool ispalindrome(int n){
    int temp=n, num=0;

    //this loop will calculate reverse of n
    while(temp>0){
        num=num*10 +temp%10;
        temp=temp/10;
    }


    if(num==n){
        return true;
    }

    return false;
}

//return the k size subarray's starting point whose subelemnts if we concatenate then we will get a palindrome
int findpalindromicsubarray(vector<int> arr,int k){
    int num=0;

    for(int i=0;i<k;i++){
        num =num*10 +arr[i];
    }

    if(ispalindrome(num)){
        return 0;  //which represents that from 0 to k-1 there is k size subarray where the concatenation of elements forms a palindrome
    }

    for(int j=k;j<arr.size();j++){
        num = (num%(int)pow(10,k-1))*10 + arr[j];

        if(ispalindrome(num)){
            return j-k+1;
        }
    }

    return -1;   //represents that we didn't get any palindrome from array
}

int main(){

    vector<int> arr ={2,3,5,1,1,5};
    int k=4;

    int ans=findpalindromicsubarray(arr,k);

    if(ans==-1){
        cout<<"palindromic subarray doesn't exists"<<endl;
    }

    else{
        for(int i=ans;i<ans+k;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}



/*TEST CASE 1:
INPUT: arr={2,3,5,1,1,5} , k=4
OUTPUT:5 1 1 5
TEST CASE 2:
INPUT:arr={1,2,3,4,5,6,7} , k=4
OUTPUT:palindromic subarray doesn't exists
TIME COMPLEXITY:O(n^2)
SPACE COMPLEXITY:O(1)
*/