#include<bits/stdc++.h>
using namespace std;
//                   
// PROBLEM STATEMENT

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// In simpler words sort an array containing 0,1,2.

// Solve the problem with a one-pass algorithm using only O(1) constant space?

// TEST CASE-
// Input:
// n=6
// nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Input:
// n=3
// nums = [2,0,1]
// Output: [0,1,2]

// The bruteforce approach - Sort the vector in nlogn time

//                                 ************************DUTCH_NATIONAL_FLAG ALGORITHM***********************************

void sortColors(vector<int> nums) {
        int n=nums.size();
        int low=0,med=0,high=n-1; // mantain 3 pointers
        int temp;
        while(med<=high){ // base condition-when med pointer becomes greater than high ,break
            if(nums[med]==0){
                // swap(nums[med],nums[low]);
                temp=nums[med];
                nums[med]=nums[low];
                nums[low]=temp;
                low++;
                med++;
            }
            else if(nums[med]==1){
                med++;
            }
            else{
                // swap(nums[med],nums[high]);
                temp=nums[med];
                nums[med]=nums[high];
                nums[high]=temp;
                high--;
            }
        }
        for(int i=0;i<n;i++){
          cout<<nums[i]<<" ";
        }
    }

    int main(){
      vector<int >nums;
      int n,input;
      cin>>n;
      for(int i=0;i<n;i++){
          cin>>input;
          nums.push_back(input);
      }
      sortColors(nums);
    }

  //  COMPLEXITY ANALYSIS-
  //     Time= O(N)
  //     space=O(1)