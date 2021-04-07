
#include <iostream>
using namespace std;
//function to implement rosum 
void rowsum(int *arr,int n,int m)
{int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            sum+=*(arr+i*m+j);
        }
        cout<<"The sum for the "<<i+1<<"th row is: "<<sum<<"\n";
        sum=0;
    }
}
//function to get the values from user for the 2-D array
void get(int *arr,int n,int m)
{cout<<"Enter array elements:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>*(arr+i*m+j);
        }
    }
}


int main()
{
    int n,m,k;
    
    cout<<"Enter the rows and columns of the array A:\n";
    cin>>n>>m;
    int a[100][100];
    
    get((int *)a,n,m);
    rowsum((int*)a,n,m);

    return 0;
}
