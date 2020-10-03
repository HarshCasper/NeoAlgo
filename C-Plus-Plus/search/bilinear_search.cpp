/*********************************************************************************
                            Bilinear Search
Author: Rishabh Gautam 
Email: rgautam1919@gmail.com
Github: rishabh7896
**********************************************************************************

We are given an array a[], check whether the value exists or not,
if exits print the index(1 based indexing) else print -1.

Input:
first line containes size of array.
Next line containes n space seperated intgeres.
Next line contains a value that needed to be searched.

Sample Input 1: 
5
5 4 3 2 1
1

Sample Output 1:
5

Sample Input 2: 
5
5 4 3 2 1
7

Sample Output 2:
-1

Bilinear approach:
Let A be the linear array of n elements. The algorithm searches for element 'key'. 
Let 'index' represent the location of the element 'key' in the array. 
The algorithm returns the values index=-1 if the element 'key' is not present in the array 
and value index if the element 'key' is present in the array.

Language: C++17
*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

//bilenear search algorithm
int bilinear(vector<int>&a,int n,int key)
{
    int front=0,back=n-1,index=-1;
    //terminating condition
    while(front<=back)
    {
        if(a[front]==key)
            index=front+1;
        if(a[back]==key)
            index=back+1;
        front++;
        back--;
    }
    return index;
}

int main()
{
    clock_t start=clock();
    //declare and read the values of n;
    int n; cin>>n;
    //declare and read the values of a[] of size n
    vector<int>a(MAX);
    for(int i=0;i<n;i++)
        cin>>a[i];
    //declare and read the value of key
    int key; cin>>key;
    //Billinear approach
    cout<<bilinear(a,n,key);

    cerr<<fixed<<setprecision(6);
    cerr<<(double)(clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}