<<<<<<< HEAD
/*
Shell sort is a highly efficient sorting algorithm and is based on insertion sort algorithm.
This algorithm avoids large shifts as in case of insertion sort, if the smaller value is to the far right 
and has to be moved to the far left.This algorithm uses insertion sort on a widely spread elements, first to sort 
them and then sorts the less widely spaced elements. This spacing is termed as interval.
Worst case time complexity = O(n2)
Best case complexity = O(nlog(n)).
Space complexity = O(1).
*/


#include<iostream>
using namespace std;
/*Method to sort the list/array*/
void shellSort(int sort[],int size){
    for(int gap=size/2;gap>0;gap/=2){
        for(int i=gap;i<size;i++){
            int temp=sort[i];
            int j;
            for(j=i;j>=gap&&sort[j-gap]>temp;j-=gap){
                sort[j]=sort[j-gap];
            }
            sort[j]=temp;
        }
    }
}
//main program
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int sort[size];
    cout<<"Enter the Elements to be sorted:";
    for(int i=0;i<size;i++){
        cin>>sort[i];
    }
    shellSort(sort,size);
    cout<<"Array after sorting is: ";
    for(int i=0;i<size;i++){
        cout<<sort[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*       Output
Enter the size of the array: 5                                                                                                                
9 5 8 1 4                                                                                                                                            5                                                                                                                                             
Array after sorting is: 1 4 5 8 9                                                                                                                                           Array after sorting is: 1 4 5 8 9 
*/
=======
#include<iostream>
using namespace std;
int main()
{
    float A[10],B[10];
    int i,j,key,m,n,temp,k;
    cout<<"\nenter no of elements in array:";
    cin>>n;
    cout<<"\nenter elements of array:";
    for(i=0;i<n;i++)
    {
        cin>>B[i];
    }
    cout<<"\nthe array elements are:";
    for(i=0;i<n;i++)
    {
        cout<<B[i]<<"\t";
    }
    for(i=n/2;i>0;i=i/2)
    {
        for(j=1;j<n;j++)
        {
            for(k=j-i;k>=0;k=k-i)
            {
                if(B[k+i]>=B[k])
                {
                    break;
                }
                else
                {
                    key=B[k];
                    B[k]=B[k+i];
                    B[k+i]=key;
                }
            }
        }
    }
    cout<<"\nthe shell sorted array is:";
    for(i=0;i<n;i++)
    {
        cout<<B[i]<<"\t";
    }


    return 0;
}
				
>>>>>>> Update Shellsort.cpp
