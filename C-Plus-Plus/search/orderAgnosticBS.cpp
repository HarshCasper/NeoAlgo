/*order augnostic Binary searches the element the array that  is sorted in Asc or Desc order.
ALGORITHM:
1. Declare an array i.e sorted in asc or desc order and a target element to search
2. Make a function call to orderAgnostic()
3. Inside orderAgnostic(),check if array is in asc or desc order
4. If target element is equal to the mid element, return mid
5. If array is in asc order and target < element at mid then, make high=mid-1
6. If array is in desc order and target < element at mid then, make low=mid+1
7. Repeat this process till low<=high
8. else, return -1 i.e element is not found in array

*/

#include<iostream>
using namespace std;

int orderAgnostic(int lst[],int target);

int main(){
    int item;
    int arr[]={22 ,34 ,51 ,63,71};
    cout<<"Element to search:"; 
    cin>>item;
    //call order agnostic binary search
    int result=orderAgnostic(arr,item);

    //return the index of item
    if(result!=-1){
        cout<<"Element found at index : "<<result;
    }
    else{
        cout<<"Element not found!!!";
    }
    return 0;
return 0;
}

int orderAgnostic(int lst[],int target){


    int low=0;
    int high=(sizeof(lst)-sizeof(lst[0]))-1;

    bool isAsc=lst[low]<lst[high];

    while(low<=high){

        int mid=low+(high-low)/2; //might be (low+high) exceeds the int range
        
        if(target==lst[mid]){
            return mid;
        }

        if(isAsc){
            if(target<lst[mid]){
            high=mid-1;
            }

            else{
                low=mid+1;
            }
        }
        else{
            if(target<lst[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
    }
    return -1;

}
/*
Input:{22,34,55,71,66,90},target=66
Output:4

Time complexity:O(logn)
Space complexity:O(1);
*/