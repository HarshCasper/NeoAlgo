#include<iostream>
using namespace std;

void subsets(int [],int);
int main()
{
    int n;
    cout<<"\nEnter the no. of elements in your array = ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the values into the array --> ";
    for(int i=0;i<n;i++)
    {cin>>a[i];}
    subsets(a,n);
    return 0;
}

void subsets(int a[], int n)
{
    int count =0;
    for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
                {
                    if(i & (1<<j))
                        {
                           cout<<a[j]<<" ";

                        }
                       count++; 
                    
                }
            cout<<endl;
        }
    cout<<"\nTotal no. of possible subset are "<<count;
}