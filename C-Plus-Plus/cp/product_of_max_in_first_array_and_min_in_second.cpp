/*Given two arrays:arr1[] and arr2[] of different size i.e.,no_of_ele_in_arr1 amd no_of_ele_in_arr2 respectively.
Task :calculate the product of max element of first array i.e.,arr1[] and min element of second array i.e.,arr2[]
Example:we are given two arrays arr1={1,2,3,4} and arr2={5,6,7,8,9} ,so the maximum element in array arr1 is 4 and minimum element in array arr2 is 5.Hence,the product of max element in array arr1 and min element in array arr2 is 4*5=20.

Approach:
->take two arrays as input.
->using std library of cpp we will find the maximum element in array arr1 and minimum element in array arr2
->after getting the max and min element we will multiply them.
->return the product.
*/



#include<bits/stdc++.h>
using namespace std;

int find_product(int arr1[], int arr2[], int no_of_ele_in_arr1, int no_of_ele_in_arr2)
    {
        
        int num1=*max_element(arr1, arr1+ no_of_ele_in_arr1);
        int num2=*min_element(arr2, arr2+ no_of_ele_in_arr2);
        int r=num1*num2;
        return r;
    }

int main()
{
    int no_of_ele_in_arr1,no_of_ele_in_arr2,arr1[no_of_ele_in_arr1],arr2[no_of_ele_in_arr2];
    cout<<"enter the no. of elements in array 1"<<endl; 
    cin>>no_of_ele_in_arr1;
    cout<<"enter the elements of array 1"<<endl;
    for(int i=0;i<no_of_ele_in_arr1;i++)
    {
        cin>>arr1[i];
    }
    
    cout<<"enter the no. of elements in array 2"<<endl; 
    cin>>no_of_ele_in_arr2;
    cout<<"enter the elements of array 2"<<endl;
    for(int i=0;i<no_of_ele_in_arr2;i++)
    {
        cin>>arr2[i];
    }
    
    
    int prod=find_product(arr1,arr2,no_of_ele_in_arr1,no_of_ele_in_arr2);
    cout<<prod;
    return 0;
}

/*Sample Input1 : 
enter the no. of elements in array 1:
3
enter the elements of array 1:
1 2 3
enter the no. of elements in array 2:
5
enter the elements of array 2:
5 7 3 1 9

Sample Output1 :
product of max element of first array and min element of second array: 3
-------------------------------------------------------  
Sample Input2 : 
enter the no. of elements in array 1:
5
enter the elements of array 1:
7, -3, 5, -8, 4
enter the no. of elements in array 2:
5
enter the elements of array 2:
9, 8, 6, -4, 2

Sample Output2 :
product of max element of first array and min element of second array: -28 
 
Time Complexity : O(n)
Auxiliary Space : O(1) 
*/
  