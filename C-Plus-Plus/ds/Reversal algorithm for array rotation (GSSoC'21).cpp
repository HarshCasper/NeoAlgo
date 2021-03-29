#include <bits/stdc++.h>

using namespace std;

class ArrayReverseAlgo{
public:

    void reverse(int arr[],int first,int last)
    {
        int temp;
        while(first<last)
        {
            temp=arr[first];
            arr[first]=arr[last];
            arr[last]=temp;
            //swapped first and last element of the array as shown above

            first++;
            last--;
        }
    }
    void leftRotate(int arr[], int n, int d) {

        if(d==0)
        return;

        d=d%n; // also covers the case when d>n

        reverse(arr,0,d-1); //ArB
        reverse(arr,d,n-1); //ArBr
        reverse(arr,0,n-1); //(ArBr) r = BA
    }

    void printArray(int arr[],int n)
    {

        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";

        cout<<endl;
    }
};

int main()
{
    int n,d;
    cout<<"Enter array length:\n";
    cin>>n;
    int arr[n];

    cout<<"Enter elements of the array:\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<"Enter d (Rotating factor):\n";
    cin>>d;

    ArrayReverseAlgo r;
    r.leftRotate(arr,n,d);

    cout<<"The rotated array is:\n";
    r.printArray(arr,n);


    return 0;
}
